<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Slideshow sidebar block'),
  'description' => t('Slideshow sidebar block'),
  'category' => 'Static Cards',
  'edit form' => 'slideshow_sidebar_block_form',
  'render callback' => 'slideshow_sidebar_block_render',
);

/**
 * An edit form for the pane's settings.
 */
function slideshow_sidebar_block_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['slideshow'] = array(
    '#type' => 'entityreference',
    '#title' => t('Slideshow'),
    '#default_value' => !empty($conf['slideshow']['entity_id']) ? $conf['slideshow']['entity_id'] : '',
    '#era_entity_type' => 'node',
    '#era_bundles' => array('slideshow'),
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function slideshow_sidebar_block_form_submit(&$form, &$form_state) {
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
function slideshow_sidebar_block_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  // Get latest slideshow if pane config is empty.
  if (empty($conf['slideshow']['entity_id'])) {
    $nid = db_select('node', 'n')
      ->fields('n', array('nid'))
      ->condition('n.type', 'slideshow')
      ->condition('n.status', NODE_PUBLISHED)
      ->orderBy('n.created', 'DESC')
      ->execute()
      ->fetchField();
  }
  else {
    $nid = $conf['slideshow']['entity_id'];
  }
  $node = node_load($nid);

  $contextual_links = '';
  if (user_access('edit NAS panes')) {
    $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);
  }

  $image_markup = '';
  if (!empty($node->field_images[LANGUAGE_NONE][0]['uri'])) {
    $image = theme('image', array('path' => image_style_url('slideshow_sidebar', $node->field_images[LANGUAGE_NONE][0]['uri'])));
    $image_markup = l($image, 'node/' . $node->nid, array('html' => TRUE));
  }

  $content = theme('slideshow_sidebar_block', array(
      'contextual_links' => $contextual_links,
      'block_title' => !empty($conf['override_title']) ? $conf['override_title_text'] : t('Slideshow'),
      'image' => $image_markup,
      'slideshow' => l($node->title, 'node/' . $node->nid),
    ));

  $block->content = $content;

  return $block;
}