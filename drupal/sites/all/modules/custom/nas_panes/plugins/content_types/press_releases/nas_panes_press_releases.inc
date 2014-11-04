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

  $results = views_get_view_result('other_press_releases');

  $press_releases = array();
  foreach ($results as $result) {
    $press_releases[] = array(
      'title' => check_plain($result->node_title),
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
