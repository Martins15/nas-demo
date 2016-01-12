<?php

/**
 * Returns the path to the adbn_map module.
 */
function adbn_map_get_module_path() {
  $path = drupal_get_path('module', 'adbn_map');
  return $path;
}

/**
 * Returns the path to the stamen asset folder.
 */
function adbn_map_get_map_assets_path() {
  $path = adbn_map_get_module_path() . '/stamen';
  return $path;
}

/**
 * Returns the path to the stamen js folder.
 */
function adbn_map_get_map_js_path() {
  $path = adbn_map_get_map_assets_path() . '/js';
  return $path;
}

/**
 * Returns the path to the stamen css folder.
 */
function adbn_map_get_map_css_path() {
  $path = adbn_map_get_map_assets_path() . '/css';
  return $path;
}

/**
 * Returns the path to the stamen data folder.
 */
function adbn_map_get_map_data_path() {
  $path = adbn_map_get_map_assets_path() . '/data';
  return $path;
}

/**
 * Returns a render array with attached JS and CSS assets for map component.
 */
function adbn_map_attach_map_assets($aggregated = TRUE) {
  $module_path = adbn_map_get_module_path();
  $map_js_path = adbn_map_get_map_js_path();
  $map_css_path = adbn_map_get_map_css_path();
  $element = array();

  // Load this to assign the jQuery to the global $ sign, because that's what
  // Stamen JS requires.
  $element['#attached']['js'][] = array(
    'data' => $module_path . '/js/adbn_map_init.js',
    'type' => 'file',
    'weight' => -1,
  );

  // Depending on whether we include the aggregated version or not, we load
  // the aggregated js, or all the separate ones.
  if ($aggregated) {
    $element['#attached']['js'][] = $map_js_path . '/audubon-climate-model.min.js';
  }
  else {
    $element['#attached']['js'][] = $map_js_path . '/vendor/polyfills.js';
    $element['#attached']['js'][] = $map_js_path . '/vendor/stamen-super-classy.js';
    $element['#attached']['js'][] = $map_js_path . '/vendor/typeahead.js';
    $element['#attached']['js'][] = $map_js_path . '/vendor/d3.v3.min.js';
    $element['#attached']['js'][] = $map_js_path . '/vendor/topojson.v1.min.js';
    $element['#attached']['js'][] = $map_js_path . '/vendor/queue.v1.min.js';
    $element['#attached']['js'][] = $map_js_path . '/vendor/venn.js';
    $element['#attached']['js'][] = $map_js_path . '/venn-over-venn.js';
    $element['#attached']['js'][] = $map_js_path . '/audubon-climate-model.js';
    $element['#attached']['js'][] = $map_js_path . '/audubon-climate-model-slideshow.js';
    $element['#attached']['js'][] = $map_js_path . '/audubon-climate-model-imagemap.js';
  }

  // Add the various js settings required to initialize the map functionality.
  $element['#attached']['js'][] = array(
    'type' => 'setting',
    'data' => array(ADBN_MAP_JS_NAMESPACE => array(
      'imagesPath' => adbn_map_get_map_css_path()
    )),
  );

  // Load the CSS. Not sure if will be needed in the future.
  $element['#attached']['css'][] = $map_css_path . '/audubon-mlimate-model.css';

  return $element;
}

/**
 * Returns a render array with the stamen search js attached.
 */
function adbn_map_attach_search_js($aggregated = TRUE, $force_attach = FALSE) {
  $content = array();

  // Check if we already attached the search js.
  $is_attached = &drupal_static('adbn_map_search_attached', FALSE);
  if ($is_attached || $force_attach) {
    return $content;
  }
  else {
    // Mark that we already have JS that attaches to the search input.
    $is_attached = TRUE;
  }

  // Get various asset paths.
  $module_path = adbn_map_get_module_path();
  $plugin_path = $module_path . '/plugins/content_types/bird_list_search_box';

  // Add the various js settings required to initialize the plugin.
  $content['#attached']['js'][] = array(
    'type' => 'setting',
    'data' => array(
      ADBN_MAP_JS_NAMESPACE => array(
        'ajaxPath' => ADBN_MAP_AJAX_PATH,
        'birdDetailPath' => ADBN_MAP_BIRD_DETAIL_PATH,
        'area' => 'BBC',
      )
    ),
  );

  // Attach general map assets.
  $content = drupal_array_merge_deep_array(array(
    $content,
    adbn_map_attach_map_assets($aggregated)
  ));

  // Load the JS file that will initialize the map.
  $content['#attached']['js'][] = $plugin_path . '/bird_list_search_box.js';
  return $content;
}
