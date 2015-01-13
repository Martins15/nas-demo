<?php
/**
 * @file
 * nas_author_page.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nas_author_page_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_node_contact';
  $strongarm->value = array(
    'status' => 1,
    'view modes' => array(
      'page_manager' => array(
        'status' => 1,
        'default' => 1,
        'choice' => 1,
      ),
      'default' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'teaser' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_node_teaser_small' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_node_teaser_no_section_link' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_node_featured' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_node_featured_small' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_node_related_features' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_node_teaser' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_editorial_card' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_node_contact'] = $strongarm;

  return $export;
}
