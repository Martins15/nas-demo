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
  // If you need additional pages:
  // By family - l(t('By family'), 'birds-of-america/by-family', array('attributes' => array('class' => array('by-family'))))
  // By state - l(t('State birds'), 'birds-of-america/state', array('attributes' => array('class' => array('by-state')))),
  $block->content = theme('boa_index_bar', array(
    'links' => array(
      l(t('Alphabetical'), 'birds-of-america/alphabetical', array(
        'attributes' => array('class' => array('by-alphabetical')))
      ),
    ),
    'boa_url' => url('birds-of-america'),
  ));

  return $block;
}
