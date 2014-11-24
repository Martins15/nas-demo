<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Magazine Issue. Articles listing bottom'),
  'description' => t('Provides articles of Magazine Issue'),
  'category' => 'NAS',
  'render callback' => 'magazine_issue_listing_bot_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);


/**
 * Run-time rendering of the body of the block (content type).
 * See ctools_plugin_examples for more advanced info.
 */
function magazine_issue_listing_bot_render($subtype, $conf, $args, $context) {
  $context_node = $context->data;
  if ($context_node->type !== 'magazine_issue') {
    return;
  }

  $articles_nodes = array();
  $magazine_issue_featured_nids = variable_get('magazine_issue_featured_nids_' . $context_node->nid);
  $mag_issue_article_nids = views_get_view_result('nas_news', 'mag_issue_article_nids', $context_node->nid);

  if (!empty($mag_issue_article_nids)) {
    if (!empty($magazine_issue_featured_nids)) {
      foreach ($mag_issue_article_nids as $key => $value) {
        if (in_array($value->nid, $magazine_issue_featured_nids)) {
          unset($mag_issue_article_nids[$key]);
        }
      }
    }
    $mag_issue_article_nids = array_values($mag_issue_article_nids);
    $mag_issue_article_nids = array_slice($mag_issue_article_nids, 5);
    foreach ($mag_issue_article_nids as $key => $value) {
      if (!empty($value->nid) && $node = node_load($value->nid)) {
        $articles_nodes[] = $node;
      }
    }
  }

  $teasers = '';
  foreach ($articles_nodes as $node) {
    $build = node_view($node, 'nas_node_teaser_wo_date');
    $teasers .= drupal_render($build);
  }

  $block = new stdClass();
  $block->content = $teasers;

  return $block;
}
