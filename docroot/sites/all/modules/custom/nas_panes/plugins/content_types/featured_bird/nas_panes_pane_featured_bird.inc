<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Bird Guide. Featured Bird'),
  'description' => t('Provides Featured Bird block for Bird Guide'),
  'category' => 'NAS',
  'edit form' => 'nas_panes_pane_featured_bird_custom_pane_edit_form',
  'render callback' => 'nas_panes_pane_featured_bird_custom_pane_render',
  'defaults' => array(
    'color' => 'light',
    'image' => 0,
    'bird' => array(
      'entity_id' => ''
    )
  ),
);

/**
 * An edit form for the pane's settings.
 */
function nas_panes_pane_featured_bird_custom_pane_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  _nas_panes_hide_pane_title_field($form);

  $form['bird'] = array(
    '#type' => 'entityreference',
    '#title' => 'Featured Bird',
    '#default_value' => $conf['bird']['entity_id'],
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
        'max_filesize' => '20 MB',
        'file_directory' => '',
        'types' => array('image'),
      ),
    ),
    '#default_value' => $conf['image'],
    '#required' => FALSE,
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
  ctools_form_include($form_state, 'nas_panes_pane_featured_bird', 'nas_panes', 'plugins/content_types/featured_bird');

  $form['color'] = array(
    '#type' => 'select',
    '#title' => t('Image color scheme'),
    '#options' => array(
      'dark' => 'dark',
      'light' => 'light'
    ),
    '#default_value' => $conf['color'],
    '#description' => t('You can choose if the image you uploaded is dark or light so that proper font styles were applied to any text content visible on that image.'),
  );

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function nas_panes_pane_featured_bird_custom_pane_edit_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
  // Save Bird Guide Featured nid to variables.
  if (isset($form_state['values']['bird']['entity_id'])) {
    variable_set('nas_bird_guide_featured_bird', $form_state['values']['bird']['entity_id']);
  }
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function nas_panes_pane_featured_bird_custom_pane_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  if (!isset($conf['bird']['entity_id']) || empty($conf['bird']['entity_id'])) {
    $block->content = '';
    if (user_access('access contextual links') && user_access('edit NAS panes')) {
      $block->content = t('No featured bird selected');
    }
    return $block;
  }

  $node = node_load($conf['bird']['entity_id']);

  $hero_image_item = field_get_items('node', $node, 'field_hero_image');

  if (!empty($hero_image_item[0]['fid'])) {
    $image_fid = $hero_image_item[0]['fid'];
  }
  if (!empty($conf['image'])) {
    $image_fid = $conf['image'];
  }
  $attribution = '';
  $hero_image_path = '';
  $hero_image_path_mobile = '';
  if (isset($image_fid) && $hero_image = file_load($image_fid)) {
    $hero_image_path = image_style_url('hero_image', $hero_image->uri);
    $hero_image_path_mobile = image_style_url('hero_mobile', $hero_image->uri);
    $attribution = _nas_panes_format_image_attribution($hero_image);
  }

  $color_classes = 'light-text dark-gradient';
  if ($conf['color'] == 'dark') {
    $color_classes = 'dark-text light-gradient';
  }

  $scientific_name_item = field_get_items('node', $node, 'field_bird_sci_name');
  $scientific_name = isset($scientific_name_item[0]['safe_value']) ? $scientific_name_item[0]['safe_value'] : '';

  $illustration_path = '';
  $illustration_item = field_get_items('node', $node, 'field_bird_illustration');
  if (!empty($illustration_item[0]['fid'])) {
    $illustration = file_load($illustration_item[0]['fid']);
    $illustration_path = !empty($illustration->uri) ? image_style_url('nas_bird_teaser_illustration', $illustration->uri) : '';
  }

  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);

  $field_audio = field_view_field('node', $node, 'field_bird_audio', 'teaser');
  $bird_audio = !empty($field_audio[0]) ? render($field_audio) : '';

  $content = theme('nas_featured_bird', array(
    'name' => check_plain($node->title),
    'scientific_name' => $scientific_name,
    'url' => url('node/' . $node->nid),
    'image_path' => $hero_image_path,
    'image_path_mobile' => $hero_image_path_mobile,
    'attribution' => $attribution,
    'illustration_path' => $illustration_path,
    'contextual_links' => $contextual_links,
    'color_classes' => $color_classes,
    'bird_audio' => $bird_audio,
  ));

  $block->content = $content;
  return $block;
}
