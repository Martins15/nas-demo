<?php

/**
 * @file
 * Define ctools content type.
 */

$plugin = array(
  'title' => t('Audubon Near You. Search'),
  'description' => t('Block with search form'),
  'category' => 'NAS',
  'edit form' => 'audubon_near_you_search_settings_form',
  'render callback' => 'audubon_near_you_search_render',
  'defaults' => array(
    'description' => 'Twenty-two state programs, 47 centers, 450+ local chapters, and countless events.',
    'form_title' => 'Explore the Audubon network.',
  ),
);

/**
 * An edit form for the pane's settings.
 */
function audubon_near_you_search_settings_form($form, &$form_state) {
  $conf = $form_state['conf'];
  _nas_panes_hide_pane_title_field($form);

  $form['description'] = array(
    '#type' => 'textfield',
    '#title' => t('Description'),
    '#default_value' => $conf['description'],
  );

  $form['form_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Form title'),
    '#default_value' => $conf['form_title'],
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function audubon_near_you_search_settings_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
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
function audubon_near_you_search_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $context);

  if (!nas_panes_location_filter_is_active()) {
    drupal_add_js('//js.maxmind.com/js/apis/geoip2/v2.1/geoip2.js', 'external');
    drupal_add_js(drupal_get_path('module', 'nas_panes') . '/plugins/content_types/audubon_near_you_search/audubon_near_you_search.js');
  }

  $form = drupal_get_form('audubon_near_you_search_form');
  $block->content = theme('audubon_near_you_search', array(
    'title' => check_plain($conf['override_title_text']),
    'description' => check_plain($conf['description']),
    'form_title' => check_plain($conf['form_title']),
    'form' => drupal_render($form),
    'contextual_links' => $contextual_links,
  ));

  return $block;
}

/**
 * Search form.
 */
function audubon_near_you_search_form($form, &$form_state) {
  $query = drupal_get_query_parameters();

  $form['state'] = array(
    '#type' => 'select',
    '#empty_option' => t('Select a State'),
    '#options' => _audubon_near_you_states(),
    '#default_value' => !empty($query['state']) ? $query['state'] : '',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => '<span class="hide-for-medium hide-for-large hide-for-xlarge">
        <i class="icon-magnifier"></i>
      </span>
      <span class="hide-for-tiny hide-for-small">' . t('Ok') . '</span>',
    '#theme_wrappers' => array('nas_button'),
    '#attributes' => array(
      'class' => array('bird-guide-zip-submit', 'button', 'pea-green'),
    ),
  );

  $form['#theme'] = 'audubon_near_you_search_form';

  return $form;
}

/**
 * Submit handler for the search form.
 */
function audubon_near_you_search_form_submit($form, &$form_state) {
  $query = array();

  if (!empty($form_state['values']['state'])) {
    $query['state'] = $form_state['values']['state'];
  }

  // Redirect to Audubon Near You page with activated filters.
  $form_state['redirect'] = array(
    'audubon-near-you',
    array(
      'query' => $query,
    ),
  );
}

/**
 * Array with US states.
 */
function _audubon_near_you_states() {
  return array(
    'AL' => t('Alabama'),
    'AK' => t('Alaska'),
    'AZ' => t('Arizona'),
    'AR' => t('Arkansas'),
    'CA' => t('California'),
    'CO' => t('Colorado'),
    'CT' => t('Connecticut'),
    'DE' => t('Delaware'),
    'DC' => t('District Of Columbia'),
    'FL' => t('Florida'),
    'GA' => t('Georgia'),
    'HI' => t('Hawaii'),
    'ID' => t('Idaho'),
    'IL' => t('Illinois'),
    'IN' => t('Indiana'),
    'IA' => t('Iowa'),
    'KS' => t('Kansas'),
    'KY' => t('Kentucky'),
    'LA' => t('Louisiana'),
    'ME' => t('Maine'),
    'MD' => t('Maryland'),
    'MA' => t('Massachusetts'),
    'MI' => t('Michigan'),
    'MN' => t('Minnesota'),
    'MS' => t('Mississippi'),
    'MO' => t('Missouri'),
    'MT' => t('Montana'),
    'NE' => t('Nebraska'),
    'NV' => t('Nevada'),
    'NH' => t('New Hampshire'),
    'NJ' => t('New Jersey'),
    'NM' => t('New Mexico'),
    'NY' => t('New York'),
    'NC' => t('North Carolina'),
    'ND' => t('North Dakota'),
    'OH' => t('Ohio'),
    'OK' => t('Oklahoma'),
    'OR' => t('Oregon'),
    'PA' => t('Pennsylvania'),
    'RI' => t('Rhode Island'),
    'SC' => t('South Carolina'),
    'SD' => t('South Dakota'),
    'TN' => t('Tennessee'),
    'TX' => t('Texas'),
    'UT' => t('Utah'),
    'VT' => t('Vermont'),
    'VA' => t('Virginia'),
    'WA' => t('Washington'),
    'WV' => t('West Virginia'),
    'WI' => t('Wisconsin'),
    'WY' => t('Wyoming'),
  );
}
