<?php

/**
 * @file
 * Views specific hooks for the NAS i18n Views module.
 */

/**
 * Implements hook_views_query_alter().
 */
function nas_i18n_views_views_query_alter(&$view, &$query) {
  if (in_array('localize', $query->options['query_tags'])) {
    global $language;
    $langcode = $language->language;
    $default_language = language_default();
    if ($langcode == $default_language->language) {
      $langcode = array($langcode, LANGUAGE_NONE);
    }

    $query->add_where(0, 'node.language', $langcode, is_array($langcode) ? 'IN' : '=');
  }
}
