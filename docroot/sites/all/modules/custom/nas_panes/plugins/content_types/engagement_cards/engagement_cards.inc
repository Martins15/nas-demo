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

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
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
    $configs = db_query('SELECT pid, configuration FROM {panels_pane} WHERE type = :type', array(':type' => $panel_type))->fetchAll();
    foreach ($configs as $config_data) {
      $config = unserialize($config_data->configuration);
      foreach ($config as &$config_part) {
        if (is_array($config_part) && isset($config_part['title'])) {
          $config_part['title'] = $title;
        }
      }
      db_query('UPDATE {panels_pane} SET configuration = :configuration WHERE type = :type AND pid = :pid', array(
        ':configuration' => serialize($config),
        ':type' => $panel_type,
        ':pid' => $config_data->pid,
      ));
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
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
  // Call main function and get what we have to render.
  $cards_array = nas_panes_engagement_cards_get_cards($subtype, $data);
  $nodes = $cards_array['nodes'];

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
      'contextual_links' => $contextual_links,
    ));
  }

  return $block;
}
