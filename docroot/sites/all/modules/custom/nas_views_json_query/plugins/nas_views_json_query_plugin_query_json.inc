<?php
/**
 * @file
 * Query plugin for nas_views_json_query.
 */

class nas_views_json_query_plugin_query_json extends views_json_query_plugin_query_json {
  /**
   * Fetch file.
   */
  function fetch_file($uri) {
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
