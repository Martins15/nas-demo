<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('BOA Index Guide Bar'),
  'description' => t('Provides "BOA Index Guide Bar" pane'),
  'category' => 'NAS',
  'render callback' => 'nas_panes_boa_index_bar_render',
);

/**
 * Run-time rendering of the body of the block (content type).
 * See ctools_plugin_examples for more advanced info.
 */
function nas_panes_boa_index_bar_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->content = theme('boa_index_bar', array(
    'links' => array(
      l('By family', 'boa/by-family', array('attributes' => array('class' => array('by-family')))),
      l('Alphabetical', 'boa/alphabetical', array('attributes' => array('class' => array('by-alphabetical')))),
      l('State birds', 'boa/state', array('attributes' => array('class' => array('by-state')))),
    ),
  ));

  return $block;
}
