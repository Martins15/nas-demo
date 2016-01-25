<?php
/**
 * @file
 * nas_language_switcher_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nas_language_switcher_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lang_dropdown_language';
  $strongarm->value = array(
    'showall' => 0,
    'tohome' => 0,
    'width' => '110',
    'display' => '1',
    'widget' => '3',
    'msdropdown' => array(
      'visible_rows' => 5,
      'rounded' => 1,
      'animation' => 'slideDown',
      'event' => 'click',
      'skin' => 'ldsSkin',
      'custom_skin' => '',
    ),
    'chosen' => array(
      'disable_search' => 1,
      'no_results_text' => 'No language match',
    ),
    'ddslick' => array(
      'ddslick_height' => '0',
      'showSelectedHTML' => 1,
      'imagePosition' => 'left',
      'skin' => 'custom',
      'custom_skin' => 'ddsDark',
    ),
    'languageicons' => array(
      'flag_position' => 1,
    ),
  );
  $export['lang_dropdown_language'] = $strongarm;

  return $export;
}
