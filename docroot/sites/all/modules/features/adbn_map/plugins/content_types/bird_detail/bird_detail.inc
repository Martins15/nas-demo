<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Bird Detail Map'),
  'description' => t('Displays bird detail map component.'),
  'category' => t('Audubon'),
  'hook theme' => 'adbn_map_bird_detail_content_type_theme',
  'edit form' => 'adbn_map_bird_detail_edit_form',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Render the content.
 */
function adbn_map_bird_detail_content_type_render($subtype, $conf, $panel_args, $context) {
  if (empty($context)) {
    return NULL;
  }

  $block = new stdClass();
  $block->module = 'adbn_map';

  $aggregated = TRUE;
  $content = array();
  $node = $context->data;
  $bird_id_field_name = 'field_bird_id';
  $language_code = $node->language;

  // Get the bird id if available.
  if (isset($node->{$bird_id_field_name}[$language_code][0]['value'])) {
    $bird_id = $node->{$bird_id_field_name}[$language_code][0]['value'];
  }
  else {
    return NULL;
  }

  // Get the bird name if available.
  $bird_name = '';
  if (isset($node->title)) {
    $bird_name = $node->title;
  }

  // Get the bird category if available.
  $bird_category = field_view_field('node', $node, 'field_bird_category', 'bird_header');
  if (isset($bird_category[0]['#markup'])) {
    $bird_category = $bird_category[0]['#markup'];
  }
  $bird_category_output = render($bird_category);

  // Extract the popup text, and send it for display.
  $popup_text = NULL;
  $popup_array = adbn_map_get_bird_page_overlay_value();
  if (!empty($popup_array['value'])) {
    $popup_text = check_markup($popup_array['value'], $popup_array['format']);
  }

  // Extract the short map description text, and send it for display.
  $map_short_description = NULL;
  $map_short_description_array = adbn_map_get_bird_page_map_short_description_value();
  if (!empty($map_short_description_array['value'])) {
    $map_short_description = check_markup($map_short_description_array['value'], $map_short_description_array['format']);
  }

  // Extract the short map description link text, and send it for display.
  $map_short_description_link_text = adbn_map_get_bird_page_map_short_description_link_value();
  $map_short_description_link = '<a class="open-bird-detail-popup">' . $map_short_description_link_text . '</a>';

  // For mobile, just replace the placeholder.
  $map_short_description_mobile = str_replace('[popup_link]', $map_short_description_link, $map_short_description);

  // For desktop remove placeholder, and append to the end.
  $map_short_description_desktop = str_replace('[popup_link]', '', $map_short_description);
  $map_short_description_desktop .= $map_short_description_link;

  // Get various asset paths.
  $module_path = adbn_map_get_module_path();
  $plugin_path = $module_path . '/plugins/content_types/bird_detail';
  $map_css_path = adbn_map_get_map_css_path();

  // Prepare share options.
  $node_url = url('node/' . $node->nid, array('absolute' => TRUE));
  //$mail_subject = t('The U.S. could lose half its bird species by 2080');
  //$mail_body = htmlspecialchars(t('Global warming threatens the birds we love, including the ' . $node->title . '. But if we band together, we can build a brighter future for birds and ourselves. Take action today at audubon.org/climate.'));
  $share_options = array(
    'share_url' => $node_url,
    //'mail_subject' => $mail_subject,
    //'mail_body' => $mail_body,
  );
  $bird_share_menu = theme('adbn_bird_share_menu', $share_options);

  // Add the various js settings required to initialize the plugin.
  $content['#attached']['js'][] = array(
    'type' => 'setting',
    'data' => array(ADBN_MAP_JS_NAMESPACE => array(
      'birdId' => $bird_id,
      'ajaxPath' => ADBN_MAP_AJAX_PATH,
      'area' => 'BBC',
      'birdDetailPath' => ADBN_MAP_BIRD_DETAIL_PATH,
      'birdShareMenu' => $bird_share_menu,
    )),
  );

  // Attach general map assets.
  $content = drupal_array_merge_deep_array(array($content, adbn_map_attach_map_assets($aggregated)));

  // Load the JS file that will initialize the map.
  $content['#attached']['js'][] = $plugin_path . '/bird_detail.js';

  // Add the markup to be displayed.
  $content['map'] = array(
    '#theme' => 'bird_detail',
    '#css_path' => $map_css_path,
    '#popup_text' => $popup_text,
    '#map_short_description_desktop' => $map_short_description_desktop,
    '#map_short_description_mobile' => $map_short_description_mobile,
    '#title' => $bird_name,
    '#bird_category' => $bird_category_output,
  );

  if (isset($conf['canvas_text'])) {
    $content['map']['#canvas_text'] = check_markup($conf['canvas_text']['value'], $conf['canvas_text']['format']);
  }

  // Mark that search JS was attached.
  $is_attached = &drupal_static('adbn_map_search_attached', FALSE);
  $is_attached = TRUE;

  $block->title = '';
  $block->content = $content;
  return $block;
}

/**
 * Theme hook for plugin.
 */
function adbn_map_bird_detail_content_type_theme(&$theme, $plugin) {
  $theme['bird_detail'] = array(
    'variables' => array(
      'css_path' => NULL,
      'popup_text' => NULL,
      'title' => NULL,
      'canvas_text' => '',
      'bird_category' => NULL,
      'map_short_description_mobile' => NULL,
      'map_short_description_desktop' => NULL,
    ),
    'path' => $plugin['path'],
    'template' => 'bird-detail',
  );
}

/**
 * Edit form for Bird detail content type.
 */
function adbn_map_bird_detail_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['canvas_text'] = array(
    '#type' => 'text_format',
    '#format' => 'full_html',
    '#title' => t('Canvas text'),
    '#default_value' => !empty($conf['canvas_text']) ? $conf['canvas_text'] : '',
  );

  return $form;
}

/**
 * Submit callback for Bird detail content type edit form.
 */
function adbn_map_bird_detail_edit_form_submit($form, &$form_state) {
  $form_state['conf']['canvas_text'] = $form_state['values']['canvas_text'];
}
