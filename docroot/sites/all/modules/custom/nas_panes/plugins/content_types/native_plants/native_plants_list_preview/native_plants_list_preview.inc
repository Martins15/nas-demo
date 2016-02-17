<?php
/**
 * @file
 * Native Plants List preview plugin.
 */

$plugin = array(
  'title' => t('Native Plants List preview'),
  'description' => t('Native Plants List preview.'),
  'category' => 'Native Plants',
  'render callback' => 'native_plants_list_preview_render',
  'hook theme' => 'native_plants_list_preview_theme',
  'no title override' => TRUE,
  'required context' => new ctools_context_required(t('Permalink'), 'entity:permalink'),
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
function native_plants_list_preview_render($subtype, $conf, $args, $context) {
  $permalink = $context->data;

  $list = array();
  $items = explode('|', $permalink->plants_cart);
  foreach ($items as $item) {
    list($id, $name) = explode(',', $item, 2);
    $list[$id] = $name;
  }

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'native_plants_list_preview',
    '#list' => $list,
    '#permalink' => l(t('You can also access it here.'), 'pl/' . $permalink->uuid),
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
  if ($is_long = $variables['count'] > 6) {
    $variables['list'] = array_slice($variables['list'], 0, 6);
  }
  $variables['list'] = implode(', ', $variables['list']);
  $variables['list'] .= $is_long ? '...' : '';
}
