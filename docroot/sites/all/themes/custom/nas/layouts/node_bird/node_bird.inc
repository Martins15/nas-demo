<?php

/**
 * @file
 * Plugin definition file for panel's layout.
 */

/**
 * Implementation of hook_panels_layouts().
 */
// Plugin definition.
$plugin = array(
  'title' => t('Bird node page'),
  'category' => t('NAS'),
  'icon' => 'node_bird.png',
  'theme' => 'panels_node_bird',
  'regions' => array(
    'header' => t('Header'),
    'top' => t('Top'),
    'main' => t('Main'),
    'similar_birds' => t('Similar birds'),
    'in_action_top' => t('In Action Header'),
    'in_action_left' => t('In Action Left'),
    'in_action_right' => t('In Action Right'),
    'in_the_news' => t('In the News'),
    'card_set' => t('Card set'),
    'across_audubon' => t('Across Audubon'),
  ),
);
