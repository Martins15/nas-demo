<?php
/**
 * @file
 * nas_amp_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nas_amp_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'amp_google_adsense_id';
  $strongarm->value = '';
  $export['amp_google_adsense_id'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'amp_google_analytics_id';
  $strongarm->value = 'UA-75708676-1';
  $export['amp_google_analytics_id'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'amp_google_doubleclick_id';
  $strongarm->value = '/';
  $export['amp_google_doubleclick_id'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'amp_library_process_full_html';
  $strongarm->value = 1;
  $export['amp_library_process_full_html'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'amp_library_process_full_html_warnings';
  $strongarm->value = 0;
  $export['amp_library_process_full_html_warnings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'amp_library_process_statistics';
  $strongarm->value = 0;
  $export['amp_library_process_statistics'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'amp_library_warnings_display';
  $strongarm->value = 0;
  $export['amp_library_warnings_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'amp_metadata_organization_logo';
  $strongarm->value = '';
  $export['amp_metadata_organization_logo'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'amp_metadata_organization_logo_image_style_id';
  $strongarm->value = 'amp_metadata_logo_600x60';
  $export['amp_metadata_organization_logo_image_style_id'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'amp_metadata_organization_name';
  $strongarm->value = '[site:name]';
  $export['amp_metadata_organization_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'amp_pixel';
  $strongarm->value = 0;
  $export['amp_pixel'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'amp_pixel_domain_name';
  $strongarm->value = '';
  $export['amp_pixel_domain_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'amp_pixel_query_string';
  $strongarm->value = '';
  $export['amp_pixel_query_string'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'amp_pixel_random_number';
  $strongarm->value = 0;
  $export['amp_pixel_random_number'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'amp_theme';
  $strongarm->value = 'nas_amp';
  $export['amp_theme'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panels_everywhere_override_theme_nas';
  $strongarm->value = 1;
  $export['panels_everywhere_override_theme_nas'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panels_everywhere_site_template_per_theme';
  $strongarm->value = 1;
  $export['panels_everywhere_site_template_per_theme'] = $strongarm;

  return $export;
}
