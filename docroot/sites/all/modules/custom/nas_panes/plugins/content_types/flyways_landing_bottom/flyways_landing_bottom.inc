<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Flyways Landing. Bottom block'),
  'description' => t('Map on background and four birds'),
  'category' => 'NAS',
  'edit form' => 'flyways_landing_bottom_form',
  'render callback' => 'flyways_landing_bottom_render',
);

/**
 * An edit form for the pane's settings.
 */
function flyways_landing_bottom_form($form, &$form_state) {
  $conf = $form_state['conf'];
  _nas_panes_hide_pane_title_field($form);

  $form['flyway'] = array(
    '#tree' => TRUE,
  );
  for ($i = 1; $i <= NAS_FLYWAYS_NUMBER; $i++) {
    $form['flyway'][$i] = array(
      '#type' => 'fieldset',
      '#title' => 'Flyway ' . $i,
      '#tree' => TRUE,
    );
    $form['flyway'][$i]['name'] = array(
      '#type' => 'textfield',
      '#title' => 'Flyway name',
      '#default_value' => !empty($conf['flyway'][$i]['name']) ? $conf['flyway'][$i]['name'] : '',
    );
    $form['flyway'][$i]['top_right_link_title'] = array(
      '#type' => 'textfield',
      '#title' => 'Top right link title',
      '#default_value' => !empty($conf['flyway'][$i]['top_right_link_title']) ? $conf['flyway'][$i]['top_right_link_title'] : '',
    );
    $form['flyway'][$i]['top_right_link_uri'] = array(
      '#type' => 'textfield',
      '#title' => 'Top right link URI',
      '#description' => 'you can use internal link i.e. node/5',
      '#default_value' => !empty($conf['flyway'][$i]['top_right_link_uri']) ? $conf['flyway'][$i]['top_right_link_uri'] : '',
    );
    $form['flyway'][$i]['text_under_top_right_link'] = array(
      '#type' => 'textfield',
      '#title' => 'Text under top righ tlink',
      '#description' => 'Exampe: 58 million acres | 17 priority bird species',
      '#default_value' => !empty($conf['flyway'][$i]['text_under_top_right_link']) ? $conf['flyway'][$i]['text_under_top_right_link'] : '',
    );
    $form['flyway'][$i]['summary'] = array(
      '#type' => 'textarea',
      '#title' => 'Summary',
      '#default_value' => !empty($conf['flyway'][$i]['summary']) ? $conf['flyway'][$i]['summary'] : '',
    );
    $form['flyway'][$i]['summary_more_link_uri'] = array(
      '#type' => 'textfield',
      '#title' => 'Summary More link URI',
      '#description' => 'you can use internal link i.e. node/5',
      '#default_value' => !empty($conf['flyway'][$i]['summary_more_link_uri']) ? $conf['flyway'][$i]['summary_more_link_uri'] : '',
    );

    $form['flyway'][$i]['summary_more_link_uri'] = array(
      '#type' => 'textfield',
      '#title' => 'Summary More link URI',
      '#description' => 'you can use internal link i.e. node/5',
      '#default_value' => !empty($conf['flyway'][$i]['summary_more_link_uri']) ? $conf['flyway'][$i]['summary_more_link_uri'] : '',
    );

    // Limit to 3 numbers of Articles.
    $form['flyway'][$i]['entity_reference'] = array(
      '#type' => 'fieldset',
      '#title' => 'News articles',
      '#tree' => TRUE,
    );
    for ($j = 1; $j <= 3; $j++) {
      $form['flyway'][$i]['entity_reference'][$j] = array(
        '#type' => 'entityreference',
        '#title' => 'News reference',
        '#title_display' => 'invisible',
        '#default_value' => !empty($conf['flyway'][$i]['entity_reference'][$j]['entity_id']) ? $conf['flyway'][$i]['entity_reference'][$j]['entity_id'] : '',
        '#era_entity_type' => 'node',
        '#era_bundles' => array('article'),
      );
    }
  }

  return $form;
}

/**
 * Submit callback.
 */
function flyways_landing_bottom_form_submit(&$form, &$form_state) {
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
function flyways_landing_bottom_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();
  // @codingStandardsIgnoreStart
  // Sanitize configuration before passing to template.
  array_walk_recursive($conf, function (&$value, $key) {
    if (strpos($key, 'image') !== FALSE) {
      $value = file_create_url($value);
    }
    elseif (strpos($key, '_uri') !== FALSE) {
      $value = url($value);
    }
    else {
      $value = check_plain($value);
    }
  });
  // @codingStandardsIgnoreEnd

  $conf_is_not_empty = function ($conf) {
    foreach ($conf['entity_reference'] as $item) {
      if (isset($item['entity_id']) && !empty($item['entity_id'])) {
        return TRUE;
      }
    }
    return FALSE;
  };

  for ($i = 1; $i <= NAS_FLYWAYS_NUMBER; $i++) {
    $title = $conf['flyway'][$i]['name'];
    $type = 'flyway';
    $result = db_query("SELECT n.nid FROM {node} n WHERE n.title = :title AND n.type = :type", array(":title" => $title, ":type" => $type));
    $condition = $result->fetchField();
    $news_nodes = array();
    if (isset($conf['flyway'][$i]) && $conf_is_not_empty($conf['flyway'][$i])) {
      // We do not use node_load_multiple so it would be possible to set same
      // news article twice.
      foreach ($conf['flyway'][$i]['entity_reference'] as $value) {
        if (!empty($value['entity_id'])) {
          $news_nodes[] = _i18n_node_load($value['entity_id']);
        }
      }
    }
    else {
      $view_results = views_get_view_result('nas_news', 'flyway_in_the_news', $condition);
      foreach ($view_results as $result) {
        $news_nodes[] = _i18n_node_load($result->nid);
      }
    }

    $teasers = array();
    foreach ($news_nodes as $node) {
      $build = node_view($node, 'nas_teaser_flyway_landing');
      $teasers[] = drupal_render($build);
    }
    if (empty($teasers)) {
      $teasers = array(t('No news of flyway @flyway', array('@flyway' => $condition)));
    }
    $conf['flyway'][$i]['news_teasers'] = implode('', $teasers);
  }

  $contextual_links = '';
  if (user_access('edit NAS panes')) {
    $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);
  }

  $vars = $conf + array(
    'contextual_links' => $contextual_links,
  );
  $content = theme('nas_flyways_landing_bottom', $vars);

  $block->content = $content;
  return $block;
}
