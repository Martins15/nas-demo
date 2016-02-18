<?php
/**
 * @file
 * Native Plants Audubon Near You plugin.
 */

$plugin = array(
  'title' => t('Native Plants Audubon Near You'),
  'description' => t('Native Plants Audubon Near You.'),
  'category' => 'Native Plants',
  'admin info' => 'native_plants_audubon_near_you_admin_info',
  'render callback' => 'native_plants_audubon_near_you_render',
  'hook theme' => 'native_plants_audubon_near_you_theme',
  'no title override' => TRUE,
  'required context' => new ctools_context_required(t('Permalink'), 'entity:permalink'),
);

/**
 * Administrative info callback.
 */
function native_plants_audubon_near_you_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = t('Audubon Near You');
  $block->content = t('Audubon Near You');
  return $block;
}

/**
 * Render callback.
 */
function native_plants_audubon_near_you_render($subtype, $conf, $args, $context) {
  $permalink = $context->data;

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'native_plants_audubon_near_you',
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function native_plants_audubon_near_you_theme(&$theme, $plugin) {
  $theme['native_plants_audubon_near_you'] = array(
    'variables' => array(),
    'template' => 'native-plants-audubon-near-you',
    'path' => $plugin['path'],
  );
}

/**
 * Preprocess function.
 */
function nas_panes_preprocess_native_plants_audubon_near_you(&$variables) {

}
