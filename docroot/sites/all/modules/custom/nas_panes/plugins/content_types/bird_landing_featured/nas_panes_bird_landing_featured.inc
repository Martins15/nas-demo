<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Bird Landing. Featured Bird'),
  'description' => t('Provides Featured Bird block for Bird Landing page'),
  'category' => 'NAS',
  'edit form' => 'bird_landing_featured_form',
  'render callback' => 'bird_landing_featured_render',
);

/**
 * An edit form for the pane's settings.
 */
function bird_landing_featured_form($form, &$form_state) {
  $conf = $form_state['conf'];
  _nas_panes_hide_pane_title_field($form);

  $form['bird'] = array(
    '#type' => 'entityreference',
    '#title' => 'Featured Bird',
    '#default_value' => !empty($conf['bird']['entity_id']) ? $conf['bird']['entity_id'] : '',
    '#era_entity_type' => 'node',
    '#era_bundles' => array('bird'),
  );

  $form['image'] = array(
    '#type' => 'media',
    '#tree' => TRUE,
    '#title' => t('Image'),
    '#description' => t('Allowed formats: png, jpg, jpeg, gif.'),
    '#media_options' => array(
      'global' => array(
        'file_extensions' => 'png jpg jpeg gif',
        'max_filesize' => '10 MB',
        'file_directory' => '',
        'types' => array('image'),
      ),
    ),
    '#default_value' => !empty($conf['image']) ? $conf['image'] : 0,
    '#required' => TRUE,
  );

  // The two function calls below are necessary if we want to use a media
  // element type, because it causes ajax requests, which in turn call
  // drupal_form_rebuild(), and without the below includes, Drupal will
  // not be able to rebuild the form.

  // Include the CTools content type plugin file, because it provides
  // the ctools_content_configure_form_defaults() function, which is needed
  // when rebuilding the form, because of an ajax action, like selecting
  // a media element.
  ctools_form_include($form_state, 'content');

  // Include this plugin file as well, so that when the form is rebuilt, it
  // can successfully retrieve the settings form.
  ctools_form_include($form_state, 'nas_panes_bird_landing_featured', 'nas_panes', 'plugins/content_types/bird_landing_featured');
  $form['header_color_mode'] = array(
    '#type' => 'radios',
    '#title' => t('Nav bar coloring'),
    '#options' => array(
      'dark' => t('Light background, black text'),
      'light' => t('Dark background, white text'),
      'none' => t('Solid black background above hero image, white text'),
    ),
    '#default_value' => !empty($conf['header_color_mode']) ? $conf['header_color_mode'] : 'light',
    '#description' => t('You can choose if the image you uploaded is dark or light so that proper font styles were applied to header content.'),
  );
  $form['disable_gradient'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable gradient'),
    '#default_value' => isset($conf['disable_gradient']) ? $conf['disable_gradient'] : '',
    '#return_value' => 'disable',
    '#description' => t('By default the nav bar appears overlaid on top of the hero image with a gradient background (which can be disabled). Additionally, the hero image can sit underneath a solid black nav bar with white text.'),
  );
  $form['color'] = array(
    '#type' => 'select',
    '#title' => t('Image color scheme'),
    '#options' => array(
      'dark' => 'dark',
      'light' => 'light',
    ),
    '#default_value' => !empty($conf['color']) ? $conf['color'] : 'dark',
    '#description' => t('You can choose if the image you uploaded is dark or light so that proper font styles were applied to any text content visible on that image.'),
  );

  $form['summary'] = array(
    '#type' => 'textarea',
    '#title' => t('Summary'),
    '#required' => TRUE,
    '#default_value' => !empty($conf['summary']) ? $conf['summary'] : '',
  );

  return $form;
}

/**
 * Submit callback.
 */
function bird_landing_featured_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
  // Save Bird Landing Featured nid to variables.
  if (isset($form_state['values']['bird']['entity_id'])) {
    variable_set('nas_bird_landing_featured_bird', $form_state['values']['bird']['entity_id']);
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 *
 * See ctools_plugin_examples for more advanced info.
 */
function bird_landing_featured_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  if (!isset($conf['bird']['entity_id']) || empty($conf['bird']['entity_id'])) {
    $block->content = '';
    if (user_access('access contextual links') && user_access('edit NAS panes')) {
      $block->content = t('No featured bird selected');
    }
    return $block;
  }

  $node = _i18n_node_load($conf['bird']['entity_id']);

  $hero_image = file_load($conf['image']);
  $hero_image_uri = nas_alters_local_image_uri($hero_image->uri);
  $hero_image_path = image_style_url('hero_image', $hero_image_uri);
  $hero_image_path_mobile = image_style_url('hero_mobile', $hero_image_uri);

  $attribution = _nas_panes_format_image_attribution($hero_image);

  $summary = check_plain($conf['summary']);

  $bird_guide_link = l(t('Bird Guide'), 'birds/bird-guide');
  $category_link = 'birds/priority';
  $category_link_more = l(t('More Priority Birds'), $category_link);

  $contextual_links = '';
  if (user_access('bird landing featured pane edit')) {
    ctools_include('modal');
    ctools_modal_add_js();
    // Add ajax-responder so ctools_ajax_command_reload() will work.
    ctools_add_js('ajax-responder');
    // We expect Featured Bird pane to be only on Bird Guide. If this is not
    // the case we will need to change this select query.
    $pid = db_query('SELECT pid FROM {panels_pane} WHERE type = :type', array(':type' => 'nas_panes_bird_landing_featured'))->fetchField();
    if (empty($pid)) {
      nas_panes_resave_panel(NAS_PANES_BIRD_LANDING_PAGE_MANAGER_CACHE_KEY);
      $pid = db_query('SELECT pid FROM {panels_pane} WHERE type = :type', array(':type' => 'nas_panes_bird_landing_featured'))->fetchField();
    }
    $links = array(
      'edit' => array(
        'title' => t('Edit'),
        'href' => 'panels/ajax/editor/edit-pane/panel_context:' . NAS_PANES_BIRD_LANDING_PAGE_MANAGER_CACHE_KEY . '::page_birds_landing_panel_context::::/' . $pid,
        'query' => array('reload' => 'true', 'nas-panes-from-page' => 'true'),
        'attributes' => array('class' => array('ctools-use-modal')),
      ),
    );
    $build = array(
      '#prefix' => '<div class="contextual-links-wrapper">',
      '#suffix' => '</div>',
      '#theme' => 'links__contextual',
      '#links' => $links,
      '#attributes' => array('class' => array('contextual-links')),
      '#attached' => array(
        'library' => array(array('contextual', 'contextual-links')),
      ),
    );
    $contextual_links = drupal_render($build);
  }

  $content = theme('nas_bird_landing_featured', array(
    'name' => check_plain($node->title),
    'url' => url('node/' . $node->nid),
    'image_path' => $hero_image_path,
    'image_path_mobile' => $hero_image_path_mobile,
    'summary' => $summary,
    'bird_guide_link' => $bird_guide_link,
    'category' => t('Priority Birds'),
    'color' => !empty($conf['color']) ? $conf['color'] : 'dark',
    'category_link_url' => url($category_link),
    'category_link_more' => $category_link_more,
    'attribution' => $attribution,
    'contextual_links' => $contextual_links,
  ));

  $class = &drupal_static('nas_header_class');
  if (!empty($conf['header_color_mode']) && $conf['header_color_mode'] == 'light') {
    $class = !empty($conf['disable_gradient']) ? 'light-text transparent' : 'light-text dark-bg transparent';
  }
  elseif (!empty($conf['header_color_mode']) && $conf['header_color_mode'] == 'dark') {
    $class = !empty($conf['disable_gradient']) ? 'dark-text transparent' : 'dark-text light-bg transparent';
  }

  $block->content = $content;
  return $block;
}
