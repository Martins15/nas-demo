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
  $args = arg();
  if ($args[0] == 'node' && is_numeric($args['1'])) {
    $node = _i18n_node_load($args[1]);
    if ($node->type != 'bird') {
      $node = FALSE;
    }
  }

  if (!empty($node)) {
    $data = nas_panes_get_site_info($node);
  }
  else {
    $data = nas_panes_get_site_info(FALSE);
  }

  if (empty($data)) {
    return;
  }

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'asc_bird_top_bar',
    '#title' => $data['title'],
    '#url' => $data['url'],
    '#attached' => array(
      'js' => array(
        drupal_get_path('module', 'nas_panes') . '/plugins/content_types/asc_bird_top_bar/asc-bird-top-bar.js',
      ),
    ),
  );

  return $block;
}
