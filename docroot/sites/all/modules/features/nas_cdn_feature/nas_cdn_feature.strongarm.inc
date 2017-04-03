<?php
/**
 * @file
 * nas_cdn_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nas_cdn_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cdn_advanced_pid_file';
  $strongarm->value = '';
  $export['cdn_advanced_pid_file'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cdn_advanced_synced_files_db';
  $strongarm->value = '';
  $export['cdn_advanced_synced_files_db'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cdn_basic_mapping';
  $strongarm->value = 'http://d2fbmjy3x0sdua.cloudfront.net|.jpg .jpeg .gif .png .mp4 .mp3 .m4v .mov
';
  $export['cdn_basic_mapping'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cdn_basic_mapping_https';
  $strongarm->value = '';
  $export['cdn_basic_mapping_https'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cdn_exception_auth_users_blacklist';
  $strongarm->value = 'admin*
node/*/edit';
  $export['cdn_exception_auth_users_blacklist'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cdn_exception_drupal_path_blacklist';
  $strongarm->value = 'file/ajax/*
netx-scan-tree/*
crop/*
js/*';
  $export['cdn_exception_drupal_path_blacklist'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cdn_exception_file_path_blacklist';
  $strongarm->value = '';
  $export['cdn_exception_file_path_blacklist'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cdn_exception_file_path_whitelist';
  $strongarm->value = 'misc/*.js
modules/*.js';
  $export['cdn_exception_file_path_whitelist'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cdn_farfuture_status';
  $strongarm->value = 1;
  $export['cdn_farfuture_status'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cdn_farfuture_unique_identifier_mapping';
  $strongarm->value = 'misc/*:modules/*:themes/*|drupal_version
sites/*|mtime
sites/*|.avi .m4v .mov .mp4 .wmv .flv|perpetual';
  $export['cdn_farfuture_unique_identifier_mapping'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cdn_https_support';
  $strongarm->value = 1;
  $export['cdn_https_support'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cdn_mode';
  $strongarm->value = 'basic';
  $export['cdn_mode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cdn_reverse_proxy_test';
  $strongarm->value = FALSE;
  $export['cdn_reverse_proxy_test'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cdn_seo_redirect';
  $strongarm->value = 1;
  $export['cdn_seo_redirect'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cdn_seo_user_agents';
  $strongarm->value = 'Amazon Cloudfront
Akamai';
  $export['cdn_seo_user_agents'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cdn_stats';
  $strongarm->value = 0;
  $export['cdn_stats'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cdn_status';
  $strongarm->value = '2';
  $export['cdn_status'] = $strongarm;

  return $export;
}
