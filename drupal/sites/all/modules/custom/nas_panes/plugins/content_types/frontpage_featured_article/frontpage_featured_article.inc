<?php

/**
 * @file
 * define ctools content type.
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
    '#pp_crop_styles' => array(NAS_FEATURED_FRONTPAGE_ARTICLE_IMAGE_STYLE),
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

  $form['tagline_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Tagline'),
    '#default_value' => !empty($conf['tagline_text']) ? $conf['tagline_text'] : '',
    '#required' => TRUE,
  );

  // Remove default title field.
  unset($form['override_title']);
  unset($form['override_title_text']);
  unset($form['override_title_markup']);

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function frontpage_featured_article_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function frontpage_featured_article_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  if (empty($conf['article']['entity_id']) || !$node = node_load($conf['article']['entity_id'])) {
    $block->content = '';
    if (user_access('access contextual links') && user_access('edit NAS panes')) {
      $block->content = t('No featured article selected');
    }
    return $block;
  }

  $image = file_load($conf['image']);
  $image_path = '';
  if (!empty($image)) {
    $image_path = image_style_url(NAS_FEATURED_FRONTPAGE_ARTICLE_IMAGE_STYLE, $image->uri);
  }

  $article_title = filter_xss($node->title);
  $article_raw_link = url('node/' . $node->nid);
  $subtitle = '';
  if ($field_items = field_get_items('node', $node, 'field_subtitle')) {
    $subtitle = $field_items[0]['safe_value'];
  }
  $tagline_text = filter_xss($conf['tagline_text']);

  $contextual_links = '';
  if (user_access('featured article pane edit')) {
    ctools_include('modal');
    ctools_modal_add_js();
    // Add ajax-responder so ctools_ajax_command_reload() will work.
    ctools_add_js('ajax-responder');
    // We expect Front Featured Article pane to be only on Front Page. If this is not
    // the case we will need to change this select query.
    $pid = db_query('SELECT pid FROM {panels_pane} WHERE type = :type', array(':type' => 'frontpage_featured_article'))->fetchField();
    if (empty($pid)) {
      page_manager_save_page_cache(NAS_PANES_NEWS_PAGE_MANAGER_CACHE_KEY);
      $pid = db_query('SELECT pid FROM {panels_pane} WHERE type = :type', array(':type' => 'frontpage_featured_article'))->fetchField();
    }
    $links = array(
      'edit' => array(
        'title' => t('Edit'),
        'href' => 'panels/ajax/editor/edit-pane/panel_context:' . NAS_PANES_FRONTPAGE_PAGE_MANAGER_CACHE_KEY . '::page_frontpage2_panel_context::::/' . $pid,
        'query' => array('reload' => 'true', 'nas-panes-from-page' => 'true'),
        'attributes' => array('class' => array('ctools-use-modal')),
      ),
    );
    $build = array(
      '#prefix' => '<div class="contextual-links-wrapper">',
      '#suffix' => '</div>',
      '#theme' => 'links__contextual',
      '#links' => $links,
      '#attributes' => array('class' => array('contextual-links')),
      '#attached' => array(
        'library' => array(array('contextual', 'contextual-links')),
      ),
    );
    $contextual_links = drupal_render($build);
  }

  $content = theme('nas_frontpage_featured_article', array(
    'image_path' => $image_path,
    'article_title' => $article_title,
    'article_raw_link' => $article_raw_link,
    'subtitle' => $subtitle,
    'tagline_text' => $tagline_text,
    'contextual_links' => $contextual_links,
  ));

  $block->content = $content;
  return $block;
}
