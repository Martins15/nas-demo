<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Magazine Issue. Articles listing top'),
  'description' => t('Provides articles of Magazine Issue'),
  'category' => 'NAS',
  'render callback' => 'magazine_issue_listing_top_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);


/**
 * Run-time rendering of the body of the block (content type).
 * See ctools_plugin_examples for more advanced info.
 */
function magazine_issue_listing_top_render($subtype, $conf, $args, $context) {
  $context_node = $context->data;
  if ($context_node->type !== 'magazine_issue') {
    return;
  }

  $articles_nodes = array();
  $magazine_issue_featured_nids = _nas_panes_magazin_featured_articles($context_node);
  $view_results = views_get_view_result('nas_news', 'mag_issue_article_nids', $context_node->nid, implode('+', $magazine_issue_featured_nids));

  if (!empty($view_results)) {
    $view_results = array_slice($view_results, 0, 5);
    foreach ($view_results as $value) {
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
