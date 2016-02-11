<?php
/**
 * @file
 * Native Plants text plugin.
 */

$plugin = array(
  'title' => t('Native Plants text'),
  'description' => t('Native Plants text.'),
  'category' => 'Native Plants',
  'admin info' => 'native_plants_text_admin_info',
  'edit form' => 'native_plants_text_edit_form',
  'render callback' => 'native_plants_text_render',
  'hook theme' => 'native_plants_text_theme',
  'no title override' => TRUE,
  'defaults' => array(
    'text' => "<p>Native plants provide food and shelter for local birds and wildlife. Native plants also require less water and fewer chemicals to maintain, which makes them better for the environment. Best of all, they are beautiful!</p><p>Audubon's native plant database is a searchable listing of nearly 3,000 plants and trees native to the United States.</p>",
  ),
);

/**
 * Administrative info callback.
 */
function native_plants_text_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = 'Native Plants text';
  $block->content = $conf['text'];
  return $block;
}

/**
 * Configuration form.
 */
function native_plants_text_edit_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  $form['text'] = array(
    '#type' => 'textarea',
    '#title' => t('Text'),
    '#default_value' => $conf['text'],
    '#wysiwyg' => TRUE,
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function native_plants_text_edit_form_submit(&$form, &$form_state) {
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
function native_plants_text_render($subtype, $conf, $args, $context) {
  // $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $context);

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'native_plants_text',
    '#text' => $conf['text'],
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function native_plants_text_theme(&$theme, $plugin) {
  $theme['native_plants_text'] = array(
    'variables' => array(
      'text' => '',
    ),
    'template' => 'native-plants-text',
    'path' => $plugin['path'],
  );
}
