<?php

/**
 * @file
 * Define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Conservation Menu Bar'),
  'description' => t('Conservation Menu Bar.'),
  'category' => 'NAS',
  'edit form' => 'conservation_menu_bar_form',
  'render callback' => 'conservation_menu_bar_render',
);

/**
 * An edit form for the pane's settings.
 */
function conservation_menu_bar_form($form, &$form_state) {
  $conf = $form_state['conf'];
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
function conservation_menu_bar_form_submit(&$form, &$form_state) {
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
function conservation_menu_bar_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();
  $items = array();

  $parameters = array(
    'only_active_trail' => FALSE,
    'min_depth' => 2,
    'max_depth' => 2,
    'conditions' => array('plid' => $conf['default_menu_item']),
  );

  $menu_items = menu_build_tree(NAS_PANES_MAIN_MENU_NAME, $parameters);

  foreach ($menu_items as $item) {
    $items[] = l($item['link']['link_title'], $item['link']['link_path']);
  }

  $block->content = theme('conservation_menu_bar', array(
      'items' => $items,
    ));

  return $block;
}

