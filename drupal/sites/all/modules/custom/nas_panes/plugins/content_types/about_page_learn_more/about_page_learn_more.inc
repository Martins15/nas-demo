<?php

/**
 * @file
 * Define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('About Page. Learn More'),
  'description' => t('About Page Learn More.'),
  'category' => 'NAS',
  'edit form' => 'about_page_learn_more_form',
  'render callback' => 'about_page_learn_more_render',
);

/**
 * An edit form for the pane's settings.
 */
function about_page_learn_more_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['references'] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
  );

  // Limit to 3 numbers of Articles/Static pages.
  for ($i = 1; $i <= 3; $i++) {
    $form['references'][$i]['entity_reference'] = array(
      '#type' => 'entityreference',
      '#title' => '',
      '#default_value' => !empty($conf['references'][$i]['entity_reference']['entity_id']) ? $conf['references'][$i]['entity_reference']['entity_id'] : '',
      '#era_entity_type' => 'node',
      '#era_bundles' => array('article', 'static_page'),
    );
  }

  return $form;
}

/**
 * Submit handler for configuration.
 */
function about_page_learn_more_form_submit(&$form, &$form_state) {
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
function about_page_learn_more_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();
  $contextual_links = '';
  $items = array();

  if (user_access('edit NAS panes')) {
    $contextual_links = nas_panes_build_page_contextual_links('about_page_learn_more', NAS_PANES_ABOUT_PAGE_MANAGER_CACHE_KEY, 'page_about_panel_context');
  }

  // References from panel settings.
  $references = array();
  foreach ($conf['references'] as $reference) {
    if (empty($reference['entity_reference']['entity_id'])) {
      continue;
    }
    $references[] = $reference['entity_reference']['entity_id'];
  }

  // Default behaviour.
  if (empty($references)) {
    $view_results = views_get_view_result('about_page_learn_more', 'default');
    foreach ($view_results as $node) {
      $references[] = $node->nid;
    }
  }

  foreach ($references as $entity_id) {
    $node = node_load($entity_id);
    $items[] = node_view($node, 'about_page_related_teaser');
  }

  // Don't display when no items.
  if (empty($items)) {
    return;
  }

  $block->content = theme('about_page_learn_more', array(
      'title' => !empty($conf['override_title_text']) ? $conf['override_title_text'] : t('Learn more about our history and our work.'),
      'items' => $items,
      'contextual_links' => $contextual_links,
    ));

  return $block;
}
