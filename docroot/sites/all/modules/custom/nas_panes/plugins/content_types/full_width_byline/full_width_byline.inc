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
  'edit form' => 'full_width_byline_form',
  'hook theme' => 'full_width_byline_theme',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'defaults' => array(
    'override' => 0,
  ),
);

function full_width_byline_form($form, &$form_state) {
//  ctools_form_include($form_state, 'content');
//  ctools_form_include($form_state, 'video-package-video-section', 'nas_panes', 'plugins/content_types/video_package_video_section');

  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  $form['override'] = array(
    '#type' => 'entityreference',
    '#title' => t('Author'),
    '#description' => t('Keep this field empty in order to use Article Author'),
    '#default_value' => $conf['override'],
    '#era_entity_type' => 'node',
    '#era_bundles' => array('contact'),
  );

  return $form;
}

/**
 * Submit callback.
 */
function full_width_byline_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (array_key_exists($key, $form_state['values'])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 *
 * See ctools_plugin_examples for more advanced info.
 */
function full_width_byline_render($subtype, $conf, $args, $context) {
  $node = $context->data;

  $author_node = NULL;
  if (!empty($conf['override'])) {
    $author_node = node_load($conf['override']);
  }

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'full_width_byline',
    '#node' => $node,
    '#author_node' => $author_node,
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function full_width_byline_theme(&$theme, $plugin) {
  $theme['full_width_byline'] = array(
    'variables' => array(
      'author_node' => NULL,
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

  $override = FALSE;
  if (empty($variables['author_node'])) {
    $author_node = $node_wrapper->field_author->value();
  }
  else {
    $override = TRUE;
    $author_node = $variables['author_node'];
  }

  $variables['author_image'] = '';
  $variables['author_name'] = '<strong>Specify author</strong>';
  $variables['author_link'] = '';
  if ($author_node) {
    if (!empty($author_node->field_image[LANGUAGE_NONE][0]['uri'])) {
      $author_image_uri = $author_node->field_image[LANGUAGE_NONE][0]['uri'];
      $author_image_uri = nas_alters_local_image_uri($author_image_uri);
      $variables['author_image'] = image_style_url('bio_image', $author_image_uri);
    }
    $variables['author_name'] = check_plain($author_node->title);
    $variables['author_link'] = url('node/' . $author_node->nid);
  }

  $variables['published'] = '';

  if (!$override) {
    // Set published date from issue magazine title.
    $variables['published'] = '';
    $magazine_issue = $node_wrapper->field_magazine_issue->value();
    if (!empty($magazine_issue->title)) {
      $variables['published'] = check_plain($magazine_issue->title);
    }
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
