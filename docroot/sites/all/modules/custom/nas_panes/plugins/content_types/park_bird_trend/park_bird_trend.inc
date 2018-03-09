<?php

/**
 * @file
 * Park select bar plugin.
 */

$plugin = array(
  'title' => t('Park bird trend'),
  'description' => t('Bird trend widget.'),
  'category' => 'Climate',
  'edit form' => 'park_bird_trend_edit_form',
  'render callback' => 'park_bird_trend_render',
  'hook theme' => 'park_bird_trend_theme',
  'no title override' => TRUE,
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'defaults' => array(
    'birds_species_title' => t('Number of Current Species'),
    'birds_extirpations_title' => t('Potential Extirpations'),
    'birds_colonizations_title' => t('Potential Colonizations'),
  ),
);

/**
 * Configuration form.
 */
function park_bird_trend_edit_form($form, &$form_state) {
  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'park_bird_trend', 'nas_panes', 'plugins/content_types/park_bird_trend');

  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  $form['birds_species_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Current Species title'),
    '#default_value' => $conf['birds_species_title'],
    '#size' => 100,
  );

  $form['birds_extirpations_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Potential Extirpations title'),
    '#default_value' => $conf['birds_extirpations_title'],
    '#size' => 100,
  );

  $form['birds_colonizations_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Potential Colonizations title'),
    '#default_value' => $conf['birds_colonizations_title'],
    '#size' => 100,
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function park_bird_trend_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (array_key_exists($key, $form_state['values'])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Render callback.
 */
function park_bird_trend_render($subtype, $conf, $args, $contexts) {

  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  if ($plugin = ctools_get_plugins('ctools', 'content_types', $subtype)) {
    $conf = array_merge($plugin['defaults'], $conf);
  }
  $node = $contexts->data;
  $fields = $conf;
  $parktrend = 'birds_parktrend_title';
  unset($fields['context']);
  unset($fields[$parktrend]);
  $fields = array_keys($fields);
  $content = array();
  $seasons = array('s' => t('summer'), 'w' => t('winter'));
  foreach ($seasons as $abbrev => $season) {
    foreach ($fields as $field) {
      $parts = explode('_', $field);
      $content[$season]['tabs'][$parts[1]]['title'] = $conf[$field];
      $field_name = 'field_birds_' . $abbrev . '_' . $parts[1] . '_desc';
      $output = _park_bird_trend_get_field_value($field_name, $node);
      $content[$season]['tabs'][$parts[1]]['desc'] = render($output);

      $efq = new EntityFieldQuery();
      $efq
        ->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'parks_to_birds_relation')
        ->propertyCondition('status', NODE_PUBLISHED)
        ->fieldCondition('field_park_reference', 'target_id', $node->nid, '=')
        ->fieldCondition('field_park_season', 'value', $season, '=')
        ->fieldCondition('field_park_trend', 'value', $parts[1], '=');
      $result = $efq->execute();
      $result = reset($result);
      $result = ($result == FALSE) ? 0 : count($result);
      $content[$season]['tabs'][$parts[1]]['amount'] = $result;
    }
  }
  $display = 'default';
  $view = views_get_view('park_bird_trends');
  $view->set_display($display);
  $view->pre_execute();
  $view->execute();

  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);
  $block = new stdClass();
  $block->content = array(
    '#theme' => 'park_bird_trend',
    '#context_links' => $contextual_links,
    '#content' => $content,
    '#view' => $view->render($display),
  );
  drupal_add_js(drupal_get_path('theme', 'nas') . '/js/vendor/owl-carousel/owl.carousel.min.js');
  drupal_add_css(drupal_get_path('theme', 'nas') . '/js/vendor/owl-carousel/owl.carousel.css');
  drupal_add_css(drupal_get_path('theme', 'nas') . '/js/vendor/owl-carousel/owl.theme.css');
  drupal_add_js(drupal_get_path('module', 'nas_panes') . '/plugins/content_types/park_bird_trend/js/park_bird_trend.js');
  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function park_bird_trend_theme(&$theme, $plugin) {
  $theme['park_bird_trend'] = array(
    'variables' => array(
      'content' => '',
      'view' => '',
      'context_links' => '',
    ),
    'template' => 'park-bird-trend',
    'path' => $plugin['path'],
  );
}

/**
 * Helper function to get field value.
 */
function _park_bird_trend_get_field_value($field, $node, $index = 0) {
  // Description fields with global values in variables.
  $global_field_birds = [
    'field_birds_s_species_desc',
    'field_birds_s_extirpations_desc',
    'field_birds_s_colonizations_desc',
    'field_birds_w_species_desc',
    'field_birds_w_extirpations_desc',
    'field_birds_w_colonizations_desc',
  ];

  $fields = field_get_items('node', $node, $field);
  $output = field_view_value('node', $node, $field, $fields[$index]);
  // Put to the Output a global value if description field is empty and global value filled.
  if (!$fields && in_array($field, $global_field_birds) && variable_get($field . '_global') != '') {
    $output = [
      '#markup' => check_markup(variable_get($field . '_global'), 'full_html'),
      '#access' => 'true',
    ];
  }
  return $output;
}
