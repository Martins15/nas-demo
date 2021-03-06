<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('BOA Plate Binocular'),
  'description' => t('Provides BOA Plate Binocular pane'),
  'category' => 'NAS',
  'edit form' => 'boa_plate_binocular_edit_form',
  'render callback' => 'boa_plate_binocular_render',
);

/**
 * An edit form for the pane's settings.
 */
function boa_plate_binocular_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['#tree'] = TRUE;
  _nas_panes_hide_pane_title_field($form);

  $form['wrapper'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  for ($i = 1; $i <= 8; $i++) {
    $form['wrapper'][$i]['entity_reference'] = array(
      '#type' => 'entityreference',
      '#default_value' => !empty($conf['wrapper'][$i]['entity_reference']) ? $conf['wrapper'][$i]['entity_reference'] : '',
      '#era_entity_type' => 'node',
      '#era_bundles' => array('boa'),
    );
  }

  return $form;
}

/**
 * Submit callback.
 */
function boa_plate_binocular_edit_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 *
 * See ctools_plugin_examples for more advanced info.
 */
function boa_plate_binocular_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  $nodes = array();
  foreach ($conf['wrapper'] as $value) {
    if ($value['entity_reference'] && $node = _i18n_node_load($value['entity_reference']['entity_id'])) {
      // Select nodes only with plate illustration.
      if ($get_field_boa_illustration = field_get_items('node', $node, 'field_boa_illustration')) {
        $image_color = '';
        if (isset($get_field_boa_illustration[0]['fid'])) {
          $file = file_load($get_field_boa_illustration[0]['fid']);
          $image_color = image_style_url('boa_plate_binocular', nas_alters_local_image_uri($file->uri));
          $credits = '';
          if ($get_field_file_credit = field_get_items('file', $file, 'field_file_credit')) {
            if (isset($get_field_file_credit[0]['value'])) {
              $credits = $get_field_file_credit[0]['value'];
            }
          }
          $image_desaturated = '';
          if ($get_field_boa_plate_illustr_des = field_get_items('node', $node, 'field_boa_plate_illustr_des')) {
            if (isset($get_field_boa_plate_illustr_des[0]['fid'])) {
              $file = file_load($get_field_boa_plate_illustr_des[0]['fid']);
              $image_desaturated = image_style_url('boa_plate_binocular', nas_alters_local_image_uri($file->uri));
            }
          }
          $nodes[] = array(
            'node' => $node,
            'image_color' => $image_color,
            'image_desaturated' => $image_desaturated,
            'credits' => $credits,
            'link' => l(t('Learn more about the') . ' ' . $node->title . ' »', 'node/' . $node->nid),
          );
        }
      }
    }
  }

  $class = '';
  if (arg(0) == 'field-guide') {
    $class = 'bird-card-grid';
  }
  if (arg(0) == 'frontpage') {
    $class = 'bird-card-set bg-bone-white bg-boa';
  }

  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);

  if (!empty($nodes)) {
    $rand_key = array_rand($nodes, 1);
    $chosen_node = $nodes[$rand_key];
  }

  drupal_add_js(array(
    'boa_plate_binocular' => array(
      'image_color' => isset($chosen_node['image_color']) ? $chosen_node['image_color'] : '',
      'image_desaturated' => isset($chosen_node['image_desaturated']) ? $chosen_node['image_desaturated'] : '',
    ),
  ), 'setting');

  $content = theme('boa_plate_binocular', array(
    'class' => $class,
    'image_desaturated' => isset($chosen_node['image_desaturated']) ? $chosen_node['image_desaturated'] : '',
    'credits' => isset($chosen_node['credits']) ? $chosen_node['credits'] : '',
    'title' => isset($chosen_node['node']->title) ? l($chosen_node['node']->title, 'node/' . $chosen_node['node']->nid) : '',
    'link' => isset($chosen_node['link']) ? $chosen_node['link'] : '',
    'contextual_links' => $contextual_links,
  ));

  $block->content = $content;
  return $block;
}
