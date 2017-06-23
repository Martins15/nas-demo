<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Full-width Hero block'),
  'description' => t('Full-width hero block for article'),
  'category' => 'Full width',
  'edit form' => 'full_width_hero_block_form',
  'render callback' => 'full_width_hero_block_render',
  'hook theme' => 'full_width_hero_block_theme',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'tags' => array('top'),
  'render first' => TRUE,
);

/**
 * An edit form for the pane's settings.
 */
function full_width_hero_block_form($form, &$form_state) {
  // Hide title the pane.
  _nas_panes_hide_pane_title_field($form);

  // Include the CTools content type plugin file, because it provides
  // the ctools_content_configure_form_defaults() function, which is needed
  // when rebuilding the form, because of an ajax action, like selecting
  // a media element.
  ctools_form_include($form_state, 'content');

  // Include this plugin file as well, so that when the form is rebuilt, it
  // can successfully retrieve the settings form.
  ctools_form_include($form_state, 'full_width_hero_block', 'nas_panes', 'plugins/content_types/full_width_hero_block');

  $conf = $form_state['conf'];
  $form['#tree'] = TRUE;
  $conf_key = 'default';

  // Panelizer.
  if (isset($form_state['display']->context['panelizer']) && !$form_state['display']->context['panelizer']->empty) {
    $conf_key = $form_state['display']->context['panelizer']->keyword . $form_state['display']->context['panelizer']->argument;
    // Support old version of the key that was simple nid. For the future it is
    // better to have also type of the entity in the key so we could enable
    // panelizer for taxonomy terms and have no conflicts in node's and term's ids.
    if (!isset($conf[$conf_key])) {
      $conf_key = $form_state['display']->context['panelizer']->argument;
    }
  }

  $form[$conf_key] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
  );

  $variants = array(
    'title_only' => t('Title only'),
    'standard_hero_photo' => t('Standard Hero photo'),
    'fullscreen_hero_photo' => t('Fullscreen Hero photo'),
  );
  $form[$conf_key]['variants'] = array(
    '#type' => 'select',
    '#title' => t('Variants'),
    '#options' => $variants,
    '#default_value' => !empty($conf[$conf_key]['variants']) ? $conf[$conf_key]['variants'] : 'title_only',
  );

  $form[$conf_key]['header_color_mode'] = array(
    '#type' => 'radios',
    '#title' => t('Nav bar coloring'),
    '#options' => array(
      'dark' => t('Light background, black text'),
      'light' => t('Dark background, white text'),
      'none' => t('Solid black background above hero image, white text'),
    ),
    '#default_value' => !empty($conf[$conf_key]['header_color_mode']) ? $conf[$conf_key]['header_color_mode'] : 'dark',
    '#description' => t('You can choose if the image you uploaded is dark or light so that proper font styles were applied to header content.'),
  );
  $form[$conf_key]['disable_gradient'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable gradient'),
    '#default_value' => !empty($conf[$conf_key]['disable_gradient']) ? $conf[$conf_key]['disable_gradient'] : '',
    '#return_value' => 'disable',
    '#description' => t('By default the nav bar appears overlaid on top of the hero image with a gradient background (which can be disabled). Additionally, the hero image can sit underneath a solid black nav bar with white text.'),
  );

  $form[$conf_key]['text_color_mode'] = array(
    '#type' => 'radios',
    '#title' => t('Text color mode'),
    '#options' => array(
      'dark' => t('Dark'),
      'light' => t('Light'),
    ),
    '#default_value' => !empty($conf[$conf_key]['text_color_mode']) ? $conf[$conf_key]['text_color_mode'] : 'dark',
    '#description' => t('You can choose if the image you uploaded is dark or light so that proper font styles were applied to any text content visible on that image.'),
  );

  return $form;
}

/**
 * Submit callback.
 */
function full_width_hero_block_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 *
 * See ctools_plugin_examples for more advanced info.
 */
function full_width_hero_block_render($subtype, $conf, $args, $context) {
  $node = $context->data;
  // We can't add node context to the pane, because it's use on landing pages too.
  $conf_key = 'default';
  if ($context_node = menu_get_object('node')) {
    // Support old configuration when key was nid only.
    if (isset($conf[$context_node->nid])) {
      $conf_key = $context_node->nid;
    }
    // New configuration has entity type prefix.
    if (isset($conf['node' . $context_node->nid])) {
      $conf_key = 'node' . $context_node->nid;
    }
  }

  if (isset($conf[$conf_key])) {
    $data = $conf[$conf_key];
  }

  $theme = $subtype;

  if ($content = _full_width_hero_hero_photo_render($node)) {
    $theme = ($data['variants'] == 'standard_hero_photo') ? $subtype . '_standard_hero_photo' : $subtype . '_fullscreen_hero_photo';
  }

  list($category_text, $category_url) = nas_panes_get_blue_text_link($node);
  $category_link = l($category_text, $category_url, array('attributes' => array('class' => 'article-slug')));

  $field_subtitle = field_get_items('node', $node, 'field_subtitle');

  // Header color mode.
  $class = &drupal_static('nas_header_class');
  if (!empty($data['header_color_mode']) && $data['header_color_mode'] == 'light') {
    $class = !empty($data['disable_gradient']) ? 'light-text transparent' : 'light-text dark-bg transparent';
  }
  elseif (!empty($data['header_color_mode']) && $data['header_color_mode'] == 'dark') {
    $class = !empty($data['disable_gradient']) ? 'dark-text transparent' : 'dark-text light-bg transparent';
  }

  // Text color mode..
  $color_mode_gradient = 'light';
  if ($data['text_color_mode'] == 'light') {
    $color_mode_gradient = 'dark';
  }

  $default_content = array(
    'title' => $node->title,
    'subtitle' => !empty($field_subtitle[0]['safe_value']) ? $field_subtitle[0]['safe_value'] : FALSE,
    'category_link' => $category_link,
    'color_mode_gradient' => $color_mode_gradient,
    'color_mode_text' => $data['text_color_mode'],
  );

  // Merge default content with new content.
  $content = $default_content + $content;

  $block = new stdClass();
  $block->content = theme($theme, $content);
  return $block;
}

/**
 * Helper function for 'Hero image'.
 *
 * @param object $node
 *   Node object.
 *
 * @return array
 *   Rendered HTML markup.
 */
function _full_width_hero_hero_photo_render($node) {
  // Add hero image.
  $get_field_hero_image = field_get_items('node', $node, 'field_hero_image');
  if (!empty($get_field_hero_image)) {
    $image_wrapper = entity_metadata_wrapper('file', $get_field_hero_image[0]['file']);
    $image_caption = check_plain($image_wrapper->field_file_caption->value()['value']);
    $hero_image = theme('image_style', array(
      'style_name' => 'hero_image',
      'path' => nas_alters_local_image_uri($get_field_hero_image[0]['file']->uri),
      'title' => $image_caption,
    ));

    $content = array(
      'hero_image' => $hero_image,
      'caption' => _nas_panes_format_image_attribution($get_field_hero_image[0]['file']),
    );
    return $content;
  }

  return array();
}

/**
 * Delegated implementation of hook_theme().
 */
function full_width_hero_block_theme(&$theme, $plugin) {
  $theme['full_width_hero_block'] = array(
    'variables' => array(
      'title' => NULL,
      'subtitle' => NULL,
      'category_link' => NULL,
      'contextual_links' => NULL,
      'color_mode_gradient' => NULL,
      'color_mode_text' => NULL,
    ),
    'template' => 'full-width-hero-block',
    'path' => $plugin['path'],
  );
  $theme['full_width_hero_block_standard_hero_photo'] = array(
    'variables' => array(
      'title' => NULL,
      'subtitle' => NULL,
      'category_link' => NULL,
      'hero_image' => NULL,
      'caption' => NULL,
      'contextual_links' => NULL,
      'color_mode_gradient' => NULL,
      'color_mode_text' => NULL,
    ),
    'template' => 'full-width-hero-block-standard-hero-photo',
    'path' => $plugin['path'],
  );
  $theme['full_width_hero_block_fullscreen_hero_photo'] = array(
    'variables' => array(
      'title' => NULL,
      'subtitle' => NULL,
      'category_link' => NULL,
      'hero_image' => NULL,
      'caption' => NULL,
      'contextual_links' => NULL,
      'color_mode_gradient' => NULL,
      'color_mode_text' => NULL,
    ),
    'template' => 'full-width-hero-block-fullscreen-hero-photo',
    'path' => $plugin['path'],
  );
}
