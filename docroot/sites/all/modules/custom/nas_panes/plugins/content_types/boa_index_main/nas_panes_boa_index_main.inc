<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('BOA index main'),
  'description' => t('Provides BOA Index pane with list of BOA'),
  'category' => t('NAS'),
  'render callback' => 'boa_index_main_render',
);

/**
 * Run-time rendering of the body of the block (content type).
 *
 * See ctools_plugin_examples for more advanced info.
 */
function boa_index_main_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  $links = array(
    /*'by-family' => array(
      'title' => t('Explore by family'),
      'query' => array(),
    ),*/
    'by-chronological' => array(
      'head_title' => t('View the plates in chronological order'),
      'title' => t('View the plates in chronological order'),
      'query' => array('sort_by' => 'field_boa_plate_value'),
    ),
    'by-alphabetical' => array(
      'head_title' => t('Alphabetical'),
      'title' => t('Alphabetical'),
      'query' => array('sort_by' => 'title'),
    ),
    'by-state' => array(
      'head_title' => t('Birds'),
      'title' => t('State Birds'),
      'query' => array('sort_by' => 'state'),
    ),
  );

  $current_link = 'by-alphabetical';
  if (!empty($_GET['sort_by'])) {
    if ($_GET['sort_by'] == 'name') {
      $content = views_embed_view('boa_index', 'boa_index');
    }
    if ($_GET['sort_by'] == 'state') {
      $content = views_embed_view('boa_index', 'boa_index_state');
    }
    else {
      $content = views_embed_view('boa_index', 'boa_index');
    }
    switch ($_GET['sort_by']) {
      case 'field_boa_plate_value':
        $current_link = 'by-chronological';
        break;

      case 'title':
        $current_link = 'by-alphabetical';
        break;

      case 'state':
        $current_link = 'by-state';
        break;
    }
  }
  else {
    $_GET['sort_by'] = 'title';
    $content = views_embed_view('boa_index', 'boa_index');
  }

  $links_to_display = array();
  foreach ($links as $id => $link) {
    if ($id == $current_link) {
      $title = ($id == 'by-chronological') ? $title = $link['head_title'] : t('Explore by @head_title', array('@head_title' => $link['head_title']));
    }
    else {
      $links_to_display[] = l($link['title'], 'birds-of-america', array(
        'query' => $link['query'],
        'fragment' => 'boa-index-plates',
        'attributes' => array(
          'id' => $id,
          'class' => array('cta'),
        ),
      ));
    }
  }

  $block->content = theme('boa_index_main', array(
    'title' => $title,
    'links' => $links_to_display,
    'content' => $content,
  ));
  return $block;
}
