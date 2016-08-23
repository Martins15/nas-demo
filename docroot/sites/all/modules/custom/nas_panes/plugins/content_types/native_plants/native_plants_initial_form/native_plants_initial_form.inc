<?php
/**
 * @file
 * Native Plants initial form plugin.
 */

$plugin = array(
  'title' => t('Native Plants initial form'),
  'description' => t('Native Plants initial form for starting page.'),
  'category' => 'Native Plants',
  'admin info' => 'native_plants_initial_form_admin_info',
  'edit form' => 'native_plants_initial_form_edit_form',
  'render callback' => 'native_plants_initial_form_render',
  'hook theme' => 'native_plants_initial_form_theme',
  'no title override' => TRUE,
  'defaults' => array(
    'title_desktop' => 'Find bird-friendly plants for your area',
    'title_mobile' => 'Find bird-friendly plants for your area',
    'email_placeholder' => 'Email Address',
    'zipcode_placeholder' => 'U.S. ZIP code',
    'button_text' => 'Search',
    'image' => 0,
    'color_scheme' => 'dark',
    'dark_gradient' => 1,
    'description' => array(
      'value' => "<p>Provide your email address to join Audubon's network of supporters protecting birds around the world.
        You'll receive a customized shopping list of the native plants you choose, tips to hep your plants thrive,
        and more ways to help the birds you love.
        <a href=\"https://audubon.org/privacy-policy\">Privacy Policy</a></p>",
      'format' => 'full_html',
    ),
  ),
  'all contexts' => TRUE,
);

/**
 * Administrative info callback.
 */
function native_plants_initial_form_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = t('Native Plants initial form');
  $block->content = $conf['button_text'];
  return $block;
}

/**
 * Configuration form.
 */
function native_plants_initial_form_edit_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'native_plants_initial_form', 'nas_panes', 'plugins/content_types/native_plants/native_plants_initial_form');

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
  $form['email_placeholder'] = array(
    '#type' => 'textfield',
    '#title' => t('Email address placeholder'),
    '#default_value' => $conf['email_placeholder'],
    '#size' => 100,
  );
  $form['zipcode_placeholder'] = array(
    '#type' => 'textfield',
    '#title' => t('ZIP code placeholder'),
    '#default_value' => $conf['zipcode_placeholder'],
    '#size' => 100,
  );
  $form['button_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Button text'),
    '#default_value' => $conf['button_text'],
    '#size' => 100,
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

  $form['description'] = array(
    '#type' => 'text_format',
    '#title' => t('Description'),
    '#default_value' => $conf['description']['value'],
    '#format' => $conf['description']['format'],
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function native_plants_initial_form_edit_form_submit(&$form, &$form_state) {
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
function native_plants_initial_form_render($subtype, $conf, $args, $contexts) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  if ($plugin = ctools_get_plugins('ctools', 'content_types', $subtype)) {
    $conf = array_merge($plugin['defaults'], $conf);
  }

  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);

  $image_path = file_create_url('sites/all/themes/custom/nas/img/plants-background.jpg');
  $image_attribution = 'Photo: Lazlo Ilyes, Flickr Creative Commons';
  if ($image = file_load($conf['image'])) {
    $image_path = image_style_url('hero_image', $image->uri);
    $image_attribution = _nas_panes_format_image_attribution($image);
  }

  $form = drupal_get_form('nas_master_native_plants_initial_form', $conf);
  $form['#theme'] = 'native_plants_initial_form';
  $rendered_form = drupal_render($form);

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'native_plants_initial_form_pane',
    '#title_desktop' => t(filter_xss($conf['title_desktop'])),
    '#title_mobile' => t(filter_xss($conf['title_mobile'])),
    '#image_path' => $image_path,
    '#image_attribution' => $image_attribution,
    '#color_scheme' => $conf['color_scheme'],
    '#dark_gradient' => $conf['dark_gradient'],
    '#description' => check_markup($conf['description']['value'], $conf['description']['format']),
    '#form' => $rendered_form,
    '#context_links' => $contextual_links,
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function native_plants_initial_form_theme(&$theme, $plugin) {
  $theme['native_plants_initial_form_pane'] = array(
    'variables' => array(
      'title_desktop' => '',
      'title_mobile' => '',
      'image_path' => '',
      'image_attribution' => '',
      'color_scheme' => '',
      'dark_gradient' => '',
      'description' => '',
      'form' => '',
      'context_links' => '',
    ),
    'template' => 'native-plants-initial-form-pane',
    'path' => $plugin['path'],
  );
  $theme['native_plants_initial_form'] = array(
    'render element' => 'form',
    'template' => 'native-plants-initial-form',
    'path' => $plugin['path'],
  );
}

/**
 * Preprocess function.
 */
function nas_panes_preprocess_native_plants_initial_form_pane(&$variables) {
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
