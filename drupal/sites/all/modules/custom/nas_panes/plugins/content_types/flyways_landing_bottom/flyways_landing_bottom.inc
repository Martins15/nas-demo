<?php

/**
 * @file
 * define ctools content type.
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
  }

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function flyways_landing_bottom_form_submit(&$form, &$form_state) {
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
function flyways_landing_bottom_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();
  // @codingStandardsIgnoreStart
  // Sanitize configuration before passing to template.
  array_walk_recursive($conf, function(&$value, $key) {
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

  $contextual_links = '';
  if (user_access('administer site configuration')) {
    ctools_include('modal');
    ctools_modal_add_js();
    // Add ajax-responder so ctools_ajax_command_reload() will work.
    ctools_add_js('ajax-responder');
    // We expect Featured Bird pane to be only on Bird Guide. If this is not
    // the case we will need to change this select query.
    $pid = db_query('SELECT pid FROM {panels_pane} WHERE type = :type', array(':type' => 'nas_panes_flyways_landing_bottom'))->fetchField();
    if (empty($pid)) {
      nas_panes_save_flyways_landing_page();
      $pid = db_query('SELECT pid FROM {panels_pane} WHERE type = :type', array(':type' => 'nas_panes_flyways_landing_bottom'))->fetchField();
    }
    $links = array(
      'edit' => array(
        'title' => t('Edit'),
        'href' => 'panels/ajax/editor/edit-pane/panel_context:' . NAS_PANES_FLYWAY_LANDING_PAGE_MANAGER_CACHE_KEY . '::page_flyways_landing_panel_context::::/' . $pid,
        'query' => array('reload' => 'true'),
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

  $vars = $conf + array(
    'contextual_links' => $contextual_links,
  );
  $content = theme('nas_flyways_landing_bottom', $vars);

  $block->content = $content;
  return $block;
}
