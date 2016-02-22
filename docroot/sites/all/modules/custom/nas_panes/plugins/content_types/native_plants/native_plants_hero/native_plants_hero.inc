<?php
/**
 * @file
 * Native Plants hero image plugin.
 */

$plugin = array(
  'title' => t('Native Plants hero image'),
  'description' => t('Native Plants hero image.'),
  'category' => 'Native Plants',
  'admin info' => 'native_plants_hero_admin_info',
  'edit form' => 'native_plants_hero_edit_form',
  'render callback' => 'native_plants_hero_render',
  'hook theme' => 'native_plants_hero_theme',
  'no title override' => TRUE,
  'defaults' => array(
    'title_desktop' => 'When you plant native plants, you help birds and the environment.',
    'title_mobile' => 'When you plant native plants, you help birds and the environment.',
    'title_mobile_shift' => 0,
    'image' => 0,
    'color_scheme' => 'dark',
    'dark_gradient' => 1,
  ),
);

/**
 * Administrative info callback.
 */
function native_plants_hero_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = $conf['title'];
  $block->content = $conf['title'];
  return $block;
}

/**
 * Configuration form.
 */
function native_plants_hero_edit_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'native_plants_hero', 'nas_panes', 'plugins/content_types/native_plants/native_plants_hero');

  $form['override_title_heading']['#access'] = FALSE;
  $form['image'] = array(
    '#type' => 'media',
    '#tree' => TRUE,
    '#title' => t('Hero Image'),
    '#description' => t('Allowed formats: png, jpg, jpeg, gif.'),
    '#media_options' => array(
      'global' => array(
        'file_extensions' => 'png jpg jpeg gif',
        'max_filesize' => '20 MB',
        'file_directory' => '',
        'types' => array('image'),
      ),
    ),
    '#default_value' => $conf['image'],
  );

  $form['title_desktop'] = array(
    '#type' => 'textfield',
    '#title' => t('Desktop title'),
    '#default_value' => $conf['title_desktop'],
  );
  $form['title_mobile'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobile title'),
    '#default_value' => $conf['title_mobile'],
  );
  $form['title_mobile_shift'] = array(
    '#type' => 'checkbox',
    '#title' => t('Place mobile title beneath Hero image'),
    '#default_value' => $conf['title_mobile_shift'],
  );
  $form['color_scheme'] = array(
    '#type' => 'radios',
    '#title' => t('Color Scheme'),
    '#options' => array(
      'dark' => t('Dark image/Light text'),
      'light' => t('Light image/Dark text'),
    ),
    '#default_value' => $conf['color_scheme'],
  );
  $form['dark_gradient'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add dark gradient at the bottom of Hero image'),
    '#default_value' => $conf['dark_gradient'],
    '#states' => array(
      'visible' => array(
        '#edit-color-scheme-dark' => array('checked' => TRUE),
      ),
    ),
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function native_plants_hero_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (array_key_exists($key, $form_state['values'])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }

  // Form build ID is required for contextual links.
  $form_state['conf']['form_build_id'] = $form_state['values']['form_build_id'];
}

/**
 * Render callback.
 */
function native_plants_hero_render($subtype, $conf, $args, $context) {
  // $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $context);

  $image_path = file_create_url('sites/all/themes/custom/nas/img/plants-background.jpg');
  $image_attribution = '';
  if ($image = file_load($conf['image'])) {
    $image_path = image_style_url('hero_image', $image->uri);
    $image_attribution = _nas_panes_format_image_attribution($image);
  }

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'native_plants_hero',
    '#title_desktop' => t(filter_xss($conf['title_desktop'])),
    '#title_mobile' => t(filter_xss($conf['title_mobile'])),
    '#title_mobile_shift' => $conf['title_mobile_shift'],
    '#color_scheme' => $conf['color_scheme'],
    '#dark_gradient' => $conf['dark_gradient'],
    '#image_path' => $image_path,
    '#image_attribution' => $image_attribution,
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function native_plants_hero_theme(&$theme, $plugin) {
  $theme['native_plants_hero'] = array(
    'variables' => array(
      'title_desktop' => '',
      'title_mobile' => '',
      'title_mobile_shift' => '',
      'image_path' => '',
      'image_attribution' => '',
      'color_scheme' => '',
      'dark_gradient' => '',
    ),
    'template' => 'native-plants-hero',
    'path' => $plugin['path'],
  );
}

/**
 * Preprocess function.
 */
function nas_panes_preprocess_native_plants_hero(&$variables) {
  switch ($variables['color_scheme']) {
    case 'dark':
      $variables['classes_array'][] = 'light-text';
      if ($variables['dark_gradient']) {
        $variables['classes_array'][] = 'dark-gradient-bottom';
      }
      break;

    case 'light':
      $variables['classes_array'][] = 'dark-text';
      break;
  }
}
