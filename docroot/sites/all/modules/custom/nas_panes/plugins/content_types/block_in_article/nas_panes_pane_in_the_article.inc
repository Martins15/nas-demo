<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Social button In The Articles'),
  'description' => t('Provides Block with Social Button in Articles'),
  'category' => 'NAS',
  'render callback' => 'nas_panes_pane_in_the_article_render',
  'all contexts' => TRUE,
);

/**
 * Run-time rendering of the body of the block (content type).
 */
function nas_panes_pane_in_the_article_render($subtype, $conf, $args, $contexts) {
  $title = $contexts['panelizer']->data->title;
  $page_link = url(drupal_get_path_alias(), array('absolute' => TRUE, 'alias' => TRUE));

  $block = new stdClass();
  $content = theme('nas_featured_social_in_article', array(
    'title' => check_plain($title),
    'page_link' => $page_link,
    'twitter_url' => url('http://twitter.com/share', array(
      'query' => array(
        'text' => $title,
        'via' => 'audubonsociety',
        'url' => $page_link,
      ),
    )),
  ));
  $block->content = $content;

  return $block;
}
