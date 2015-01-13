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
  'title' => t('Magazine Issue page'),
  'category' => t('NAS'),
  'icon' => 'nas_magazine_issue_page.png',
  'theme' => 'panels_nas_magazine_issue_page',
  'regions' => array(
    'header' => t('Header'),
    'title' => t('Title'),
    'featured' => t('Featured'),
    'mag_issue_nav' => t('Navigation'),
    'cover' => t('Cover'),
    'articles_top' => t('Articles top'),
    'donate' => t('Donate'),
    'articles_bottom' => t('Articles bottom'),
    'right_sidebar' => t('Right sidebar'),
    'other_issues' => t('Other issues'),
  ),
);
