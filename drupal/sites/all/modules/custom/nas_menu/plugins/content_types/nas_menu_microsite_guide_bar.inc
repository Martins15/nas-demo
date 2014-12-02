<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Bird Guide Bar'),
  'description' => t('Display bird guide bar used on microsites'),
  'category' => 'NAS Header/Footer',
  'edit form' => 'nas_menu_guide_bar_pane_edit_form',
  'render callback' => 'nas_menu_guide_bar_pane_render',
  'defaults' => array(
    'title' => '',
    'preamble' => '',
    'logo' => '',
    'css_class' => '',
    'css_background_style' => '',
  ),
  'all contexts' => TRUE,
);

/**
 * An edit form for the pane's settings.
 */
function nas_menu_guide_bar_pane_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Guide Bar Title'),
    '#description' => t('span tag is allowed'),
    '#default_value' => $conf['title'],
  );

  $form['preamble'] = array(
    '#type' => 'textfield',
    '#title' => t('Preamble'),
    '#default_value' => $conf['preamble'],
  );

  $form['logo'] = array(
    '#type' => 'textfield',
    '#title' => t('Path to logo'),
    '#default_value' => $conf['logo'],
  );

  $form['css_class'] = array(
    '#type' => 'textfield',
    '#title' => t('CSS class'),
    '#description' => t('Separate multiple classes by space'),
    '#default_value' => $conf['css_class'],
  );

  $form['css_background_style'] = array(
    '#type' => 'textfield',
    '#title' => t('CSS background color'),
    '#description' => t('Input any valid CSS style background color attribute(Ex: #276074, red)'),
    '#default_value' => $conf['css_background_style'],
  );

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function nas_menu_guide_bar_pane_edit_form_submit(&$form, &$form_state) {
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
function nas_menu_guide_bar_pane_render($subtype, $conf, $args, $contexts) {
  $title = filter_xss($conf['title'], array('span'));
  $preamble = check_plain($conf['preamble']);
  $css_class = trim(check_plain($conf['css_class']));
  $css_background_style = check_plain($conf['css_background_style']);
  $logo_path = check_plain($conf['logo']);
  if ($logo_path) {
    $logo = theme_image(array('path' => file_create_url($logo_path), 'alt' => '', 'attributes' => array('class' => array('canon-logo'))));
  }

  $pane_attr = array('class' => array('guide-bar'));
  $custom_classes = explode(' ', $css_class);
  foreach ($custom_classes as $custom_class) {
    $pane_attr['class'][] = $custom_class;
  }
  if ($css_background_style) {
    $pane_attr['style'] = 'background-color: ' . $css_background_style;
  }

  $contextual_links = '';
  if (module_exists('contextual') && user_access('access contextual links')) {
    ctools_include('ajax');
    ctools_include('modal');
    ctools_modal_add_js();
    // Add ajax-responder so ctools_ajax_command_reload() will work.
    ctools_add_js('ajax-responder');
    $pid = db_query('SELECT pid FROM {panels_pane} WHERE type = :type', array(':type' => $subtype))->fetchField();
    if (empty($pid)) {
      nas_panes_resave_panel(NAS_PANES_BIRD_GUIDE_PAGE_MANAGER_CACHE_KEY);
      $pid = db_query('SELECT pid FROM {panels_pane} WHERE type = :type', array(':type' => $subtype))->fetchField();
    }

    $links = array(
      'pane-edit' => array(
        'title' => t('edit guide bar'),
        'href' => 'panels/ajax/editor/edit-pane/panel_context:' . NAS_PANES_BIRD_GUIDE_PAGE_MANAGER_CACHE_KEY . '::page_bird_guide_panel_context::::/' . $pid,
        'query' => array('reload' => 'true'),
        'attributes' => array('class' => array('ctools-use-modal')),
      ),
    );
    $pane_attr['class'][] = 'contextual-links-region';

    $build = array(
      '#prefix' => '<div class="contextual-links-wrapper">',
      '#suffix' => '</div>',
      '#theme' => 'links__contextual',
      '#links' => $links,
      '#attributes' => array('class' => array('contextual-links')),
      '#attached' => array(
        'library' => array(array('contextual', 'contextual-links')),
      ),
    );
    $contextual_links = drupal_render($build);
  }

  $block = new stdClass();

  $t_vars = array(
    'div_attributes' => drupal_attributes($pane_attr),
    'title' => $title,
    'preamble' => $preamble,
    'logo' => $logo,
    'contextual_links' => $contextual_links,
  );
  $content = theme('nas_guide_bar', $t_vars);
  $block->title = t('Footer');
  $block->content = $content;

  return $block;
}