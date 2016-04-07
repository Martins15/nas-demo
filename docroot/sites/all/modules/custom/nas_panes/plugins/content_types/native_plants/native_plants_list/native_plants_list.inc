<?php
/**
 * @file
 * Native Plants list plugin.
 */

$plugin = array(
  'title' => t('Native Plants List'),
  'description' => t('Native Plants List.'),
  'category' => 'Native Plants',
  'render callback' => 'native_plants_list_render',
  'hook theme' => 'native_plants_list_theme',
  'required context' => array(
    new ctools_context_required(t('Permalink'), 'entity:permalink'),
  ),
);

/**
 * Render callback.
 */
function native_plants_list_render($subtype, $conf, $args, $contexts) {
  $permalink = reset($contexts)->data;
  $plants = drupal_json_decode($permalink->plants_cart);

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'native_plants_list',
    '#plants' => $plants,
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function native_plants_list_theme(&$theme, $plugin) {
  $theme['native_plants_list'] = array(
    'variables' => array(
      'plants' => array(),
    ),
    'template' => 'native-plants-list',
    'path' => $plugin['path'],
  );
}

/**
 * Preprocess function.
 */
function nas_panes_preprocess_native_plants_list(&$variables) {
  _nas_master_native_plants_preprocess_plants_list($variables);
}
