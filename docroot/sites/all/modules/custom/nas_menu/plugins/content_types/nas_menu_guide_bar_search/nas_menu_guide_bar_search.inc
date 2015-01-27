<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Bird Guide Bar with search'),
  'description' => t('Display bird guide bar used on birds pages'),
  'category' => 'NAS Header/Footer',
  'edit form' => 'nas_menu_guide_bar_search_pane_edit_form',
  'render callback' => 'nas_menu_guide_bar_search_pane_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * An edit form for the pane's settings.
 */
function nas_menu_guide_bar_search_pane_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $context = reset($form_state['display']->context);
  $conf_key = empty($context->data->nid) ? 'default' : $context->data->nid;

  $form[$conf_key] = array(
    '#type' => 'fieldset',
    '#title' => t('Related News settings'),
    '#tree' => TRUE,
  );

  $form[$conf_key]['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Guide Bar Title'),
    '#description' => t('span tag is allowed'),
    '#default_value' => !empty($conf[$conf_key]['title']) ? $conf[$conf_key]['title'] : $conf['default']['title'],
  );

  $form[$conf_key]['link'] = array(
    '#title' => t('Link'),
    '#type' => 'textfield',
    '#default_value' => !empty($conf[$conf_key]['link']) ? $conf[$conf_key]['link'] : $conf['default']['link'],
  );

  $form[$conf_key]['preamble'] = array(
    '#type' => 'textfield',
    '#title' => t('Preamble'),
    '#default_value' => !empty($conf[$conf_key]['preamble']) ? $conf[$conf_key]['preamble'] : $conf['default']['preamble'],
  );

  $form[$conf_key]['logo'] = array(
    '#type' => 'textfield',
    '#title' => t('Path to logo'),
    '#default_value' => !empty($conf[$conf_key]['logo']) ? $conf[$conf_key]['logo'] : $conf['default']['logo'],
  );

  $form[$conf_key]['css_class'] = array(
    '#type' => 'textfield',
    '#title' => t('CSS class'),
    '#description' => t('Separate multiple classes by space'),
    '#default_value' => !empty($conf[$conf_key]['css_class']) ? $conf[$conf_key]['css_class'] : $conf['default']['css_class'],
  );

  $form[$conf_key]['css_background_style'] = array(
    '#type' => 'textfield',
    '#title' => t('CSS background color'),
    '#description' => t('Input any valid CSS style background color attribute(Ex: #276074, red)'),
    '#default_value' => !empty($conf[$conf_key]['css_background_style']) ? $conf[$conf_key]['css_background_style'] : $conf['default']['css_background_style'],
  );

  return $form;
}

/**
 * Submit callback.
 */
function nas_menu_guide_bar_search_pane_edit_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Render callback.
 */
function nas_menu_guide_bar_search_pane_render($subtype, $conf, $args, $context) {
  $conf_key = !empty($context->data->nid) ? $context->data->nid : 'default';
  $block_conf = !empty($conf[$conf_key]) ? $conf[$conf_key] : $conf['default'];

  $title = !empty($block_conf['title']) ? filter_xss($block_conf['title'], array('span')) : '';
  $preamble = !empty($block_conf['preamble']) ? check_plain($block_conf['preamble']) : '';
  $css_class = !empty($block_conf['css_class']) ? trim(check_plain($block_conf['css_class'])) : '';
  $css_background_style = !empty($block_conf['css_background_style']) ? check_plain($block_conf['css_background_style']) : '';
  $logo_path = !empty($block_conf['logo']) ? check_plain($block_conf['logo']) : '';
  $link = !empty($block_conf['link']) ? url($block_conf['link']) : '';
  $logo = '';
  if (!empty($logo_path)) {
    $logo = theme_image(array(
        'path' => file_create_url($logo_path),
        'alt' => '',
        'attributes' => array('class' => array('canon-logo')),
      ));
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
  if (user_access('edit NAS panes')) {
    if ($conf_key == 'default') {
      $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);
    }
    else {
      $contextual_links = _nas_panes_build_panelizer_contextual_links($subtype, $context->data, 'strategy', 'default');
    }
  }

  if ($contextual_links) {
    $pane_attr['class'][] = 'contextual-links-region';
  }

  $block = new stdClass();

  $t_vars = array(
    'div_attributes' => drupal_attributes($pane_attr),
    'title' => $title,
    'preamble' => $preamble,
    'logo' => $logo,
    'exposed_form' => nas_menu_guide_bar_search_get_exposed_filters(FALSE, TRUE),
    'contextual_links' => $contextual_links,
    'link' => $link,
  );
  $content = theme('nas_guide_bar_search', $t_vars);
  $block->title = t('Footer');
  $block->content = $content;

  return $block;
}

/**
 * Guide bar search form.
 *
 * @param bool $auto_submit
 *   Whether form should use auto submit.
 *
 * @param bool $external_page
 *   If search block uses on internal page.
 *
 * @return string
 *   Rendered form.
 */
function nas_menu_guide_bar_search_get_exposed_filters($auto_submit = TRUE, $external_page = FALSE) {
  $view = views_get_view('nas_bird_guide');
  $view->set_display('nas_bird_guide_fav_birds');
  $view->init_handlers();
  $view->override_url = 'birds/bird-guide';
  $view->display_handler->options['inherit_panels_path'] = FALSE;
  $form_state = array(
    'view' => $view,
    'display' => $view->display_handler->display,
    'exposed_form_plugin' => $view->display_handler->get_plugin('exposed_form'),
    'method' => 'get',
    'rerender' => TRUE,
    'no_redirect' => FALSE,
    'storage' => array(
      'external_page' => $external_page,
    ),
  );
  $form = drupal_build_form('views_exposed_form', $form_state);

  // Disable autosubmit by removing ctools classes.
  if (!$auto_submit && !empty($form['submit']['#attributes']['class'])) {
    $auto_submit_classes = array('ctools-use-ajax', 'ctools-auto-submit-click');
    $form['submit']['#attributes']['class'] = array_diff($form['submit']['#attributes']['class'], $auto_submit_classes);
  }

  // Hide taxonomy fields.
  if ($external_page) {
    $form['field_bird_call_type_tid']['#access'] = FALSE;
    $form['field_bird_family_tid']['#access'] = FALSE;
    $form['field_bird_region_tid']['#access'] = FALSE;
  }

  return drupal_render($form);
}
