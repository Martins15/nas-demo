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
  $form['paddings'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Paddings'),
    '#options' => array(
      'top' => t('Top padding'),
      'between' => t('Additional space between title and content'),
      'bottom' => t('Bottom padding'),
      'double-bottom' => t('Double bottom padding'),
    ),
    '#default_value' => !empty($conf['paddings']) ? $conf['paddings'] : _editorial_card_4x_default_paddings_conf(),
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
      '#tree' => TRUE,
    );
    $form['refs'][$i]['reference'] = array(
      '#type' => 'entityreference',
      '#title' => t('Reference %number', array('%number' => $i)),
      '#default_value' => !empty($conf['refs'][$i]['reference']['entity_id']) ? $conf['refs'][$i]['reference']['entity_id'] : 0,
      '#era_entity_type' => 'node',
      '#era_bundles' => array('article', 'project', 'static_page', 'slideshow'),
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

  $teasers = array();
  foreach ($conf['refs'] as $ref) {
    if (empty($ref['reference']['entity_id']) || !$node = node_load($ref['reference']['entity_id'])) {
      continue;
    }
    $build = node_view($node, 'editorial_card_4x');
    $teaser = drupal_render($build);
    $teasers[] = $teaser;
  }

  if (empty($conf['paddings'])) {
    $conf['paddings'] = _editorial_card_4x_default_paddings_conf();
  }
  $spacebottom = '';
  if ($conf['paddings']['double-bottom']) {
    $spacebottom = 'space-bottom double';
  }
  elseif ($conf['paddings']['bottom']) {
    $spacebottom = 'space-bottom';
  }

  $block = new stdClass();
  $block->content = theme('editorial_card_4x', array(
    'teasers' => $teasers,
    'title' => check_plain($conf['override_title_text']),
    'more_link' => $more_link,
    'contextual_links' => $contextual_links,
    'spacetop' => $conf['paddings']['top'],
    'spacebetween' => $conf['paddings']['between'],
    'spacebottom' => $spacebottom,
  ));

  return $block;
}

/**
 * Helper function to provide default panes padding configuration.
 */
function _editorial_card_4x_default_paddings_conf() {
  return array(
    'top' => 'top',
    'between' => 'between',
    'bottom' => 'bottom',
    'double-bottom' => 0,
  );
}