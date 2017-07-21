<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'title' => t('2x Editorial Cards + 1 Conservation News'),
  'description' => t('Provides "2x Editorial cards & 1 Conservation News" pane'),
  'category' => 'NAS',
  'edit form' => 'editorial2_conservation1_edit_form',
  'render callback' => 'editorial2_conservation1_render',
  'hook theme' => 'editorial2_conservation1_theme',
  'defaults' => array(
    'config' => array(
      'references' => array(),
      'news_references' => array(),
      'node_references' => array(),
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
 * An edit form for the pane's settings.
 */
function editorial2_conservation1_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['#tree'] = TRUE;

  $conf_key = 'config';
  $form[$conf_key] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
  );
  for ($i = 1; $i <= 2; $i++) {
    $default_value = &$conf[$conf_key]['references'][$i]['entity_reference']['entity_id'];
    $form[$conf_key]['references'][$i]['entity_reference'] = array(
      '#type' => 'entityreference',
      '#default_value' => $default_value ? $default_value : '',
      '#title' => t('Editorial card'),
      '#required' => TRUE,
      '#era_entity_type' => 'node',
      '#era_bundles' => array(
        'article',
        'static_page',
        'slideshow',
      ),
    );
  }
  for ($i = 1; $i <= 3; $i++) {
    $default_value = &$conf[$conf_key]['news_references'][$i]['entity_reference']['entity_id'];
    $form[$conf_key]['news_references'][$i]['entity_reference'] = array(
      '#type' => 'entityreference',
      '#default_value' => $default_value ? $default_value : '',
      '#title' => t('Conservation News Tracker options'),
      '#required' => TRUE,
      '#era_entity_type' => 'taxonomy_term',
      '#era_bundles' => array('conservation_news_tracker'),
      '#era_cardinality' => 1,
    );
  }
  $default_value = &$conf[$conf_key]['node_references']['entity_reference']['entity_id'];
  $form[$conf_key]['node_references']['entity_reference'] = array(
    '#type' => 'entityreference',
    '#default_value' => $default_value ? $default_value : '',
    '#title' => t('Conservation News Tracker full page.'),
    '#description' => t('For \'More\' link in filter.'),
    '#required' => TRUE,
    '#era_entity_type' => 'node',
    '#era_bundles' => array('static_page'),
    '#era_cardinality' => 1,
  );
  $form[$conf_key]['more_link'] = array(
    '#type' => 'fieldset',
    '#title' => t('More Link'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#tree' => TRUE,
  );
  $form[$conf_key]['more_link']['more_link_text'] = array(
    '#type' => 'textfield',
    '#title' => t('More link text'),
    '#default_value' => $conf[$conf_key]['more_link']['more_link_text'],
  );
  $form[$conf_key]['more_link']['more_link_url'] = array(
    '#type' => 'textfield',
    '#title' => t('More link URL'),
    '#default_value' => $conf[$conf_key]['more_link']['more_link_url'],
  );

  $form[$conf_key]['styles'] = array(
    '#type' => 'fieldset',
    '#title' => t('Styles'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#tree' => TRUE,
  );
  $form[$conf_key]['styles']['additional_classes'] = array(
    '#type' => 'textfield',
    '#title' => t('Additional classes'),
    '#default_value' => $conf[$conf_key]['styles']['additional_classes'],
  );
  $form[$conf_key]['styles']['padding'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Padding'),
    '#options' => array(
      'top' => t('Top padding'),
      'between' => t('Additional space between title and content'),
      'bottom' => t('Bottom padding'),
      'double-bottom' => t('Double bottom padding'),
    ),
    '#default_value' => $conf[$conf_key]['styles']['padding'],
  );
  return $form;
}

/**
 * Submit function, anything in the $form_state[conf] automatically gets saved.
 */
function editorial2_conservation1_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 */
function editorial2_conservation1_render($subtype, $conf, $args, $context) {
  $config = $conf['config'];
  $more_link = '';
  if (!empty($config['more_link']['more_link_text']) &&
    !empty($config['more_link']['more_link_url'])
  ) {
    $more_link = l($config['more_link']['more_link_text'], $config['more_link']['more_link_url']);
  }

  $teasers = array();
  // Search for editorial Cards.
  foreach ($config['references'] as $reference) {
    if (
      !empty($reference['entity_reference']['entity_id']) &&
      ($node = node_load($reference['entity_reference']['entity_id'])) &&
      $node->status == NODE_PUBLISHED
    ) {
      $build = node_view($node, 'editorial_card_3x');
      $teasers[] = drupal_render($build);
    }
  }

  $views_block = array(
    'attached' => array(
      'js' => array(
        drupal_get_path('module', 'nas_conservation_news_feature') . '/plugins/content_types/editorial_card2x_conservation_1x/editorial_card2x_conservation_1x.js'
      ),
    )
  );

  //Search for Conservation News References.
  $views_block['views'][] = _editorial2_conservation1_get_view();
  $views_block['terms'][] = array(
    'term_id' => '',
    'term_label' => t('All'),
  );
  foreach ($config['news_references'] as $reference) {
    if ($entity_id = $reference['entity_reference']['entity_id']) {
      $views_block['views'][] = _editorial2_conservation1_get_view($entity_id);
      $views_block['terms'][] = array(
        'term_id' => $entity_id,
        'term_label' => $reference['entity_reference']['entity_label'],
      );
      $views_block['filter_title'] = t('Topics:');
    }
  }

  if ($node_entity_id = $config['node_references']['entity_reference']['entity_id']) {
    $views_block['filter_more_link'] = l(t('More'), 'node/' . $node_entity_id);
  }
  $teasers[] = theme('conservation_news_view', $views_block);

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
  drupal_static('nas_conservation_news_feature_remove_ajx_history', TRUE);
  $block = new stdClass();
  $block->content = array(
    '#theme' => 'editorial2_conservation1',
    '#teasers' => $teasers,
    '#title' => $title,
    '#more_link' => $more_link,
    '#additional_classes' => $config['styles']['additional_classes'],
    '#space_top' => $config['styles']['padding']['top'],
    '#space_between' => $config['styles']['padding']['between'],
    '#space_bottom' => $space_bottom,
    '#attached' => array(
      'js' => array(
        drupal_get_path('module', 'nas_conservation_news_feature') . '/plugins/content_types/editorial_card2x_conservation_1x/editorial_card2x_conservation_1x.js'
      ),
    )
  );
  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function editorial2_conservation1_theme(&$theme, $plugin) {
  $theme['editorial2_conservation1'] = array(
    'variables' => array(
      'teasers' => NULL,
      'title' => NULL,
      'more_link' => NULL,
      'additional_classes' => NULL,
      'space_top' => NULL,
      'space_between' => NULL,
      'space_bottom' => NULL,
    ),
    'template' => 'editorial-card2x-conservation-1x',
    'path' => $plugin['path'],
  );
  $theme['conservation_news_view'] = array(
    'variables' => array(
      'terms' => array(
        'term_id' => NULL,
        'term_label' => NULL,
      ),
      'views' => NULL,
      'filter_title' => NULL,
      'filter_more_link' => NULL,
    ),
    'template' => 'conservation-news-view',
    'path' => $plugin['path'],
  );
}

/**
 * Helper function to get rendered view.
 */
function _editorial2_conservation1_get_view($entity_id = FALSE) {
  $view = views_get_view(CONSERVATION_NEWS_VIEW);
  $view->set_display("block");
  if ($entity_id) {
    $view->set_arguments(array($entity_id));
  }
  $view->display_handler->default_display->options['css_class'] = 'view-term-id-' . $entity_id;
  $view->pre_execute();
  $view->execute();
  $view->post_execute();
  return $view->render();
}
