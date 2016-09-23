<?php
/**
 * @file
 * drupal_firewall_settings_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function drupal_firewall_settings_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dfw_token';
  $strongarm->value = array(
    'token_clear' => FALSE,
  );
  $export['dfw_token'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dfw_vars_cron';
  $strongarm->value = array(
    'acquia_agent' => FALSE,
    'acquia_purge' => FALSE,
    'acquia_spi' => FALSE,
    'captcha' => FALSE,
    'ctools' => FALSE,
    'feeds' => FALSE,
    'field' => FALSE,
    'ga_stats' => FALSE,
    'job_scheduler' => FALSE,
    'l10n_update' => FALSE,
    'nas_content_aggregation' => FALSE,
    'nas_pm_xmlsitemap' => FALSE,
    'node' => FALSE,
    'redirect' => FALSE,
    'scheduler' => FALSE,
    'search' => FALSE,
    'search_api' => FALSE,
    'search_api_acquia' => FALSE,
    'search_api_solr' => FALSE,
    'system' => FALSE,
    'views_bulk_operations' => FALSE,
    'xmlsitemap_menu' => FALSE,
    'xmlsitemap_node' => FALSE,
    'xmlsitemap_taxonomy' => FALSE,
    'xmlsitemap' => FALSE,
    'xmlsitemap_engines' => FALSE,
  );
  $export['dfw_vars_cron'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dfw_vars_field_update_forbid';
  $strongarm->value = array(
    'field_sql_storage' => FALSE,
    'list' => TRUE,
    'dfw_field_update_forbid' => FALSE,
  );
  $export['dfw_vars_field_update_forbid'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dfw_vars_menu';
  $strongarm->value = array(
    'strongarm' => FALSE,
    'i18n_variable' => FALSE,
    'uuid_features' => FALSE,
    'block' => FALSE,
    'webform' => FALSE,
    'acquia_agent' => FALSE,
    'acquia_purge' => FALSE,
    'acquia_search_multi_subs' => FALSE,
    'acquia_spi' => FALSE,
    'adbn_map' => FALSE,
    'adbn_sso' => FALSE,
    'adminimal_admin_menu' => FALSE,
    'ajax_screen_lock' => FALSE,
    'bean' => FALSE,
    'bean_admin_ui' => FALSE,
    'bean_wysiwyg' => FALSE,
    'bulk_export' => FALSE,
    'captcha' => FALSE,
    'colorbox' => FALSE,
    'composer_manager' => FALSE,
    'contact' => FALSE,
    'ctools' => FALSE,
    'date_api' => FALSE,
    'date_popup' => FALSE,
    'date_views' => FALSE,
    'deepzoom' => FALSE,
    'disqus' => FALSE,
    'eck' => FALSE,
    'email' => FALSE,
    'entity' => FALSE,
    'entityreference' => FALSE,
    'entityreference_autocomplete' => FALSE,
    'expire' => FALSE,
    'facetapi' => FALSE,
    'fb_instant_articles' => FALSE,
    'feeds' => FALSE,
    'feeds_ex' => FALSE,
    'feeds_tamper_ui' => FALSE,
    'feeds_ui' => FALSE,
    'fieldable_panels_panes' => FALSE,
    'field_collection' => FALSE,
    'field_ui' => FALSE,
    'file' => FALSE,
    'file_entity' => FALSE,
    'filter' => FALSE,
    'flipboardrss' => FALSE,
    'fpa' => FALSE,
    'ga_stats' => FALSE,
    'geocoder' => FALSE,
    'i18n_field' => FALSE,
    'i18n_node' => FALSE,
    'i18n_pc' => FALSE,
    'i18n_translation' => FALSE,
    'image' => FALSE,
    'imagecache_external' => FALSE,
    'jquery_colorpicker' => FALSE,
    'jquery_update' => FALSE,
    'l10n_update' => FALSE,
    'locale' => FALSE,
    'location' => FALSE,
    'mailsystem' => FALSE,
    'mandrill' => FALSE,
    'media' => FALSE,
    'media_internet' => FALSE,
    'media_wysiwyg' => FALSE,
    'menu' => FALSE,
    'metatag' => FALSE,
    'mimemail' => FALSE,
    'module_filter' => FALSE,
    'nas_boa_plates' => FALSE,
    'nas_content_aggregation' => FALSE,
    'nas_events' => FALSE,
    'nas_export_birds' => FALSE,
    'nas_import' => FALSE,
    'nas_master_native_plants' => FALSE,
    'nas_near_you' => FALSE,
    'nas_page_scheduler' => FALSE,
    'nas_panes' => FALSE,
    'node' => FALSE,
    'nodequeue' => FALSE,
    'panels' => FALSE,
    'panels_everywhere' => FALSE,
    'pasteformat' => FALSE,
    'path' => FALSE,
    'protected_pages' => FALSE,
    'recaptcha' => FALSE,
    'redirect' => FALSE,
    'remote_stream_wrapper' => FALSE,
    'scheduler' => FALSE,
    'search' => FALSE,
    'search_api' => FALSE,
    'search_api_facetapi' => FALSE,
    'search_api_solr' => FALSE,
    'seckit' => FALSE,
    'securepages' => FALSE,
    'smtp' => FALSE,
    'soundmanager2' => FALSE,
    'staticmap' => FALSE,
    'system' => FALSE,
    'taxonomy' => FALSE,
    'token' => FALSE,
    'translation' => FALSE,
    'transliteration' => FALSE,
    'user' => FALSE,
    'uuid' => FALSE,
    'views_content' => FALSE,
    'views_ui' => FALSE,
    'wysiwyg' => FALSE,
    'field_group' => FALSE,
    'pathauto' => FALSE,
    'xmlsitemap' => FALSE,
    'xmlsitemap_engines' => FALSE,
    'auto_entitylabel' => FALSE,
    'i18n_menu' => FALSE,
    'i18n_taxonomy' => FALSE,
    'bigmenu' => FALSE,
    'epsacrop' => FALSE,
    'i18n' => FALSE,
    'i18n_string' => FALSE,
    'views' => FALSE,
    'entity_translation' => FALSE,
    'pp_crop' => FALSE,
    'features' => FALSE,
    'panelizer' => FALSE,
    'devel' => FALSE,
    'page_manager' => FALSE,
    'admin_menu' => FALSE,
    'better_formats' => FALSE,
    'title' => FALSE,
    'lazyloader' => FALSE,
  );
  $export['dfw_vars_menu'] = $strongarm;

  return $export;
}
