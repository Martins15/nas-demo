<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Full-width Byline'),
  'description' => t('Full-width Byline for article'),
  'category' => 'Full width',
  'render callback' => 'full_width_byline_render',
  'hook theme' => 'full_width_byline_theme',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'tags' => array('top'),
);

/**
 * Run-time rendering of the body of the block (content type).
 *
 * See ctools_plugin_examples for more advanced info.
 */
function full_width_byline_render($subtype, $conf, $args, $context) {
  $node = $context->data;

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'full_width_byline',
    '#node' => $node,
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function full_width_byline_theme(&$theme, $plugin) {
  $theme['full_width_byline'] = array(
    'variables' => array(
      'node' => NULL,
      'author_name' => NULL,
      'author_link' => NULL,
      'author_image' => NULL,
      'node_url' => NULL,
    ),
    'template' => 'full-width-byline',
    'path' => $plugin['path'],
  );
}

/**
 * Preprocess function for full_width_byline.
 */
function nas_panes_preprocess_full_width_byline(&$variables) {
  $node = $variables['node'];

  $node_wrapper = entity_metadata_wrapper('node', $node);
  $author_node = $node_wrapper->field_author->value();

  $variables['author_image'] = '';
  if (!empty($author_node->field_image[LANGUAGE_NONE][0]['uri'])) {
    $author_image_uri = $author_node->field_image[LANGUAGE_NONE][0]['uri'];
    $author_image_uri = nas_alters_local_image_uri($author_image_uri);
    $variables['author_image'] = image_style_url('bio_image', $author_image_uri);
  }
  $variables['author_name'] = check_plain($author_node->title);
  $variables['author_link'] = url('node/' . $author_node->nid);

  // Set published date from issue magazine title.
  $variables['published'] = '';
  $magazine_issue = $node_wrapper->field_magazine_issue->value();
  if (!empty($magazine_issue->title)) {
    $variables['published'] = check_plain($magazine_issue->title);
  }

  // Set published date based on created date or field_article_date.
  if (empty($variables['published'])) {
    $created = $node->created;
    $article_date = $node_wrapper->field_article_date->value();
    if (!empty($article_date)) {
      $created = $article_date;
    }
    $variables['published'] = format_date($created, 'custom', 'F d, Y');
  }

  if (!$variables['node_url']) {
    $variables['node_url'] = url('node/' . $node->nid, array('absolute' => TRUE, 'alias' => TRUE));
  }
}
