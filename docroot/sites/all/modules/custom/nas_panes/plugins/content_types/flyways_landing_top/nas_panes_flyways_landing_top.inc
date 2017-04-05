<?php

/**
 * @file
 * Defines ctools content type.
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
    $form['header_color_mode'] = array(
      '#type' => 'radios',
      '#title' => t('Nav bar coloring'),
      '#options' => array(
        'dark' => t('Light background, black text'),
        'light' => t('Dark background, white text'),
        'none' => t('Solid black background above hero image, white text'),
      ),
      '#default_value' => !empty($conf['header_color_mode']) ? $conf['header_color_mode'] : 'dark',
      '#description' => t('You can choose if the image you uploaded is dark or light so that proper font styles were applied to header content.'),
    );
    $form['disable_gradient'] = array(
      '#type' => 'checkbox',
      '#title' => t('Disable gradient'),
      '#default_value' => isset($conf['disable_gradient']) ? $conf['disable_gradient'] : '',
      '#return_value' => 'disable',
      '#description' => t('By default the nav bar appears overlaid on top of the hero image with a gradient background (which can be disabled). Additionally, the hero image can sit underneath a solid black nav bar with white text.'),
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
 * Submit callback.
 */
function flyways_landing_top_form_submit(&$form, &$form_state) {
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
function flyways_landing_top_render($subtype, $conf, $args, $contexts) {

  $class = &drupal_static('nas_header_class');
  if (!empty($conf['header_color_mode']) && $conf['header_color_mode'] == 'light') {
    $class = !empty($conf['disable_gradient']) ? 'light-text transparent' : 'light-text dark-bg transparent';
  }
  elseif (!empty($conf['header_color_mode']) && $conf['header_color_mode'] == 'dark') {
    $class = !empty($conf['disable_gradient']) ? 'dark-text transparent' : 'dark-text light-bg transparent';
  }

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
