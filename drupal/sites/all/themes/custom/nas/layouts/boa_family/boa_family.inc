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
  'title' => t('Bird of America Family page'),
  'category' => t('NAS'),
  'icon' => 'boa_family.png',
  'theme' => 'boa_family',
  'regions' => array(
    'title' => t('Title'),
    'scientific_name' => t('Scientific name'),
    'header' => t('Header'),
    'body_column_1' => t('Body first column'),
    'body_column_2' => t('Body second column'),
    'bottom' => t('Bottom'),
  ),
);
