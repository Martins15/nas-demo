<?php

/**
 * @file
 * Define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Frontpage. Flyway section.'),
  'description' => t('Provides Frontpage Flyway blocks'),
  'category' => 'NAS',
  'render callback' => 'frontpage_flyway_pane_render',
  'all contexts' => TRUE,
);

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function frontpage_flyway_pane_render($subtype, $conf, $args, $contexts) {
  $block_title = '';

  $block = new stdClass();
  $block->content = '';

  drupal_add_js('//js.maxmind.com/js/apis/geoip2/v2.1/geoip2.js', 'external');
  drupal_add_js(drupal_get_path('module', 'nas_panes') . '/plugins/content_types/frontpage_flyway/frontpage_flyway.js');

  //We use 2 functions from this plugin.
  module_load_include('inc', 'fieldable_panels_panes', 'plugins/content_types/fieldable_panels_pane');

  //Select all nas_flyway_section FPPs.
  $query = db_select('fieldable_panels_panes', 'fpp');
  $query->fields('fpp', array('bundle', 'uuid'));
  $query->condition('fpp.bundle', 'nas_flyway_section', '=');
  $result = $query->execute()->fetchAll();

  $i = 1;
  foreach ($result as $value) {
    $subtype_name = 'uuid:' . $value->uuid;
    $fpp = fieldable_panels_panes_load_entity($subtype_name);
    $get_field_flyway = field_get_items('fieldable_panels_pane', $fpp, 'field_flyway');
    if (!isset($get_field_flyway[0])) {
      continue;
    }
    $entity = entity_load('node', array($get_field_flyway[0]['target_id']));
    $entity = reset($entity);
    $get_field_flyway_states = field_get_items('node', $entity, 'field_flyway_states');
    $iso_codes = array();
    if (!empty($get_field_flyway_states)) {
      foreach ($get_field_flyway_states as $tid) {
        $term = taxonomy_term_load($tid['tid']);
        $get_field_iso_code = field_get_items('taxonomy_term', $term, 'field_iso_code');
        if (isset($get_field_iso_code[0])) {
          $iso_codes[] = $get_field_iso_code[0]['value'];
        }
      }
      drupal_add_js(array('frontpage_flyway' => array('flyway-section-' . $i => $iso_codes)), 'setting');
    }
    $fpp_view = fieldable_panels_panes_view($fpp, 'full');
    $block->content .= '<div class="flyway-section flyway-section-' . $i . '">' . drupal_render($fpp_view) . '</div>';
    $i++;
  }
  return $block;
}
