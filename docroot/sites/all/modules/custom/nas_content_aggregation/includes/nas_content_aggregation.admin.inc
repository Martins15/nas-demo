<?php
/**
 * @file
 * Administration pages for nas_content_aggregation module.
 */

/**
 * Form for press_room CT.
 */
function nas_content_aggregation_editorial_cards_form($form, &$form_state) {
  $storage = variable_get('nas_content_aggregation_storage', array());
  $form['nas_content_aggregation_help'] = array(
    '#markup' => t('This form provide possibility import content from Audubon States & Centers sites.')
  );
  $form['#tree'] = TRUE;
  $form['nas_content_aggregation_frequency'] = array(
    '#title' => t('Frequency'),
    '#type' => 'textfield',
    '#size' => 10,
    '#maxlength' => 2,
    '#required' => TRUE,
    '#default_value' => !empty($storage['frequency']) ? $storage['frequency'] : 1,
    '#description' => t('Provide a frequency in number of days, how often import should start.
    For example if entered value 5, import will start each 5 days.'),
  );

  $number_items = isset($form_state['num_urls']) ? $form_state['num_urls'] : count($storage['settings']);
  $number_items = $number_items > 0 ? $number_items : 1;

  $form['nas_agg_wrap'] = array(
    '#type' => 'fieldset',
  );
  $form['nas_agg_wrap']['nas_agg_urls'] = array(
    '#prefix' => '<div id="urls-fieldset-wrapper">',
    '#suffix' => '</div>',
  );

  $display_remove = $number_items;
  if (isset($form_state['deleted_items'])) {
    foreach ($form_state['deleted_items'] as $items) {
      $display_remove--;
    }
  }

  for ($i = 0; $i < $number_items; $i++) {
    $form['nas_agg_wrap']['nas_agg_urls'][$i] = array(
      '#type' => 'fieldset',
      '#title' => t('URL'),
      '#collapsed' => FALSE,
      '#collapsible' => TRUE,
      '#tree' => TRUE
    );
    $form['nas_agg_wrap']['nas_agg_urls'][$i]['url'] = array(
      '#type' => 'textfield',
      '#default_value' => !empty($storage['settings'][$i]['url']) ? $storage['settings'][$i]['url'] : '',
      '#description' => t('Enter source url with http:// as prefix'),
    );

    $available_ct = array(
      'article',
      'slideshow',
      'pressrelease',
      'static_page'
    );
    $form['nas_agg_wrap']['nas_agg_urls'][$i]['type'] = array(
      '#type' => 'textfield',
      '#size' => 30,
      '#default_value' => !empty($storage['settings'][$i]['type']) ? $storage['settings'][$i]['type'] : '',
      '#description' => t(' Enter content types using coma as a separator.
      Available types: <b>@ct</b>.
      Example: if entered value is "article" from provided url will be imported only article content.', array('@ct' => implode(', ', $available_ct))),
    );
    $section_terms = array('none' => t('Select Editorial Category'));
    $section_terms += _nas_panes_get_taxonomy_options('section');
    $form['nas_agg_wrap']['nas_agg_urls'][$i]['ed_terms'] = array(
      '#type' => 'select',
      '#title' => t('Editorial section'),
      '#options' => $section_terms,
      '#default_value' => !empty($storage['settings'][$i]['ed_terms']) ? $storage['settings'][$i]['ed_terms'] : array(),
      '#description' => t('Choose editorial categories, and imported content will be tagged these categories.'),
    );
    $menu_terms = array('none' => t('Select Menu Category'));
    $menu_terms += _nas_panes_get_taxonomy_options('menu_section');
    $form['nas_agg_wrap']['nas_agg_urls'][$i]['menu_terms'] = array(
      '#type' => 'select',
      '#title' => t('Menu Section'),
      '#options' => $menu_terms,
      '#default_value' => !empty($storage['settings'][$i]['menu_terms']) ? $storage['settings'][$i]['menu_terms'] : array(),
      '#description' => t('Choose menu categories, and imported content will be tagged these categories.'),
    );
    if ($display_remove > 1) {
      $form['nas_agg_wrap']['nas_agg_urls'][$i]['remove_' . $i] = array(
        '#type' => 'submit',
        '#name' => 'remove_' . $i,
        '#value' => t('Remove'),
        '#submit' => array('nas_content_aggregation_ajax_add_more_remove_one'),
        '#ajax' => array(
          'callback' => 'nas_content_aggregation_ajax_form_update_callback',
          'wrapper' => 'urls-fieldset-wrapper',
        ),
      );
    }
  }
  $form['nas_agg_wrap']['nas_agg_urls']['add_url'] = array(
    '#type' => 'submit',
    '#value' => t('Add one more'),
    '#name' => 'add',
    '#submit' => array('nas_content_aggregation_ajax_add_more_add_one'),
    '#ajax' => array(
      'callback' => 'nas_content_aggregation_ajax_form_update_callback',
      'wrapper' => 'urls-fieldset-wrapper',
    ),
  );
  if (isset($form_state['deleted_items'])) {
    foreach ($form_state['deleted_items'] as $items) {
      unset($form['nas_agg_wrap']['nas_agg_urls'][$items]);
    }
  }
  if ($display_remove > 1) {
    $form['nas_agg_wrap']['nas_agg_urls']['remove_url'] = array(
      '#type' => 'submit',
      '#value' => t('Remove one'),
      '#name' => 'remove_last',
      '#submit' => array('nas_content_aggregation_ajax_add_more_remove_one'),
      '#ajax' => array(
        'callback' => 'nas_content_aggregation_ajax_form_update_callback',
        'wrapper' => 'urls-fieldset-wrapper',
      ),
    );
  }
  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save Settings'),
  );
  $form['save_import'] = array(
    '#type' => 'submit',
    '#value' => t('Save Settings & Start Import'),
  );
  $form_state['num_urls'] = $number_items;

  return $form;
}

/**
 * Add additional field for url.
 *
 * @param array $form
 *   Array of form elements.
 * @param array $form_state
 *   Array of Form state elements
 */
function nas_content_aggregation_ajax_add_more_add_one($form, &$form_state) {
  $form_state['num_urls']++;
  $form_state['rebuild'] = TRUE;
}

/**
 * Return a form after updating number of form elements.
 *
 * @param array $form
 *   Array of form elements.
 * @param array $form_state
 *   Array of Form state elements
 */
function nas_content_aggregation_ajax_form_update_callback($form, $form_state) {
  return $form['nas_agg_wrap']['nas_agg_urls'];
}

/**
 * Remove field for url from form.
 *
 * @param array $form
 *   Array of form elements.
 * @param array $form_state
 *   Array of Form state elements.
 */
function nas_content_aggregation_ajax_add_more_remove_one($form, &$form_state) {
  $parents = &$form_state['triggering_element']['#parents'];
  if ($parents[0] == 'nas_agg_wrap' && is_numeric($parents[2])) {
    $item = explode('_', $parents[3]);
    $form_state['deleted_items'][$parents[2]] = $item[1];
  }
  else {
    if ($form_state['num_urls'] > 1) {
      $form_state['num_urls']--;
    }
  }
  $form_state['rebuild'] = TRUE;
}


/**
 * Validation form.
 */
function nas_content_aggregation_editorial_cards_form_validate($form, &$form_state) {
  $values = &$form_state['values'];
  if (isset($form_state['values']['add']) ||
    isset($form_state['values']['remove']) ||
    isset($form_state['values']['remove_last'])
  ) {
    return TRUE;
  }
  if (!is_numeric($values['nas_content_aggregation_frequency'])) {
    form_set_error("nas_content_aggregation_frequency", t('Please provide numeric value'));
  }
  elseif ((int) $values['nas_content_aggregation_frequency'] <= 0) {
    form_set_error("nas_content_aggregation_frequency", t('Entered value is incorrect.'));
  }
  foreach ($values['nas_agg_wrap']['nas_agg_urls'] as $key => $val) {
    if (is_array($val)) {
      if (filter_var($val['url'], FILTER_VALIDATE_URL) === FALSE) {
        form_set_error("nas_agg_wrap][nas_agg_urls][$key][url", t('Entered URL address is incorrect.'));
        return FALSE;
      }
      else {
        $url = parse_url($val['url']);
        $current_url = parse_url(url(NULL, array('absolute' => TRUE)));
        if ($url['host'] == $current_url['host']) {
          //form_set_error("nas_agg_wrap][nas_agg_urls][$key][url", t('You can\'t import content from current host.'));
          //return FALSE;
        }
      }
      $available_ct = nas_content_aggregation_available_ct();
      if (!empty($values['nas_agg_wrap']['nas_agg_urls'][$key]['type'])) {
        $entered_ct = explode(',', $values['nas_agg_wrap']['nas_agg_urls'][$key]['type']);
        $entered_ct = array_map('trim', $entered_ct);
        if (array_diff($entered_ct, $available_ct)) {
          form_set_error("nas_agg_wrap][nas_agg_urls][$key][type", t('Entered content type is invalid.'));
          return FALSE;
        }
        else {
          $val['url'] .= '?type_filter=' . implode(',', $entered_ct);
        }
      }

      // Get url from headers.
      $response = drupal_http_request($val['url']);
      if ($response->code == 200 &&
        isset($response->headers['x-editorial-feed'])
      ) {
        $form_state['storage']['source_url'][$key] = $response->headers['x-editorial-feed'];
      }
      else {
        form_set_error("nas_agg_wrap][nas_agg_urls][$key][url", t('Entered URL doesn\'t contain any content available for import.
        Please check your url and try again.'));
      }
    }
  }
}

/**
 * Submit callback for nas_import_press_room_ct_form.
 */
function nas_content_aggregation_editorial_cards_form_submit($form, &$form_state) {
  $settings = array();
  foreach ($form_state['values']['nas_agg_wrap']['nas_agg_urls'] as $val) {
    if (is_array($val)) {
      $settings[] = array(
        'type' => $val['type'],
        'url' => $val['url'],
        'ed_terms' => $val['ed_terms'] != 'none' ? $val['ed_terms'] : NULL,
        'menu_terms' => $val['menu_terms'] != 'none' ? $val['menu_terms'] : NULL
      );
    }
  }
  $storage = array(
    'settings' => $settings,
    'feeds' => $form_state['storage']['source_url'],
    'frequency' => $form_state['values']['nas_content_aggregation_frequency'],
    'cron_time' => time()
  );

  if ($form_state['values']['op'] == $form_state['values']['save']) {
    variable_set('nas_content_aggregation_storage', $storage);
    drupal_set_message(t('Settings have been saved.'));
  }
  if ($form_state['values']['op'] == $form_state['values']['save_import']) {
    variable_set('nas_content_aggregation_storage', $storage);
    nas_content_aggregation_import_nodes($storage);
  }
}
