<?php

/**
 * @file
 * Contains token definitions.
 */

/**
 * Implements hook_token_info().
 */
function nas_alters_token_info() {
  $info['tokens']['current-page']['encoded-url'] = array(
    'name' => t('Encoded URL'),
    'description' => t('Encoded URL of the current page.'),
  );

  return $info;
}

/**
 * Implements hook_tokens().
 */
function nas_alters_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();

  $url_options = array('absolute' => TRUE);
  if (isset($options['language'])) {
    $url_options['language'] = $options['language'];
  }

  if ($type == 'current-page') {
    $current_path = current_path();
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'encoded-url':
          $replacements[$original] = urlencode(url($current_path, $url_options));
          break;
      }
    }
  }

  return $replacements;
}
