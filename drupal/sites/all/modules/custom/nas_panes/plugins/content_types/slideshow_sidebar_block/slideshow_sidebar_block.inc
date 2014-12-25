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
    '#required' => TRUE,
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

  $contextual_links = '';
  if (user_access('edit NAS panes')) {
    $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);
  }

  $content = theme('slideshow_sidebar_block', array(
      'contextual_links' => $contextual_links,
      'block_title' => !empty($conf['override_title']) ? $conf['override_title_text'] : t('Slideshow'),
      'slideshow' => l($conf['slideshow']['entity_label'], 'node/' . $conf['slideshow']['entity_id']),
    ));

  $block->content = $content;

  return $block;
}
