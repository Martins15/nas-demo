<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Geographical Search'),
  'description' => t('Displays geographical search map component.'),
  'category' => t('Audubon'),
  'hook theme' => 'adbn_map_geo_search_content_type_theme',
  'defaults' => array(
  ),
);

/**
 * Render the content.
 */
function adbn_map_geo_search_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->module = 'adbn_map';

  $aggregated = FALSE;
  $content = array();

  // Get various asset paths.
  $module_path = drupal_get_path('module', 'adbn_map');
  $plugin_path = $module_path . '/plugins/content_types/geo_search';
  $map_css_path = adbn_map_get_map_css_path();

  $descriptions = adbn_map_get_geo_search_descriptions();

  // Extract the sort description text, and send it for display.
  $sort_description = NULL;
  $sort_description_array = adbn_map_get_geo_search_page_sort_description();
  if (!empty($sort_description_array['value'])) {
    $sort_description = check_markup($sort_description_array['value'], $sort_description_array['format']);
  }

  // Add the various js settings required to initialize the plugin.
  $content['#attached']['js'][] = array(
    'type' => 'setting',
    'data' => array(ADBN_MAP_JS_NAMESPACE => array(
      'ajaxPath' => ADBN_MAP_AJAX_PATH,
      'area' => 'BBC',
      'birdDetailPath' => ADBN_MAP_BIRD_DETAIL_PATH,
      'descriptions' => $descriptions,
    )),
  );

  // Attach general map assets.
  $content = drupal_array_merge_deep_array(array($content, adbn_map_attach_map_assets($aggregated)));

  // Load the JS file that will initialize the map.
  $content['#attached']['js'][] = $plugin_path . '/geo_search.js';

  // Add the markup to be displayed.
  $content['map'] = array(
    '#theme' => 'geo_search',
    '#css_path' => $map_css_path,
    '#sort_description' => $sort_description,
  );

  // Mark that search JS was attached.
  $is_attached = &drupal_static('adbn_map_search_attached', FALSE);
  $is_attached = TRUE;

  $block->title = '';
  $block->content = $content;
  return $block;
}

/**
 * Returns an edit form for the custom type.
 */
function adbn_map_geo_search_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  return $form;
}

function adbn_map_geo_search_content_type_edit_form_submit($form, &$form_state) {
  // Copy everything from our defaults.
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Theme hook for plugin.
 */
function adbn_map_geo_search_content_type_theme(&$theme, $plugin) {
  $theme['geo_search'] = array(
    'variables' => array(
      'css_path' => NULL,
      'sort_description' => NULL,
    ),
    'path' => $plugin['path'],
    'template' => 'geo-search',
  );
}