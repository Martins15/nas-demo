<?php
/**
 * @file
 * Special message to show when there is no translation of the page.
 */

$plugin = array(
  'title' => t('Language message'),
  'description' => t('Special message to show when there is no translation of the page.'),
  'category' => 'NAS',
  'admin info' => 'nas_language_message_admin_info',
  'edit form' => 'nas_language_message_edit_form',
  'render callback' => 'nas_language_message_render',
  'hook theme' => 'nas_language_message_theme',
  'defaults' => array(
    'title' => '¡Atención!',
    'override_title_text' => '¡Atención!',
  ),
);

define('NAS_LANGUAGE_DEFAULT_SPANISH_MESSAGE', 'La página que intenta visitar sólo está disponible en inglés. ¡Disculpa!');
define('NAS_LANGUAGE_DEFAULT_ENGLISH_MESSAGE', 'The page you are about to visit is currently only available in English. Sorry!');

/**
 * Callback to provide administrative info.
 */
function nas_language_message_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = $conf['title'];
  $block->content =
    variable_get('nas_language_message_fieldset_spanish_message', NAS_LANGUAGE_DEFAULT_SPANISH_MESSAGE) .
    '<br />' .
    variable_get('nas_language_message_fieldset_english_message', NAS_LANGUAGE_DEFAULT_ENGLISH_MESSAGE);
  return $block;
}

/**
 * Configuration form.
 */
function nas_language_message_edit_form($form, &$form_state) {
  $form['override_title_heading']['#access'] = FALSE;
  $form['spanish_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Spanish message'),
    '#default_value' => variable_get('nas_language_message_fieldset_spanish_message', NAS_LANGUAGE_DEFAULT_SPANISH_MESSAGE),
    '#size' => 100,
  );
  $form['english_message'] = array(
    '#type' => 'textfield',
    '#title' => t('English message'),
    '#default_value' => variable_get('nas_language_message_fieldset_english_message', NAS_LANGUAGE_DEFAULT_ENGLISH_MESSAGE),
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
    '#default_value' => variable_get('nas_language_message_fieldset_image', 0),
  );
  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'nas_language_message', 'nas_panes', 'plugins/content_types/nas_language_message');

  return $form;
}

/**
 * Submit handler for configuration.
 */
function nas_language_message_edit_form_submit(&$form, &$form_state) {
  // Form build ID is required for contextual links.
  $form_state['conf']['form_build_id'] = $form_state['input']['form_build_id'];

  variable_set('nas_language_message_fieldset_spanish_message', $form_state['values']['spanish_message']);
  variable_set('nas_language_message_fieldset_english_message', $form_state['values']['english_message']);
  variable_set('nas_language_message_fieldset_image', $form_state['values']['image']);
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
    'library' => array(
      array('system', 'jquery.cookie'),
    ),
    'css' => array(
      $plugin['path'] . '/css/nas_language_message.css',
    ),
    'js' => array(
      $plugin['path'] . '/js/nas_language_message.js',
      $plugin['path'] . '/js/nas_language_message.modal.js',
    ),
  );

  $image_path = $plugin['path'] . '/img/pinguin.png';
  if ($image = file_load(variable_get('nas_language_message_fieldset_image', 0))) {
    $image_path = nas_alters_local_image_uri($image->uri);
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
        'spanish_message' => filter_xss(variable_get('nas_language_message_fieldset_spanish_message', NAS_LANGUAGE_DEFAULT_SPANISH_MESSAGE)),
        'english_message' => filter_xss(variable_get('nas_language_message_fieldset_english_message', NAS_LANGUAGE_DEFAULT_SPANISH_MESSAGE)),
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
