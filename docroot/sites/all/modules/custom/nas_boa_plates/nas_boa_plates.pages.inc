<?php
/**
 * @file
 * Page callbacks.
 */

/**
 * Page callback.
 */
function nas_boa_plates_page($node) {
  ctools_include('ajax');
  ctools_include('modal');
  ctools_modal_add_js();

  $image = field_get_items('node', $node, 'field_boa_illustration');
  $deepzoom_image = field_view_value('node', $node, 'field_boa_illustration', $image[0], array(
    'type' => 'deepzoom_image',
    'settings' => array(
      'image_style' => 'large',
      'image_link' => 'content',
    ),
  ));
  $result = array(
    'image' => $deepzoom_image,
  );

  $output = array(
    ctools_modal_command_display('deepzoom', $result),
    ajax_command_invoke('#modalContent', 'addClass', array('boa-plate-popup')),
    ajax_command_invoke('#modalContent', 'applySeadragon', array()),
  );

  print ajax_render($output);
  exit;
}
