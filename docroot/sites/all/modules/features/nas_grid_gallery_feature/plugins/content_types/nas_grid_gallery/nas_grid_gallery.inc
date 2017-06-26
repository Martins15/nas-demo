<?php
/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Grid Gallery'),
  'description' => t('Gallery images based on Ligthbox.'),
  'category' => 'NAS',
  'edit form' => 'nas_grid_gallery_edit_form',
  'render callback' => 'nas_grid_gallery_render',
  'hook theme' => 'nas_grid_gallery_theme',
  'required context' => new ctools_context_optional(t('Node'), 'node'),
  'no title override' => TRUE,
  'defaults' => array(
    'gallery_caption' => '',
    'grid_size' => 0,
    'gallery_images' => array(),
    'mobile_fallback' => 0,
    'mobile_fallback_image' => 0,
  ),
);

/**
 * An edit form for the pane's settings.
 */
function nas_grid_gallery_edit_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  // Hide title the pane.
  _nas_panes_hide_pane_title_field($form);

  // Include the CTools content type plugin file, because it provides
  // the ctools_content_configure_form_defaults() function, which is needed
  // when rebuilding the form, because of an ajax action, like selecting
  // a media element.
  ctools_form_include($form_state, 'content');

  // Include this plugin file as well, so that when the form is rebuilt, it
  // can successfully retrieve the settings form.
  ctools_form_include($form_state, 'nas_grid_gallery', 'nas_grid_gallery_feature', 'plugins/content_types/nas_grid_gallery');

  $form['#tree'] = TRUE;

  $grid_size_options = array(
    '0' => t('- Select grid size -'),
    '1x1' => t('(1x1) 1 column, 1 row'),
    '2x1' => t('(2x1) 2 columns, 1 row'),
    '2x2' => t('(2x2) 2 columns, 2 rows'),
    '3x2' => t('(3x2) 3 columns, 2 rows'),
    '3x1' => t('(3x1) 3 columns, 1 row'),
    '6x2' => t('(6x2) 6 columns, 2 rows'),
    '6x3' => t('(6x3) 6 columns, 3 rows'),
  );

  $form['grid_size'] = array(
    '#type' => 'select',
    '#title' => t('Grid size'),
    '#options' => $grid_size_options,
    '#ajax' => array(
      'callback' => '_nas_grid_gallery_ajax_form_callback',
      'wrapper' => 'gallery-images-wrapper',
      'event' => 'change',
      'method' => 'replace',
      'effect' => 'fade',
    ),
    '#default_value' => $conf['grid_size'],
  );

  // Get Grid size for make image count.
  $grid_size_value = isset($form_state['values']['grid_size']) ? $form_state['values']['grid_size'] : '';

  // Get default value when count is empty or when it has been update via form.
  if (empty($form_state['storage']['count']) || (!empty($grid_size_value) && $form_state['storage']['grid_size'] != $grid_size_value)) {
    // Update value when form has been submitted.
    if (!empty($grid_size_value)) {
      $grid = _nas_grid_gallery_grid_info($grid_size_value);
      $form_state['storage']['count'] = $grid['images'];
    }
    // Get from panel pane configuration.
    elseif (!empty($conf['grid_size'])) {
      $grid = _nas_grid_gallery_grid_info($conf['grid_size']);
      $form_state['storage']['count'] = $grid['images'];
    }
    // Default value.
    else {
      $form_state['storage']['count'] = 0;
    }
  }

  // Create wrapper for ajax.
  $form['gallery_images'] = array(
    '#type' => ' container',
    '#prefix' => '<div id="gallery-images-wrapper">',
    '#suffix' => '</div>',
  );

  for ($i = 0; $i < $form_state['storage']['count']; $i++) {
    if (empty($conf['gallery_images'][$i])) {
      $conf['images'][$i] = array();
    }
    $form['gallery_images'][$i]['image'] = array(
      '#type' => 'media',
      '#tree' => TRUE,
      '#title' => t('Image № @number', array('@number' => $i + 1)),
      '#description' => t('Allowed formats: png, jpg, jpeg, gif.'),
      '#media_options' => array(
        'global' => array(
          'file_extensions' => 'png jpg jpeg gif',
          'max_filesize' => '20 MB',
          'file_directory' => 'grid_gallery',
          'types' => array('image'),
        ),
      ),
      '#default_value' => !empty($conf['gallery_images'][$i]['image']) ? $conf['gallery_images'][$i]['image'] : '',
    );
  }

  $form['gallery_caption'] = array(
    '#type' => 'textarea',
    '#title' => t('Gallery caption'),
    '#rows' => 2,
    '#default_value' => $conf['gallery_caption'],
  );

  $form['mobile_fallback'] = array(
    '#type' => 'select',
    '#title' => t('Mobile fallback'),
    '#options' => array(
      0 => t('None'),
      'slideshow' => t('Slideshow'),
      'single' => t('Single picture'),
    ),
    '#default_value' => $conf['mobile_fallback'],
  );

  $form['mobile_fallback_image'] = array(
    '#type' => 'media',
    '#tree' => TRUE,
    '#title' => t('Mobile Fallback Image'),
    '#description' => t('Allowed formats: png, jpg, jpeg, gif.'),
    '#media_options' => array(
      'global' => array(
        'file_extensions' => 'png jpg jpeg gif',
        'max_filesize' => '20 MB',
        'file_directory' => 'grid_gallery',
        'types' => array('image'),
      ),
    ),
    '#default_value' => $conf['mobile_fallback_image'],
  );

  $plugin_path = drupal_get_path('module', 'nas_grid_gallery_feature') . '/plugins/content_types/nas_grid_gallery';
  $form['#attached']['css'][] = $plugin_path . '/css/grid_gallery_admin.css';

  return $form;
}

/**
 * Validation callback.
 */
function nas_grid_gallery_edit_form_validate($form, $form_state) {
  $values = &$form_state['values'];
  // Check if all images exist.
  if (isset($values['gallery_images'])) {
    foreach ($values['gallery_images'] as $item) {
      if (!$item['image']) {
        form_set_error('images', t('Please add other images.'));
      }
    }
  }

  if ($values['mobile_fallback'] == 'single') {
    if (!$values['mobile_fallback_image'] || !file_load($values['mobile_fallback_image'])) {
      form_set_error('mobile_fallback_image', t('Please specify the mobile fallback image.'));
    }
  }
}

/**
 * Submit callback.
 */
function nas_grid_gallery_edit_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Render callback.
 */
function nas_grid_gallery_render($subtype, $conf, $args, $context) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  if ($plugin = ctools_get_plugins('ctools', 'content_types', $subtype)) {
    $conf = array_merge($plugin['defaults'], $conf);
  }

  if (!$conf['gallery_images']) {
    return;
  }

  $grid_classes = array(
    '1x1' => 'tiny-12',
    '2x1' => 'tiny-6',
    '2x2' => 'tiny-6',
    '3x1' => 'small-4 tiny-12',
    '3x2' => 'small-4 tiny-6',
    '6x2' => 'small-2 tiny-6',
    '6x3' => 'small-2 tiny-6',
    '6x6' => 'small-2 tiny-6',
  );
  $grid_info = _nas_grid_gallery_grid_info($conf['grid_size']);
  $class_column = $grid_classes[$conf['grid_size']];

  $images = array();
  foreach ($conf['gallery_images'] as $image) {
    if (empty($image['image'])) {
      continue;
    }
    if (!$image_file = file_load($image['image'])) {
      continue;
    }
    $image_uri = nas_alters_local_image_uri($image_file->uri);
    $vars = array(
      'thumbnail_path' => image_style_url('grid_gallery_thumbnail', $image_uri),
      'lightbox_path' => image_style_url('grid_gallery_lightbox', $image_uri),
      'attributes' => '',
      'attributes_plain' => '',
      'caption' => '',
      'credit' => '',
      'class_column' => $class_column,
    );
    if (function_exists('_nas_panes_format_image_attribution')) {
      $vars['attributes'] = _nas_panes_format_image_attribution($image_file);
      $vars['attributes_plain'] = _nas_panes_format_image_attribution($image_file, TRUE);
      $image_attributes = _nas_panes_format_image_attribution($image_file, FALSE, TRUE);
      $vars['caption'] = filter_xss(_filter_autop($image_attributes['caption']), array('a', 'em', 'i', 'b', 'strong', 'cite', 'blockquote', 'code', 'ul', 'ol', 'li', 'dl', 'dt', 'dd', 'p'));
      $vars['credit'] = $image_attributes['credit'] ? 'Photo: ' . filter_xss($image_attributes['credit']) : '';
    }
    $images[] = $vars;
  }

  $mobile_fallback_image = '';
  if ($conf['mobile_fallback'] == 'single') {
    if ($mobile_fallback_image_file = file_load($conf['mobile_fallback_image'])) {
      $mobile_fallback_image_uri = nas_alters_local_image_uri($mobile_fallback_image_file->uri);
      $mobile_fallback_image = image_style_url('grid_gallery_thumbnail', $mobile_fallback_image_uri);
    }
  }

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'nas_grid_gallery',
    '#grid_size' => $conf['grid_size'],
    '#images' => $images,
    '#rows' => $grid_info['rows'],
    '#columns' => $grid_info['columns'],
    '#gallery_caption' => !empty($conf['gallery_caption']) ? filter_xss(_filter_autop($conf['gallery_caption']), array('a', 'em', 'i', 'b', 'strong', 'cite', 'blockquote', 'code', 'ul', 'ol', 'li', 'dl', 'dt', 'dd', 'p')) : FALSE,
    '#output_placeholder' => _nas_grid_gallery_placeholder(),
    '#mobile_fallback' => $conf['mobile_fallback'],
    '#mobile_fallback_image' => $mobile_fallback_image,
  );

  if (!$plugin) {
    return $block;
  }

  $block->content['#attached'] = array(
    'css' => array(
      $plugin['path'] . '/css/blueimp-gallery.min.css',
      $plugin['path'] . '/css/grid_gallery.css' => array(
        'group' => CSS_THEME,
        'weight' => 999
      ),
    ),
    'js' => array(
      array(
        'type' => 'file',
        'data' => $plugin['path'] . '/js/blueimp-gallery.js',
        'group' => JS_LIBRARY,
        'weight' => 100,
      ),
      array(
        'type' => 'file',
        'data' => $plugin['path'] . '/js/blueimp-gallery-fullscreen.js',
        'group' => JS_LIBRARY,
        'weight' => 101,
      ),
      array(
        'type' => 'file',
        'data' => $plugin['path'] . '/js/jquery.blueimp-gallery.js',
        'group' => JS_LIBRARY,
        'weight' => 102,
      ),
      array(
        'type' => 'file',
        'data' => $plugin['path'] . '/js/grid_gallery.js',
        'group' => JS_THEME,
      ),
    ),
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function nas_grid_gallery_theme(&$theme, $plugin) {
  $theme['nas_grid_gallery'] = array(
    'variables' => array(
      'grid_size' => NULL,
      'images' => NULL,
      'rows' => NULL,
      'columns' => NULL,
      'gallery_caption' => NULL,
      'output_placeholder' => NULL,
      'mobile_fallback' => NULL,
      'mobile_fallback_image' => NULL,
    ),
    'template' => 'nas-grid-gallery',
    'path' => $plugin['path'],
  );
}

/**
 * Ajax callback for form.
 */
function _nas_grid_gallery_ajax_form_callback($form, &$form_state) {
  return $form['gallery_images'];
}

/**
 * Helper function to control gallery ligthbox placeholder output.
 *
 * Grid Gallery lightbox must be output only once on the page.
 *
 * @return bool
 *   True if gallery lightbox placeholder needs to be output.
 */
function _nas_grid_gallery_placeholder() {
  static $called = FALSE;

  if (!$called) {
    $called = TRUE;
    return TRUE;
  }

  return FALSE;
}

/**
 * Create array with information about grid.
 */
function _nas_grid_gallery_grid_info($grid_size) {
  if ($grid_size) {
    list($columns, $rows) = explode('x', $grid_size, 2);
    $images = $rows * $columns;
    return array(
      'rows' => $rows,
      'columns' => $columns,
      'images' => $images,
    );
  }
  return array();
}
