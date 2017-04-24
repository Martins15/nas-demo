<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('2x Editorial Cards + 1 Engagement card'),
  'description' => t('Provides "2x Editorial cards & 1 Engagement card" pane'),
  'category' => 'S&C Panes',
  'edit form' => 'editorial_card_2x_plus_edit_form',
  'render callback' => 'editorial_card_2x_plus_render',
  'admin title' => 'editorial_card_2x_plus_admin_title',
  'admin info' => 'editorial_card_2x_plus_admin_info',
  'hook theme' => 'editorial_card_2x_plus_theme',
  'defaults' => array(
    'config' => array(
      'refs' => array(),
      'styles' => array(
        'padding' => array(
          'top' => 0,
          'between' => 0,
          'bottom' => 0,
          'double-bottom' => 0,
        ),
        'additional_classes' => '',
      ),
      'more_link' => array(
        'more_link_text' => '',
        'more_link_url' => '',
      ),
    ),
  ),
);

/**
 * Help function to provide administrative title.
 */
function editorial_card_2x_plus_admin_title($subtype, $conf, $context = NULL) {
  return t('2x Editorial Cards + 1 Engagement card');
}

/**
 * Callback to provide administrative info.
 *
 * The preview in panels when building a panel.
 */
function editorial_card_2x_plus_admin_info($subtype, $conf, $context = NULL) {
  if (empty($conf)) {
    return;
  }
  $block = new stdClass();
  $block->title = t('2x Editorial cards & Engagement card');
  $block->content = '';
  $items = array();
  foreach ($conf['refs'] as $ref) {
    foreach ($ref['editorial'] as $editorial) {
      if (!empty($editorial['entity_label'])) {
        $items[] = $editorial['entity_label'];
      }
    }
    if (!empty($ref['engagement']['entity_label'])) {
      $items[] = $ref['engagement']['entity_label'];
    }
  }
  $block->content = theme('item_list', array('items' => $items));
  return $block;
}

/**
 * An edit form for the pane's settings.
 */
function editorial_card_2x_plus_edit_form($form, &$form_state) {
  $conf = $form_state['conf']['config'];
  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'editorial_card_2x_plus', 'nas_panes', 'plugins/content_types/state_center/editorial_card_2x_plus');

  $count = isset($conf['count']) ? $conf['count'] : 1;
  $count = isset($form_state['values']['count']) ? $form_state['values']['count'] : $count;
  $form['#tree'] = TRUE;
  $form['config']['count'] = array(
    '#type' => 'select',
    '#title' => t('Number of rows'),
    '#options' => array_combine(range(1, 6), range(1, 6)),
    '#ajax' => array(
      'callback' => 'editorial_card_2x_plus_change_number_of_items',
      'wrapper' => 'count-wrapper',
    ),
    '#default_value' => $count,
  );

  $form['config']['refs'] = array(
    '#prefix' => '<div id="count-wrapper">',
    '#suffix' => '</div>',
    '#tree' => TRUE,
  );
  for ($i = 0; $i < $count; $i++) {
    $ref = !empty($conf['refs']['refs_' . $i]) ? $conf['refs']['refs_' . $i] : array();
    $form['config']['refs']['refs_' . $i] = array(
      '#type' => 'fieldset',
      '#title' => t('References row !i:', array('!i' => $i + 1)),
      '#collapsible' => TRUE,
      '#collapsed' => $i > 0 ? TRUE : FALSE,
    );
    for ($e = 0; $e < 2; $e++) {
      $form['config']['refs']['refs_' . $i]['editorial'][$e] = array(
        '#type' => 'entityreference',
        '#title' => t('Editorial card Reference %number', array('%number' => $e + 1)),
        '#default_value' => !empty($ref['editorial'][$e]['entity_id']) ? $ref['editorial'][$e]['entity_id'] : 0,
        '#era_entity_type' => 'node',
        '#era_bundles' => array(
          'article',
          'static_page',
          'slideshow',
        ),
      );
    }
    $form['config']['refs']['refs_' . $i]['engagement'] = array(
      '#type' => 'entityreference',
      '#title' => t('Engagement Reference'),
      '#default_value' => !empty($ref['engagement']['entity_id']) ? $ref['engagement']['entity_id'] : 0,
      '#era_entity_type' => 'node',
      '#era_bundles' => array('engagement_cards'),
    );
  }

  $form['config']['more_link'] = array(
    '#type' => 'fieldset',
    '#title' => t('More Link'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#tree' => TRUE,
  );
  $form['config']['more_link']['more_link_text'] = array(
    '#type' => 'textfield',
    '#title' => t('More link text'),
    '#default_value' => $conf['more_link']['more_link_text'],
  );
  $form['config']['more_link']['more_link_url'] = array(
    '#type' => 'textfield',
    '#title' => t('More link URL'),
    '#default_value' => $conf['more_link']['more_link_url'],
  );

  $form['config']['styles'] = array(
    '#type' => 'fieldset',
    '#title' => t('Styles'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#tree' => TRUE,
  );
  $form['config']['styles']['additional_classes'] = array(
    '#type' => 'textfield',
    '#title' => t('Additional classes'),
    '#default_value' => $conf['styles']['additional_classes'],
  );
  $form['config']['styles']['padding'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Padding'),
    '#options' => array(
      'top' => t('Top padding'),
      'between' => t('Additional space between title and content'),
      'bottom' => t('Bottom padding'),
      'double-bottom' => t('Double bottom padding'),
    ),
    '#default_value' => $conf['styles']['padding'],
  );

  return $form;
}

/**
 * Submit function, anything in the $form_state[conf] automatically gets saved.
 */
function editorial_card_2x_plus_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Edit form submit for changing number of references.
 */
function editorial_card_2x_plus_change_number_of_items($form, &$form_state) {
  return $form['refs'];
}

/**
 * Run-time rendering of the body of the block (content type).
 *
 * See ctools_plugin_examples for more advanced info.
 */
function editorial_card_2x_plus_render($subtype, $conf, $args, $context) {
  $config = $conf['config'];
  $more_link = '';
  if (!empty($config['more_link']['more_link_text']) &&
    !empty($config['more_link']['more_link_url'])
  ) {
    $more_link = l($config['more_link']['more_link_text'], $config['more_link']['more_link_url']);
  }

  $teasers = array();
  foreach ($config['refs'] as $key => $ref) {
    foreach ($ref['editorial'] as $editorial) {
      if (!empty($editorial['entity_id']) && $node = node_load($editorial['entity_id'])) {
        $build = node_view($node, 'editorial_card_3x');
        $teasers[$key][] = drupal_render($build);
      }
    }
    $node = !empty($ref['engagement']['entity_id']) ? node_load($ref['engagement']['entity_id']) : FALSE;
    if ($node && $node->status === '1') {
      $teasers[$key][] = _editorial_card_2x_plus_render_engagement_helper($node);
    }
    else {
      $contexts = array();
      if (!empty($context[0]->data)) {
        $contexts['node'] = $context[0]->data;
      }
      // @TODO decide how to migrate or reuse this function nas_panes_engagement_cards_get_cards()
      $nodes = asc_panes_engagement_cards_get_cards(3, 1, array(), $contexts);
      foreach ($nodes as $node) {
        $teasers[$key][] = _editorial_card_2x_plus_render_engagement_helper($node);
      }
    }
  }
  $teasers = array_slice($teasers, 0, !empty($config['count']) ? $config['count'] : 2);

  $title = '';
  if (!empty($conf['override_title_text']) && !empty($teasers)) {
    $title = ctools_context_keyword_substitute($conf['override_title_text'], array(), array($context));
  }
  $space_bottom = '';
  if ($config['styles']['padding']['double-bottom']) {
    $space_bottom = 'space-bottom double';
  }
  elseif ($config['styles']['padding']['bottom']) {
    $space_bottom = 'space-bottom';
  }

  $block = new stdClass();
  $block->content = theme('editorial_card_2x_plus', array(
    'teasers' => $teasers,
    'title' => $title,
    'more_link' => $more_link,
    'additional_classes' => $config['styles']['additional_classes'],
    'space_top' => $config['styles']['padding']['top'],
    'space_between' => $config['styles']['padding']['between'],
    'space_bottom' => $space_bottom,
  ));

  return $block;
}

/**
 * Render engagement cards helper.
 *
 * @param object $node
 *   Node object.
 *
 * @return string
 *   Rendered HTML result.
 */
function _editorial_card_2x_plus_render_engagement_helper($node) {
  $build = node_view($node, 'teaser');
  return '<div class="columns large-4">' . drupal_render($build) . '</div>';
}

/**
 * Delegated implementation of hook_theme().
 */
function editorial_card_2x_plus_theme(&$theme, $plugin) {
  $theme['editorial_card_2x_plus'] = array(
    'variables' => array(
      'teasers' => NULL,
      'title' => NULL,
      'more_link' => NULL,
      'additional_classes' => NULL,
      'space_top' => NULL,
      'space_between' => NULL,
      'space_bottom' => NULL,
    ),
    'template' => 'editorial-card-2x-plus',
    'path' => $plugin['path'],
  );
}
