<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Hero Video pane'),
  'description' => t('Hero Video pane'),
  'category' => 'NAS',
  'edit form' => 'hero_video_form',
  'render callback' => 'hero_video_form_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * An edit form for the pane's settings.
 */
function hero_video_form($form, &$form_state) {
  _nas_panes_hide_pane_title_field($form);
  return $form;
}

/**
 * Submit handler for configuration.
 */
function hero_video_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 *
 * @see ctools_plugin_examples()
 */
function hero_video_form_render($subtype, $conf, $args, $contexts) {
  $node = $contexts->data;
  if ($node->type !== 'article') {
    return;
  }

  $hero_video = field_get_items('node', $node, 'field_hero_video');
  $hero_video_poster = field_get_items('node', $node, 'field_hero_video_poster');
  $hero_video_settings = field_get_items('node', $node, 'field_hero_video_settings');

  // Hero Video.
  if (!is_array($hero_video)) {
    return;
  }
  $hero_video = reset($hero_video);
  if (!empty($hero_video['file']->uri) && !empty($hero_video['file']->filemime)) {
    $hero_video = $hero_video['file'];
  }
  else {
    if (empty($hero_video['fid'])) {
      return;
    }
    $hero_video = file_load($hero_video['fid']);
  }

  // Hero video poster.
  $hero_image_path = '';
  if (is_array($hero_video_poster)) {
    $hero_video_poster = reset($hero_video_poster);
    if (empty($hero_video_poster['file']->uri)) {
      return;
    }
    $image_uri = nas_alters_local_image_uri($hero_video_poster['file']->uri);
    $hero_image_path = image_style_url('hero_video_poster', $image_uri);
  }

  // Hero video settings.
  $settings = array();
  if (!empty($hero_video_settings)) {
    foreach ($hero_video_settings as $setting) {
      $settings[$setting['value']] = $setting['value'];
    }
    $hero_video_settings = $settings;
    $settings = array();
  }
  // Get default values for field to avoid IF()s in template.
  $hero_video_settings_default_values = field_info_field('field_hero_video_settings');
  foreach ($hero_video_settings_default_values['settings']['allowed_values'] as $value) {
    $settings[$value] = (!empty($hero_video_settings[$value])) ? $value : '';
  }

  $content = theme('hero_video_pane', array(
    'video_url' => file_create_url($hero_video->uri),
    'video_type' => $hero_video->filemime,
    'video_settings' => $settings,
    'video_poster' => $hero_image_path,
  ));
  $block = new stdClass();
  $block->content = $content;
  return $block;
}
