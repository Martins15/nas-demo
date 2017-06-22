<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Full-width Body text'),
  'no title override' => TRUE,
  'description' => t('Full-width Body text for article'),
  'category' => 'Full width',
  'edit form' => 'full_width_body_text_form',
  'render callback' => 'full_width_body_text_render',
  'hook theme' => 'full_width_body_text_theme',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'tags' => array('primary_content'),
);

/**
 * An edit form for the pane's settings.
 */
function full_width_body_text_form($form, &$form_state) {
  // Include the CTools content type plugin file, because it provides
  // the ctools_content_configure_form_defaults() function, which is needed
  // when rebuilding the form, because of an ajax action, like selecting
  // a media element.
  ctools_form_include($form_state, 'content');

  // Include this plugin file as well, so that when the form is rebuilt, it
  // can successfully retrieve the settings form.
  ctools_form_include($form_state, 'full_width_body_text', 'nas_panes', 'plugins/content_types/full_width_body_text');

  $conf = $form_state['conf'];
  $form['#tree'] = TRUE;
  $conf_key = 'default';

  // Panelizer.
  if (isset($form_state['display']->context['panelizer']) && !$form_state['display']->context['panelizer']->empty) {
    $conf_key = $form_state['display']->context['panelizer']->keyword . $form_state['display']->context['panelizer']->argument;
    // Support old version of the key that was simple nid. For the future it is
    // better to have also type of the entity in the key so we could enable
    // panelizer for taxonomy terms and have no conflicts in node's and term's ids.
    if (!isset($conf[$conf_key])) {
      $conf_key = $form_state['display']->context['panelizer']->argument;
    }
  }

  $form[$conf_key] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
  );

  $form[$conf_key]['aligner_start'] = array(
    '#markup' => '<div class="option-text-aligner clearfix">',
  );
  $form[$conf_key]['override_title'] = array(
    '#type' => 'checkbox',
    '#title' => t('Override title'),
    '#default_value' => !empty($conf[$conf_key]['override_title']) ? $conf[$conf_key]['override_title'] : '',
    '#id' => 'override-title-checkbox',
  );

  $form[$conf_key]['override_title_text'] = array(
    '#type' => 'textfield',
    '#size' => 35,
    '#default_value' => !empty($conf[$conf_key]['override_title_text']) ? $conf[$conf_key]['override_title_text'] : '',
    '#id' => 'override-title-textfield',
    '#dependency_type' => 'hidden',
    '#dependency' => array('override-title-checkbox' => array(1)),
    '#maxlength' => 1024,
  );

  $form[$conf_key]['override_title_heading'] = array(
    '#type' => 'select',
    '#options' => array(
      'h1' => 'h1',
      'h2' => 'h2',
      'h3' => 'h3',
      'h4' => 'h4',
      'h5' => 'h5',
      'h6' => 'h6',
      'div' => 'div',
      'span' => 'span',
    ),
    '#default_value' => !empty($conf[$conf_key]['override_title_heading']) ? $conf[$conf_key]['override_title_heading'] : 'h2',
    '#id' => 'override-title-heading',
    '#dependency' => array('override-title-checkbox' => array(1)),
  );

  $form[$conf_key]['aligner_stop'] = array(
    '#markup' => '</div>',
  );

  $form[$conf_key]['override_title_markup'] = array(
    '#prefix' => '<div class="description">',
    '#suffix' => '</div>',
    '#markup' => 'You may use %keywords from contexts, as well as %title to contain the original title.',
  );

  $form[$conf_key]['add_margin'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add left and right margin for block'),
    '#default_value' => !empty($conf[$conf_key]['add_margin']) ? $conf[$conf_key]['add_margin'] : 1,
  );

  $form[$conf_key]['body_text'] = array(
    '#type' => 'text_format',
    '#title' => t('Text'),
    '#rows' => 8,
    '#default_value' => !empty($conf[$conf_key]['body_text']['value']) ? $conf[$conf_key]['body_text']['value'] : '',
    '#format' => !empty($conf[$conf_key]['body_text']['format']) ? $conf[$conf_key]['body_text']['format'] : 'full_html',
    '#maxlength' => 3000,
  );

  return $form;
}

/**
 * Submit callback.
 */
function full_width_body_text_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 *
 * See ctools_plugin_examples for more advanced info.
 */
function full_width_body_text_render($subtype, $conf, $args, $context) {
  // We can't add node context to the pane, because it's use on landing pages too.
  $conf_key = 'default';
  if ($context_node = menu_get_object('node')) {
    // Support old configuration when key was nid only.
    if (isset($conf[$context_node->nid])) {
      $conf_key = $context_node->nid;
    }
    // New configuration has entity type prefix.
    if (isset($conf['node' . $context_node->nid])) {
      $conf_key = 'node' . $context_node->nid;
    }
  }

  if (isset($conf[$conf_key])) {
    $data = $conf[$conf_key];
  }

  $title = array(
    'title' => $data['override_title'],
    'title_text' => $data['override_title_text'],
    'title_heading' => $data['override_title_heading'],
  );

  $block = new stdClass();
  $block->content = theme('full_width_body_text', array(
    'title' => $title,
    'body_text' => !empty($data['body_text']['value']) ? $data['body_text']['value'] : '',
    'margin' => $data['add_margin'],
  ));

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function full_width_body_text_theme(&$theme, $plugin) {
  $theme['full_width_body_text'] = array(
    'variables' => array(
      'title' => NULL,
      'body_text' => NULL,
      'margin' => NULL,
    ),
    'template' => 'full-width-body-text',
    'path' => $plugin['path'],
  );
}
