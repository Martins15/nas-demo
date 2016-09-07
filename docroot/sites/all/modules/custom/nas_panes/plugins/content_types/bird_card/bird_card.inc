<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Bird card'),
  'description' => t('Provides Bird card pane'),
  'category' => t('Basic Modules'),
  'edit form' => 'bird_card_edit_form',
  'render callback' => 'bird_card_render',
  'tags' => array('full_width'),
);

/**
 * An edit form for the pane's settings.
 */
function bird_card_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['#tree'] = TRUE;

  ctools_form_include($form_state, 'content');
  ctools_form_include(
    $form_state,
    'bird_card',
    'nas_panes',
    'plugins/content_types/bird_card'
  );

  $rows_number =  NAS_BIRD_CARDS_NUMBER;
  if (!empty($form_state['values']['rows'])) {
    $rows_number = $form_state['values']['rows'];
  }
  elseif (!empty($conf['rows'])) {
    $rows_number = $conf['rows'];
  }

  $form['pager'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display Bird Cards in a Single Row'),
    '#description' => t('Check to display this set of bird cards in a single,
    scrollable row. If unchecked, all the cards you select will be displayed
    in a grid on the page.'),
    '#default_value' => !empty($conf['pager']) ? TRUE : FALSE,
  );

  $form['rows'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of cards'),
    '#default_value' => $rows_number,
    '#size' => 10,
  );

  $form['update_rows'] = array(
    '#type' => 'button',
    '#value' => t('Update'),
    '#ajax' => array(
      'callback' => 'bird_card_change_rows_callback',
      'wrapper' => 'ajax-bird-card-form',
      'effect' => 'fade',
    ),
  );

  $form['refs'] = array(
    '#type' => 'fieldset',
    '#title' => t('References'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  for ($i = 0; $i < $rows_number; $i++) {
    $form['refs'][$i] = array(
      '#tree' => TRUE,
    );
    $form['refs'][$i]['reference'] = array(
      '#type' => 'entityreference',
      '#default_value' => !empty($conf['refs'][$i]['reference']['entity_id']) ? $conf['refs'][$i]['reference']['entity_id'] : 0,
      '#era_entity_type' => 'node',
      '#era_bundles' => array('local_bird'),
    );
    $form['refs'][$i]['weight'] = array(
      '#type' => 'weight',
      '#title' => t('Weight'),
      '#default_value' => $i,
      '#delta' => $rows_number,
      '#title_display' => 'invisible',
    );

    $form['refs']['#prefix'] = '<div id="ajax-bird-card-form">';
    $form['refs']['#suffix'] = '</div>';
  }
  $form['more_link'] = array(
    '#type' => 'fieldset',
    '#title' => t('More Link'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['more_link']['more_link_text'] = array(
    '#type' => 'textfield',
    '#title' => t('More link text'),
    '#default_value' => !empty($conf['more_link']['more_link_text']) ? $conf['more_link']['more_link_text'] : '',
  );
  $form['more_link']['more_link_url'] = array(
    '#type' => 'textfield',
    '#title' => t('More link URL'),
    '#default_value' => !empty($conf['more_link']['more_link_url']) ? $conf['more_link']['more_link_url'] : '',
  );
  return $form;
}

/**
 * Returns changed bird_card_edit_form.
 *
 * @return array
 *   Form API array.
 */
function bird_card_change_rows_callback($form, &$form_state) {
  // Render bird card references.
  $table_id = 'bird-card-items-table';
  bird_card_render_references($form, $table_id);

  return $form['refs'];
}


/**
 * Theme callback for the bird_card_edit_form form.
 *
 * The theme callback will format the $form data structure into a table and
 * add our tabledrag functionality.
 *
 * @return array
 *   The rendered tabledrag form
 */
function theme_bird_card_edit_form($variables) {
  $form = $variables['form'];
  // Render bird card references.
  $table_id = 'bird-card-items-table';
  bird_card_render_references($form, $table_id);
  $output = drupal_render_children($form);

  drupal_add_tabledrag($table_id, 'order', 'sibling', 'bird-card-item-weight');
  return $output;
}


/**
 * Submit function, anything in the formstate[conf] automatically gets saved.
 *
 * Notice, the magic that automatically does that for you.
 */
function bird_card_edit_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      if ($key == 'refs') {
        $order = array();
        foreach ($form_state['values'][$key] as $ref_key => $row) {
          $order[$ref_key] = $row['weight'];
        }
        array_multisort($order, SORT_ASC, $form_state['values'][$key]);
      }
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 *
 * See ctools_plugin_examples for more advanced info
 */
function bird_card_render($subtype, $conf, $args, $context) {
  $js_options = array(
    'group' => JS_THEME,
    'every_page' => FALSE,
  );
  drupal_add_js(path_to_theme() . '/js/vendor/owl-carousel/owl.carousel.min.js', $js_options);
  drupal_add_js(path_to_theme() . '/js/nas/owl-settings.js', $js_options);

  $teasers = array();
  foreach ($conf['refs'] as $ref) {
    if (empty($ref['reference']['entity_id']) ||
      !$node = node_load($ref['reference']['entity_id'])
    ) {
      continue;
    }
    $build = node_view($node, 'teaser');
    $teasers[] = drupal_render($build);
  }
  $more_link = '';
  if (!empty($conf['more_link']['more_link_text']) &&
    !empty($conf['more_link']['more_link_url'])
  ) {
    $more_link = l($conf['more_link']['more_link_text'], $conf['more_link']['more_link_url']);
  }

  $block = new stdClass();
  $block->content = theme(
    'bird_card',
    array(
      'teasers' => $teasers,
      'title' => check_plain($conf['override_title_text']),
      'more_link' => $more_link,
      'pager' => !empty($conf['pager']) ? TRUE : FALSE,
    )
  );

  return $block;
}

/**
 * Helper function for render bird card references.
 */
function bird_card_render_references(&$form, $table_id) {
  $refs = element_children($form['refs']);
  $rows_number = count($refs);

  $rows = array();
  for ($i = 0; $i < $rows_number; $i++) {
    $form['refs'][$i]['weight']['#attributes']['class'] = array('bird-card-item-weight');
    $rows[] = array(
      'data' => array(
        drupal_render($form['refs'][$i]['reference']),
        drupal_render($form['refs'][$i]['weight']),
      ),
      'class' => array('draggable'),
    );
  }

  $header = array(t('Bird reference'), t('Weight'));
  $form['refs']['table_drag']['#markup'] = theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('id' => $table_id),
  ));
}
