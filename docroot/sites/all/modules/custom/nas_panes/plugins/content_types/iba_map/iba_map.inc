<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('IBA Map'),
  'description' => t('Provides ESRI map both for Individual and State'),
  'category' => 'NAS',
  'render callback' => 'iba_map_render',
  'hook theme' => 'iba_map_theme',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Run-time rendering of the body of the block (content type).
 */
function iba_map_render($subtype, $conf, $args, $context) {
  if (empty($context)) {
    return;
  }

  $node = $context->data;

  switch ($node->type) {
    case 'iba':
      $lat_field = 'field_iba_lat';
      $long_field = 'field_iba_long';
      $level = 12;
      break;

    case 'iba_state':
      $lat_field = 'field_iba_state_latitude';
      $long_field = 'field_iba_state_longitude';
      $level = 6;
      $get_level = field_get_items('node', $node, 'field_iba_state_map_level');
      if (!empty($get_level[0]['value'])) {
        $level = $get_level[0]['value'];
      }
      break;

    default:
      return;
  }

  $lat = field_get_items('node', $node, $lat_field);
  $long = field_get_items('node', $node, $long_field);

  if (empty($long[0]['value']) || empty($lat[0]['value'])) {
    return;
  }

  $center = $long[0]['value'] . ',' . $lat[0]['value'];
  // TODO: Remove this adjustment when the service is fixed.
  if ($node->type == 'iba_state') {
    $center = ($long[0]['value'] / 100000) . ',' . ($lat[0]['value'] / 100000);
  }

  $query = array(
    'webmap=a93821755e634f0295ea30c4d1eefec0',
    'center=' . $center,
    'zoom=true',
    'scale=true',
    'disable_scroll=true',
    'theme=light',
    'level=' . $level,
  );

  $src = '//audubon.maps.arcgis.com/apps/Embed/index.html?' . implode('&amp;', $query);

  $block = new stdClass();
  $block->content = theme('iba_map', array(
    'src' => $src,
  ));

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function iba_map_theme(&$theme, $plugin) {
  $theme['iba_map'] = array(
    'variables' => array(
        'src' => '',
      ),
    'template' => 'iba-map',
    'path' => $plugin['path'],
  );
}
