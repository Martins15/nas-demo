<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Venn Diagrams Component'),
  'description' => t('Displays bird detail venn diagrams component.'),
  'category' => t('Audubon'),
  'hook theme' => 'adbn_map_venn_diagrams_content_type_theme',
);

/**
 * Render the content.
 */
function adbn_map_venn_diagrams_content_type_render($subtype, $conf, $panel_args, $context) {
  $content = array();

  // Extract the venn description text, and send it for display.
  $venn_description = NULL;
  $venn_description_array = adbn_main_get_bird_page_venn_description_value();
  if (!empty($venn_description_array['value'])) {
    $venn_description = check_markup($venn_description_array['value'], $venn_description_array['format']);
  }

  // Add the markup to be displayed.
  $content['map'] = array(
    '#theme' => 'venn_diagrams',
    '#venn_description' => $venn_description,
  );

  $block = new stdClass();
  $block->title = '';
  $block->content = $content;
  return $block;
}

/**
 * Theme hook for plugin.
 */
function adbn_map_venn_diagrams_content_type_theme(&$theme, $plugin) {
  $theme['venn_diagrams'] = array(
    'variables' => array(
      'venn_description' => NULL,
    ),
    'path' => $plugin['path'],
    'template' => 'venn-diagrams',
  );
}