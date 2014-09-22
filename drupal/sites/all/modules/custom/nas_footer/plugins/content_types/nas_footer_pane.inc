<?php

/**
 * @file
 * define ctools content type.
 */

define('NAS_MENU_FOOTER_MENU', 'menu-footer');
define('NAS_MENU_FOOTER_COPYRIGHT_MENU', 'menu-footer-copyright');

$plugin = array(
    'single' => TRUE,
    'title' => t('Footer'),
    'description' => t('Display footer section'),
    'category' => 'NAS Header/Footer',
    'edit form' => 'nas_footer_pane_custom_pane_edit_form',
    'render callback' => 'nas_footer_pane_custom_pane_render',
    'admin info' => 'nas_footer_pane_custom_pane_admin_info',
    'defaults' => array(
        'title' => '',
        'mission' => '',
        'copyright' => '',
    ),
    'all contexts' => TRUE,
);

/**
 * An edit form for the pane's settings.
 */
function nas_footer_pane_custom_pane_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['title'] = array(
      '#type' => 'textfield',
      '#title' => t('Mission title'),
      //'#description' => t('Text to display, it may use substitution strings'),
      '#default_value' => $conf['title'],
  );

  $form['mission'] = array(
      '#type' => 'textarea',
      '#title' => t('Mission'),
      //'#description' => t('Text to display, it may use substitution strings'),
      '#default_value' => $conf['mission'],
  );

  $form['copyright'] = array(
      '#type' => 'textfield',
      '#title' => t('Copyright'),
      //'#description' => t('Text to display, it may use substitution strings'),
      '#default_value' => $conf['title'],
  );

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function nas_footer_pane_custom_pane_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function nas_footer_pane_custom_pane_render($subtype, $conf, $args, $contexts) {

  $footer_menu_tree = menu_tree_all_data(NAS_MENU_FOOTER_MENU, 2);
  $footer_copyright_menu_tree = menu_tree_all_data(NAS_MENU_FOOTER_COPYRIGHT_MENU, 2);

  $title = '';
  $mission = '';
  $copyright = '';
  // Update the strings to allow contexts.
  if (!empty($contexts)) {
    $title = ctools_context_keyword_substitute(filter_xss($conf['title']), array(), $contexts);
    $mission = ctools_context_keyword_substitute(filter_xss($conf['mission']), array(), $contexts);
    $copyright = ctools_context_keyword_substitute(filter_xss($conf['copyright']), array(), $contexts);
  }

  $footer_copyright_menu = theme('nas_footer_copyright_menu', array('menu_tree' => $footer_copyright_menu_tree));
  $footer_menu = theme('nas_footer_menu', array('menu_tree' => $footer_menu_tree));

  $block = new stdClass();

  $t_vars = array(
      'mission_title' => $title,
      'mission' => $mission,
      'copyright' => $copyright,
      'footer_menu' => $footer_menu,
      'footer_copyright_menu' => $footer_copyright_menu,
  );
  $content = theme('nas_footer', $t_vars);
  $block->title = t('Footer');
  $block->content = $content;

  return $block;
}