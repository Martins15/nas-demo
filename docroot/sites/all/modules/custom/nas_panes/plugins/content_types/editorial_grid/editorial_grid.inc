<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Editorial Grid'),
  'description' => t('Provides "Editorial Grid" pane'),
  'category' => 'Editorial cards',
  'edit form' => 'editorial_grid_edit_form',
  'render callback' => 'editorial_grid_render',
  'required context' => new ctools_context_optional(t('Node'), 'node'),
  'admin title' => 'editorial_grid_admin_title',
  'hook theme' => 'editorial_grid_theme',
  'defaults' => array(
    'filter' => array(
      'menu_section' => '',
      'editorial_section' => array(),
    ),
    'more_link_text' => '',
    'more_link_url' => '',
    'show_search' => 0,
    'paddings' => _editorial_grid_default_paddings_conf(),
  ),
);

/**
 * Title callback.
 */
function editorial_grid_admin_title($subtype, $conf, $context = NULL) {
  $output = t('Editorial Grid');
  return $output;
}

/**
 * An edit form for the pane's settings.
 */
function editorial_grid_edit_form($form, &$form_state) {
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  $form['#tree'] = TRUE;

  if (isset($_GET['nas-panes-from-page'])) {
    $form['context']['#prefix'] = '<div style="display:none;">';
    $form['context']['#suffix'] = '</div>';
  }

  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'editorial_grid', 'nas_panes', 'plugins/content_types/editorial_grid');

  $form['filter'] = array(
    '#type' => 'container',
  );
  $form['filter']['help'] = array(
    '#markup' => t('Menu section or/and Editorial section or/and Internal tagging term(s) you would like to filter articles appearing in this listing by:'),
  );
  $form['filter']['required'] = array(
    '#prefix' => '<br>',
    '#markup' => t('One of Menu section or Editorial section or Internal tagging term(s) must be fill.'),
  );
  $filter_state = array(
    'enabled' => array(
      ':input[name="preset"]' => array('value' => 'nas_editorial_grid'),
    ),
  );
  $form['filter']['menu_section'] = array(
    '#type' => 'entityreference',
    '#title' => t('Menu section'),
    '#description' => t("If you'd like set more one terms please write them separated by commas. Example: Bird, Bird FAQs"),
    '#default_value' => !empty($conf['filter']['menu_section']) ? array_keys($conf['filter']['menu_section']) : array(),
    '#era_entity_type' => 'taxonomy_term',
    '#era_bundles' => array('menu_section'),
    '#era_cardinality' => -1,
    '#states' => $filter_state,
  );
  $form['filter']['editorial_section'] = array(
    '#type' => 'entityreference',
    '#title' => t('Editorial section'),
    '#description' => t("If you'd like set more one terms please write them separated by commas. Example: Bird, Bird FAQs"),
    '#default_value' => !empty($conf['filter']['editorial_section']) ? array_keys($conf['filter']['editorial_section']) : array(),
    '#era_entity_type' => 'taxonomy_term',
    '#era_bundles' => array('section'),
    '#era_cardinality' => -1,
    '#states' => $filter_state,
  );
  $form['filter']['internal_tagging'] = array(
    '#type' => 'entityreference',
    '#title' => t('Internal tagging'),
    '#description' => t("If you'd like set more one terms please write them separated by commas. Example: Bird, Bird FAQs"),
    '#default_value' => !empty($conf['filter']['internal_tagging']) ? array_keys($conf['filter']['internal_tagging']) : array(),
    '#era_entity_type' => 'taxonomy_term',
    '#era_bundles' => array('internal_tagging'),
    '#era_cardinality' => -1,
    '#states' => $filter_state,
  );
  $form['show_search'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show search'),
    '#default_value' => $conf['show_search'],
  );
  $form['more_link_text'] = array(
    '#type' => 'textfield',
    '#title' => t('More link text'),
    '#default_value' => $conf['more_link_text'],
  );
  $form['more_link_url'] = array(
    '#type' => 'textfield',
    '#title' => t('More link URL'),
    '#default_value' => $conf['more_link_url'],
  );
  $form['paddings'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Paddings'),
    '#options' => array(
      'top' => t('Top padding'),
      'between' => t('Additional space between title and content'),
      'bottom' => t('Bottom padding'),
      'double-bottom' => t('Double bottom padding'),
    ),
    '#default_value' => !empty($conf['paddings']) ? $conf['paddings'] : _editorial_grid_default_paddings_conf(),
  );

  return $form;
}

/**
 * Submit handler for progress bar form.
 */
function editorial_grid_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Validation callback.
 */
function editorial_grid_edit_form_validate($form, $form_state) {
  $filter_values =& $form_state['values']['filter'];

  $error = 0;
  foreach ($filter_values as $value) {
    if (empty($value)) {
      $error++;
    }
  }
  if ($error === 3) {
    form_set_error('filter', t('One of section must be fill.'));
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 *
 * See ctools_plugin_examples for more advanced info.
 */
function editorial_grid_render($subtype, $conf, $args, $context) {
  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $context);

  $more_link = '';
  if (!empty($conf['more_link_text']) && !empty($conf['more_link_url'])) {
    $more_link = l($conf['more_link_text'], $conf['more_link_url']);
  }

  $args = array();
  _editorial_grid_get_view_args($args, array(
    'menu_section',
    'editorial_section',
    'internal_tagging'
  ), $context, $conf);

  $view = views_get_view('nas_editorial_grid');
  $view->set_display('default');
  $view->set_use_ajax(TRUE);
  if (!$conf['show_search']) {
    $filter = $view->get_item('default', 'filter', 'search_api_views_fulltext');
    $filter['exposed'] = FALSE;
    $view->set_item('default', 'filter', 'search_api_views_fulltext', $filter);
  }
  $pager = $view->display_handler->get_option('pager');
  $pager['type'] = 'none';
  $view->display_handler->set_option('pager', $pager);
  $view->pre_execute($args);
  $view->execute();
  $content = $view->render();
  $view->destroy();

  if (empty($conf['paddings'])) {
    $conf['paddings'] = _editorial_grid_default_paddings_conf();
  }
  $spacebottom = '';
  if ($conf['paddings']['double-bottom']) {
    $spacebottom = 'space-bottom double';
  }
  elseif ($conf['paddings']['bottom']) {
    $spacebottom = 'space-bottom';
  }

  $block = new stdClass();
  $block->content = theme('editorial_grid', array(
    'content' => $content,
    'title' => !empty($conf['override_title_text']) ? check_plain($conf['override_title_text']) : '',
    'more_link' => $more_link,
    'contextual_links' => $contextual_links,
    'spacetop' => $conf['paddings']['top'],
    'spacebetween' => $conf['paddings']['between'],
    'spacebottom' => $spacebottom,
  ));

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function editorial_grid_theme(&$theme, $plugin) {
  $theme['editorial_grid'] = array(
    'variables' => array(
      'content' => '',
      'title' => '',
      'more_link' => '',
      'contextual_links' => '',
      'spacetop' => '',
      'spacebetween' => '',
      'spacebottom' => '',
    ),
    'template' => 'editorial-grid',
    'path' => $plugin['path'],
  );
}

/**
 * Helper function to get arguments to embedded view from existing contexts.
 *
 * @param array $args
 *   Arguments.
 * @param array $settings
 *   Array of required context types.
 * @param mixed $context
 *   Available context.
 * @param array $conf
 *   Pane configuration.
 *
 * @return array
 *   Array of args to be passed into view.
 */
function _editorial_grid_get_view_args(array &$args, array $settings, $context, array $conf = array()) {
  foreach ($settings as $require_context) {
    $arg_key = count($args);
    switch ($require_context) {
      case 'menu_section':
      case 'editorial_section':
      case 'internal_tagging':
        $args[$arg_key] = 'all';
        if (!empty($conf['filter'][$require_context])) {
          // Apply filter or add default value.
          $editorial_filter = array();
          foreach ($conf['filter'][$require_context] as $reference) {
            if (!empty($reference['entity_id'])) {
              $editorial_filter[] = $reference['entity_id'];
            }
          }
          if (!empty($editorial_filter)) {
            $args[$arg_key] = implode('+', $editorial_filter);
          }
        }
        break;

      default:
        if (is_array($context->type) && in_array($require_context, $context->type)) {
          $args[] = $context->argument;
        }
        break;
    }
  }

  return $args;
}

/**
 * Helper function to provide default panes padding configuration.
 */
function _editorial_grid_default_paddings_conf() {
  return array(
    'top' => 'top',
    'between' => 'between',
    'bottom' => 'bottom',
    'double-bottom' => 0,
  );
}
