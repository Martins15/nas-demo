<?php

/**
 * @file
 * Define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Big Social Owl block'),
  'category' => 'Basic Modules',
  'edit form' => 'big_social_owl_block_form',
  'render callback' => 'big_social_owl_block_render',
  'no title override' => TRUE,
  'hook theme' => 'big_social_owl_block_theme',
  'defaults' => array(
    'left_link' => array(
      'social_icon' => '',
      'social_link_text' => '',
      'social_link_url' => '',
    ),
    'center_image' => array(
      'image_type' => 'owl',
      'custom_image' => 0,
    ),
    'right_link' => array(
      'social_icon' => '',
      'social_link_text' => '',
      'social_link_url' => '',
    ),
    'styles' => array(
      'padding' => array(
        'top' => 'top',
        'bottom' => 'bottom',
      ),
    ),
  ),
  'tags' => array('full_width'),
);

/**
 * An edit form for the pane's settings.
 */
function big_social_owl_block_form($form, &$form_state) {
  $conf = $form_state['conf'];
  // The two function calls below are necessary if we want to use a media
  // element type, because it causes ajax requests, which in turn call
  // drupal_form_rebuild(), and without the below includes, Drupal will
  // not be able to rebuild the form.

  // Include the CTools content type plugin file, because it provides
  // the ctools_content_configure_form_defaults() function, which is needed
  // when rebuilding the form, because of an ajax action, like selecting
  // a media element.
  ctools_form_include($form_state, 'content');

  // Include this plugin file as well, so that when the form is rebuilt, it
  // can successfully retrieve the settings form.
  ctools_form_include($form_state, 'big_social_owl_block', 'nas_panes', 'plugins/content_types/big_social_owl_block');

  $icon_types = array(
    'facebook' => t('Facebook'),
    'twitter' => t('Twitter'),
    'mail' => t('Email'),
    'pinterest' => t('Pinterest'),
    'instagram' => t('Instagram'),
  );

  $form['left_link'] = array(
    '#type' => 'fieldset',
    '#title' => t('Left social link'),
    '#tree' => TRUE,
  );
  $form['left_link']['social_icon'] = array(
    '#type' => 'select',
    '#title' => t('Social icon'),
    '#options' => $icon_types,
    '#default_value' => $conf['left_link']['social_icon'],
  );
  $form['left_link']['social_link_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Link text'),
    '#default_value' => $conf['left_link']['social_link_text'],
  );
  $form['left_link']['social_link_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Link url'),
    '#default_value' => $conf['left_link']['social_link_url'],
  );

  $form['center_image'] = array(
    '#type' => 'fieldset',
    '#title' => t('Center image'),
    '#tree' => TRUE,
  );
  $form['center_image']['image_type'] = array(
    '#type' => 'radios',
    '#title' => t('Type of image'),
    '#options' => array(
      'owl' => t('Owl'),
      'custom' => t('Custom'),
    ),
    '#default_value' => $conf['center_image']['image_type'],
  );

  $form['center_image']['custom_image'] = array(
    '#type' => 'media',
    '#tree' => TRUE,
    '#title' => t('Custom image'),
    '#description' => t('Click "Browse" to locate the file on your computer or in the site\'s File Library.'),
    '#media_options' => array(
      'global' => array(
        'file_extensions' => 'png',
        'max_filesize' => '20 MB',
        'file_directory' => 'big_social_images',
        'min_resolution' => '328x248',
        'types' => array('image'),
        'allowed_schemes' => array(
          'public' => 'public',
        ),
      ),
    ),
    '#default_value' => $conf['center_image']['custom_image'],
    '#required' => FALSE,
    '#pp_crop_styles' => array('social_owl_image'),
    '#states' => array(
      'visible' => array(
        ':input[name="center_image[image_type]"]' => array(
          'value' => 'custom',
        ),
      ),
    ),
  );

  $form['right_link'] = array(
    '#type' => 'fieldset',
    '#title' => t('Right social link'),
    '#tree' => TRUE,
  );
  $form['right_link']['social_icon'] = array(
    '#type' => 'select',
    '#title' => t('Social icon'),
    '#options' => $icon_types,
    '#default_value' => $conf['right_link']['social_icon'],
  );
  $form['right_link']['social_link_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Link text'),
    '#default_value' => $conf['right_link']['social_link_text'],
  );
  $form['right_link']['social_link_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Link url'),
    '#default_value' => $conf['right_link']['social_link_url'],
  );
  $form['styles'] = array(
    '#type' => 'fieldset',
    '#title' => t('Styles'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );
  $form['styles']['padding'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Padding'),
    '#options' => array(
      'top' => t('Top padding'),
      'bottom' => t('Bottom padding'),
    ),
    '#default_value' => $conf['styles']['padding'],
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function big_social_owl_block_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 *
 * @see ctools_plugin_examples()
 */
function big_social_owl_block_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();
  $image_src = url(drupal_get_path('theme', 'nas') . '/img/owl-head.png');
  $image = file_load($conf['center_image']['custom_image']);
  if (!empty($image)) {
    $image_src = image_style_url('social_owl_image', nas_alters_local_image_uri($image->uri));
  }

  $block->content = theme('big_social_owl_block', array(
    'left_icon_type' => $conf['left_link']['social_icon'],
    'left_text' => $conf['left_link']['social_link_text'],
    'left_url' => $conf['left_link']['social_link_url'],
    'image_src' => $image_src,
    'right_icon_type' => $conf['right_link']['social_icon'],
    'right_text' => $conf['right_link']['social_link_text'],
    'right_url' => $conf['right_link']['social_link_url'],
    'space_top' => isset($conf['styles']['padding']['top']) ? $conf['styles']['padding']['top'] : 'top',
    'space_bottom' => isset($conf['styles']['padding']['bottom']) ? $conf['styles']['padding']['bottom'] : 'bottom',
  ));

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function big_social_owl_block_theme(&$theme, $plugin) {
  $theme['big_social_owl_block'] = array(
    'variables' => array(
      'left_icon_type' => '',
      'left_text' => '',
      'left_url' => '',
      'image_src' => '',
      'right_icon_type' => '',
      'right_text' => '',
      'right_url' => '',
      'space_top' => '',
      'space_bottom' => '',
    ),
    'template' => 'big-social-owl-block',
    'path' => $plugin['path'],
  );
}
