<?php

/**
 * @file
 * Provide views data for panelizer entities.
 */

/**
 * Implements hook_views_data().
 */
function panelizer_views_integration_views_data() {
  // ----------------------------------------------------------------
  // node table -- basic table information.

  // Define the base group of this table. Fields that don't
  // have a group defined will go into this field by default.
  $data['panelizer_entity']['table']['group'] = t('Panelizer');

  // Advertise this table as a possible base table
  $data['panelizer_entity']['table']['base'] = array(
    'field' => 'nid',
    'title' => t('Panelizer'),
    'weight' => -10,
    'defaults' => array(
      'field' => 'name',
    ),
  );
  $data['panelizer_entity']['table']['entity type'] = 'panelizer_entity';
  $data['panelizer_entity']['table']['join']  = array(
    'node' => array(
      'table' => 'panelizer_entity',
      'left_field' => 'nid',
      'field' => 'entity_id',
      'type' => 'LEFT OUTER',
      'extra' => 'panelizer_entity.entity_type=\'node\'',
    )
  );

  // nid
  $data['panelizer_entity']['entity_id'] = array(
    'title' => t('Panelized entity ID'),
    'help' => t('Panelized entity ID.'), // The help that appears on the UI,
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_panelizer_entity',
      'click sortable' => TRUE,
    ),
  );

  // title
  // This definition has more items in it than it needs to as an example.
  $data['panelizer_entity']['name'] = array(
    'title' => t('Panelizer layout'), // The item it appears as on the UI,
    'help' => t('The panelized entity layout name.'), // The help that appears on the UI,
    // Information for displaying a title as a field
    'field' => array(
      'field' => 'name', // the real field. This could be left out since it is the same.
      'group' => t('Panelizer'), // The group it appears in on the UI. Could be left out.
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
      'link_to_node default' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    // Information for accepting a layout as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_panelizer_layout',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  return $data;
}
