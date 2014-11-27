<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('BOA Family Species'),
  'description' => t('Provides "BOA Family Species" pane'),
  'category' => 'NAS',
  'render callback' => 'nas_panes_boa_family_species_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function nas_panes_boa_family_species_render($subtype, $conf, $args, $context) {
  $context_node = $context->data;
  if ($context_node->type !== 'boaf') {
    return;
  }
  $block_title = t('@title in the News', array('@title' => $context_node->title));

  $trail = menu_get_active_trail();
  // If BOA Family is not presented in menu then there are no children Genus.
  if (empty($trail[1])) {
    return;
  }
  $genera = array();
  // Second level links of BOA menu are links to Genus.
  $parameters = array(
    'only_active_trail' => FALSE,
    'min_depth' => 2,
    'conditions' => array('plid' => $trail[1]['mlid']),
  );
  $genera_links = menu_build_tree('boa', $parameters);
  foreach ($genera_links as $genus_link) {
    if ($genus_link['link']['router_path'] !== 'node/%') {
      continue;
    }
    list(, $nid) = explode('/', $genus_link['link']['link_path']);
    if (!$genus_node = node_load($nid)) {
      continue;
    }
    $genus = array(
      'node' => $genus_node,
      'species' => array(),
    );
    // Third level links of BOA menu are links to Bird Species.
    $parameters = array(
      'only_active_trail' => FALSE,
      'min_depth' => 3,
      'conditions' => array('plid' => $genus_link['link']['mlid']),
    );
    $species_links = menu_build_tree('boa', $parameters);
    foreach ($species_links as $species_link) {
      if ($species_link['link']['router_path'] !== 'node/%') {
        continue;
      }
      list(, $nid) = explode('/', $species_link['link']['link_path']);
      if (!$species_node = node_load($nid)) {
        continue;
      }
      $build = node_view($species_node, 'teaser');
      $genus['species'][] = drupal_render($build);
    }
    $genus['number'] = _boa_family_species_to_roman(count($genera) + 1);
    $genus['title'] = check_plain($genus_node->title);
    $genus['scientific_name'] = '';
    if ($items = field_get_items('node', $genus_node, 'field_scientific_name')) {
      $genus['scientific_name'] = $items[0]['safe_value'];
    }
    $genera[] = $genus;
  }

  $block = new stdClass();
  $block->content = '';
  if (!empty($genera)) {
    $block->content = theme('boa_family_species', array(
      'genera' => $genera,
      'title' => $block_title,
    ));
  }

  return $block;
}

/**
 * Helper function to convert to roman numbers.
 *
 * @param int $number
 *   Number.
 *
 * @return string
 *   Roman number.
 */
function _boa_family_species_to_roman($number) {
  $flip = array(
    1 => 'I',
    2 => 'II',
    3 => 'III',
    4 => 'IV',
    5 => 'V',
    6 => 'VI',
    7 => 'VII',
  );

  return isset($flip[$number]) ? $flip[$number] : 'N';
}