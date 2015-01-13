<?php
/**
 * @file
 * nas_engagement_cards_feature.features.uuid_nodequeue_item.inc
 */

/**
 * Implements hook_uuid_features_default_nodequeue_items().
 */
function nas_engagement_cards_feature_uuid_features_default_nodequeue_items() {
  $nodequeue_items = array();

  $nodequeue_items[] = array(
    'queue_name' => 'engagement_cards',
    'node_uuid' => '18af636f-888f-48ba-b1a3-1ff450d9188d',
  );

  return $nodequeue_items;
}
