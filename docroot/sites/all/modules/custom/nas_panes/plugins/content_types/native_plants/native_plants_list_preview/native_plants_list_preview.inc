<?php

/**
 * @file
 * Native Plants List preview plugin.
 */

$plugin = array(
  'title' => t('Native Plants List preview'),
  'description' => t('Native Plants List preview.'),
  'category' => 'Native Plants',
  'admin info' => 'native_plants_list_preview_admin_info',
  'render callback' => 'native_plants_list_preview_render',
  'hook theme' => 'native_plants_list_preview_theme',
  'no title override' => TRUE,
  'required context' => array(
    new ctools_context_required(t('Permalink'), 'entity:permalink'),
  ),
);

/**
 * Administrative info callback.
 */
function native_plants_list_preview_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = t('List preview');
  $block->content = t('List preview');
  return $block;
}

/**
 * Render callback.
 */
function native_plants_list_preview_render($subtype, $conf, $args, $contexts) {
  $permalink = reset($contexts)->data;

  $list = array();
  if ($items = drupal_json_decode($permalink->plants_cart)) {
    foreach ($items as $plant_id => $item) {
      $list[$plant_id] = $item['CommonName'];
    }
  }
  else {
    return;
  }

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'native_plants_list_preview',
    '#list' => $list,
    '#permalink' => l(t('You can also access it here.'), 'native-plants/list/' . $permalink->uuid),
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function native_plants_list_preview_theme(&$theme, $plugin) {
  $theme['native_plants_list_preview'] = array(
    'variables' => array(
      'count' => '',
      'list' => array(),
      'permalink' => '',
    ),
    'template' => 'native-plants-list-preview',
    'path' => $plugin['path'],
  );
}

/**
 * Preprocess function.
 */
function nas_panes_preprocess_native_plants_list_preview(&$variables) {
  $variables['count'] = count($variables['list']);
  $list = '';
  foreach ($variables['list'] as $item) {
    if (drupal_strlen($list) < 110) {
      $list .= $list ? ', ' . filter_xss($item) : filter_xss($item);
    }
    else {
      $list .= '...';
      break;
    }
  }
  $variables['list'] = $list;
}
