<?php
/**
 * @file
 * Event social sharing block.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Social buttons for Event'),
  'description' => t('Provides Block with Social Buttons for Event page'),
  'category' => 'NAS',
  'edit form' => 'events_social_block_edit_form',
  'render callback' => 'events_social_block_render',
  'no title override' => TRUE,
  'all contexts' => TRUE,
  'hook theme' => 'events_social_block_theme',
  'defaults' => _events_social_block_defaults(),
);

/**
 * An edit form for the pane's settings.
 */
function events_social_block_edit_form($form, &$form_state) {
  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'events_social_block', 'asc_panes', 'plugins/content_types/events_social_block');

  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  $form['#tree'] = TRUE;
  $form['caption'] = array(
    '#type' => 'textfield',
    '#title' => t('Caption text'),
    '#default_value' => $conf['caption'],
  );
  $form['twitter_account'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter account'),
    '#default_value' => $conf['twitter_account'],
  );

  return $form;
}

/**
 * Submit callback.
 */
function events_social_block_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Render callback.
 */
function events_social_block_render($subtype, $conf, $args, $contexts) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $default_conf = _events_social_block_defaults();
  $conf = array_merge($default_conf, $conf);

  global $base_root;
  $page_link = $base_root . '/' . request_uri();
  $title = drupal_get_title();

  $contextual_links = nas_panes_build_page_contextual_links_from_current_page(
    $subtype,
    $conf,
    $args,
    $contexts
  );

  $block = new stdClass();
  $block->content = theme('events_social_block', array(
    'caption' => $conf['caption'],
    'title' => $title,
    'page_link' => $page_link,
    'contextual_links' => $contextual_links,
    'twitter_url' => url('http://twitter.com/share', array(
      'query' => array(
        // We need to remove the encoding done by check_plain() to allow the
        // url() function to correctly urlencode the query parameters.
        'text' => htmlspecialchars_decode($title, ENT_QUOTES),
        'via' => $conf['twitter_account'],
        'url' => $page_link,
      ),
    )),
  ));

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function events_social_block_theme(&$theme, $plugin) {
  $theme['events_social_block'] = array(
    'variables' => array(
      'caption' => NULL,
      'title' => NULL,
      'page_link' => NULL,
      'contextual_links' => NULL,
      'twitter_url' => NULL,
    ),
    'template' => 'events-social-block',
    'path' => $plugin['path'],
  );
}

/**
 * Helper function to return block defaults.
 */
function _events_social_block_defaults() {
  return array(
    'caption' => t('Share this event'),
    'twitter_account' => 'audubonsociety',
  );
}
