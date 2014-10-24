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
);

/**
 * An edit form for the pane's settings.
 */
function nas_panes_pane_featured_bird_custom_pane_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['bird'] = array(
    '#type' => 'entityreference',
    '#title' => 'Featured Bird',
    '#default_value' => !empty($conf['bird']['entity_id']) ? $conf['bird']['entity_id'] : '',
    '#era_entity_type' => 'node',
    '#era_bundles' => array('bird'),
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
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function nas_panes_pane_featured_bird_custom_pane_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  if (!isset($conf['bird']['entity_id']) || empty($conf['bird']['entity_id'])) {
    $block->content = '';
    if (user_access('administer site configuration')) {
      $block->content = t('No featured bird selected');
    }
    return $block;
  }

  $node = node_load($conf['bird']['entity_id']);

  $color_mode_item = field_get_items('node', $node, 'field_color_mode');
  $color_mode = isset($color_mode_item[0]['value']) ? $color_mode_item[0]['value'] : 'dark';

  $scientific_name_item = field_get_items('node', $node, 'field_bird_sci_name');
  $scientific_name = isset($scientific_name_item[0]['safe_value']) ? $scientific_name_item[0]['safe_value'] : '';

  $hero_image_item = field_get_items('node', $node, 'field_hero_image');
  $hero_image = file_load($hero_image_item[0]['fid']);
  $hero_image_path = image_style_url(NAS_FEATURED_BIRD_IMAGE_STYLE, $hero_image->uri);
  $hero_image_path_mobile = image_style_url(NAS_FEATURED_BIRD_IMAGE_STYLE_MOBILE, $hero_image->uri);

  $image_caption_item = field_get_items('file', $hero_image, 'field_file_caption');
  $image_caption = isset($image_caption_item[0]['safe_value']) ? $image_caption_item[0]['safe_value'] : '';
  $image_credit_item = field_get_items('file', $hero_image, 'field_file_credit');
  $image_credit = isset($image_credit_item[0]['safe_value']) ? $image_credit_item[0]['safe_value'] : '';
  $image_string = trim(implode(' ', array($image_caption, $image_credit)));
  if (empty($image_string)) {
    $image_string = t('Please edit Caption and Credits of hero image of the selected bird.');
  }

  $illustration_item = field_get_items('node', $node, 'field_bird_illustration');
  $illustration = file_load($illustration_item[0]['fid']);
  $illustration_path = image_style_url(NAS_FEATURED_ILLUSTRATION_IMAGE_STYLE, $illustration->uri);

  $contextual_links = '';
  if (user_access('administer site configuration')) {
    ctools_include('modal');
    ctools_modal_add_js();
    // Add ajax-responder so ctools_ajax_command_reload() will work.
    ctools_add_js('ajax-responder');
    // We expect Featured Bird pane to be only on Bird Guide. If this is not
    // the case we will need to change this select query.
    $pid = db_query('SELECT pid FROM {panels_pane} WHERE type = :type', array(':type' => 'nas_panes_pane_featured_bird'))->fetchField();
    if (empty($pid)) {
      nas_panes_save_bird_guide_pane();
      $pid = db_query('SELECT pid FROM {panels_pane} WHERE type = :type', array(':type' => 'nas_panes_pane_featured_bird'))->fetchField();
    }
    $links = array(
      'edit' => array(
        'title' => t('Edit'),
        'href' => 'panels/ajax/editor/edit-pane/panel_context:page-bird_guide::page_bird_guide_panel_context::::/' . $pid,
        'query' => array('reload' => 'true'),
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

  $content = theme('nas_featured_bird', array(
    'name' => check_plain($node->title),
    'scientific_name' => $scientific_name,
    'url' => url('node/' . $node->nid),
    'image_path' => $hero_image_path,
    'image_path_mobile' => $hero_image_path_mobile,
    'image_string' => $image_string,
    'illustration_path' => $illustration_path,
    'contextual_links' => $contextual_links,
    'color' => $color_mode,
  ));

  $block->content = $content;
  return $block;
}
