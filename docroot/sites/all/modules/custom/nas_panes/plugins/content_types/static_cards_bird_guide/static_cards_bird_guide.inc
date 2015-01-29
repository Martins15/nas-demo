<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Static cards. Bird Guide'),
  'description' => t('Static cards. Bird Guide'),
  'category' => 'Static Cards',
  'edit form' => 'static_cards_bird_guide_form',
  'render callback' => 'static_cards_bird_guide_render',
);

/**
 * An edit form for the pane's settings.
 */
function static_cards_bird_guide_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['items'] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
  );

  for ($i = 0; $i < 4; $i++) {
    $form['items'][$i] = array(
      '#type' => 'fieldset',
      '#title' => t('Bird @num', array('@num' => $i + 1)),
      '#tree' => TRUE,
    );

    $form['items'][$i]['bird'] = array(
      '#type' => 'entityreference',
      '#default_value' => !empty($conf['items'][$i]['bird']['entity_id']) ? $conf['items'][$i]['bird']['entity_id'] : '',
      '#era_entity_type' => 'node',
      '#era_bundles' => array('bird'),
    );
  }

  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'static_cards_three_columns', 'nas_panes', 'plugins/content_types/static_cards_three_columns');

  return $form;
}

/**
 * Submit handler for configuration.
 */
function static_cards_bird_guide_form_submit(&$form, &$form_state) {
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
function static_cards_bird_guide_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  $contextual_links = '';
  if (user_access('edit NAS panes')) {
    $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);
  }

  $links = theme('item_list', array(
    'items' => array(
      l(t('Explore Our Bird Guide'), 'birds/bird-guide'),
      l(t('Adopt a Bird'), 'https://secure.audubon.org/site/SPageNavigator/2014_Adoption_Catalog_Homepage.html', array('attributes' => array('class' => array('cta')))),
    ),
    'attributes' => array(
      'class' => array(
        'section-nav',
        'inline-list',
      ),
    ),
  ));

  $nids = array();
  $teasers = array();
  foreach ($conf['items'] as $item) {
    if (!empty($item['bird']['entity_id'])) {
      $nids[] = $item['bird']['entity_id'];
    }
  }

  if (empty($nids)) {
    $view_results = views_get_view_result('nas_birds_view', 'audubon_bird_guide_random');
    foreach ($view_results as $item) {
      $nids[] = $item->nid;
    }
  }

  $nodes = node_load_multiple($nids);
  foreach ($nodes as $node) {
    $teasers[] = node_view($node, 'teaser');
  }

  $content = theme('static_cards_bird_guide', array(
      'title' => !empty($conf['override_title']) ? $conf['override_title_text'] : '',
      'items' => $teasers,
      'links' => $links,
      'contextual_links' => $contextual_links,
    ));

  $block->content = $content;

  return $block;
}
