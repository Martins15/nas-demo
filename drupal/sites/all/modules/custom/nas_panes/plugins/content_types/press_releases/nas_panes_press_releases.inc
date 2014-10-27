<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Press Releases'),
  'description' => t('Provides Block with other Press Releases'),
  'category' => 'NAS',
  'render callback' => 'nas_panes_press_releases_render',
  'all contexts' => TRUE,
);

/**
 * Run-time rendering of the body of the block (content type).
 */
function nas_panes_press_releases_render($subtype, $conf, $args, $contexts) {

  if (!empty($contexts)) {
    $node = reset($contexts)->data;
    if ($node->type !== 'article') {
      return;
    }
  }

  $query = db_select('node', 'n');
  $query->fields('n', array('nid', 'title'));
  $query->join('panelizer_entity', 'pe', 'pe.entity_id = n.nid AND pe.entity_type = :type', array(':type' => 'node'));
  $query->condition('pe.name', 'node:article:press_release');
  $query->orderBy('n.created', 'DESC');
  $query->range(0, 5);
  $results = $query->execute();

  $press_releases = array();
  foreach ($results as $result) {
    $press_releases[] = array(
      'title' => check_plain($result->title),
      'url' => url('node/' . $result->nid),
    );
  }

  $block = new stdClass();
  $block->content = theme('nas_panes_press_releases', array(
    'title' => t('Other Releases'),
    'releases' => $press_releases,
  ));

  return $block;
}
