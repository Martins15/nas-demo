<?php
/**
 * @file
 * Native Plants Share plugin.
 */

$plugin = array(
  'title' => t('Native Plants Share'),
  'description' => t('Native Plants Share.'),
  'category' => 'Native Plants',
  'admin info' => 'native_plants_share_admin_info',
  'edit form' => 'native_plants_share_edit_form',
  'render callback' => 'native_plants_share_render',
  'hook theme' => 'native_plants_share_theme',
  'no title override' => TRUE,
  'required context' => new ctools_context_required(t('Permalink'), 'entity:permalink'),
  'defaults' => array(
    'text' => array(
      'value' => '<p>By planting native plants, you will help birds and the environment both locally and across the continent.</p>',
      'format' => 'full_html',
    ),
    'label_desktop' => 'Share your pledge',
    'label_mobile' => 'Spread the word',
  ),
);

/**
 * Configuration form.
 */
function native_plants_share_edit_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  $form['text'] = array(
    '#type' => 'text_format',
    '#title' => t('Text'),
    '#default_value' => $conf['text']['value'],
    '#format' => $conf['text']['format'],
  );
  $form['label_desktop'] = array(
    '#type' => 'textfield',
    '#title' => t('Desktop label'),
    '#default_value' => $conf['label_desktop'],
  );
  $form['label_mobile'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobile label'),
    '#default_value' => $conf['label_mobile'],
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function native_plants_share_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (array_key_exists($key, $form_state['values'])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }

  // Form build ID is required for contextual links.
  $form_state['conf']['form_build_id'] = $form_state['values']['form_build_id'];
}

/**
 * Administrative info callback.
 */
function native_plants_share_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = t('List share');
  $block->content = t('List share');
  return $block;
}

/**
 * Render callback.
 */
function native_plants_share_render($subtype, $conf, $args, $context) {
  $permalink = $context->data;

  $permalink_url = url('pl/' . $permalink->uuid, array('absolute' => TRUE));

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'native_plants_share',
    '#text' => check_markup($conf['text']['value'], $conf['text']['format']),
    '#label_desktop' => t(filter_xss($conf['label_desktop'])),
    '#label_mobile' => t(filter_xss($conf['label_mobile'])),
    '#permalink' => $permalink_url,
    '#twitter_url' => url('http://twitter.com/share', array(
      'query' => array(
        'text' => '',
        'via' => 'audubonsociety',
        'url' => $permalink_url,
      ),
    )),
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function native_plants_share_theme(&$theme, $plugin) {
  $theme['native_plants_share'] = array(
    'variables' => array(
      'text' => '',
      'label_mobile' => '',
      'label_desktop' => '',
      'permalink' => '',
      'twitter_url' => '',
    ),
    'template' => 'native-plants-share',
    'path' => $plugin['path'],
  );
}

/**
 * Preprocess function.
 */
function nas_panes_preprocess_native_plants_share(&$variables) {

}
