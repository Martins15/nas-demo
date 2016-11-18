<?php
/**
 * @file
 * nas_netx_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nas_netx_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'netx_authentication_type';
  $strongarm->value = 'call';
  $export['netx_authentication_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'netx_cookie';
  $strongarm->value = 'JSESSIONID=0DFC270B5C8B146DFEEA28C53CBAF754.audubon; Path=/; Secure; HttpOnly';
  $export['netx_cookie'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'netx_cron_amount';
  $strongarm->value = '10';
  $export['netx_cron_amount'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'netx_cron_threshold';
  $strongarm->value = '10800';
  $export['netx_cron_threshold'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'netx_cron_threshold_attributes';
  $strongarm->value = '10800';
  $export['netx_cron_threshold_attributes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'netx_cron_threshold_categories';
  $strongarm->value = '10800';
  $export['netx_cron_threshold_categories'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'netx_log_requests';
  $strongarm->value = 1;
  $export['netx_log_requests'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'netx_pass';
  $strongarm->value = 'zbnjV2nm';
  $export['netx_pass'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'netx_server';
  $strongarm->value = 'audubon.netx.net';
  $export['netx_server'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'netx_upload_category';
  $strongarm->value = 'Photos';
  $export['netx_upload_category'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'netx_user';
  $strongarm->value = 'asc';
  $export['netx_user'] = $strongarm;

  return $export;
}
