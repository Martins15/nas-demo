<?php

/**
 * @file
 * Query plugin for nasnp_views_json_query.
 */

// @codingStandardsIgnoreStart
/**
 * Class nasnp_views_json_query_plugin_query_json.
 */
class nasnp_views_json_query_plugin_query_json extends views_json_query_plugin_query_json {

  /**
   * {@inheritdoc}
   */
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
          $this->zipcode = $this->filter[$key]->value;
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
    $cache_file = 'views_json_query_' . md5($uri);

    $tmp_cache_dest = 'temporary://views_json_query';
    $tmp_cache_file_uri = $tmp_cache_dest . '/' . $cache_file;

    if (file_exists($tmp_cache_file_uri)) {
      return file_get_contents($tmp_cache_file_uri);
    }

    if (!file_prepare_directory($tmp_cache_dest, FILE_CREATE_DIRECTORY |
      FILE_MODIFY_PERMISSIONS)) {
      throw new Exception(
        t('Files directory either cannot be created or is not writable.')
      );
    }

    $pub_cache_file_uri = 'public://views_json_query/' . $cache_file;
    if ($output = file_exists($pub_cache_file_uri) ? file_get_contents($pub_cache_file_uri) : parent::fetch_file($uri)) {
      file_unmanaged_save_data($output, $tmp_cache_file_uri, FILE_EXISTS_REPLACE);
    }

    return $output;
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

    // Sort the results according to weights and then common names inside the
    // same weight group if results are not filtered, alphabetically otherwise.
    $filtered = isset($this->filter_taxonomy);
    uasort($ret, function($a, $b) use ($filtered) {
      if ($filtered) {
        return strcmp($a->CommonName, $b->CommonName);
      }
      return ($a->Weight - $b->Weight) ? ($a->Weight - $b->Weight) : strcmp($a->CommonName, $b->CommonName);
    });

    // Check if we should return Tier 1 results - find only Tier1 results.
    if ($view->current_display == 'native_plants_search_pane_tier1') {
      $ret = array_filter($ret, function ($result) {
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
    $static_cache = &drupal_static(__METHOD__, array());
    if (isset($static_cache[$view->name])) {
      $ret = $static_cache[$view->name];
      return;
    }

    $plant_ids = array();

    // Load all available plant attributes and bird types.
    $np_attr_voc = taxonomy_vocabulary_machine_name_load('native_plant_attributes');
    $np_res_voc = taxonomy_vocabulary_machine_name_load('native_plant_resources');
    $np_bird_types_voc = taxonomy_vocabulary_machine_name_load('native_plant_bird_types');
    $np_attr_terms = taxonomy_get_tree($np_attr_voc->vid, 0, NULL, TRUE);
    $np_res_terms = taxonomy_get_tree($np_res_voc->vid, 0, NULL, TRUE);
    $np_bird_types_terms = taxonomy_get_tree($np_bird_types_voc->vid, 0, NULL, TRUE);
    $np_attr_term_wrappers = array();
    $np_res_term_wrappers = array();
    $np_bird_types_term_wrappers = array();
    foreach ($np_attr_terms as $term) {
      $np_attr_term_wrappers[] = entity_metadata_wrapper('taxonomy_term', $term);
    }
    foreach ($np_res_terms as $term) {
      $np_res_term_wrappers[] = entity_metadata_wrapper('taxonomy_term', $term);
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

      if ($cached_plant = cache_get('native_plants_' . $plant_id)) {
        $result = $cached_plant->data;
        continue;
      }

      $plant_ids[$result_key] = $plant_id;
      $result->PlantID = $plant_id;

      // TODO: use rawurlencode() on the filename of the PlantImg URL.
      $result->PlantImg = str_replace(' ', '%20', $result->PlantImg);

      $result->Tier1 = FALSE;
      $result->Tier1StateCodes = array();
      $result->Description = '';
      $result->Source = '';
      $result->LocalLink = '';
      $result->PlantImgLocal = '';

      $result->LocalLink = url('nas_master_native_plants/native_plant_create', array(
        'query' => array(
          'CommonName' => $result->CommonName,
          'ScientificName' => $result->ScientificName,
          'Family' => $result->Family,
          'PlantID' => $result->PlantID,
          'PlantImg' => $result->PlantImg,
        ),
      ));

      // Assign plant attributes and bird types; and weight results based on
      // the lightest attribute.
      $result->Attributes = array();
      $result->Resources = array();
      $result->BirdTypes = array();
      $result->Weight = 100;
      foreach ($np_attr_term_wrappers as $wrapper) {
        foreach ($wrapper->field_np_attr_machine_attributes as $field_wrapper) {
          $value = $field_wrapper->value();
          if (property_exists($result, $value) && $result->$value == '1') {
            $result->Attributes[] = $wrapper->tid->value();

            $weight = $wrapper->weight->value();
            if ($result->Weight > $weight) {
              $result->Weight = $weight;
            }
          }
        }
      }
      $result->Attributes = array_values(array_unique($result->Attributes));
      foreach ($np_res_term_wrappers as $wrapper) {
        foreach ($wrapper->field_np_attr_machine_attributes as $field_wrapper) {
          $value = $field_wrapper->value();
          if (property_exists($result, $value) && $result->$value == '1') {
            $result->Resources[] = $wrapper->tid->value();
          }
        }
      }
      $result->Resources = array_values(array_unique($result->Resources));
      foreach ($np_bird_types_term_wrappers as $wrapper) {
        foreach ($wrapper->field_np_attr_machine_attributes as $field_wrapper) {
          $value = $field_wrapper->value();
          if (property_exists($result, $value) && $result->$value == '1') {
            $result->BirdTypes[] = $wrapper->tid->value();
          }
        }
      }
      $result->BirdTypes = array_values(array_unique($result->BirdTypes));
      $result->BirdTypesRandomized = $result->BirdTypes;
      shuffle($result->BirdTypesRandomized);
    }

    if (!empty($plant_ids)) {
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'native_plant')
        ->fieldCondition('field_native_plant_id', 'value', $plant_ids, 'IN');
      $results = $query->execute();
      if (!isset($results['node'])) {
        $results['node'] = array();
      }

      foreach ($results['node'] as $node_info) {
        $local_node = node_load($node_info->nid);
        $local_node_wrapper = entity_metadata_wrapper('node', $local_node);

        $plant_id = $local_node_wrapper->field_native_plant_id->value();
        $result_key = array_search($plant_id, $plant_ids);
        if ($result_key !== FALSE && $local_node->status == NODE_PUBLISHED) {
          if ($image = $local_node_wrapper->field_image->value()) {
            $file_object = file_load($image['fid']);
            $ret[$result_key]->PlantImgLocal = array(
              'uri' => $image['uri'],
              'attribution' => _nas_panes_format_image_attribution($file_object),
            );
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
          $ret[$result_key]->Tier1 = TRUE;
          // Check for Tier 1 states.
          $tier1_states = $local_node_wrapper->field_native_plant_tier1_states->value();
          if (!empty($tier1_states)) {
            $tier1_state_codes = array();
            foreach ($tier1_states as $state_term) {
              $term_state_code = field_get_items('taxonomy_term', $state_term, 'field_iso_code');
              $tier1_state_codes[] = reset($term_state_code)['value'];
            }
            $ret[$result_key]->Tier1StateCodes = $tier1_state_codes;
          }
        }
      }

      // Prepare images.
      foreach ($ret as $result_key => &$result) {
        $result->PlantImgDesktop = '';
        $result->PlantImgMobile = '';
        $result->PlantImgLightbox = '';
        if ($result->PlantImgLocal) {
          $result->PlantImgDesktop = theme('image_style', array(
            'path' => nas_alters_local_image_uri($result->PlantImgLocal['uri']),
            'style_name' => 'native_plant_desktop',
            'alt' => $result->CommonName,
            'attributes' => array(
              'data-caption' => $result->PlantImgLocal['attribution'],
            ),
          ));
          $result->PlantImgMobile = theme('image_style', array(
            'path' => nas_alters_local_image_uri($result->PlantImgLocal['uri']),
            'style_name' => 'native_plant_mobile',
            'alt' => $result->CommonName,
          ));
          $result->PlantImgLightbox = image_style_url('native_plant_lightbox', nas_alters_local_image_uri($result->PlantImgLocal['uri']));
        }
        elseif ($result->PlantImg) {
          $params = array(
            'path' => $result->PlantImg,
            'style_name' => 'native_plant_desktop',
            'alt' => $result->CommonName,
          );
          if ($attribution = nas_master_native_plants_get_image_attributions_by_plantid($result->PlantID)) {
            $params['attributes'] = array(
              'data-caption' => $attribution,
            );
          }
          $result->PlantImgDesktop = theme('imagecache_external', $params);
          $result->PlantImgMobile = theme('imagecache_external', array(
            'path' => $result->PlantImg,
            'style_name' => 'native_plant_mobile',
            'alt' => $result->CommonName,
          ));
          if ($path = imagecache_external_generate_path($result->PlantImg)) {
            $result->PlantImgLightbox = image_style_url('native_plant_lightbox', $path);
          }
        }
      }

      // Clean-up and set cached values for plants.
      foreach ($ret as $result_key => &$result) {
        $unset_keys = array(
          'ButterflyPlant',
          'ButterflyTallamyPlant',
          'Duration',
          'Evergreen',
          'FleshyFruits',
          'Forbs',
          'FruitVegetation',
          'GrassGrasslike',
          'HummingBirdNectar',
          'Nuts',
          'NutsSeeds',
          'Seeds',
          'Shrub',
          'Succulent',
          'Tree',
          'Vegetation',
          'Vine',
        );
        foreach ($unset_keys as $key) {
          unset($result->$key);
        }
        cache_set('native_plants_' . $result->PlantID, $result, 'cache', CACHE_TEMPORARY);
      }
    }

    // Check Tier 1 plants by user state code.
    $user_state_code = _nas_master_native_plants_zipcode_to_state($this->zipcode);
    if (!empty($user_state_code)) {
      foreach ($ret as &$result) {
        if ($result->Tier1 && !empty($result->Tier1StateCodes)) {
          if (!in_array($user_state_code, $result->Tier1StateCodes)) {
            $result->Tier1 = FALSE;
          }
        }
      }
    }

    $static_cache[$view->name] = $ret;
  }

}
// @codingStandardsIgnoreEnd
