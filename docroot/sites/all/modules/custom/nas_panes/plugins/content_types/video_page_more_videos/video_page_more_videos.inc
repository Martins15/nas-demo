<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Video page: more videos'),
  'description' => t('Provides "Video page: more videos" pane'),
  'category' => 'NAS',
  'edit form' => 'video_page_more_videos_edit_form',
  'render callback' => 'video_page_more_videos_render',
  'required context' => new ctools_context_optional(t('Node'), 'node'),
);

/**
 * An edit form for the pane's settings.
 */
function video_page_more_videos_edit_form($form, &$form_state) {
  $form['#tree'] = TRUE;

  $context = reset($form_state['display']->context);
  $conf_key = $form_state['display']->context['panelizer']->empty ? 'default' : $context->data->nid;
  $conf = !empty($form_state['conf'][$conf_key]) ? $form_state['conf'][$conf_key] : array();

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
      '#era_bundles' => array('video_page'),
    );
  }

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function video_page_more_videos_edit_form_submit(&$form, &$form_state) {
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
function video_page_more_videos_render($subtype, $conf, $args, $context) {
  ctools_form_include($form_state, 'editorial_card_4x', 'nas_panes', 'plugins/content_types/editorial_card_4x');

  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $context);

  $conf_key = $context->empty ? 'default' : $context->data->nid;

  $more_link = '';
  if (!empty($conf['more_link_text']) && !empty($conf['more_link_url'])) {
    $more_link = l($conf['more_link_text'], $conf['more_link_url']);
  }

  $nids = array();
  if (!empty($conf[$conf_key]['refs'])) {
    foreach ($conf[$conf_key]['refs'] as $ref) {
      if (!empty($ref['reference']['entity_id'])) {
        $nids[] = $ref['reference']['entity_id'];
      }
    }
  }

  $teasers = array();

  // Nodes are set.
  if ($nids && $nodes = node_load_multiple($nids)) {
    foreach ($conf[$conf_key]['refs'] as $ref) {
      if (empty($ref['reference']['entity_id']) || !isset($nodes[$ref['reference']['entity_id']])) {
        continue;
      }
      $build = node_view($nodes[$ref['reference']['entity_id']], 'editorial_card_4x');
      $teaser = drupal_render($build);
      $teasers[] = $teaser;
    }
  }
  // Default behaviour - latest videos and webcams.
  else {
    $view = views_get_view('latest_videos');
    if (!empty($context->data->nid)) {
      $view->set_arguments(array($context->data->nid));
    }
    $view->set_display('master');
    $view->pre_execute();
    $view->execute();
    foreach ($view->result as $result) {
      $node = node_load($result->nid);
      $node_view = node_view($node, 'editorial_card_4x');
      $teasers[] = drupal_render($node_view);
    }
  }
  if (!$teasers) {
    return;
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
