<?php
/**
 * @file
 * Native Plants bar plugin.
 */

$plugin = array(
  'title' => t('Native Plants bar'),
  'description' => t('Native Plants bar with title text.'),
  'category' => 'Native Plants',
  'admin info' => 'native_plants_bar_admin_info',
  'edit form' => 'native_plants_bar_edit_form',
  'render callback' => 'native_plants_bar_render',
  'hook theme' => 'native_plants_bar_theme',
  'no title override' => TRUE,
  'defaults' => array(
    'title_desktop' => 'Audubon Native Plants Database',
    'title_mobile' => 'Native Plants Database',
    'title_link' => 'native-plants',
    'background_color' => '66a122',
  ),
);

/**
 * Administrative info callback.
 */
function native_plants_bar_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = $conf['title_desktop'];
  $block->content = $conf['title_desktop'];
  return $block;
}

/**
 * Configuration form.
 */
function native_plants_bar_edit_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  $form['title_desktop'] = array(
    '#type' => 'textfield',
    '#title' => t('Bar text for desktop'),
    '#default_value' => $conf['title_desktop'],
    '#size' => 100,
  );
  $form['title_mobile'] = array(
    '#type' => 'textfield',
    '#title' => t('Bar text for mobile'),
    '#default_value' => $conf['title_mobile'],
    '#size' => 100,
  );
  $form['title_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Bar text link'),
    '#description' => t('Relative or absolute link.'),
    '#default_value' => $conf['title_link'],
    '#size' => 100,
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function native_plants_bar_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (array_key_exists($key, $form_state['values'])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }

  // Form build ID is required for contextual links.
  $form_state['conf']['form_build_id'] = $form_state['values']['form_build_id'];
}

/**
 * Render callback.
 */
function native_plants_bar_render($subtype, $conf, $args, $contexts) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  if ($plugin = ctools_get_plugins('ctools', 'content_types', $subtype)) {
    $conf = array_merge($plugin['defaults'], $conf);
  }

  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'native_plants_bar',
    '#title_desktop' => t(filter_xss($conf['title_desktop'])),
    '#title_mobile' => t(filter_xss($conf['title_mobile'])),
    '#title_link' => url(check_plain($conf['title_link'])),
    '#background_color' => $conf['background_color'],
    '#context_links' => $contextual_links,
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function native_plants_bar_theme(&$theme, $plugin) {
  $theme['native_plants_bar'] = array(
    'variables' => array(
      'title_desktop' => '',
      'title_mobile' => '',
      'title_link' => '',
      'background_color' => '',
      'context_links' => '',
    ),
    'template' => 'native-plants-bar',
    'path' => $plugin['path'],
  );
}
