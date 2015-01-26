<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Flyway In The News'),
  'description' => t('Provides related to flyway news'),
  'category' => 'NAS',
  'edit form' => 'nas_panes_flyway_in_the_news_edit_form',
  'render callback' => 'nas_panes_flyway_in_the_news_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * An edit form for the pane's settings.
 */
function nas_panes_flyway_in_the_news_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['#tree'] = TRUE;
  _nas_panes_hide_pane_title_field($form);

  if (!empty($form_state['display']->context)) {
    $data = reset($form_state['display']->context)->data;
    if ($data->type !== 'flyway') {
      return $form;
    }
  }
  $form['articles'] = array(
    '#type' => 'fieldset',
    '#title' => t('News'),
    '#tree' => TRUE,
  );
  // Limit to 3 numbers of Articles.
  for ($i = 1; $i <= 3; $i++) {
    $form['articles'][$i]['entity_reference'] = array(
      '#type' => 'entityreference',
      '#title' => '',
      '#default_value' => !empty($conf['articles'][$i]['entity_reference']['entity_id']) ? $conf['articles'][$i]['entity_reference']['entity_id'] : '',
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
function nas_panes_flyway_in_the_news_edit_form_submit(&$form, &$form_state) {
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
function nas_panes_flyway_in_the_news_render($subtype, $conf, $args, $context) {
  $context_node = $context->data;
  if ($context_node->type !== 'flyway') {
    return;
  }
  $block_title = t('@title in the News', array('@title' => $context_node->title));

  $news_nodes = array();

  $conf_is_empty = TRUE;
  if (!empty($conf['articles'])) {
    foreach ($conf['articles'] as $item) {
      if (!empty($item['entity_reference']['entity_id'])) {
        $conf_is_empty = FALSE;
        break;
      }
    }
  }

  if (!$conf_is_empty) {
    foreach ($conf['articles'] as $value) {
      if (!empty($value['entity_reference']['entity_id']) && $node = node_load($value['entity_reference']['entity_id'])) {
        $news_nodes[] = $node;
      }
    }
  }
  else {
    $view_results = views_get_view_result('nas_news', 'flyway_in_the_news', $context_node->nid);
    foreach ($view_results as $result) {
      $news_nodes[] = node_load($result->nid);
    }
  }

  $teasers = array();
  foreach ($news_nodes as $node) {
    $build = node_view($node, 'nas_node_teaser_small');
    $teasers[] = drupal_render($build);
  }

  $contextual_links = '';
  if (user_access('edit NAS panes')) {
    $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);
  }
  $vars['contextual_links'] = $contextual_links;

  $block = new stdClass();
  $block->content = '';
  if (!empty($teasers)) {
    $block->content = theme('flyway_in_the_news', array(
      'teasers' => $teasers,
      'title' => $block_title,
      'more_link' => l(t('More News »'), ''),
      'contextual_links' => $contextual_links,
    ));
  }

  return $block;
}
