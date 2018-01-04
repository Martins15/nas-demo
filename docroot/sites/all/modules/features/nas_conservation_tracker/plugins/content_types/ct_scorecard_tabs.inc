<?php

/**
 * @file
 * Content type plugin for CT.
 */

$plugin = array(
  'title' => t('CT Scorecard Tabs'),
  'description' => t('Displays CT Scorecard Tabs'),
  'single' => TRUE,
  'content_types' => array('ct_scorecard_tabs'),
  'render callback' => 'nas_conservation_tracker_scorecard_tabs_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'edit form' => 'nas_conservation_tracker_scorecard_tabs_edit_form',
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
function nas_conservation_tracker_scorecard_tabs_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  if (!empty($context->data->field_scorecard_id[$context->data->language][0]['value'])) {
    $scorecard_id = $context->data->field_scorecard_id[$context->data->language][0]['value'];
  }
  elseif (!empty($context->data->field_scorecard_id[LANGUAGE_NONE][0]['value'])) {
    $scorecard_id = $context->data->field_scorecard_id[LANGUAGE_NONE][0]['value'];
  }
  else {
    return;
  }
  $data = nas_conservation_tracker_get_json('scorecard-' . $scorecard_id);
  //dpm($data);
  $links = menu_tree_all_data('menu-ct-menu');
  $vars['menu_tree'] = array();

  foreach ($links as $link) {
    $key = $link['link']['mlid'];
    $vars['menu_tree'][$key] = array(
      'markup' => l($link['link']['link_title'], $link['link']['router_path']),
      'children' => array(),
    );
    foreach ($link['below'] as $child) {
      $attr = array();
      if ($child['link']['link_title'] == $data['settings']['menuParent']) {
        $attr['class'][] = 'active-trail';
      }
      $vars['menu_tree'][$key]['children'][] = array(
        'markup' => l($child['link']['link_title'], $child['link']['router_path'], $attr),
      );
    }
  }
  $vars['menu_tree'][] = array('markup' => $context->data->title);

  $block->content = theme('ct_scorecard_tabs', $vars);

  return $block;
}

/**
 * Ctools edit form.
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function nas_conservation_tracker_scorecard_tabs_edit_form($form, &$form_state) {
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
function nas_conservation_tracker_scorecard_tabs_edit_form_submit($form, &$form_state) {

}
