<?php
/**
 * @file
 * Query plugin for nas_views_json_query.
 */

class nas_views_json_query_plugin_query_json extends views_json_query_plugin_query_json {
  function parse(&$view, $data) {
    $data->contents = json_decode($data->contents, FALSE);
    parent::parse($view, $data);
  }
}
