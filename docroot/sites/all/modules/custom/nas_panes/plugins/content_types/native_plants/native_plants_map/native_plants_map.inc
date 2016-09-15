<?php
/**
 * @file
 * Native Plants Nurseries map plugin.
 */

$plugin = array(
  'title' => t('Native Plants Nurseries Map'),
  'description' => t('Native Plants Nurseries Map.'),
  'category' => 'Native Plants',
  'admin info' => 'native_plants_map_admin_info',
  'edit form' => 'native_plants_map_edit_form',
  'render callback' => 'native_plants_map_render',
  'hook theme' => 'native_plants_map_theme',
  'defaults' => array(
    'title' => 'Native Plant nurseries nationwide',
    'override_title_text' => 'Native Plant nurseries nationwide',
    'map' => array(
      'value' => '<iframe width="100%" height="100%" frameborder="0" scrolling="no" marginheight="0" marginwidth="0" src="//audubon.maps.arcgis.com/apps/Embed/index.html?webmap=6d4de5b3a14a4b90a214155db7f8cb7e&amp;extent=-129.5384,22.9645,-64.6311,52.567&amp;zoom=true&amp;scale=false&amp;theme=light"></iframe>',
      'format' => 'map',
    ),
  ),
);

/**
 * Administrative info callback.
 */
function native_plants_map_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = t('Nurseries Map');
  $block->content = t('Nurseries Map');
  return $block;
}

/**
 * Configuration form.
 */
function native_plants_map_edit_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  $form['override_title_heading']['#access'] = FALSE;
  $form['map'] = array(
    '#type' => 'text_format',
    '#title' => t('Map embed code'),
    '#default_value' => $conf['map']['value'],
    '#format' => $conf['map']['format'],
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function native_plants_map_edit_form_submit(&$form, &$form_state) {
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
function native_plants_map_render($subtype, $conf, $args, $contexts) {
  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'native_plants_map',
    '#title' => t(filter_xss($conf['override_title_text'])),
    '#map' => check_markup($conf['map']['value'], $conf['map']['format']),
    '#context_links' => $contextual_links,
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function native_plants_map_theme(&$theme, $plugin) {
  $theme['native_plants_map'] = array(
    'variables' => array(
      'title' => '',
      'map' => '',
      'context_links' => '',
    ),
    'template' => 'native-plants-map',
    'path' => $plugin['path'],
  );
}

/**
 * Preprocess function.
 */
function nas_panes_preprocess_native_plants_map(&$variables) {

}
