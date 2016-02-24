<?php
/**
 * @file
 * Native Plants list plugin.
 */

$plugin = array(
  'title' => t('Native Plants List'),
  'description' => t('Native Plants List.'),
  'category' => 'Native Plants',
  'render callback' => 'native_plants_list_render',
  'hook theme' => 'native_plants_list_theme',
  'required context' => new ctools_context_required(t('Permalink'), 'entity:permalink'),
);

/**
 * Render callback.
 */
function native_plants_list_render($subtype, $conf, $args, $context) {
  // $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $context);

  $permalink = $context->data;
  $plants = drupal_json_decode($permalink->plants_cart);

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'native_plants_list',
    '#plants' => $plants,
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function native_plants_list_theme(&$theme, $plugin) {
  $theme['native_plants_list'] = array(
    'variables' => array(
      'plants' => array(),
    ),
    'template' => 'native-plants-list',
    'path' => $plugin['path'],
  );
}

/**
 * Preprocess function.
 */
function nas_panes_preprocess_native_plants_list(&$variables) {
  foreach ($variables['plants'] as &$plant) {
    $plant['BirdTypes'] = explode(',', $plant['BirdTypes']);
    $plant['BirdTypesValues'] = array();
  }

  $np_bird_types_voc = taxonomy_vocabulary_machine_name_load('native_plant_bird_types');
  $np_bird_types_terms = taxonomy_get_tree($np_bird_types_voc->vid, 0, NULL, TRUE);
  $np_bird_types_term_wrappers = array();
  foreach ($np_bird_types_terms as $term) {
    $np_bird_types_term_wrappers[] = entity_metadata_wrapper('taxonomy_term', $term);
  }

  foreach ($np_bird_types_term_wrappers as $wrapper) {
    $link = $wrapper->field_link->value();
    if ($link) {
      $url = $link['url'];
    }
    else {
      $url = '';
    }

    foreach ($variables['plants'] as &$plant) {
      if (in_array($wrapper->tid->value(), $plant['BirdTypes'])) {
        $plant['BirdTypesValues'][$wrapper->tid->value()] = array(
          'tid' => $wrapper->tid->value(),
          'name' => $wrapper->name->value(),
          'image' => $wrapper->field_np_bird_type_image->value(),
          'url' => $url,
        );
      }
    }
  }

  foreach ($variables['plants'] as &$plant) {
    $plant['BirdTypesDesktop'] = array();
    $plant['BirdTypesMobile'] = array();
    foreach ($plant['BirdTypesValues'] as $bird_type) {
      $plant['BirdTypesDesktop'][] = l($bird_type['name'], $bird_type['url'], array('attributes' => array('class' => array('native-plant-bird-category-link'))));
      $plant['BirdTypesMobile'][] = l($bird_type['name'], $bird_type['url']);
    }
  }
}
