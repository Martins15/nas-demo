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

  // Get the bird id if available.
  if (isset($node->field_bird_id[LANGUAGE_NONE][0]['value'])) {
    $bird_id = $node->field_bird_id[LANGUAGE_NONE][0]['value'];
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
  $langcode = $node->language == 'es' ? 'es' : 'en';
  $options = array('langcode' => $langcode);
  $content['map'] = array(
    '#theme' => 'bird_detail',
    '#langcode' => $langcode,
    '#css_path' => $map_css_path,
    '#description' => t('The darker the color, the more favorable the climate conditions are for survival. The outlined areas represent approximate current range for each season.', array(), $options),
    '#link_text' => t('More on reading these maps.', array(), $options),
    '#img_path' => drupal_get_path('module', 'adbn_map') . '/img',
    '#title' => $bird_name,
    '#bird_category' => $bird_category_output,
  );

  if (isset($conf['canvas_text'])) {
    $value = token_replace($conf['canvas_text'][$langcode]['value'], array('node' => $node), array('clear' => TRUE));
    $content['map']['#canvas_text'] = check_markup($value, $conf['canvas_text'][$langcode]['format']);
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
      'langcode' => 'en',
      'css_path' => NULL,
      'title' => NULL,
      'description' => '',
      'link_text' => '',
      'img_path' => '',
      'canvas_text' => '',
      'bird_category' => NULL,
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
    '#type' => 'fieldset',
    '#title' => t('Canvas text'),
    '#tree' => TRUE,
  );

  foreach (language_list() as $language) {
    $form['canvas_text'][$language->language] = array(
      '#type' => 'text_format',
      '#title' => $language->name,
      '#format' => 'full_html',
      '#default_value' => !empty($conf['canvas_text']) ? $conf['canvas_text'][$language->language]['value'] : '',
    );
  }

  $rows = array();
  $rows[] = array(
    'id' => 'bird',
    'data' => array('Bird node', ''),
    'class' => array('token-group'),
  );

  foreach (field_info_instances('node', 'bird') as $instance) {
    $rows[] = array(
      'parent' => 'bird',
      'data' => array($instance['label'], '[node:' . $instance['field_name'] . ']'),
    );
  }

  $form['tokens'] = array('#type' => 'fieldset', '#title' => t('Replacement patterns'));
  $form['tokens']['tree'] = array(
    '#theme' => 'tree_table',
    '#header' => array(
      t('Name'),
      t('Token'),
    ),
    '#rows' => $rows,
    '#attributes' => array('class' => array('token-tree')),
    '#empty' => t('No tokens available'),
    '#attached' => array(
      'js' => array(drupal_get_path('module', 'token') . '/token.js'),
      'css' => array(drupal_get_path('module', 'token') . '/token.css'),
      'library' => array(array('token', 'treeTable')),
    ),
  );

  $form['#after_build'][] = 'adbn_map_bird_detail_edit_form_after_build';

  return $form;
}

/**
 * After build handler for Bird Detail edit form.
 */
function adbn_map_bird_detail_edit_form_after_build($form, &$form_state) {
  foreach (element_children($form['canvas_text']) as $child) {
    $form['canvas_text'][$child]['format']['#access'] = FALSE;
  }

  return $form;
}

/**
 * Submit callback for Bird detail content type edit form.
 */
function adbn_map_bird_detail_edit_form_submit($form, &$form_state) {
  $form_state['conf']['canvas_text'] = $form_state['values']['canvas_text'];
}
