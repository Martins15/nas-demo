<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'title' => t('Conservation News Tracker Single'),
  'description' => t('Provides conservation news view pane for single term'),
  'category' => 'NAS',
  'edit form' => 'conservation_news_tracker_single_edit_form',
  'render callback' => 'conservation_news_tracker_single_render',
  'hook theme' => 'conservation_news_tracker_single_theme',
  'defaults' => array(
    'config' => array(
      'references' => array(),
      'news_references' => array(),
    ),
  ),
);

/**
 * An edit form for the pane's settings.
 */
function conservation_news_tracker_single_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['#tree'] = TRUE;
  $form['override_title']['#default_value'] = isset($conf['override_title']) ? $conf['override_title'] : 1;
  $form['override_title_text']['#default_value'] = isset($conf['override_title_text']) ? $conf['override_title_text'] : $conf['config']['news_references']['entity_reference']['entity_label'];
  $form['override_title_heading']['#default_value'] = isset($conf['override_title_heading']) ? $conf['override_title_heading'] : 'div';
  $conf_key = 'config';
  $form[$conf_key] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
  );
  $default_value = &$conf['config']['news_references']['entity_reference']['entity_id'];
  $form[$conf_key]['news_references']['entity_reference'] = array(
    '#type' => 'entityreference',
    '#default_value' => $default_value ? $default_value : '',
    '#title' => t('Conservation News Tracker options'),
    '#required' => TRUE,
    '#era_entity_type' => 'taxonomy_term',
    '#era_bundles' => array('conservation_news_tracker'),
    '#era_cardinality' => 1,
  );
  return $form;

}

/**
 * Render callback.
 */
function conservation_news_tracker_single_render($subtype, $conf, $args, $context) {
  $content = array();
  $title = '';
  if (!empty($conf['override_title_text'])) {
    $title = ctools_context_keyword_substitute($conf['override_title_text'], array(), array($context));
  }
  $entity_id = &$conf['config']['news_references']['entity_reference']['entity_id'];
  $entity_label = strtolower($conf['config']['news_references']['entity_reference']['entity_label']);
  $title_classes = '';
  $title_id = '';
  $image = '';
  if (!empty($entity_id)) {
    $view = views_get_view(CONSERVATION_NEWS_VIEW);
    $view->set_display("page");
    $view->set_arguments(array($entity_id));
    $view->display_handler->default_display->options['css_class'] = 'view-term-id-' . $entity_id;
    $view->pre_execute();
    $view->execute();
    $view->post_execute();
    $content = $view->render();
    // Set title attributes
    $title_classes = 'conservation-news-title term-name-' . $entity_label;
    $title_id = 'term_id_' . $entity_id;
    // Load term icon.
    $icon = taxonomy_term_load($entity_id);
    if (!empty($icon->field_conservation_news_icon[LANGUAGE_NONE][0]) &&
      $icon = $icon->field_conservation_news_icon[LANGUAGE_NONE][0]
    ) {
      $icon['path'] = file_create_url($icon['uri']);
      $icon['attributes'] = array('class' => 'conservation-news-icon conservation-news-icon-' . $entity_label);
      $image = theme_image($icon);
    }
  }
  $block = new stdClass();
  $block->content = theme('conservation_news_tracker_single', array(
    'content' => $content,
    'title' => $title,
    'title_classes' => $title_classes,
    'title_id' => $title_id,
    'image' => $image,
    'override_title_heading' => $conf['override_title_heading'],
  ));
  drupal_static('nas_conservation_news_feature_remove_ajx_history', TRUE);
  drupal_add_js(drupal_get_path('module', 'nas_conservation_news_feature') . '/plugins/content_types/conservation_news_tracker_single/conservation_news_tracker_single.js');
  return $block;
}

/**
 * Submit callback.
 */
function conservation_news_tracker_single_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Delegated implementation of hook_theme().
 */
function conservation_news_tracker_single_theme(&$theme, $plugin) {
  $theme['conservation_news_tracker_single'] = array(
    'variables' => array(
      'content' => NULL,
      'title' => NULL,
      'title_classes' => NULL,
      'title_id' => NULL,
      'image' => NULL,
      'override_title_heading' => NULL,
    ),
    'template' => 'conservation-news-tracker-single',
    'path' => $plugin['path'],
  );
}
