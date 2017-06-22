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
    '#author' => _full_width_byline_author($node),
    '#node_url' => url(drupal_get_path_alias(), array('absolute' => TRUE, 'alias' => TRUE)),
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
      'author' => NULL,
      'node_url' => NULL,
    ),
    'template' => 'full-width-byline',
    'path' => $plugin['path'],
  );
}

/**
 * Helper function.
 *
 * Get information about author.
 */
function _full_width_byline_author($node) {
  $author = array(
    'name' => '',
    'link' => '',
    'image_path' => FALSE,
    'date' => '',
  );
  $published = '';
  $node_wrapper = entity_metadata_wrapper('node', $node);

  if (!empty($node->field_author['und'][0]['target_id'])) {
    $item_id[] = $node->field_author['und'][0]['target_id'];
    $entities = entity_load('node', $item_id);
    foreach ($entities as $id => $entity) {
      $image_field = field_get_items('node', $entity, 'field_image');
      if ($image_field) {
        if ($image_file = file_load($image_field[0]['fid'])) {
          $image_uri = nas_alters_local_image_uri($image_file->uri);
          $author['image_path'] = image_style_url('bio_image', $image_uri);
          ;
        }
      }
      $author['name'] = check_plain($entity->title);
      $author['link'] = url('node/' . $id);
    }
  }

  // Set published date from issue magazine title.
  $magazine_issue = $node_wrapper->field_magazine_issue->value();
  if (!empty($magazine_issue->title)) {
    $published = $magazine_issue->title;
  }

  // Set published date based on created date or field_article_date.
  if (empty($published)) {
    $created = $node->created;
    $article_date = $node_wrapper->field_article_date->value();
    if (!empty($article_date)) {
      $created = strtotime($node->field_article_date[LANGUAGE_NONE][0]['value']);
    }
    $published = date('F d, Y', $created);
  }

  $author['date'] = t('@date', array('@date' => $published));
  return $author;
}
