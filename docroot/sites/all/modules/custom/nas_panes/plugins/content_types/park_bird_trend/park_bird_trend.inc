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
    'birds_current_title' => t('Number of Current Species'),
    'birds_extirpation_title' => t('Potential Extirpations'),
    'birds_colonization_title' => t('Potential Colonizations'),
    'birds_park_trend_title' => t('Overall Park Trend'),
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

  $form['birds_current_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Current Species title'),
    '#default_value' => $conf['birds_current_title'],
    '#size' => 100,
  );

  $form['birds_extirpation_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Potential Extirpations title'),
    '#default_value' => $conf['birds_extirpation_title'],
    '#size' => 100,
  );

  $form['birds_colonization_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Potential Colonizations title'),
    '#default_value' => $conf['birds_colonization_title'],
    '#size' => 100,
  );

  $form['birds_park_trend_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Overall Park Trend title'),
    '#default_value' => $conf['birds_park_trend_title'],
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

  $seasons = array('s' => t('summer'), 'w' => t('winter'));
  $trends = array('current', 'extirpation', 'colonization', 'park_trend');
  $content = array();
  foreach ($seasons as $abbrev => $season) {
    foreach ($trends as $trend) {
//      $content[$season]['views'][$display]['rendered'] = ;
//      $content[$season]['views'][$display]['amount'] = $view->query->pager->total_items;
      if($trend == 'park_trend') {
        $content[$season][$trend]['title'] = $conf['birds_' . $trend . '_title'];
        $field_name = 'field_' . $trend . '_' . $abbrev;
        $output = _park_bird_trend_get_field_value($field_name, $node);
        $content[$season][$trend]['desc'] = render($output);
      }else{
        $content[$season]['tabs'][$trend]['title'] = $conf['birds_' . $trend . '_title'];
        $field_name = 'field_birds_' . $abbrev . '_' . $trend . '_desc';
        $output = _park_bird_trend_get_field_value($field_name, $node);
        $content[$season]['tabs'][$trend]['desc'] = render($output);
      }
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
 *
 */
function _park_bird_trend_get_field_value($field, $node, $index = 0) {
  $fields = field_get_items('node', $node, $field);
  $output = field_view_value('node', $node, $field, $fields[$index]);
  return $output;
}