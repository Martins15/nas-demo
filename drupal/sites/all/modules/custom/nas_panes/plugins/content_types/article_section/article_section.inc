<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Article Section'),
  'description' => t('Provides Block with blue slug text'),
  'category' => 'NAS',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'defaults' => array(
    'classes' => 'article-slug',
  ),
);

/**
 * Run-time rendering of the body of the block (content type).
 */
function nas_panes_article_section_content_type_render($subtype, $conf, $args, $context) {
  if (!empty($context)) {
    $node = $context->data;
  }

  $block = new stdClass();
  $block->content = '';

  list($text, $url) = nas_panes_get_blue_text_link($node);

  if ($text && $url) {
    $block->content = theme('nas_panes_article_section', array(
      'url' => $url,
      'text' => $text,
      'link_classes' => $conf['classes'],
    ));
  }

  return $block;
}

/**
 * Returns an edit form for custom type settings.
 */
function nas_panes_article_section_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['classes'] = array(
    '#title' => t('Link classes'),
    '#type' => 'textfield',
    '#default_value' => $conf['classes'],
  );
  return $form;
}

/**
 * Submit handler for the custom type settings form.
 */
function nas_panes_article_section_content_type_edit_form_submit($form, &$form_state) {
  // Copy everything from our defaults.
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Returns the administrative title for a type.
 */
function nas_panes_article_section_content_type_admin_title($subtype, $conf, $context) {
  return t('"@s" sections blue slug text', array('@s' => $context->identifier));
}
