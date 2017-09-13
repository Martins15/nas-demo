<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Video Package Video Section'),
  'description' => t('Video Package Video Section for article'),
  'category' => 'Video package',
  'edit form' => 'video_package_video_section_form',
  'render callback' => 'video_package_video_section_render',
  'hook theme' => 'video_package_video_section_theme',
  'no title override' => TRUE,
  'defaults' => array(
    'title_long' => '',
    'title_short' => '',
    'hash' => '',
    'video' => 0,
    'video_credit' => '',
    'poster' => 0,
    'thumbnail_video' => 0,
    'thumbnail_poster' => 0,
    'title_position' => 'top',
    'title_offset' => '',
    'title_color' => '5087e9',
  ),
);

/**
 * An edit form for the pane's settings.
 */
function video_package_video_section_form($form, &$form_state) {
  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'video-package-video-section', 'nas_panes', 'plugins/content_types/video_package_video_section');

  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  $form['title_long'] = array(
    '#type' => 'textfield',
    '#title' => t('Section title'),
    '#description' => t('E.g. %example', array('%example' => '1: The crocodile hunter')),
    '#default_value' => $conf['title_long'],
  );

  $form['title_short'] = array(
    '#type' => 'textfield',
    '#title' => t('Section short title'),
    '#description' => t('E.g. %example', array('%example' => 'The Crock Doc')),
    '#default_value' => $conf['title_short'],
  );

  $form['title_color'] = array(
    '#type' => 'jquery_colorpicker',
    '#title' => t('Title color'),
    '#default_value' => !empty($conf['title_color']) ? $conf['title_color'] : '',
  );

  $form['hash'] = array(
    '#type' => 'textfield',
    '#title' => t('Section hash tag'),
    '#description' => t('E.g. %e1 or %e2. Please don\'t start tag from numbers, use lowercase letters, numbers and dashes', array(
      '%e1' => 'section-1',
      '%e2' => 'the-crock-doc',
    )),
    '#default_value' => $conf['hash'],
    '#required' => TRUE,
  );

  $form['video'] = array(
    '#type' => 'media',
    '#tree' => TRUE,
    '#title' => t('Video'),
    '#description' => t('Allowed formats: mp4.'),
    '#media_options' => array(
      'global' => array(
        'file_extensions' => 'mp4',
        'file_directory' => '',
        'types' => array('video'),
      ),
    ),
    '#default_value' => $conf['video'],
    '#required' => TRUE,
  );

  $form['video_credit'] = array(
    '#type' => 'textfield',
    '#title' => t('Video credit'),
    '#description' => t('Video credit text'),
    '#default_value' => !empty($conf['video_credit']) ? $conf['video_credit'] : '',
  );

  $form['poster'] = array(
    '#type' => 'media',
    '#tree' => TRUE,
    '#title' => t('Poster'),
    '#description' => t('Allowed formats: jpg, jpeg. The first frame of the video. No image style is applied, the dimensions of the image must match video dimensions'),
    '#media_options' => array(
      'global' => array(
        'file_extensions' => 'jpg jpeg',
        'max_filesize' => '20 MB',
        'file_directory' => '',
        'types' => array('image'),
      ),
    ),
    '#default_value' => $conf['poster'],
    '#required' => TRUE,
  );

  $form['thumbnail_video'] = array(
    '#type' => 'media',
    '#tree' => TRUE,
    '#title' => t('Thumbnail Video'),
    '#description' => t('Allowed formats: mp4. Use the main video scaled to 320px width'),
    '#media_options' => array(
      'global' => array(
        'file_extensions' => 'mp4',
        'file_directory' => '',
        'types' => array('video'),
      ),
    ),
    '#default_value' => $conf['thumbnail_video'],
  );

  $form['thumbnail_poster'] = array(
    '#type' => 'media',
    '#tree' => TRUE,
    '#title' => t('Thumbnail Poster'),
    '#description' => t('Allowed formats: jpg, jpeg. The first frame of the thumbnail video. No image style is applied, the dimensions of the image must match video dimensions'),
    '#media_options' => array(
      'global' => array(
        'file_extensions' => 'jpg jpeg',
        'max_filesize' => '20 MB',
        'file_directory' => '',
        'types' => array('image'),
      ),
    ),
    '#default_value' => $conf['thumbnail_poster'],
  );

  $form['title_position'] = array(
    '#type' => 'select',
    '#options' => array(
      'top' => t('Top'),
      'bottom' => t('Bottom'),
    ),
    '#title' => t('Title position'),
    '#default_value' => $conf['title_position'],
  );

  $form['title_offset'] = array(
    '#type' => 'textfield',
    '#title' => t('Title offset'),
    '#description' => t('This field works in pair with Title Position field'),
    '#default_value' => $conf['title_offset'],
  );
  $form['#attached']['css'][] = drupal_get_path('module', 'nas_panes') . '/plugins/content_types/frontpage_featured/css/colorpicker_overrides.css';
  $form['#attached']['css'][] = libraries_get_path('colorpicker') . '/css/colorpicker.css';

  return $form;
}

/**
 * Submit callback.
 */
function video_package_video_section_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (array_key_exists($key, $form_state['values'])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 *
 * See ctools_plugin_examples for more advanced info.
 */
function video_package_video_section_render($subtype, $conf, $args, $context) {
  $file = file_load($conf['poster']);
  $uri = nas_alters_local_image_uri($file->uri);
  $poster = file_create_url($uri);
  // Force stage file proxy download images.
  if (!file_exists($uri)) {
    $poster = image_style_url('slideshow', $uri);
  }

  $file = file_load($conf['video']);
  $video = file_create_url($file->uri);

  $thumbnail_poster = '';
  $thumbnail_video = '';

  if ($file = file_load($conf['thumbnail_poster'])) {
    $uri = nas_alters_local_image_uri($file->uri);
    $thumbnail_poster = file_create_url($uri);
    // Force stage file proxy download images.
    if (!file_exists($uri)) {
      $thumbnail_poster = image_style_url('slideshow', $uri);
    }
  }

  if ($file = file_load($conf['thumbnail_video'])) {
    $thumbnail_video = file_create_url($file->uri);
  }

  $top = $bottom = '';
  if ($conf['title_position'] == 'top') {
    $top = $conf['title_offset'];
  }
  elseif ($conf['title_position'] == 'bottom') {
    $bottom = $conf['title_offset'];
  }

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'video_package_video_section',
    '#poster' => $poster,
    '#video' => $video,
    '#video_credit' => !empty($conf['video_credit']) ? check_plain($conf['video_credit']) : '',
    '#thumbnail_poster' => $thumbnail_poster,
    '#thumbnail_video' => $thumbnail_video,
    '#title_short' => check_plain($conf['title_short']),
    '#title_long' => check_plain($conf['title_long']),
    '#title_color' => !empty($conf['title_color']) ? '#' . $conf['title_color'] : ' ',
    '#hash' => drupal_html_id($conf['hash']),
    '#top' => $top,
    '#bottom' => $bottom,
  );
  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function video_package_video_section_theme(&$theme, $plugin) {
  $theme['video_package_video_section'] = array(
    'variables' => array(
      'poster' => NULL,
      'video' => NULL,
      'video_credit' => NULL,
      'thumbnail_poster' => NULL,
      'thumbnail_video' => NULL,
      'title_short' => NULL,
      'title_long' => NULL,
      'title_color' => NULL,
      'hash' => NULL,
      'top' => NULL,
      'bottom' => NULL,
    ),
    'template' => 'video-package-video-section',
    'path' => $plugin['path'],
  );

}
