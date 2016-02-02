<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Magazine Bar'),
  'description' => t('Magazine Bar'),
  'category' => 'NAS',
  'render callback' => 'magazine_bar_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Render content.
 */
function magazine_bar_render($subtype, $conf, $args, $context) {
  $node = $context->data;

  if (empty($node)
    || $node->type !== 'article'
    || empty($node->field_magazine_issue[LANGUAGE_NONE][0]['target_id'])
    || empty($node->panelizer['page_manager']->name)
    || $node->panelizer['page_manager']->name !== 'node:article:big_image') {
    return;
  }

  $magazine_issue = _i18n_node_load($node->field_magazine_issue[LANGUAGE_NONE][0]['target_id']);

  if (!$magazine_issue) {
    return;
  }

  $data = nas_extract_magazine_date($magazine_issue->title);
  $data['link'] = url('node/' . $magazine_issue->nid);

  $block = new stdClass();
  $block->content = theme('magazine_bar', $data);

  return $block;
}

