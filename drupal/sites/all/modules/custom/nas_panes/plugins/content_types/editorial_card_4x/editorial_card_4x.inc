<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Editorial card (4x)'),
  'description' => t('Provides Editorial card (4x) pane'),
  'category' => 'Editorial cards',
  'edit form' => 'editorial_card_4x_edit_form',
  'render callback' => 'editorial_card_4x_render',
);

/**
 * An edit form for the pane's settings.
 */
function editorial_card_4x_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['#tree'] = TRUE;

  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'editorial_card_4x', 'nas_panes', 'plugins/content_types/editorial_card_4x');

  $form['more_link_text'] = array(
    '#type' => 'textfield',
    '#title' => t('More link text'),
    '#default_value' => !empty($conf['more_link_text']) ? $conf['more_link_text'] : '',
  );
  $form['more_link_url'] = array(
    '#type' => 'textfield',
    '#title' => t('More link URL'),
    '#default_value' => !empty($conf['more_link_url']) ? $conf['more_link_url'] : '',
  );

  $form['refs'] = array(
    '#type' => 'fieldset',
    '#title' => t('References'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  // Limit to 4 numbers of references.
  for ($i = 1; $i <= 4; $i++) {
    $form['refs'][$i] = array(
      '#type' => 'fieldset',
      '#title' => t('Reference %number', array('%number' => $i)),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#tree' => TRUE,
    );
    $form['refs'][$i]['image'] = array(
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
      '#default_value' => !empty($conf['refs'][$i]['image']) ? $conf['refs'][$i]['image'] : 0,
    );
    $form['refs'][$i]['category'] = array(
      '#title' => 'Category/Eyebrow',
      '#type' => 'textfield',
      '#default_value' => !empty($conf['refs'][$i]['category']) ? $conf['refs'][$i]['category'] : '',
    );
    $form['refs'][$i]['category_url'] = array(
      '#title' => 'Category/Eyebrow URL',
      '#type' => 'textfield',
      '#default_value' => !empty($conf['refs'][$i]['category_url']) ? $conf['refs'][$i]['category_url'] : '',
    );
    $form['refs'][$i]['title'] = array(
      '#title' => t('Title'),
      '#type' => 'textfield',
      '#default_value' => !empty($conf['refs'][$i]['title']) ? $conf['refs'][$i]['title'] : '',
    );
    $form['refs'][$i]['url'] = array(
      '#title' => 'URL',
      '#type' => 'textfield',
      '#default_value' => !empty($conf['refs'][$i]['url']) ? $conf['refs'][$i]['url'] : '',
    );
  }

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function editorial_card_4x_edit_form_submit(&$form, &$form_state) {
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
function editorial_card_4x_render($subtype, $conf, $args, $context) {
  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $context);

  $more_link = '';
  if (!empty($conf['more_link_text']) && !empty($conf['more_link_url'])) {
    $more_link = l($conf['more_link_text'], $conf['more_link_url']);
  }

  $references = array();
  foreach ($conf['refs'] as $ref) {
    if (empty($ref['url'])) {
      continue;
    }
    $reference = array(
      'category' => '',
      'title_link' => '',
      'image_link' => '',
    );
    if (!empty($ref['category']) && !empty($ref['category_url'])) {
      $reference['category'] = l($ref['category'], $ref['category_url'], array(
        'attributes' => array(
          'class' => array('editorial-card-slug'),
        )));
    }
    if (!empty($ref['image'])) {
      $file = file_load($ref['image']);
      $image = theme('image_style', array(
          'style_name' => 'article_teaser',
          'path' => $file->uri,
        ));
      $reference['image_link'] = l($image, $ref['url'], array('html' => TRUE));
    }
    if (!empty($ref['title'])) {
      $reference['title_link'] = l($ref['title'], $ref['url']);
    }
    if (array_filter($reference)) {
      $references[] = $reference;
    }
  }

  $block = new stdClass();
  $block->content = theme('editorial_card_4x', array(
    'references' => $references,
    'title' => $conf['override_title'] ? $conf['override_title_text'] : '',
    'more_link' => $more_link,
    'contextual_links' => $contextual_links,
  ));

  return $block;
}
