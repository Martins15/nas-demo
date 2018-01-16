<?php

/**
 * @file
 * Content type plugin for CT.
 */

$plugin = array(
  'title' => t('CT Scorecard Carousel'),
  'description' => t('Displays CT Scorecard Carousel'),
  'single' => TRUE,
  'content_types' => array('ct_scorecard_carousel'),
  'render callback' => 'nas_conservation_tracker_scorecard_carousel_render',
  //'required context' => new ctools_context_required(t('Node'), 'node'),
  'edit form' => 'nas_conservation_tracker_scorecard_carousel_edit_form',
  'category' => 'NAS Conservation Tracker',
);

/**
 * Render callback function.
 *
 * @param $subtype
 * @param $conf
 * @param $args
 * @param $context
 * @return stdClass
 */
function nas_conservation_tracker_scorecard_carousel_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $vars = array(
    'title' => t('Popular right now'),
    'items' => array(),
  );
  $data = nas_conservation_tracker_get_json('popular');
  if (!empty($data['items'])) {
    foreach ($data['items'] as $item) {
      $vars['items'][] = array(
        'title' => $item['title'],
        'category' => $item['category'],
        'href' => $item['href'],
      );
    }
    $owl = '//cdnjs.cloudflare.com/ajax/libs/owl-carousel/1.3.3/owl.carousel.min.js';
    drupal_add_js(variable_get('nas_conservation_tracker_owl', $owl));
  }
  $block->content = theme('ct_scorecard_carousel', $vars);

  return $block;
}

/**
 * Ctools edit form.
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function nas_conservation_tracker_scorecard_carousel_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  // some code TBD.
  return $form;
}

/**
 * Ctools edit form submit handler.
 *
 * @param $form
 * @param $form_state
 */
function nas_conservation_tracker_scorecard_carousel_edit_form_submit($form, &$form_state) {

}
