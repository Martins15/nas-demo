<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Audubon Near You. Bird Guide'),
  'description' => t('Audubon Near You. Bird Guide'),
  'category' => 'NAS',
  'render callback' => 'audubon_near_you_bird_guide_render',
);


/**
 * Run-time rendering of the body of the block (content type).
 *
 * @see ctools_plugin_examples()
 */
function audubon_near_you_bird_guide_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();
  $query = drupal_get_query_parameters();

  $links = theme('item_list', array(
    'items' => array(
      l(t('Explore Our Bird Guide'), 'birds/bird-guide'),
      l(t('Adopt a Bird'), 'https://secure.audubon.org/site/SPageNavigator/2014_Adoption_Catalog_Homepage.html', array('attributes' => array('class' => array('cta')))),
    ),
    'attributes' => array(
      'class' => array(
        'section-nav',
        'inline-list',
      ),
    ),
  ));

  $state = !empty($query['state']) ? $query['state'] : 'all';
  $filter_active = nas_panes_location_filter_is_active();
  $content = theme('audubon_near_you_bird_guide', array(
    'links' => $links,
    'content' => theme('audubon_near_you_bird_guide_content', array(
      'items' => $filter_active ? _nas_panes_get_priority_birds($state) : array(),
      'hide_empty_text' => TRUE,
      'filter_active' => $filter_active,
    )),
  ));

  $block->content = $content;

  return $block;
}
