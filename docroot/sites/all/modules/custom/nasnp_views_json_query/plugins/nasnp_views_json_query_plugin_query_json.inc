<?php
/**
 * @file
 * Query plugin for nasnp_views_json_query.
 */

class nasnp_views_json_query_plugin_query_json extends views_json_query_plugin_query_json {
  public function query($get_count = FALSE) {
    $filters = array();
    if (isset($this->filter)) {
      foreach ($this->filter as $filter) {
        if ($filter->options['key'] == 'zipcode') {
          continue;
        }
        $filters[] = $filter->generate();
      }
    }

    return $filters;
  }

  /**
   * Fetch file.
   */
  public function fetch_file($uri) {
    // Check for the zipcode value; do not request any data if no zipcode.
    $request = FALSE;
    if (isset($this->filter)) {
      foreach ($this->filter as $key => $filter) {
        if ($filter->options['key'] == 'zipcode') {
          $uri = str_replace('zipcode', $filter->value, $uri);
          unset($this->filter[$key]);
          $request = TRUE;
        }
      }
    }

    // Return empty string to terminate the parse step.
    if (!$request) {
      return drupal_json_encode('');
    }

    // Hard code caching - if there are saved results use them.
    $destination = 'public://views_json_query';
    $cache_file = 'views_json_query_' . md5($uri);
    $cache_file_uri = "$destination/$cache_file";

    if (file_exists($cache_file_uri)) {
      return file_get_contents($cache_file_uri);
    }

    return parent::fetch_file($uri);
  }

  /**
   * Parse.
   */
  public function parse(&$view, $data) {
    // Audubon JSON needs double decoding.
    $decode = drupal_json_decode($data->contents);
    // Do not process if there was no request or the result is empty.
    if ($decode === '' || $decode === '[]') {
      return TRUE;
    }
    $data->contents = $decode;

    // Below is the modified parse function from the parent class.
    $ret = json_decode($data->contents, FALSE);
    if (!$ret) {
      return FALSE;
    }

    // Get rows.
    $ret = $this->apath($this->options['row_apath'], $ret);

    // MODIFICATIONS: Add local data to the results.
    $this->add_local_data($ret, $view);

    // Check if we should return Tier 1 results - find only Tier1 results.
    if ($view->current_display == 'native_plants_search_pane_tier1') {
      $ret = array_filter($ret, function($result) {
        return $result->Tier1;
      });
    }
    $view->result_unfiltered = $ret;

    // Filter.
    foreach ($ret as $k => $row) {
      $check = TRUE;
      foreach ($view->build_info['query'] as $filter) {
        $l = is_object($row) ? $row->{$filter[0]} : $row[$filter[0]];
        $check = $this->ops($filter[1], $l, $filter[2]);
        if (!$check) {
          break;
        }
      }

      // Check taxonomy filters.
      if (isset($this->filter_taxonomy)) {
        // Single taxonomy filter flag.
        $tax_filter_check = TRUE;
        foreach ($this->filter_taxonomy as $values) {
          $values_check = FALSE;
          foreach ($values as $value) {
            $l = is_object($row) ? $row->{$value} : $row[$value];
            // If at least one attribute of taxonomy term is satisfied, then
            // this taxonomy filter is satisfied.
            if ($l === "1") {
              $values_check = TRUE;
              break;
            }
          }
          if (!$values_check) {
            $tax_filter_check = FALSE;
          }
        }
        if (!$tax_filter_check) {
          $check = FALSE;
        }
      }

      if (!$check) {
        unset($ret[$k]);
      }
    }

    try {
      if ($this->pager->use_count_query() || !empty($view->get_total_rows)) {
        // Hackish execute_count_query implementation.
        $this->pager->total_items = count($ret);
        if (!empty($this->pager->options['offset'])) {
          $this->pager->total_items -= $this->pager->options['offset'];
        }

        $this->pager->update_page_info();
      }

      // Deal with offset & limit.
      $offset = !empty($this->offset) ? intval($this->offset) : 0;
      $limit = !empty($this->limit) ? intval($this->limit) : 0;
      $ret = $limit ? array_slice($ret, $offset, $limit) : array_slice($ret, $offset);

      $result = array();
      foreach ($ret as $row) {
        $new_row = new stdClass();
        $new_row = $this->parse_row(NULL, $row, $row);
        $result[] = (object) $new_row;
      }

      if (!empty($this->orderby)) {
        // Array reverse, because the most specific are first.
        foreach (array_reverse($this->orderby) as $orderby) {
          $orderby->sort($result);
        }
      }
      $view->result = $result;
      $view->total_rows = count($result);

      $this->pager->post_execute($view->result);

      return TRUE;
    }
    catch (Exception $e) {
      $view->result = array();
      if (!empty($view->live_preview)) {
        drupal_set_message(time());
        drupal_set_message($e->getMessage(), 'error');
      }
      else {
        debug($e->getMessage(), 'Views Json Backend');
      }
    }
  }

  /**
   * Fake function required for taxonomy filters.
   */
  public function add_table($table, $relationship = NULL, $join = NULL, $alias = NULL) {
    return 'taxonomy';
  }

  /**
   * Fake function required for taxonomy filters.
   */
  public function add_relationship($alias, $join, $base, $link_point = NULL) {
    return $alias;
  }

  /**
   * Fake function required for taxonomy filters.
   */
  public function ensure_table($table, $relationship = NULL, $join = NULL) {
    return 'taxonomy';
  }

  /**
   * Add taxonomy filters to the query.
   */
  public function add_where($group, $field, $value = NULL, $operator = NULL) {
    if ($term = taxonomy_term_load($value)) {
      $term_wrapper = entity_metadata_wrapper('taxonomy_term', $term);
      $values = array();
      foreach ($term_wrapper->field_np_attr_machine_attributes as $field_wrapper) {
        $values[] = $field_wrapper->value();
      }
      $this->filter_taxonomy[] = $values;
    }
  }

  /**
   * Fake function required for taxonomy filters.
   */
  public function add_tag($tag) {}

  /**
   * Attach local data to the results.
   */
  public function add_local_data(&$ret, &$view) {
    $cache = &drupal_static(__METHOD__, array());
    if (isset($cache[$view->name])) {
      $ret = $cache[$view->name]['ret'];
      return;
    }

    $plant_ids = array();

    // Load all available plant attributes and bird types.
    $np_attr_voc = taxonomy_vocabulary_machine_name_load('native_plant_attributes');
    $np_bird_types_voc = taxonomy_vocabulary_machine_name_load('native_plant_bird_types');
    $np_attr_terms = taxonomy_get_tree($np_attr_voc->vid, 0, NULL, TRUE);
    $np_bird_types_terms = taxonomy_get_tree($np_bird_types_voc->vid, 0, NULL, TRUE);

    $np_attr_term_wrappers = array();
    $np_bird_types_term_wrappers = array();
    foreach ($np_attr_terms as $term) {
      $np_attr_term_wrappers[] = entity_metadata_wrapper('taxonomy_term', $term);
    }
    foreach ($np_bird_types_terms as $term) {
      $np_bird_types_term_wrappers[] = entity_metadata_wrapper('taxonomy_term', $term);
    }

    foreach ($ret as $result_key => &$result) {
      $plant_id = nas_master_native_plants_generate_plant_id(
        array(
          $result->ScientificName,
          $result->Family,
        )
      );
      $plant_ids[$result_key] = $plant_id;

      if ($cached_plant = cache_get('native_plants_' . $plant_id)) {
        $result = $cached_plant->data;
        continue;
      }

      $result->PlantID = $plant_id;

      // TODO: use rawurlencode() on the filename of the PlantImg URL.
      $result->PlantImg = str_replace(' ', '%20', $result->PlantImg);

      $result->Tier1 = FALSE;
      $result->Description = '';
      $result->Source = '';
      $result->LocalLink = '';
      $result->LocalPlantImg = '';

      // Assign plant attributes and bird types; and weight results based on
      // the lightest attribute.
      $result->Attributes = array();
      $result->BirdTypes = array();
      $result->Weight = 100;
      foreach ($np_attr_term_wrappers as $wrapper) {
        foreach ($wrapper->field_np_attr_machine_attributes as $field_wrapper) {
          $value = $field_wrapper->value();
          if ($result->$value == '1') {
            $result->Attributes[$wrapper->tid->value()] = array(
              'tid' => $wrapper->tid->value(),
              'name' => $wrapper->name->value(),
              'color' => $wrapper->field_np_attr_color->value(),
            );

            $weight = $wrapper->weight->value();
            if ($result->Weight > $weight) {
              $result->Weight = $weight;
            }
          }
        }
      }
      foreach ($np_bird_types_term_wrappers as $wrapper) {
        $link = $wrapper->field_link->value();
        if ($link) {
          $url = $link['url'];
        }
        else {
          $url = '';
        }
        foreach ($wrapper->field_np_attr_machine_attributes as $field_wrapper) {
          $value = $field_wrapper->value();
          if ($result->$value == '1') {
            $result->BirdTypes[$wrapper->tid->value()] = array(
              'tid' => $wrapper->tid->value(),
              'name' => $wrapper->name->value(),
              'image' => $wrapper->field_np_bird_type_image->value(),
              'url' => $url,
            );
          }
        }
      }

      cache_set('native_plants_' . $plant_id, $result, 'cache', CACHE_TEMPORARY);
    }

    if (empty($plant_ids)) {
      $cache[$view->name]['ret'] = $ret;
      return;
    }

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'native_plant')
      ->fieldCondition('field_native_plant_id', 'value', $plant_ids, 'IN');
    $results = $query->execute();
    if (!isset($results['node'])) {
      $cache[$view->name]['ret'] = $ret;
      return;
    }

    global $native_plants_zipcode;
    $user_state_code = _nas_master_native_plants_zipcode_to_state($native_plants_zipcode);

    foreach ($results['node'] as $node_info) {
      $local_node = node_load($node_info->nid);
      $local_node_wrapper = entity_metadata_wrapper('node', $local_node);

      $plant_id = $local_node_wrapper->field_native_plant_id->value();
      $result_key = array_search($plant_id, $plant_ids);
      if ($result_key !== FALSE && $local_node->status == NODE_PUBLISHED) {
        if ($image = $local_node_wrapper->field_image->value()) {
          $ret[$result_key]->LocalPlantImg = $image['uri'];
        }

        if ($local_node_wrapper->body->value()) {
          $description = $local_node_wrapper->body->value->value();
          $ret[$result_key]->Description = $description;
        }
        if ($source = $local_node_wrapper->field_native_plant_source->value()) {
          $ret[$result_key]->Source = l($source['title'], $source['url']);
        }

        // Check if this is Tier 1 result.
        if (!$local_node_wrapper->field_native_plant_tier1->value()) {
          continue;
        }
        // Check for Tier 1 states.
        $tier1_states = $local_node_wrapper->field_native_plant_tier1_states->value();
        if (!empty($tier1_states) && $user_state_code) {
          $tier1_state_codes = array();
          foreach ($tier1_states as $state_term) {
            $term_state_code = field_get_items('taxonomy_term', $state_term, 'field_iso_code');
            $tier1_state_codes[] = reset($term_state_code)['value'];
          }

          if (!in_array($user_state_code, $tier1_state_codes)) {
            continue;
          }
        }

        $ret[$result_key]->Tier1 = TRUE;
      }
    }

    // Sort the results according to weights and then common names inside the
    // same weight group.
    uasort($ret, function($a, $b) {
      return ($a->Weight - $b->Weight) ? ($a->Weight - $b->Weight) : strcmp($a->CommonName, $b->CommonName);
    });

    $cache[$view->name]['ret'] = $ret;
  }
}
