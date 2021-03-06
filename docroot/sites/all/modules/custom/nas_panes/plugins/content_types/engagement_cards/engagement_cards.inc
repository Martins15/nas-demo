<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'title' => t('Engagement cards. Bottom.'),
  'description' => t('Provides Engagement cards pane for bottom of the page'),
  'category' => 'NAS',
  'no title override' => TRUE,
  'edit form' => 'engagement_cards_edit_form',
  'render callback' => 'engagement_cards_render',
  'render last' => TRUE,
);

/**
 * An edit form for the pane's settings.
 */
function engagement_cards_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['#tree'] = TRUE;

  $conf_key = 'default';
  if (isset($form_state['display']->context['panelizer'])) {
    $conf_key = $form_state['display']->context['panelizer']->empty ? $conf_key : $form_state['display']->context['panelizer']->argument;
  }
  $form[$conf_key] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
  );
  $form[$conf_key]['global_configuration'] = array(
    '#type' => 'checkbox',
    '#title' => t('Global configuration'),
    '#description' => t('Check it to set the title globally for all panes of this type.'),
  );

  $form[$conf_key]['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#size' => 50,
    '#default_value' => isset($conf[$conf_key]['title']) ? $conf[$conf_key]['title'] : nas_panes_engagement_cards_default_title(),
    '#description' => t('Only English title should be set here; to translate it go to <a href="!link" target="_blank">Translate interface</a>.', array('!link' => url('admin/config/regional/translate/translate'))),
  );
  // Limit to 3 number of engegement cards.
  for ($i = 1; $i <= 3; $i++) {
    $form[$conf_key]['references'][$i]['entity_reference'] = array(
      '#type' => 'entityreference',
      '#default_value' => !empty($conf[$conf_key]['references'][$i]['entity_reference']['entity_id']) ? $conf[$conf_key]['references'][$i]['entity_reference']['entity_id'] : '',
      '#title' => t('Engagement card'),
      '#era_entity_type' => 'node',
      '#era_bundles' => array('engagement_cards'),
    );
  }
  $form[$conf_key]['wrapper'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add wrapper'),
    '#description' => t('This option adds some HTML-markup (.card-set wrapper), so the pane can be injected to non-"engagement cards" regions.'),
    '#default_value' => isset($conf[$conf_key]['wrapper']) ? $conf[$conf_key]['wrapper'] : 0,
  );

  return $form;
}

/**
 * Submit callback.
 */
function engagement_cards_edit_form_submit(&$form, &$form_state) {
  $global_config = FALSE;
  $title = '';

  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
      if (is_array($form_state['conf'][$key]) && isset($form_state['conf'][$key]['global_configuration'])) {
        // Do not store global config flag in configuration.
        $global_config = $form_state['conf'][$key]['global_configuration'];
        $title = $form_state['conf'][$key]['title'];
        unset($form_state['conf'][$key]['global_configuration']);
      }
    }
  }

  // Update all engagement cards with global configuration.
  if ($global_config) {
    variable_set('nas_panes_engagement_cards_default_title', $title);

    // Update all overridden pane configs.
    $panel_type = 'engagement_cards';
    $configs = db_select('panels_pane', 'pp')
      ->fields('pp', array('pid', 'configuration'))
      ->condition('pp.type', $panel_type)
      ->execute()
      ->fetchAll();

    foreach ($configs as $config_data) {
      $config = unserialize($config_data->configuration);
      foreach ($config as &$config_part) {
        if (is_array($config_part) && isset($config_part['title'])) {
          $config_part['title'] = $title;
        }
      }
      db_update('panels_pane')
        ->fields(array('configuration' => serialize($config)))
        ->condition('type', $panel_type)
        ->condition('pid', $config_data->pid)
        ->execute();
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 *
 * See ctools_plugin_examples for more advanced info.
 */
function engagement_cards_render($subtype, $conf, $args, $context) {
  // We can't add node context to the pane, because it's use on landing pages too.
  $conf_key = 'default';
  if ($context_node = menu_get_object('node')) {
    $conf_key = isset($conf[$context_node->nid]) ? $context_node->nid : $conf_key;
  }
  if (isset($conf[$conf_key])) {
    $data = $conf[$conf_key];
  }

  $nodes = array();
  engagement_cards_manual($data, $nodes);

  // If don't have manual carts call main function
  // and get what we have to render.
  if (empty($nodes)) {
    $nodes = nas_panes_engagement_cards_get_cards($subtype, $data, 3);
  }

  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $context);
  if (arg(0) == 'frontpage') {
    $contextual_links = nas_panes_build_page_contextual_links($subtype, NAS_PANES_FRONTPAGE_PAGE_MANAGER_CACHE_KEY, 'page_frontpage2_panel_context');
  }

  // Finally render selected nodes.
  $teasers = array();
  foreach ($nodes as $node) {
    $node_build = node_view($node);
    $teasers[] = drupal_render($node_build);
  }

  $block = new stdClass();
  $block->content = '';
  if (!empty($teasers) || !empty($contextual_links)) {
    $block->content = theme('engagement_cards', array(
      'title' => isset($data['title']) ? t($data['title']) : nas_panes_engagement_cards_default_title(),
      'teasers' => $teasers,
      'prefix' => !empty($data['wrapper']) ? '<div class="card-set">' : '',
      'suffix' => !empty($data['wrapper']) ? '</div>' : '',
      'contextual_links' => $contextual_links,
    ));
  }

  return $block;
}

/**
 * Get manual engagement cards.
 */
function engagement_cards_manual($data, &$nodes) {
  if (!isset($data['references'])) {
    return;
  }
  foreach ($data['references'] as $value) {
    if (!empty($value['entity_reference']['entity_id']) && $node = node_load($value['entity_reference']['entity_id'])) {
      if ($node->status == NODE_PUBLISHED) {
        $nodes[] = $node;
      }
    }
  }
}
