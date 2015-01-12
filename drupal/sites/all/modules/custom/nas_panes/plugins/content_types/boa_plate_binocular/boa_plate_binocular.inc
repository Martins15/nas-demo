<?php

/**
 * @file
 * define ctools content type.
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

  $form['wrapper'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  for ($i = 1; $i <= 6; $i++) {
    $form['wrapper'][$i]['entity_reference'] = array(
      '#type' => 'entityreference',
      '#default_value' => !empty($conf['wrapper'][$i]['entity_reference']) ? $conf['wrapper'][$i]['entity_reference'] : '',
      '#era_entity_type' => 'node',
      '#era_bundles' => array('boa'),
    );
  }

  // Remove default title field.
  unset($form['override_title']);
  unset($form['override_title_text']);
  unset($form['override_title_markup']);

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function boa_plate_binocular_edit_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info.
 */
function boa_plate_binocular_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  $nodes = array();
  foreach ($conf['wrapper'] as $value) {
    if ($value['entity_reference'] && $node = node_load($value['entity_reference']['entity_id'])) {
      // Select nodes only with plate illustration.
      if ($get_field_boa_illustration = field_get_items('node', $node, 'field_boa_illustration')) {
        $image_color = '';
        if (isset($get_field_boa_illustration[0]['fid'])) {
          $file = file_load($get_field_boa_illustration[0]['fid']);
          $image_color = image_style_url('boa_plate_binocular', $file->uri);
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
              $image_desaturated = image_style_url('boa_plate_binocular', $file->uri);
            }
          }
          $nodes[] = array(
            'node' => $node,
            'image_color' => $image_color,
            'image_desaturated' => $image_desaturated,
            'credits' => $credits,
            'link' => l(t('Learn more about the') . ' ' .  $node->title . ' »', 'node/' . $node->nid),
          );
        }
      }
    }
  }
  // Current page is a one of landing pages.
  $args_cache_key_pairs = array(
    'bird-guide' => array(
      'cache_key' => NAS_PANES_BIRD_GUIDE_PAGE_MANAGER_CACHE_KEY,
      'panel_context' => 'page_bird_guide_panel_context',
    ),
    'frontpage' => array(
      'cache_key' => NAS_PANES_FRONTPAGE_PAGE_MANAGER_CACHE_KEY,
      'panel_context' => 'page_frontpage2_panel_context',
    ),
  );
  if (arg(0) == 'birds' && arg(1) == 'bird-guide' && !arg(2)) {
    $key = 'bird-guide';
    $class = 'bird-card-grid';
  }
  if (arg(0) == 'frontpage') {
    $key = 'frontpage';
    $class = 'bird-card-set bg-bone-white bg-boa';
  }
  if (isset($args_cache_key_pairs[$key])) {
    $context['landing'] = array(
      'cache_key' => $args_cache_key_pairs[$key]['cache_key'],
      'panel_context' => $args_cache_key_pairs[$key]['panel_context'],
    );
    $contextual_links = nas_panes_build_page_contextual_links('boa_plate_binocular', $context['landing']['cache_key'], $context['landing']['panel_context']);
  }

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
    'title' => isset($chosen_node['node']->title) ? l($chosen_node['node']->title, 'node/' . $chosen_node->nid) : '',
    'link' => isset($chosen_node['link']) ? $chosen_node['link'] : '',
    'contextual_links' => $contextual_links,
  ));

  $block->content = $content;
  return $block;
}
