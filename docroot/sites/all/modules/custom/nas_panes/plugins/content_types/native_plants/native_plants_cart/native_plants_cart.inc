<?php
/**
 * @file
 * Native Plants cart plugin.
 */

$plugin = array(
  'title' => t('Native Plants cart'),
  'description' => t('Native Plants cart with the list of chosen plants.'),
  'category' => 'Native Plants',
  'admin info' => 'native_plants_cart_admin_info',
  'edit form' => 'native_plants_cart_edit_form',
  'render callback' => 'native_plants_cart_render',
  'hook theme' => 'native_plants_cart_theme',
  'defaults' => array(
    'title' => 'Your plant list',
    'override_title_text' => 'Your plant list',
    'button_desktop' => 'Get your list & Join the sanctuary',
    'button_mobile' => 'Get your list',
  ),
);

/**
 * Administrative info callback.
 */
function native_plants_cart_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = $conf['title'];
  $block->content = $conf['button_desktop'];
  return $block;
}

/**
 * Configuration form.
 */
function native_plants_cart_edit_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  $form['override_title_heading']['#access'] = FALSE;
  $form['button_desktop'] = array(
    '#type' => 'textfield',
    '#title' => t('Button text for desktop'),
    '#default_value' => $conf['button_desktop'],
    '#size' => 100,
  );
  $form['button_mobile'] = array(
    '#type' => 'textfield',
    '#title' => t('Button text for mobile'),
    '#default_value' => $conf['button_mobile'],
    '#size' => 100,
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function native_plants_cart_edit_form_submit(&$form, &$form_state) {
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
function native_plants_cart_render($subtype, $conf, $args, $context) {
  // $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $context);

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'native_plants_cart',
    '#title' => t(filter_xss($conf['title'])),
    '#button_desktop' => t(filter_xss($conf['button_desktop'])),
    '#button_mobile' => t(filter_xss($conf['button_mobile'])),
  );

  if (!$plugin = ctools_get_plugins('ctools', 'content_types', $subtype)) {
    return $block;
  }

  $block->content['#attached'] = array(
    'library' => array(
      array('system', 'jquery.cookie'),
    ),
    'js' => array(
      $plugin['path'] . '/js/native_plants_cart.js',
      libraries_get_path('json2') . '/json2.js',
    ),
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function native_plants_cart_theme(&$theme, $plugin) {
  $theme['native_plants_cart'] = array(
    'variables' => array(
      'title' => '',
      'button_desktop' => '',
      'button_mobile' => '',
    ),
    'template' => 'native-plants-cart',
    'path' => $plugin['path'],
  );
}
