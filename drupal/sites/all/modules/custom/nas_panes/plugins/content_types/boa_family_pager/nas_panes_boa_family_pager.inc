<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('BOA Family Pager'),
  'description' => t('Provides "BOA Family Pager" pane'),
  'category' => 'NAS',
  'render callback' => 'nas_panes_boa_family_pager_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function nas_panes_boa_family_pager_render($subtype, $conf, $args, $context) {
  $context_node = $context->data;
  if ($context_node->type !== 'boaf') {
    return;
  }

  $parameters = array(
    'only_active_trail' => FALSE,
    'min_depth' => 1,
    'min_depth' => 1,
  );
  $_links = menu_build_tree('boa', $parameters);
  $links = array();
  foreach ($_links as $link) {
    if ($link['link']['router_path'] === 'node/%') {
      if ($link['link']['link_path'] === $_GET['q']) {
        $current = count($links);
      }
      $links[] = $link['link'];
    }
  }
  $prev_key = $current - 1 < 0 ? count($links) - 1 : $current - 1;
  $next_key = $current + 1 < count($links) ? $current + 1 : 0;

  list(, $nid) = explode('/', $links[$prev_key]['link_path']);
  $prev_node = node_load($nid);
  $prev_title = check_plain($prev_node->title);
  $prev_link = l('', $links[$prev_key]['link_path'], array('attributes' => array('class' => 'previous')));
  list(, $nid) = explode('/', $links[$next_key]['link_path']);
  $next_node = node_load($nid);
  $next_title = check_plain($next_node->title);
  $next_link = l('', $links[$next_key]['link_path'], array('attributes' => array('class' => 'next')));

  $block = new stdClass();
  $block->content = '';
  $block->content = theme('boa_family_pager', array(
      'prev_title' => $prev_title,
      'prev_link' => $prev_link,
      'next_title' => $next_title,
      'next_link' => $next_link,
  ));

  return $block;
}
