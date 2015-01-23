<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Flyways Landing. Top block'),
  'description' => t('Map on background and four birds'),
  'category' => 'NAS',
  'edit form' => 'flyways_landing_top_form',
  'render callback' => 'flyways_landing_top_render',
);

/**
 * An edit form for the pane's settings.
 */
function flyways_landing_top_form($form, &$form_state) {
  $conf = $form_state['conf'];
  _nas_panes_hide_pane_title_field($form);

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => 'Title',
    '#default_value' => !empty($conf['title']) ? $conf['title'] : '',
  );

  $form['subtitle'] = array(
    '#type' => 'textfield',
    '#title' => 'Subtitle',
    '#default_value' => !empty($conf['subtitle']) ? $conf['subtitle'] : '',
  );

  $form['hero_image'] = array(
    '#type' => 'textfield',
    '#title' => 'Hero Image',
    '#description' => 'Path to the hero image. i.e. public://...',
    '#default_value' => !empty($conf['hero_image']) ? $conf['hero_image'] : '',
  );

  $form['bottomtitle'] = array(
    '#type' => 'textfield',
    '#title' => 'Bottom Title',
    '#default_value' => !empty($conf['bottomtitle']) ? $conf['bottomtitle'] : '',
  );

  $form['flyway'] = array(
    '#tree' => TRUE,
  );
  for ($i = 1; $i <= NAS_FLYWAYS_NUMBER; $i++) {
    $form['flyway'][$i] = array(
      '#type' => 'fieldset',
      '#title' => 'Flyway ' . $i,
      '#tree' => TRUE,
    );
    $form['flyway'][$i]['image'] = array(
      '#type' => 'textfield',
      '#title' => 'Image',
      '#default_value' => !empty($conf['flyway'][$i]['image']) ? $conf['flyway'][$i]['image'] : '',
    );
    $form['flyway'][$i]['coordinates'] = array(
      '#type' => 'textfield',
      '#title' => 'Coordinates',
      '#default_value' => !empty($conf['flyway'][$i]['coordinates']) ? $conf['flyway'][$i]['coordinates'] : '',
    );
    $form['flyway'][$i]['bird'] = array(
      '#type' => 'textfield',
      '#title' => 'Bird name',
      '#default_value' => !empty($conf['flyway'][$i]['bird']) ? $conf['flyway'][$i]['bird'] : '',
    );
    $form['flyway'][$i]['flyway'] = array(
      '#type' => 'textfield',
      '#title' => 'Flyway',
      '#default_value' => !empty($conf['flyway'][$i]['flyway']) ? $conf['flyway'][$i]['flyway'] : '',
    );
  }

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function flyways_landing_top_form_submit(&$form, &$form_state) {
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
function flyways_landing_top_render($subtype, $conf, $args, $contexts) {
  $header_class = &drupal_static('nas_header_class');
  $header_class = 'transparent light-bg dark-text';

  $block = new stdClass();
  // @codingStandardsIgnoreStart
  // Sanitize configuration before passing to template.
  array_walk_recursive($conf, function(&$value, $key) {
    if (strpos($key, 'image') !== FALSE) {
      $value = file_create_url($value);
    }
    else {
      $value = check_plain($value);
    }
  });
  // @codingStandardsIgnoreEnd

  $contextual_links = '';
  if (user_access('edit NAS panes')) {
    $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);
  }

  $vars = $conf + array(
    'contextual_links' => $contextual_links,
  );
  $content = theme('nas_flyways_landing_top', $vars);

  $block->content = $content;
  return $block;
}
