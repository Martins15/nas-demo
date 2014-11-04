<?php

/**
 * @file
 * Definition of views_handler_filter_panelizer_layout.
 */

/**
 * Filter by panelizer layout.
 *
 * @ingroup views_filter_handlers
 */
class views_handler_filter_panelizer_layout extends views_handler_filter_in_operator {
  function get_value_options() {
    if (isset($this->value_options)) {
      return;
    }

    $this->value_options = array();

//    $query = db_select('panelizer_entity', 'p');
//    $query->addField('p', 'name');
//    $query->distinct();
//    $panelized_layouts = $query->execute();
//
//    foreach ($panelized_layouts as $layout) {
//      $this->value_options[$layout->name] = $layout->name; //$layout['title'];
//    }

    $layouts = array_keys(ctools_export_crud_load_all('panelizer_defaults'));
    $this->value_options = array_combine($layouts, $layouts);
  }
}
