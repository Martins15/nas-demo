<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Slideshow sidebar block'),
  'description' => t('Slideshow sidebar block'),
  'category' => 'Static Cards',
  'edit form' => 'slideshow_sidebar_block_form',
  'render callback' => 'slideshow_sidebar_block_render',
);

/**
 * An edit form for the pane's settings.
 */
function slideshow_sidebar_block_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['override_title'] = NULL;

  $form['block_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#required' => TRUE,
    '#default_value' => !empty($conf['block_title']) ? $conf['block_title'] : '',
  );

  $form['logo'] = array(
    '#type' => 'media',
    '#tree' => TRUE,
    '#title' => t('Logo'),
    '#description' => t('Allowed formats: png, jpg, jpeg, gif.'),
    '#media_options' => array(
      'global' => array(
        'file_extensions' => 'png jpg jpeg gif',
        'max_filesize' => '10 MB',
        'file_directory' => 'slideshow_logo',
        'types' => array('image'),
      ),
    ),
    '#default_value' => !empty($conf['logo']) ? $conf['logo'] : 0,
  );

  $form['slideshow'] = array(
    '#type' => 'entityreference',
    '#title' => t('Slideshow'),
    '#default_value' => !empty($conf['slideshow']['entity_id']) ? $conf['slideshow']['entity_id'] : '',
    '#era_entity_type' => 'node',
    '#era_bundles' => array('slideshow'),
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function slideshow_sidebar_block_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 *
 * @see ctools_plugin_examples()
 */
function slideshow_sidebar_block_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  drupal_add_css(drupal_get_path('module', 'nas_panes') . '/plugins/content_types/slideshow_sidebar_block/style.css');

  // Get latest slideshow if pane config is empty.
  if (empty($conf['slideshow']['entity_id'])) {
    $nid = db_select('node', 'n')
      ->fields('n', array('nid'))
      ->condition('n.type', 'slideshow')
      ->condition('n.status', NODE_PUBLISHED)
      ->orderBy('n.created', 'DESC')
      ->execute()
      ->fetchField();
  }
  else {
    $nid = $conf['slideshow']['entity_id'];
  }
  $node = _i18n_node_load($nid);

  $contextual_links = '';
  if (user_access('edit NAS panes')) {
    $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);
  }

  $image_markup = '';
  if (!empty($node->field_images[LANGUAGE_NONE][0]['uri'])) {
    $image_uri = nas_alters_local_image_uri($node->field_images[LANGUAGE_NONE][0]['uri']);
    $image = theme('image', array('path' => image_style_url('slideshow_sidebar', $image_uri)));
    $image_markup = l($image, 'node/' . $node->nid, array('html' => TRUE));
  }

  $logo_markup = '';
  if (!empty($conf['logo'])) {
    $logo_uri = nas_alters_local_image_uri($node->field_editorial_card_icon[LANGUAGE_NONE][0]['uri']);
    $logo = theme('image', array('path' => image_style_url('medium', $logo_uri)));
    $logo_markup = l($logo, 'node/' . $node->nid, array('html' => TRUE));
  }

  $block_title = (!empty($node->field_editorial_card_caption)) ? $node->field_editorial_card_caption[LANGUAGE_NONE][0]['value'] : t('Slideshow');

  $content = theme('slideshow_sidebar_block', array(
      'contextual_links' => $contextual_links,
      'block_title' => $block_title,
      'image' => $image_markup,
      'logo' => $logo_markup,
      'slideshow' => l($node->title, 'node/' . $node->nid),
      'link' => l(t('See more photos'), 'node/' . $node->nid, array('class' => array('see-more-photos')))
    ));

  $block->content = $content;
  return $block;
}
