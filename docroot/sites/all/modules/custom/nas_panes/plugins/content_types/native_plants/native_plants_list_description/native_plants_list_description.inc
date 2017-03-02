<?php

/**
 * @file
 * Native Plants List description plugin.
 */

$plugin = array(
  'title' => t('Native Plants List description'),
  'description' => t('Native Plants List description.'),
  'category' => 'Native Plants',
  'admin info' => 'native_plants_list_description_admin_info',
  'edit form' => 'native_plants_list_description_edit_form',
  'render callback' => 'native_plants_list_description_render',
  'hook theme' => 'native_plants_list_description_theme',
  'required context' => array(
    new ctools_context_required(t('Permalink'), 'entity:permalink'),
  ),
  'defaults' => array(
    'title' => 'Your Native Plant List',
    'override_title_text' => 'Your Native Plant List',
    'text' => array(
      'value' => '<p>Thank you for planting for birds. With your help, we can grow 1 million bird-friendly plants.&nbsp;Below you can find the plant list you selected from <a href="/native-plants">Audubon&#39;s Native Plants Database</a>.</p>
<p>You can access this list on the web at any time using the following link:</p>',
      'format' => 'full_html',
    ),
  ),
);

/**
 * Administrative info callback.
 */
function native_plants_list_description_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = $conf['override_title_text'];
  $block->content = check_markup($conf['text']['value'], $conf['text']['format']);
  return $block;
}

/**
 * Configuration form.
 */
function native_plants_list_description_edit_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  $form['override_title_heading']['#access'] = FALSE;
  $form['text'] = array(
    '#type' => 'text_format',
    '#title' => t('Text'),
    '#default_value' => $conf['text']['value'],
    '#format' => $conf['text']['format'],
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function native_plants_list_description_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (array_key_exists($key, $form_state['values'])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }

  // Form build ID is required for contextual links.
  $form_state['conf']['form_build_id'] = $form_state['values']['form_build_id'];
}

/**
 * Render callback.
 */
function native_plants_list_description_render($subtype, $conf, $args, $contexts) {
  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);

  $permalink = reset($contexts)->data;
  $permalink_url = url('native-plants/list/' . $permalink->uuid, array('absolute' => TRUE));

  $text = ctools_context_keyword_substitute($conf['text']['value'], array(), $contexts);
  $text = check_markup($text, $conf['text']['format']);
  $text = strtr($text, array('!permalink' => l($permalink_url, $permalink_url)));
  $title = filter_xss($conf['override_title_text']);

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'native_plants_list_description',
    '#title' => t('@title', array('@title' => $title)),
    '#text' => $text,
    '#permalink' => $permalink_url,
    '#context_links' => $contextual_links,
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function native_plants_list_description_theme(&$theme, $plugin) {
  $theme['native_plants_list_description'] = array(
    'variables' => array(
      'title' => '',
      'text' => '',
      'permalink' => '',
      'context_links' => '',
    ),
    'template' => 'native-plants-list-description',
    'path' => $plugin['path'],
  );
}
