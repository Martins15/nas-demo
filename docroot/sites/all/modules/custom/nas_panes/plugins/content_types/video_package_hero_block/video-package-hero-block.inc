<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Video Package Hero block'),
  'description' => t('Video Package hero block for article'),
  'category' => 'Video package',
  'edit form' => 'video_package_hero_block_form',
  'render callback' => 'video_package_hero_block_render',
  'hook theme' => 'video_package_hero_block_theme',
);

/**
 * An edit form for the pane's settings.
 */
function video_package_hero_block_form($form, &$form_state) {
  // Hide title the pane.
  _nas_panes_hide_pane_title_field($form);

  // Include the CTools content type plugin file, because it provides
  // the ctools_content_configure_form_defaults() function, which is needed
  // when rebuilding the form, because of an ajax action, like selecting
  // a media element.
  ctools_form_include($form_state, 'content');

  // Include this plugin file as well, so that when the form is rebuilt, it
  // can successfully retrieve the settings form.
  ctools_form_include($form_state, 'video-package-hero-block', 'nas_panes', 'plugins/content_types/video_package_hero_block');

  $conf = $form_state['conf'];

  $form['title_long'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#description' => t('E.g. %example', array('%example' => '1: The crocodile hunter')),
    '#default_value' => !empty($conf['title_long']) ? $conf['title_long'] : '',
  );

  $form['image'] = array(
    '#type' => 'media',
    '#tree' => TRUE,
    '#title' => t('Image'),
    '#description' => t('Allowed formats: jpg, jpeg. Used for mobile devices.'),
    '#media_options' => array(
      'global' => array(
        'file_extensions' => 'jpg jpeg',
        'max_filesize' => '20 MB',
        'file_directory' => '',
        'types' => array('image'),
      ),
    ),
    '#default_value' => !empty($conf['image']) ? $conf['image'] : 0,
    '#pp_crop_styles' => array('featured_frontpage'),
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
    '#default_value' => !empty($conf['video']) ? $conf['video'] : 0,
  );

  $form['title_position'] = array(
    '#type' => 'select',
    '#options' => array(
      'top' => t('Top'),
      'bottom' => t('Bottom'),
    ),
    '#title' => t('Title position'),
    '#default_value' => !empty($conf['title_position']) ? $conf['title_position'] : 'top',
  );

  $form['title_offset'] = array(
    '#type' => 'textfield',
    '#title' => t('Title offset'),
    '#description' => t('This field works in pair with Title Position field'),
    '#default_value' => !empty($conf['title_offset']) ? $conf['title_offset'] : NULL,
  );

  return $form;
}

/**
 * Submit callback.
 */
function video_package_hero_block_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 */
function video_package_hero_block_render($subtype, $conf, $args, $context) {

  $image = '';
  if (!empty($conf['image'])) {
    $file = file_load($conf['image']);
    $uri = nas_alters_local_image_uri($file->uri);
    $image = image_style_url('hero_image', $uri);
  }

  $file = file_load($conf['video']);
  $video = file_create_url($file->uri);

  $path = drupal_get_path('theme', 'nas') . '/prototypes/video-page-2/';

  $top = $bottom = '';
  if (!empty($conf['title_offset']) && !empty($conf['title_position'])) {
    if ($conf['title_position'] == 'top') {
      $top = $conf['title_offset'];
    }
    elseif ($conf['title_position'] == 'bottom') {
      $bottom = $conf['title_offset'];
    }
  }

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'video_package_hero_block',
    '#image' => $image,
    '#video' => $video,
    '#title_long' => check_plain($conf['title_long']),
    '#top' => $top,
    '#bottom' => $bottom,
    '#attached' => array(
      'js' => array(
        $path . 'vendor/slick.js' => array(
          'type' => 'file',
          'group' => JS_LIBRARY,
        ),
        $path . 'vendor/jquery.waypoints.min.js' => array(
          'type' => 'file',
          'group' => JS_LIBRARY,
        ),
        $path . 'vendor/inview.min.js' => array(
          'type' => 'file',
          'group' => JS_LIBRARY,
        ),
        $path . 'vendor/sticky.min.js' => array(
          'type' => 'file',
          'group' => JS_LIBRARY,
        ),
        $path . 'video-package-auto.js' => array(
          'type' => 'file',
          'group' => JS_THEME,
        ),
      ),
      'css' => array(
        $path . 'vendor/slick.css',
      ),
    ),
  );
  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function video_package_hero_block_theme(&$theme, $plugin) {
  $theme['video_package_hero_block'] = array(
    'variables' => array(
      'title_long' => NULL,
      'image' => NULL,
      'video' => NULL,
      'top' => NULL,
      'bottom' => NULL,
    ),
    'template' => 'video-package-hero-block',
    'path' => $plugin['path'],
  );
}
