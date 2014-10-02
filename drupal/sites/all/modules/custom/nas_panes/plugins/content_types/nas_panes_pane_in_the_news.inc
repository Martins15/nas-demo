<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Bird In The News'),
  'description' => t('Provides Bird In The News block'),
  'category' => 'NAS',
  'edit form' => 'nas_panes_pane_in_the_news_custom_pane_edit_form',
  'render callback' => 'nas_panes_pane_in_the_news_custom_pane_render',
  'all contexts' => TRUE,
);

/**
 * An edit form for the pane's settings.
 */
function nas_panes_pane_in_the_news_custom_pane_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['#tree'] = TRUE;

  if (!empty($form_state['display']->context)) {
    $data = reset($form_state['display']->context)->data;
    if ($data->type !== 'bird') {
      return $form;
    }
  }
  // Limit to 3 numbers of Articles.
  for ($i = 1; $i <= 3; $i++) {
    $form[$data->nid][$i]['entity_reference'] = array(
      '#type' => 'entityreference',
      '#title' => '',
      '#default_value' => !empty($conf[$data->nid][$i]['entity_reference']['entity_id']) ? $conf[$data->nid][$i]['entity_reference']['entity_id'] : '',
      '#era_entity_type' => 'node',
      '#era_bundles' => array('article'),
    );
  }

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function nas_panes_pane_in_the_news_custom_pane_edit_form_submit(&$form, &$form_state) {
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
function nas_panes_pane_in_the_news_custom_pane_render($subtype, $conf, $args, $contexts) {
  if (!empty($contexts)) {
    $data = reset($contexts)->data;
    if ($data->type !== 'bird') {
      return;
    }
  }

  $condition = $data->nid;
  $view_diplay_id = 'nas_bird_in_the_news_default';

  if (isset($conf[$data->nid])) {
    foreach ($conf[$data->nid] as $value) {
      if (!empty($value['entity_reference']['entity_id'])) {
        $arg[] = $value['entity_reference']['entity_id'];
      }
    }
    if (count($arg)) {
      $condition = implode(' ', $arg);
      $view_diplay_id = 'nas_bird_in_the_news';
    }
  }

  $block = new stdClass();
  $content = views_embed_view('nas_news', $view_diplay_id, $condition);
  $block->content = $content;

  return $block;
}
