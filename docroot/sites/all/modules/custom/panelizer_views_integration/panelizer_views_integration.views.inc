<?php

/**
 * @file
 * Provide views data for panelizer entities.
 */

/**
 * Implements hook_views_data().
 */
function panelizer_views_integration_views_data() {

  // Node table -- basic table information.

  // Define the base group of this table. Fields that don't
  // have a group defined will go into this field by default.
  $data['panelizer_entity']['table']['group'] = t('Panelizer');

  // Advertise this table as a possible base table.
  $data['panelizer_entity']['table']['base'] = array(
    'field' => 'vid',
    'title' => t('Panelizer'),
    'weight' => -10,
    'defaults' => array(
      'field' => 'name',
    ),
  );
  $data['panelizer_entity']['table']['entity type'] = 'panelizer_entity';
  $data['panelizer_entity']['table']['join'] = array(
    'node' => array(
      'table' => 'panelizer_entity',
      'left_field' => 'vid',
      'field' => 'revision_id',
      'type' => 'LEFT OUTER',
      'extra' => 'panelizer_entity.entity_type=\'node\'',
    )
  );

  // Nid.
  $data['panelizer_entity']['entity_id'] = array(
    'title' => t('Panelized entity ID'),
    'help' => t('Panelized entity ID.'),
    // Information for displaying the nid.
    'field' => array(
      'handler' => 'views_handler_field_panelizer_entity',
      'click sortable' => TRUE,
    ),
  );

  // This definition has more items in it than it needs to as an example.
  $data['panelizer_entity']['name'] = array(
    'title' => t('Panelizer layout'),
    'help' => t('The panelized entity layout name.'),
    // Information for displaying a title as a field.
    'field' => array(
      'field' => 'name',
      'group' => t('Panelizer'),
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
      'link_to_node default' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    // Information for accepting a layout as a filter.
    'filter' => array(
      'handler' => 'views_handler_filter_panelizer_layout',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  return $data;
}
