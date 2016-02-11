<?php
/**
 * @file
 * Native Plants hero image plugin.
 */

$plugin = array(
  'title' => t('Native Plants hero image'),
  'description' => t('Native Plants hero image.'),
  'category' => 'Native Plants',
  'admin info' => 'native_plants_hero_admin_info',
  'edit form' => 'native_plants_hero_edit_form',
  'render callback' => 'native_plants_hero_render',
  'hook theme' => 'native_plants_hero_theme',
  'defaults' => array(
    'title' => 'When you plant native plants, you help birds and the environment.',
    'override_title_text' => 'When you plant native plants, you help birds and the environment.',
    'image' => 0,
  ),
);

/**
 * Administrative info callback.
 */
function native_plants_hero_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = $conf['title'];
  $block->content = $conf['title'];
  return $block;
}

/**
 * Configuration form.
 */
function native_plants_hero_edit_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  $form['override_title_heading']['#access'] = FALSE;
  $form['image'] = array(
    '#type' => 'media',
    '#tree' => TRUE,
    '#title' => t('Image'),
    '#description' => t('Allowed formats: png, jpg, jpeg, gif.'),
    '#media_options' => array(
      'global' => array(
        'file_extensions' => 'png jpg jpeg gif',
        'max_filesize' => '20 MB',
        'file_directory' => '',
        'types' => array('image'),
      ),
    ),
    '#default_value' => $conf['image'],
  );
  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'native_plants_hero', 'nas_panes', 'plugins/content_types/native_plants_hero');

  return $form;
}

/**
 * Submit handler for configuration.
 */
function native_plants_hero_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (array_key_exists($key, $form_state['values'])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }

  // Form build ID is required for contextual links.
  $form_state['conf']['form_build_id'] = $form_state['values']['form_build_id'];
}

/**
 * Render callback.
 */
function native_plants_hero_render($subtype, $conf, $args, $context) {
  // $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $context);

  $image_path = '';
  $image_attribution = '';
  if ($image = file_load($conf['image'])) {
    $image_path = image_style_url('hero_image', $image->uri);
    $image_attribution = _nas_panes_format_image_attribution($image);
  }

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'native_plants_hero',
    '#title' => t(filter_xss($conf['title'])),
    '#image_path' => $image_path,
    '#image_attribution' => $image_attribution,
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function native_plants_hero_theme(&$theme, $plugin) {
  $theme['native_plants_hero'] = array(
    'variables' => array(
      'title' => '',
      'image_path' => '',
      'image_attribution' => '',
    ),
    'template' => 'native-plants-hero',
    'path' => $plugin['path'],
  );
}
