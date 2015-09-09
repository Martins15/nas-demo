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

  // As we have multiple site template variants footer block settings should be
  // populate to all of the panes.
  db_query('UPDATE {panels_pane} SET configuration = :configuration WHERE type = :type', array(
    ':configuration' => serialize($form_state['conf']),
    ':type' => 'nas_footer_pane',
  ));
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function nas_footer_pane_custom_pane_render($subtype, $conf, $args, $contexts) {

  $footer_menu_tree = i18n_menu_localize_tree(menu_tree_all_data(NAS_MENU_FOOTER_MENU));
  $footer_copyright_menu_tree = i18n_menu_localize_tree(menu_tree_all_data(NAS_MENU_FOOTER_COPYRIGHT_MENU));
  foreach ($footer_copyright_menu_tree as $key => $value) {
    if ($value['link']['hidden'] == TRUE) {
      unset($footer_copyright_menu_tree[$key]);
    }
  }
  foreach ($footer_menu_tree as $key => $value) {
    foreach ($footer_menu_tree[$key]['below'] as $keys => $values) {
      if ($values['link']['hidden'] == TRUE) {
        unset($footer_menu_tree[$key]['below'][$keys]);
      }
    }
  }
  $title = '';
  $mission = '';
  $copyright = '';

  $logo = '';
  $logo_path = filter_xss($conf['logo_path']);
  if ($logo_path) {
    $logo = theme_image(array('path' => file_create_url($logo_path), 'alt' => '', 'attributes' => array('class' => array('footer-logo'))));
  }

  $title = filter_xss($conf['title']);
  $mission = filter_xss($conf['mission']);
  $copyright = filter_xss($conf['copyright']);

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
  }

  $custom_links = nas_footer_pane_get_contextual_links();

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

function nas_footer_pane_get_contextual_links() {
  if (!user_access('edit NAS panes')) {
    return array();
  }

  $pm_page = page_manager_get_current_page();
  if (!isset($pm_page) || !isset($pm_page['handler']->conf['panels_everywhere_site_template'])) {
    return array();
  }

  ctools_include('modal');
  ctools_modal_add_js();
  // Add ajax-responder so ctools_ajax_command_reload() will work.
  ctools_add_js('ajax-responder');

  // Lookup pid.
  if (empty($pm_page['handler']->conf['display'])) {
    $pm_page['handler']->conf['display'] = panels_load_display($pm_page['handler']->conf['did']);
  }
  $pid = 0;
  // Get pid from loaded display.
  foreach ($pm_page['handler']->conf['display']->content as $_pid => $pane) {
    if (($pane->subtype == 'nas_footer_pane')) {
      $pid = $_pid;
      break;
    }
  }
  // @todo sometimes cache_key is empty. We need build it manually.
  if (isset($pm_page['handler']->conf['display']->cache_key)) {
    $cache_key = $pm_page['handler']->conf['display']->cache_key;
  }
  if (empty($cache_key)) {
    $cache_key = 'panel_context:site_template::' . $pm_page['handler']->conf['panels_everywhere_site_template'] . '::::';
  }
  $links = array(
    'edit' => array(
      'title' => t('edit text/logo'),
      'href' => 'panels/ajax/editor/edit-pane/' . $cache_key . '/' . $pid,
      'query' => array('reload' => 'true', 'nas-panes-from-page' => 'true'),
      'attributes' => array('class' => array('ctools-use-modal')),
    ),
  );

  return $links;
}