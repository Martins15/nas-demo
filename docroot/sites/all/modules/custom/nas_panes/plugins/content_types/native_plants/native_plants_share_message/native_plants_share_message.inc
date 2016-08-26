<?php
/**
 * @file
 * Native Plants Share message plugin.
 */

$plugin = array(
  'title' => t('Native Plants Share message'),
  'description' => t('Native Plants Share message.'),
  'category' => 'Native Plants',
  'admin info' => 'native_plants_share_message_admin_info',
  'edit form' => 'native_plants_share_message_edit_form',
  'render callback' => 'native_plants_share_message_render',
  'hook theme' => 'native_plants_share_message_theme',
  'no title override' => TRUE,
  'all contexts' => TRUE,
  'defaults' => array(
    'title_desktop' => 'Tell your friends',
    'title_mobile' => 'Tell your friends',
    'share_text' => "Join me in planting bird-friendly native plants as part of Audubon's Plants For Birds program...",
    'share_url' => 'native-plants',
  ),
);

/**
 * Administrative info callback.
 */
function native_plants_share_message_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = t('Native Plants Share message');
  $block->content = $conf['share_text'];
  return $block;
}

/**
 * Configuration form.
 */
function native_plants_share_message_edit_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  $form['title_desktop'] = array(
    '#type' => 'textfield',
    '#title' => t('Desktop title'),
    '#default_value' => $conf['title_desktop'],
  );
  $form['title_mobile'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobile title'),
    '#default_value' => $conf['title_mobile'],
  );
  $form['share_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Text'),
    '#default_value' => $conf['share_text'],
  );
  $form['share_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Share URL or path'),
    '#default_value' => $conf['share_url'],
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function native_plants_share_message_edit_form_submit(&$form, &$form_state) {
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
function native_plants_share_message_render($subtype, $conf, $args, $contexts) {
  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);

  $share_url = url($conf['share_url'], array('absolute' => TRUE));
  $block = new stdClass();
  $block->content = array(
    '#theme' => 'native_plants_share_message',
    '#title_desktop' => t(filter_xss($conf['title_desktop'])),
    '#title_mobile' => t(filter_xss($conf['title_mobile'])),
    '#share_text' => $conf['share_text'],
    '#share_url' => $share_url,
    '#twitter_url' => url('http://twitter.com/share', array(
      'query' => array(
        'text' => $conf['share_text'],
        'via' => 'audubonsociety',
        'url' => $share_url,
      ),
    )),
    '#context_links' => $contextual_links,
  );

  if (!$plugin = ctools_get_plugins('ctools', 'content_types', $subtype)) {
    return $block;
  }

  $block->content['#attached'] = array(
    'js' => array(
      $plugin['path'] . '/js/native_plants_share_message.js',
      array(
        'data' => array(
          'native_plants_share_message' => array(
            'twitter_url' => url('http://twitter.com/share', array(
              'query' => array(
                'text' => 'share_text_placeholder',
                'via' => 'audubonsociety',
                'url' => $share_url,
              ),
            )),
          ),
        ),
        'type' => 'setting',
      ),
    ),
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function native_plants_share_message_theme(&$theme, $plugin) {
  $theme['native_plants_share_message'] = array(
    'variables' => array(
      'title_desktop' => '',
      'title_mobile' => '',
      'share_text' => '',
      'share_url' => '',
      'twitter_url' => '',
      'context_links' => '',
    ),
    'template' => 'native-plants-share-message',
    'path' => $plugin['path'],
  );
}
