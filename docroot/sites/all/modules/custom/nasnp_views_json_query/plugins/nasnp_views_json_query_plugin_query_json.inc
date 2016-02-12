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
    // Do not process if there was no request.
    if ($decode === '') {
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
      if (!$check) {
        unset($ret[$k]);
      }
    }

    // MODIFICATIONS: Add local data to the results.
    $this->add_local_data($ret, $view);

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
   * Attach local data to the results.
   */
  public function add_local_data(&$ret, &$view) {
    $plant_ids = array();
    $view->result_tier1 = array();

    foreach ($ret as $result_key => &$result) {
      $plant_id = nas_master_native_plants_generate_plant_id(
        array(
          $result->ScientificName,
          $result->Family,
        )
      );
      $result->PlantID = $plant_id;
      $plant_ids[$result_key] = $plant_id;

      $result->Tier1 = FALSE;
      $result->Description = '';
      $result->LocalLink = 'node/add/native-plant?edit[title]=' . $result->CommonName
        . '&edit[field_native_plant_common_name][und][0][value]=' . $result->CommonName
        . '&edit[field_np_scientific_name][und][0][value]=' . $result->ScientificName
        . '&edit[field_native_plant_family][und][0][value]=' . $result->Family;
    }
    if (empty($plant_ids)) {
      return;
    }

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'native_plant')
      ->fieldCondition('field_native_plant_id', 'value', $plant_ids, 'IN');
    $results = $query->execute();
    if (!isset($results['node'])) {
      return;
    }

    foreach ($results['node'] as $node_info) {
      $local_node = node_load($node_info->nid);
      $local_node_wrapper = entity_metadata_wrapper('node', $local_node);

      $plant_id = $local_node_wrapper->field_native_plant_id->value();
      $result_key = array_search($plant_id, $plant_ids);
      if ($result_key !== FALSE) {
        $ret[$result_key]->LocalLink = 'node/' . $node_info->nid . '/edit';
        // Do not add info from not published nodes.
        if ($local_node->status == NODE_NOT_PUBLISHED) {
          continue;
        }

        $ret[$result_key]->Tier1 = TRUE;
        if ($local_node_wrapper->body->value()) {
          $description = $local_node_wrapper->body->value->value();
          $ret[$result_key]->Description = $description;
        }

        // Move this result to Tier1 results.
        $view->result_tier1[] = $ret[$result_key];
        unset($ret[$result_key]);
      }
    }
  }
}
