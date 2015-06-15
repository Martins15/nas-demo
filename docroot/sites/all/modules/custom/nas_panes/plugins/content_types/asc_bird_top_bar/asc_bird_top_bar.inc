<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('S&C Field Guide Top bar'),
  'description' => t('Provides bar for field guide Bird page with returning URL to S&C.'),
  'category' => 'NAS',
  'render callback' => 'asc_bird_top_bar_render',
);

/**
 * Render content.
 */
function asc_bird_top_bar_render($subtype, $conf, $args, $context) {
  $params = drupal_get_query_parameters();

  if (!isset($params['site'])) {
    return;
  }

  // Get State or Center by provided site code.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'location')
    ->fieldCondition('field_location_link', 'url', $params['site'] . '.', 'CONTAINS')
    ->propertyCondition('status', NODE_PUBLISHED);
  $result = $query->execute();

  if (isset($result['node']) && count($result['node']) == 1) {
    $node = node_load(reset($result['node'])->nid);
    $url = 'http://' . $params['site'] . '.audubon.org';

    $data = array(
      'title' => $node->title,
      'url' => $url,
    );

    $block = new stdClass();
    $block->content = theme('asc_bird_top_bar', $data);

    return $block;
  }
}
