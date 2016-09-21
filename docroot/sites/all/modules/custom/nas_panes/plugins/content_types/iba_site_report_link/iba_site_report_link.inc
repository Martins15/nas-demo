<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('IBA Site Report Link'),
  'description' => t('Provides IBA Site Report Link pane'),
  'category' => 'NAS',
  'render callback' => 'iba_site_report_link_render',
  'hook theme' => 'iba_site_report_link_theme',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Run-time rendering of the body of the block (content type).
 * See ctools_plugin_examples for more advanced info.
 */
function iba_site_report_link_render($subtype, $conf, $args, $context) {
  $node = $context->data;
  if ($node->type !== 'iba') {
    return;
  }

  if (!$iba_id_items = field_get_items('node', $node, 'field_iba_id')) {
    return FALSE;
  }
  $iba_id = $iba_id_items[0]['value'];

  $url = 'http://netapp.audubon.org/iba/Reports/' . $iba_id;

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'iba_site_report_link',
    '#link' => l(t('Download Site Report'), $url),
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function iba_site_report_link_theme(&$theme, $plugin) {
  $theme['iba_site_report_link'] = array(
    'variables' => array(
      'link' => '',
    ),
    'template' => 'iba-site-report-link',
    'path' => $plugin['path'],
  );
}
