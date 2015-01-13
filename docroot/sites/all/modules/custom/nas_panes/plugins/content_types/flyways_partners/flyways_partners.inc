<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Flyways Landing. Partners'),
  'description' => t('Big image background. Text with link.'),
  'category' => 'NAS',
  'edit form' => 'flyways_partners_form',
  'render callback' => 'flyways_partners_render',
  'defaults' => array(
    'title' => 'Partners',
    'background_image' => 'public://breakout-section-6.jpg',
    'summary' => 'Audubon works with 19 BirdLife International partners and others',
    'read_more_link' => '<front>',
  ),
);

/**
 * An edit form for the pane's settings.
 */
function flyways_partners_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => 'Title',
    '#default_value' => $conf['title'],
  );

  $form['background_image'] = array(
    '#type' => 'textfield',
    '#title' => 'Background image',
    '#description' => 'URI of the image i.e. public://background.jpg',
    '#default_value' => $conf['background_image'],
  );

  $form['summary'] = array(
    '#type' => 'textarea',
    '#title' => 'Summary',
    '#default_value' => $conf['summary'],
  );

  $form['read_more_link'] = array(
    '#type' => 'textarea',
    '#title' => 'Read More link uri',
    '#description' => 'Link can be drupal internal i.e. node/5',
    '#default_value' => $conf['read_more_link'],
  );

  // Remove default title field.
  unset($form['override_title']);
  unset($form['override_title_text']);
  unset($form['override_title_markup']);

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function flyways_partners_form_submit(&$form, &$form_state) {
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
function flyways_partners_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();
  // @codingStandardsIgnoreStart
  // Sanitize configuration before passing to template.
  array_walk_recursive($conf, function(&$value, $key) {
    if (strpos($key, 'link') !== FALSE) {
      $value = url($value);
    }
    elseif (strpos($key, 'image') !== FALSE) {
      $value = file_create_url($value);
    }
    else {
      $value = check_plain($value);
    }
  });
  // @codingStandardsIgnoreEnd

  $contextual_links = '';
  if (user_access('access contextual links') && user_access('edit NAS panes')) {
    ctools_include('modal');
    ctools_modal_add_js();
    // Add ajax-responder so ctools_ajax_command_reload() will work.
    ctools_add_js('ajax-responder');
    // We expect Featured Bird pane to be only on Bird Guide. If this is not
    // the case we will need to change this select query.
    $pid = db_query('SELECT pid FROM {panels_pane} WHERE type = :type', array(':type' => 'flyways_partners'))->fetchField();
    if (empty($pid)) {
      nas_panes_resave_panel(NAS_PANES_FLYWAY_LANDING_PAGE_MANAGER_CACHE_KEY);
      $pid = db_query('SELECT pid FROM {panels_pane} WHERE type = :type', array(':type' => 'flyways_partners'))->fetchField();
    }
    $links = array(
      'edit' => array(
        'title' => t('Edit'),
        'href' => 'panels/ajax/editor/edit-pane/panel_context:' . NAS_PANES_FLYWAY_LANDING_PAGE_MANAGER_CACHE_KEY . '::page_flyways_landing_panel_context::::/' . $pid,
        'query' => array('reload' => 'true', 'nas-panes-from-page' => 'true'),
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
  $content = theme('nas_flyways_partners', $vars);

  $block->content = $content;
  return $block;
}
