<?php
/**
 * @file
 * Native Plants Audubon Near You plugin.
 */

$plugin = array(
  'title' => t('Native Plants Audubon Near You'),
  'description' => t('Native Plants Audubon Near You.'),
  'category' => 'Native Plants',
  'admin info' => 'native_plants_audubon_near_you_admin_info',
  'edit form' => 'native_plants_audubon_near_you_edit_form',
  'render callback' => 'native_plants_audubon_near_you_render',
  'hook theme' => 'native_plants_audubon_near_you_theme',
  'defaults' => array(
    'title' => 'Connect with Audubon near you for help with your native plants:',
    'override_title_text' => 'Connect with Audubon near you for help with your native plants:',
    'image' => 0,
    'services_title_desktop' => 'Services provided at !resource_name',
    'services_title_mobile' => 'Native plant services provided:',
    'zipcode' => '33556',
  ),
  'all contexts' => TRUE,
);

/**
 * Administrative info callback.
 */
function native_plants_audubon_near_you_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = $conf['title'];
  $block->content = $conf['services_title_desktop'];
  return $block;
}

/**
 * Configuration form.
 */
function native_plants_audubon_near_you_edit_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'native_plants_audubon_near_you', 'nas_panes', 'plugins/content_types/native_plants/native_plants_audubon_near_you');

  $form['override_title_heading']['#access'] = FALSE;
  $form['image'] = array(
    '#type' => 'media',
    '#tree' => TRUE,
    '#title' => t('Image'),
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

  $form['services_title_desktop'] = array(
    '#type' => 'textfield',
    '#title' => t('Services title desktop'),
    '#default_value' => $conf['services_title_desktop'],
  );
  $form['services_title_mobile'] = array(
    '#type' => 'textfield',
    '#title' => t('Services title mobile'),
    '#default_value' => $conf['services_title_mobile'],
  );

  $form['zipcode'] = array(
    '#type' => 'textfield',
    '#title' => t('ZIP code'),
    '#default_value' => $conf['zipcode'],
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function native_plants_audubon_near_you_edit_form_submit(&$form, &$form_state) {
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
function native_plants_audubon_near_you_render($subtype, $conf, $args, $context) {
  // $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $context);

  $zipcode = ctools_context_keyword_substitute($conf['zipcode'], array(), $context);
  ctools_include('plugins');
  $geometry = array();
  if ($zipcode_geocoder = ctools_get_plugins('geocoder', 'geocoder_handler', 'zipcode')) {
    if ($function = ctools_plugin_get_function($zipcode_geocoder, 'callback')) {
      $geometry = $function($zipcode);
    }
  }

  $resource = array();
  if ($geometry) {
    $latlon = $geometry->coords[1] . ',' . $geometry->coords[0];
    $view_results = views_get_view_result('community_resources_near_you', 'default', $latlon);
  }
  else {
    $view_results = views_get_view_result('community_resources_near_you', 'default');
  }

  // Prepare 1 community resource.
  foreach ($view_results as $result) {
    if (!$node = node_load($result->entity)) {
      continue;
    }
    $node_wrapper = entity_metadata_wrapper('node', $node);
    $resource = array(
      'title' => $node_wrapper->title->value(),
      'address' => $node_wrapper->field_community_resource_address->value(),
      'phone' => $node_wrapper->field_community_resource_phone->value(),
      'link' => $node_wrapper->field_community_resource_link->value(),
      'services' => array(),
    );
    $field = field_info_field('field_community_res_services');
    foreach ($node_wrapper->field_community_res_services->value() as $key) {
      $resource['services'][] = $field['settings']['allowed_values'][$key];
    }
    break;
  }

  if (!$resource) {
    return '';
  }

  // Use fallback image or the configured one.
  $image_path = file_create_url('sites/all/themes/custom/nas/img/np-thank-you-bg-1.jpg');
  if ($image = file_load($conf['image'])) {
    // TODO: do we need specific image style here?
    $image_path = image_style_url('hero_image', $image->uri);
  }

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'native_plants_audubon_near_you',
    '#title' => t(filter_xss($conf['title'])),
    '#services_title_desktop' => t(filter_xss($conf['services_title_desktop']),
      array('!resource_name' => '<span class="no-wrap">' . $resource['title'] . '</span>')),
    '#services_title_mobile' => t(filter_xss($conf['services_title_mobile'])),
    '#resource' => $resource,
    '#image_path' => $image_path,
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function native_plants_audubon_near_you_theme(&$theme, $plugin) {
  $theme['native_plants_audubon_near_you'] = array(
    'variables' => array(
      'title' => '',
      'services_title_desktop' => '',
      'services_title_mobile' => '',
      'resource' => array(),
      'image_path' => '',
    ),
    'template' => 'native-plants-audubon-near-you',
    'path' => $plugin['path'],
  );
}

/**
 * Preprocess function.
 */
function nas_panes_preprocess_native_plants_audubon_near_you(&$variables) {
  $res = &$variables['resource'];
  $res['link']['rendered'] = l(t('Visit Site'),
    $res['link']['url'],
    array('attributes' => array('class' => array('button', 'pea-green'))));
  $res['address']['rendered'] = '';
  $res['address']['rendered'] .= $res['address']['thoroughfare'] ? $res['address']['thoroughfare'] . '<br/>' : '';
  $res['address']['rendered'] .= $res['address']['locality'] ? $res['address']['locality'] . ', ' : '';
  $res['address']['rendered'] .= $res['address']['administrative_area'] ? $res['address']['administrative_area'] : '';
  $res['address']['rendered'] .= $res['address']['postal_code'] ? ' ' . $res['address']['postal_code'] : '';
  $res['address']['rendered'] .= $res['address']['rendered'] ? '<br/>' : '';

  $services_list = array(
    '#theme' => 'item_list',
    '#items' => $res['services'],
    '#attributes' => array(
      'class' => array(
        'connect-audubon-near-you--services-list'
      ),
    ),
  );
  $res['services']['rendered'] = drupal_render($services_list);
}
