<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('BOA index main'),
  'description' => t('Provides BOA Index pane with list of BOA'),
  'category' => 'NAS',
  'edit form' => 'boa_index_main_form',
  'render callback' => 'boa_index_main_render',
  'defaults' => array(
    'title' => 'Explore by family',
    'links' => '<ul class="section-nav inline-list">
        <li><a href="?sort_by=field_boa_plate_value" id="by-family" class="cta">View the plates in chronological order</a></li>
        <li><a href="?sort_by=title" id="by-alphabetical" class="cta">Alphabetically</a></li>
        <li><a href="?sort_by=name" id="by-state" class="cta">State Birds</a></li>
      </ul>',
  ),
);

/**
 * An edit form for the pane's settings.
 */
function boa_index_main_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => $conf['title'],
  );

  $form['links'] = array(
    '#type' => 'textarea',
    '#title' => t('Links'),
    '#default_value' => $conf['links'],
    '#description' => t('Sort links content'),
  );

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function boa_index_main_form_submit(&$form, &$form_state) {
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
function boa_index_main_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  $contextual_links = nas_panes_build_page_contextual_links('nas_panes_boa_index_main', NAS_PANES_BOA_INDEX_PAGE_MANAGER_CACHE_KEY, 'page_boa_index_panel_context');

  $block->content = theme('boa_index_main', array(
    'title' => check_plain($conf['title']),
    'links' => filter_xss($conf['links']),
    'content' => views_embed_view('boa_index', 'panel_pane_1'),
    'contextual_links' => $contextual_links,
  ));
  return $block;
}
