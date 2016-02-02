<?php

/**
 * @file
 * Define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Our Leadership listing'),
  'description' => t('Our Leadership listing pane.'),
  'category' => 'NAS',
  'edit form' => 'our_leadership_list_form',
  'render callback' => 'our_leadership_list_render',
);

/**
 * An edit form for the pane's settings.
 */
function our_leadership_list_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['items'] = array(
    '#tree' => TRUE,
  );
  for ($i = 0; $i < 50; $i++) {
    $form['items'][$i] = array(
      '#type' => 'entityreference',
      '#title' => '',
      '#default_value' => !empty($conf['items'][$i]['entity_id']) ? $conf['items'][$i]['entity_id'] : '',
      '#era_entity_type' => 'node',
      '#era_bundles' => array('contact'),
    );
  }

  return $form;
}

/**
 * Submit handler for configuration.
 */
function our_leadership_list_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 */
function our_leadership_list_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();
  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);

  $items = array();
  foreach ($conf['items'] as $item) {
    if (!empty($item['entity_id']) && $node = _i18n_node_load($item['entity_id'])) {
      $build = node_view($node, 'teaser');
      $items[] = drupal_render($build);
    }
  }
  if (!$items) {
    $items = array('&nbsp;');
  }

  $block->content = theme('our_leadership_list', array(
      'title' => $conf['override_title_text'] ? $conf['override_title_text'] : t('Meet our leadership team.'),
      'items' => $items,
      'contextual_links' => $contextual_links,
    ));

  return $block;
}

