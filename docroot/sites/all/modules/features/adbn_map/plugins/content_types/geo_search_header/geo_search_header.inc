<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Geographical Search Header'),
  'description' => t('Displays the geographical search header component.'),
  'category' => t('Audubon'),
  'hook theme' => 'adbn_map_geo_search_header_content_type_theme',
  'no title override' => TRUE,
  'defaults' => array(
    'title' => t('Find a bird near you'),
  ),
);

/**
 * Render the content.
 */
function adbn_map_geo_search_header_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->module = 'adbn_map';

  $content = array();

  $title = isset($conf['title']) ? $conf['title'] : t('Find a bird near you');

  // Add the markup to be displayed.
  $content['geo_search_header'] = array(
    '#theme' => 'geo_search_header',
    '#title' => $title,
  );

  $block->title = '';
  $block->content = $content;
  return $block;
}

/**
 * Returns an edit form for the custom type.
 */
function adbn_map_geo_search_header_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $title = isset($conf['title']) ? $conf['title'] : t('Find a bird near you');
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#description' => t('Enter the title to appear at the top.'),
    '#default_value' => $title,
  );

  return $form;
}

/**
 * Submit callback for settings form.
 */
function adbn_map_geo_search_header_content_type_edit_form_submit($form, &$form_state) {
  // Copy everything from our defaults.
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Callback to provide the administrative title of the plugin.
 */
function adbn_map_geo_search_header_content_type_admin_title($subtype, $conf) {
  if (isset($conf['title']) && !empty($conf['title'])) {
    $admin_title = $conf['title'];
  }
  else {
    $admin_title = t('Find a bird near you');
  }

  $output = t('Search Header Component Title: @title', array('@title' => $admin_title));

  return $output;
}

/**
 * Theme hook for plugin.
 */
function adbn_map_geo_search_header_content_type_theme(&$theme, $plugin) {
  $theme['geo_search_header'] = array(
    'variables' => array('vars' => NULL, 'title' => NULL),
    'path' => $plugin['path'],
    'template' => 'geo-search-header',
  );
}