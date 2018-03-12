<?php

/**
 * @file
 * Content type plugin for CT.
 */
$plugin = [
  'title' => t('CT Landscapes Main'),
  'description' => t('Displays CT Landscapes Main Content'),
  'single' => TRUE,
  'content_types' => ['ct_landscapes_main'],
  'render callback' => 'nas_conservation_tracker_landscapes_main_render',
  //'required context' => new ctools_context_required(t('Node'), 'node'),
  'edit form' => 'nas_conservation_tracker_landscapes_main_edit_form',
  'category' => 'NAS Conservation Tracker',
];

/**
 * Render callback function.
 *
 * @param $subtype
 * @param $conf
 *
 * @param $args
 * @param $context
 *
 * @return stdClass
 */
function nas_conservation_tracker_landscapes_main_render($subtype, $conf, $args, $context) {
  $block = new stdClass();


  $js_path = drupal_get_path('module', 'nas_conservation_tracker') . '/js/';
  drupal_add_js($js_path . 'landscapes.js');
  drupal_add_js($js_path . 'units.js');

  drupal_add_js($js_path . 'nas_conservation_tracker_landscapes.js', [
    'weight' => 999,
    'group' => JS_THEME,
  ]);

  // Map.
  $map_info = current(leaflet_map_get_info());
  $map_info['settings']['layerControl'] = TRUE;
  $map_info['layers']['earth']['urlTemplate'] = '//server.arcgisonline.com/ArcGIS/rest/services/Canvas//World_Dark_Gray_Base/MapServer/tile/{z}/{y}/{x}';
  $map_info['layers']['earth']['options'] = array('attribution' => 'Mapnik | ESRI');
  // TODO make it configrable via form.
  $map_info['settings']['zoomDefault'] = 3;
  $map_info['settings']['zoom'] = 3;
  $map_info['settings']['zoomControl'] = FALSE;
  $map_info['settings']['dragging'] = TRUE;
  $map_info['settings']['touchZoom'] = FALSE;
  $map_info['settings']['doubleClickZoom'] = FALSE;
  $map_info['settings']['scrollWheelZoom'] = FALSE;
  $map_info['settings']['boxZoom'] = FALSE;
  $map_info['settings']['keyboard'] = FALSE;

  $map_info['center'] = [
    'lat' => '18.020098201368114',
    'lon' => '-102.33378906250001',
  ];
  $features = [
  ];
  $map = leaflet_build_map($map_info, $features, variable_get('nas_conservation_tracker_landscapes_map_height', '990') . 'px');

  $form = drupal_get_form('nas_conservation_tracker_landscapes_map_form');
  $refine_button = nas_conservation_tracker_refine_button('landscapes');

  $vars = [
    'map' => render($map),
    'form' => render($form),
    'refine_listing' => render($refine_button),
  ];

  $block->content = theme('ct_landscapes_main', $vars);

  return $block;
}

function nas_conservation_tracker_landscapes_map_form($form, &$form_state) {
  $form = [
    '#action' => '#',
    'strategies' => [
      '#type' => 'radios',
      '#title' => t('Strategies'),
      '#default_value' => 'coasts',
      '#options' => [
        'coasts' => t('Coasts'),
        'working lands' => t('Working Lands'),
        'water' => t('Water'),
      ],
    ],
    'status' => [
      '#type' => 'checkboxes',
      '#title' => t('Action Status'),
      '#default_value' => array('at work', 'scoping', 'future'),
      '#options' => [
        'at work' => t('At work'),
        'scoping' => t('Scoping'),
        'future' => t('Future'),
      ],
    ],
    'flyways' => [
      '#type' => 'checkboxes',
      '#title' => t('Flyways'),
      '#default_value' => array('pacific', 'atlantic', 'mississippi', 'central'),
      '#options' => [
        'pacific' => t('Pacific'),
        'atlantic' => t('Atlantic'),
        'mississippi' => t('Mississippi'),
        'central' => t('Central'),
      ],
    ],
  ];
  return $form;
}


/**
 * Ctools edit form.
 *
 * @param $form
 * @param $form_state
 *
 * @return mixed
 */
function nas_conservation_tracker_landscapes_main_edit_form($form, &$form_state) {
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
function nas_conservation_tracker_landscapes_main_edit_form_submit($form, &$form_state) {

}
