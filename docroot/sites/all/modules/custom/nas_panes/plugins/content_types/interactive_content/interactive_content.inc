<?php

/**
 * @file
 * Define ctools content type.
 */

$plugin = array(
  'title' => t('Interactive content'),
  'description' => t('Provides pane with ability to insert CSS\JS.'),
  'category' => 'Climate',
  'edit form' => 'interactive_content_edit_form',
  'render callback' => 'interactive_content_render',
  'hook theme' => 'interactive_content_theme',
  'no title override' => TRUE,
);

/**
 * Configuration form.
 */
function interactive_content_edit_form($form, &$form_state) {
  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'interactive_content', 'nas_panes', 'plugins/content_types/interactive_content');
  $conf = $form_state['conf'];

  $form['use_title'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use title'),
    '#default_value' => isset($conf['use_title']) ? $conf['use_title'] : '',
  );
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => !empty($conf['title']) ? $conf['title'] : '',
    '#size' => 100,
    '#states' => array(
      'visible' => array(
        '#edit-use-title' => array('checked' => TRUE),
      ),
    ),
  );
  $form['use_description'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use description'),
    '#default_value' => isset($conf['use_description']) ? $conf['use_description'] : '',
  );

  $form['description'] = array(
    '#type' => 'text_format',
    '#title' => t('Description'),
    '#rows' => 5,
    '#default_value' => !empty($conf['description']['value']) ? $conf['description']['value'] : '',
    '#format' => 'full_html',
    '#states' => array(
      'visible' => array(
        '#edit-use-description' => array('checked' => TRUE),
      ),
    ),
  );

  $form['assets'] = array(
    '#type' => 'text_format',
    '#title' => t('CSS&JS'),
    '#description' => t('Use &lt;script&gt; and &lt;style&gt; tags'),
    '#rows' => 5,
    '#default_value' => !empty($conf['assets']['value']) ? $conf['assets']['value'] : '',
    '#format' => 'full_html',
    '#required' => TRUE,
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function interactive_content_edit_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Render callback.
 */
function interactive_content_render($subtype, $conf, $args, $contexts) {
  $title = '';
  if (!empty($conf['use_title']) && !empty($conf['title'])) {
    $title = $conf['title'];
  }
  $description = '';
  if (!empty($conf['use_description']) && !empty($conf['description']['value'])) {
    $description = $conf['description']['value'];
  }
  $block = new stdClass();
  $block->content = array(
    '#theme' => 'interactive_content',
    '#context_links' => nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts),
    '#title' => $title,
    '#description' => $description,
    '#assets' => !empty($conf['assets']['value']) ? $conf['assets']['value'] : '',
  );
  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function interactive_content_theme(&$theme, $plugin) {
  $theme['interactive_content'] = array(
    'variables' => array(
      'context_links' => NULL,
      'title' => NULL,
      'description' => NULL,
      'assets' => NULL,
    ),
    'template' => 'interactive-content',
    'path' => $plugin['path'],
  );
}
