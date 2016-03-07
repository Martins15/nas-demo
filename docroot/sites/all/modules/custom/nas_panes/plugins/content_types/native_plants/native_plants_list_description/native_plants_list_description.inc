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
    'title'=> 'Your Native Plant List',
    'override_title_text' => 'Your Native Plant List',
    'text_top' => array(
      'value' => '<p>Thanks for joining the world\'s largest bird sanctuary. Below you can find the plant list you selected from <a href="/native-plants">Audubon\'s Native Plants Database</a>.</p><p>You can access this list on the web at any time using the following link:</p>',
      'format' => 'full_html',
    ),
    'share_label' => 'Share your list',
    'text_bottom' => array(
      'value' => '<p>To access local resources and places to buy native plants in your area, visit our <a href="#">Native Plants Resources page</a> and enter your zip code.</p>',
      'format' => 'full_html',
    ),
  ),
);

/**
 * Administrative info callback.
 */
function native_plants_list_description_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = $conf['title'];
  $block->content = check_markup($conf['text_top']['value'], $conf['text_top']['format']);
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
  $form['text_top'] = array(
    '#type' => 'text_format',
    '#title' => t('Text top'),
    '#default_value' => $conf['text_top']['value'],
    '#format' => $conf['text_top']['format'],
  );
  $form['share_label'] = array(
    '#type' => 'textfield',
    '#title' => t('Share label'),
    '#default_value' => $conf['share_label'],
  );
  $form['text_bottom'] = array(
    '#type' => 'text_format',
    '#title' => t('Text bottom'),
    '#default_value' => $conf['text_bottom']['value'],
    '#format' => $conf['text_bottom']['format'],
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
  // $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $context);

  $permalink = reset($contexts)->data;
  $permalink_url = url('native-plants/list/' . $permalink->uuid, array('absolute' => TRUE));

  $text_top = ctools_context_keyword_substitute($conf['text_top']['value'], array(), $contexts);
  $text_top = check_markup($text_top, $conf['text_top']['format']);
  $text_bottom = ctools_context_keyword_substitute($conf['text_bottom']['value'], array(), $contexts);
  $text_bottom = check_markup($text_bottom, $conf['text_bottom']['format']);

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'native_plants_list_description',
    '#title' => t(filter_xss($conf['title'])),
    '#text_top' => $text_top,
    '#share_label' => t(filter_xss($conf['share_label'])),
    '#permalink' => $permalink_url,
    '#twitter_url' => url('http://twitter.com/share', array(
      'query' => array(
        'text' => '',
        'via' => 'audubonsociety',
        'url' => $permalink_url,
      ),
    )),
    '#text_bottom' => $text_bottom,
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
      'text_top' => '',
      'share_label' => '',
      'permalink' => '',
      'twitter_url' => '',
      'text_bottom' => '',
    ),
    'template' => 'native-plants-list-description',
    'path' => $plugin['path'],
  );
}
