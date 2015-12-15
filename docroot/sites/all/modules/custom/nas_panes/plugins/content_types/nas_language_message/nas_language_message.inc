<?php
/**
 * @file
 * Special message to show when there is no translation of the page.
 */

$plugin = array(
  'title' => t('Language message'),
  'description' => t('Special message to show when there is no translation of the page.'),
  'category' => 'NAS',
  'edit form' => 'nas_language_message_edit_form',
  // 'no title override' => TRUE,
  'render callback' => 'nas_language_message_render',
  'hook theme' => 'nas_language_message_theme',
  'defaults' => array(
    'title' => '¡Atención!',
    'override_title_text' => '¡Atención!',
    'spanish_message' => 'La página que intenta visitar sólo está disponible en inglés. ¡Disculpa!',
    'english_message' => 'The page you are about to visit is currently only available in English. Sorry!',
    'image' => 0,
  ),
);

/**
 * Configuration form.
 */
function nas_language_message_edit_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  $form['override_title_heading']['#access'] = FALSE;
  $form['spanish_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Spanish message'),
    '#default_value' => $conf['spanish_message'],
    '#size' => 100,
  );
  $form['english_message'] = array(
    '#type' => 'textfield',
    '#title' => t('English message'),
    '#default_value' => $conf['english_message'],
    '#size' => 100,
  );

  $form['image'] = array(
    '#type' => 'media',
    '#tree' => TRUE,
    '#title' => t('Image'),
    '#description' => t('Allowed formats: png, jpg, jpeg, gif.'),
    '#media_options' => array(
      'global' => array(
        'file_extensions' => 'png jpg jpeg gif',
        'max_filesize' => '20 MB',
        'file_directory' => '',
        'types' => array('image'),
      ),
    ),
    '#default_value' => $conf['image'],
  );
  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'nas_language_message', 'nas_panes', 'plugins/content_types/nas_language_message');

  return $form;
}

/**
 * Submit handler for configuration.
 */
function nas_language_message_edit_form_submit(&$form, &$form_state) {
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
function nas_language_message_render($subtype, $conf, $args, $context) {
  // $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $context);

  $block = new stdClass();
  $block->content = array(
    '#markup' => '',
  );

  if (!$plugin = ctools_get_plugins('ctools', 'content_types', $subtype)) {
    return $block;
  }

  $block->content['#attached'] = array(
    'css' => array(
      $plugin['path'] . '/css/nas_language_message.css',
    ),
    'js' => array(
      $plugin['path'] . '/js/nas_language_message.js',
      $plugin['path'] . '/js/nas_language_message.modal.js',
    ),
  );

  $image_path = $plugin['path'] . '/img/pinguin.png';
  if ($image = file_load($conf['image'])) {
    $image_path = $image->uri;
  }

  ctools_include('modal');
  ctools_modal_add_js();

  $settings = array(
    'naslanguagemessagemodal' => array(
      'modalSize' => array(
        'type' => 'notscale',
        'width' => 400,
        'height' => 320,
        'addWidth' => 0,
        'addHeight' => 0,
        'contentRight' => 0,
        'contentBottom' => 0,
      ),
      'modalTheme' => 'NASLanguageMessageModalDialog',
      // 'throbberTheme' => 'NASLanguageMessageModalThrobber',
      'modalOptions' => array(
        'opacity' => 0.55,
        'background' => '#000',
      ),
      'animation' => 'fadeIn',
      'animationSpeed' => 'slow',
      'closeText' => t('Okay'),
      'closeImage' => '',
      'loadingText' => filter_xss($conf['title']),
      'throbber' => theme('nas_language_message', array(
        'title' => filter_xss($conf['title']),
        'spanish_message' => filter_xss($conf['spanish_message']),
        'english_message' => filter_xss($conf['english_message']),
        'image' => theme('image', array(
          'path' => $image_path,
        )),
      )),
    ),
  );
  $block->content['#attached']['js'][] = array(
    'data' => $settings,
    'type' => 'setting',
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function nas_language_message_theme(&$theme, $plugin) {
  $theme['nas_language_message'] = array(
    'variables' => array(
      'title' => '',
      'spanish_message' => '',
      'english_message' => '',
      'image' => '',
    ),
    'template' => 'nas-language-message',
    'path' => $plugin['path'],
  );
}
