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
    return parent::parse($view, $data);
  }
}
