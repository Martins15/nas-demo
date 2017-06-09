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
  ctools_form_include($form_state, 'nas_grid_gallery', 'nas_grid_gallery_feature', 'plugins/content_types');

  $form['#tree'] = TRUE;

  $grid_size_options = array(
    '0' => t('- Select grid size -'),
    '1x1' => t('(1x1) 1 row, 1 column'),
    '2x2' => t('(2x2) 2 rows, 2 columns'),
    '2x3' => t('(2x3) 2 rows, 3 columns'),
    '3x1' => t('(3x1) 3 rows, 1 column'),
    '3x6' => t('(3x6) 3 rows, 6 columns'),
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
          'file_directory' => '',
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

  $form['#attached']['css'][] = drupal_get_path('module', 'nas_grid_gallery_feature') . '/plugins/content_types/css/grid_gallery_admin.css';

  return $form;
}

/**
 * Validation callback.
 */
function nas_grid_gallery_edit_form_validate($form, $form_state) {
  $values =& $form_state['values'];
  // Check if all images exist.
  if (isset($values['gallery_images'])) {
    foreach ($values['gallery_images'] as $item) {
      if (!$item['image']) {
        form_set_error('images', t('Please add other images.'));
      }
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

  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $context);

  $grid_info = _nas_grid_gallery_grid_info($conf['grid_size']);

  if ($conf['gallery_images']) {
    foreach ($conf['gallery_images'] as $image) {
      if (!empty($image['image'])) {
        $image_file = file_load($image['image']);
        $image_uri = nas_alters_local_image_uri($image_file->uri);
        $vars['thumbnail_path'] = image_style_url('grid_gallery_thumbnail', nas_alters_local_image_uri($image_uri));
        $vars['lightbox_path'] = image_style_url('grid_gallery_lightbox', nas_alters_local_image_uri($image_uri));
        $vars['thumbnail_title'] = '';
        if (!empty($image_file) && function_exists('_nas_panes_format_image_attribution')) {
          $vars['thumbnail_title'] = _nas_panes_format_image_attribution($image_file);
        }
      }
      $images[] = $vars;
    }
  }

  $class_column = ' large-12';
  if ($grid_info['columns'] == 2) {
    $class_column = ' large-6';
  }
  if ($grid_info['columns'] == 3) {
    $class_column = ' large-4';
  }
  if ($grid_info['columns'] == 6) {
    $class_column = ' large-2';
  }

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'nas_grid_gallery',
    '#grid_size' => $conf['grid_size'],
    '#images' => $images,
    '#rows' => $grid_info['rows'],
    '#columns' => $grid_info['columns'],
    '#class_column' => $class_column,
    '#gallery_caption' => !empty($conf['gallery_caption']) ? check_plain($conf['gallery_caption']) : FALSE,
    '#contextual_links' => $contextual_links,
  );

  if (!$plugin = ctools_get_plugins('ctools', 'content_types', $subtype)) {
    return $block;
  }

  $block->content['#attached'] = array(
    'css' => array(
      $plugin['path'] . '/css/grid_gallery.css',
    ),
    'js' => array(
      $plugin['path'] . '/js/grid_gallery.js',
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
      'class_column' => NULL,
      'gallery_caption' => NULL,
      'contextual_links' => NULL,
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
 * Create array with information about grid.
 */
function _nas_grid_gallery_grid_info($grid_size) {
  if ($grid_size) {
    list($columns, $rows) = explode("x", $grid_size, 2);
    $images = $rows * $columns;
    return array('rows' => $rows, 'columns' => $columns, 'images' => $images);
  }
  return array();
}
