<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Frontpage Bird In The News'),
  'description' => t('Provides Bird In The News block'),
  'category' => 'NAS',
  'render callback' => 'frontpage_in_the_news_render',
  'all contexts' => TRUE,
);

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function frontpage_in_the_news_render($subtype, $conf, $args, $contexts) {
  $teasers = array();
  $results = views_get_view_result('frontpage_birds_in_the_news');
  foreach ($results as $result) {
    $bird_node = _i18n_node_load($result->nid);
    $article_node = _i18n_node_load($result->field_related_bird_node_nid);
    list($blue_link_text, $blue_link_url) = nas_panes_get_blue_text_link($article_node);
    $build = node_view($bird_node, 'teaser');
    $teasers[] = array(
      'bird' => drupal_render($build),
      'blue_link_text' => $blue_link_text,
      'blue_link_url' => $blue_link_url,
      'article_url' => url('node/' . $article_node->nid),
      'article_title' => check_plain($article_node->title),
    );
  }

  $block = new stdClass();
  $block->content = t('There are no news articles with related birds.');

  $block_title = t('Birds in the News');
  if (!empty($teasers)) {
    $block->content = theme('frontpage_in_the_news', array(
      'teasers' => $teasers,
      'title' => $block_title,
      'bird_guide_title' => 'Explore Our Bird Guide',
      'bird_guide_link' => url('birds/bird-guide'),
    ));
  }

  return $block;
}
