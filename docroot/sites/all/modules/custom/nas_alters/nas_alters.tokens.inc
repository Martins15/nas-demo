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
  $info['tokens']['node']['meta_twitter_photo'] = array(
    'name' => t('Photo for twitter metatag'),
    'description' => 'Photo for twitter metatag.',
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

  if ($type == 'node') {
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'meta_twitter_photo':
          if (!empty($data['node']->field_social_media_photo[LANGUAGE_NONE][0]['uri'])) {
            $uri = $data['node']->field_social_media_photo[LANGUAGE_NONE][0]['uri'];
            $style = 'social_media_photo';
          }
          elseif (!empty($data['node']->field_editorial_card_image[LANGUAGE_NONE][0]['uri'])) {
            $uri = $data['node']->field_editorial_card_image[LANGUAGE_NONE][0]['uri'];
            $style = 'hero_mobile';
          }
          elseif (!empty($data['node']->field_hero_image[LANGUAGE_NONE][0]['file']->uri)) {
            $uri = $data['node']->field_hero_image[LANGUAGE_NONE][0]['file']->uri;
            $style = 'hero_mobile';
          }
          if (!empty($uri) && !empty($style)) {
            $uri = nas_alters_local_image_uri($uri);
            $path = image_style_url($style, $uri);
            $replacements[$original] = $path;
          }
          break;
      }
    }
  }
  return $replacements;
}
