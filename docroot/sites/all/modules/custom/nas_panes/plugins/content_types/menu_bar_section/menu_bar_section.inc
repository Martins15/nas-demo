<?php

/**
 * @file
 * Define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Menu Bar Section'),
  'description' => t('Menu Bar Section.'),
  'category' => 'NAS',
  'edit form' => 'menu_bar_section_form',
  'render callback' => 'menu_bar_section_render',
);

/**
 * An edit form for the pane's settings.
 */
function menu_bar_section_form($form, &$form_state) {
  $conf = $form_state['conf'];
  _nas_panes_hide_pane_title_field($form);
  $options = menu_parent_options(array(NAS_PANES_MAIN_MENU_NAME => NAS_PANES_MAIN_MENU_NAME), NULL);

  $form['default_menu_item'] = array(
    '#type' => 'select',
    '#title' => t('Default menu item'),
    '#options' => $options,
    '#default_value' => NAS_PANES_MAIN_MENU_NAME . ':' . $conf['default_menu_item'],
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function menu_bar_section_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      if ($key == 'default_menu_item') {
        // Default format of options MENU_NAME:mlid. We need save only mlid.
        list(, $mlid) = explode(':', $form_state['values'][$key]);
        $form_state['conf'][$key] = $mlid;
      }
      else {
        $form_state['conf'][$key] = $form_state['values'][$key];
      }
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 *
 * @see ctools_plugin_examples()
 */
function menu_bar_section_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();
  $items = array();

  $parent = menu_link_load($conf['default_menu_item']);
  $parameters = array(
    'active_trail' => array($parent['plid']),
    'only_active_trail' => FALSE,
    'min_depth' => $parent['depth'] + 1,
    'max_depth' => $parent['depth'] + 1,
    'conditions' => array('plid' => $parent['mlid']),
  );

  $menu_items = i18n_menu_localize_tree(menu_build_tree(NAS_PANES_MAIN_MENU_NAME, $parameters));

  foreach ($menu_items as $item) {
    $items[] = l(t($item['link']['link_title']), $item['link']['link_path']);
  }

  $block->content = theme('menu_bar_section', array('items' => $items));

  return $block;
}
