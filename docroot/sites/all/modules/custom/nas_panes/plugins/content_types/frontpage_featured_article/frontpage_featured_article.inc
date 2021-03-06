<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Frontpage. Featured article'),
  'description' => t('Provides Featured article for frontpage'),
  'category' => 'NAS',
  'edit form' => 'frontpage_featured_article_form',
  'render callback' => 'frontpage_featured_article_render',
);

/**
 * An edit form for the pane's settings.
 */
function frontpage_featured_article_form($form, &$form_state) {
  $conf = $form_state['conf'];
  _nas_panes_hide_pane_title_field($form);

  $form['image'] = array(
    '#type' => 'media',
    '#tree' => TRUE,
    '#title' => t('Image'),
    '#description' => t('Allowed formats: png, jpg, jpeg, gif.'),
    '#media_options' => array(
      'global' => array(
        'file_extensions' => 'png jpg jpeg gif',
        'max_filesize' => '20 MB',
        'file_directory' => '',
        'types' => array('image'),
      ),
    ),
    '#default_value' => !empty($conf['image']) ? $conf['image'] : 0,
    '#required' => TRUE,
    '#pp_crop_styles' => array(NAS_EDITORIAL_CARD_FEATURED_IMAGE_STYLE),
  );

  // The two function calls below are necessary if we want to use a media
  // element type, because it causes ajax requests, which in turn call
  // drupal_form_rebuild(), and without the below includes, Drupal will
  // not be able to rebuild the form.

  // Include the CTools content type plugin file, because it provides
  // the ctools_content_configure_form_defaults() function, which is needed
  // when rebuilding the form, because of an ajax action, like selecting
  // a media element.
  ctools_form_include($form_state, 'content');

  // Include this plugin file as well, so that when the form is rebuilt, it
  // can successfully retrieve the settings form.
  ctools_form_include($form_state, 'frontpage_featured_article', 'nas_panes', 'plugins/content_types/frontpage_featured_article');

  $form['article'] = array(
    '#type' => 'entityreference',
    '#title' => 'Featured article',
    '#default_value' => !empty($conf['article']['entity_id']) ? $conf['article']['entity_id'] : '',
    '#era_entity_type' => 'node',
    '#era_bundles' => array('article'),
  );

  return $form;
}

/**
 * Submit callback.
 */
function frontpage_featured_article_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 *
 * See ctools_plugin_examples for more advanced info.
 */
function frontpage_featured_article_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  if (empty($conf['article']['entity_id']) || !$node = _i18n_node_load($conf['article']['entity_id'])) {
    $block->content = '';
    if (user_access('access contextual links') && user_access('edit NAS panes')) {
      $block->content = t('No featured article selected');
    }
    return $block;
  }

  $image = file_load($conf['image']);
  $image_path = '';
  if (!empty($image)) {
    $image_uri = nas_alters_local_image_uri($image->uri);
    $image_path = image_style_url(NAS_EDITORIAL_CARD_FEATURED_IMAGE_STYLE, $image_uri);
  }

  $article_raw_link = url('node/' . $node->nid);
  // Card title.
  if ($ec_title_items = field_get_items('node', $node, 'field_editorial_card_title')) {
    $article_title = $ec_title_items[0]['safe_value'];
  }
  else {
    $article_title = filter_xss($node->title);
  }

  $subtitle = '';
  if ($ec_subtitle_items = field_get_items('node', $node, 'field_editorial_card_subtitle')) {
    $subtitle = $ec_subtitle_items[0]['safe_value'];
  }
  elseif ($field_items = field_get_items('node', $node, 'field_subtitle')) {
    $subtitle = $field_items[0]['safe_value'];
  }

  list($section_link_text, $section_link_url) = nas_panes_get_blue_text_link($node);

  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);

  $content = theme('nas_frontpage_featured_article', array(
    'image_path' => $image_path,
    'article_title' => $article_title,
    'article_raw_link' => $article_raw_link,
    'subtitle' => $subtitle,
    'section_link_text' => $section_link_text,
    'section_link_url' => $section_link_url,
    'contextual_links' => $contextual_links,
  ));

  $block->content = $content;
  return $block;
}
