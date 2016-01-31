<?php
/**
 * @file
 * Query plugin for nasnp_views_json_query.
 */

class nasnp_views_json_query_plugin_query_json extends views_json_query_plugin_query_json {
  function query($get_count = FALSE) {
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
  function fetch_file($uri) {
    if (isset($this->filter)) {
      foreach ($this->filter as $key => $filter) {
        if ($filter->options['key'] == 'zipcode') {
          $uri = str_replace('zipcode', $filter->value, $uri);
          unset($this->filter[$key]);
        }
      }
    }
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
  function parse(&$view, $data) {
    $data->contents = json_decode($data->contents, FALSE);
    parent::parse($view, $data);
  }
}
