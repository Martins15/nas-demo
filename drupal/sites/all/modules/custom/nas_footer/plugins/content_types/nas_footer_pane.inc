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
        'logo_path' => 'public://footer-logo.png',
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

  $form['logo_path'] = array(
      '#type' => 'textfield',
      '#title' => t('Path to logo'),
      //'#description' => t('Text to display, it may use substitution strings'),
      '#default_value' => $conf['logo_path'],
  );

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

  $logo = '';
  $logo_path = filter_xss($conf['logo_path']);
  if ($logo_path) {
    $logo = theme_image(array('path' => file_create_url($logo_path), 'alt' => '', 'attributes' => array('class' => array('footer-logo'))));
  }

  // Update the strings to allow contexts.
  if (!empty($contexts)) {
    $title = ctools_context_keyword_substitute(filter_xss($conf['title']), array(), $contexts);
    $mission = ctools_context_keyword_substitute(filter_xss($conf['mission']), array(), $contexts);
    $copyright = ctools_context_keyword_substitute(filter_xss($conf['copyright']), array(), $contexts);
  }

  $footer_copyright_menu = theme('nas_footer_copyright_menu', array('menu_tree' => $footer_copyright_menu_tree));
  $footer_menu = theme('nas_footer_menu', array('menu_tree' => $footer_menu_tree));

  $block = new stdClass();

  ctools_include('ajax');
  ctools_include('modal');
  ctools_modal_add_js();
  // Add ajax-responder so ctools_ajax_command_reload() will work.
  ctools_add_js('ajax-responder');
  $pid = db_query('SELECT pid FROM {panels_pane} WHERE type = :type', array(':type' => 'nas_footer_pane'))->fetchField();
  if (empty($pid)) {
    nas_footer_save_footer_pane();
    $pid = db_query('SELECT pid FROM {panels_pane} WHERE type = :type', array(':type' => 'nas_footer_pane'))->fetchField();
//    $pid = 'new-' . ctools_uuid_generate();
  }

  $custom_links = array(
    'pane-edit' => array(
      'title' => t('edit texts/logo'),
      'href' => 'panels/ajax/editor/edit-pane/panel_context:site_template::site_template_panel_context_2::::/' . $pid,
      'query' => array('reload' => 'true'),
      'attributes' => array('class' => array('ctools-use-modal')),
    ),
  );

  $contextual_links['menu'] = nas_menu_cl(NAS_MENU_FOOTER_MENU, $custom_links);
  $contextual_links['cr_menu'] = nas_menu_cl(NAS_MENU_FOOTER_COPYRIGHT_MENU);

  $t_vars = array(
    'logo' => $logo,
    'mission_title' => $title,
    'mission' => $mission,
    'copyright' => $copyright,
    'footer_menu' => $footer_menu,
    'footer_copyright_menu' => $footer_copyright_menu,
    'contextual_links' => $contextual_links
  );
  $content = theme('nas_footer', $t_vars);
  $block->title = t('Footer');
  $block->content = $content;

  return $block;
}