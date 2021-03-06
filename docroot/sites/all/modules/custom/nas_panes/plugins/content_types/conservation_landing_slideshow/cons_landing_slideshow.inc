<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Conservation landing. Slideshow.'),
  'description' => t('Provides Slideshow for conservation landing page'),
  'category' => 'NAS',
  'edit form' => 'cons_landing_slideshow_edit_form',
  'render callback' => 'cons_landing_slideshow_render',
);

/**
 * An edit form for the pane's settings.
 */
function cons_landing_slideshow_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['#tree'] = TRUE;
  _nas_panes_hide_pane_title_field($form);

  // The two function calls below are necessary if we want to use a media
  // element type, because it causes ajax requests, which in turn call
  // drupal_form_rebuild(), and without the below includes, Drupal will
  // not be able to rebuild the form.

  // Include the CTools content type plugin file, because it provides
  // the ctools_content_configure_form_defaults() function, which is needed
  // when rebuilding the form, because of an ajax action, like selecting
  // a media element.
  ctools_form_include($form_state, 'content');

  // Include this plugin file as well, so that when the form is rebuilt, it
  // can successfully retrieve the settings form.
  ctools_form_include($form_state, 'cons_landing_slideshow', 'nas_panes', 'plugins/content_types/conservation_landing_slideshow');

  $form['wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => '',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#prefix' => '<div class="wrapper">',
    '#suffix' => '</div>',
  );
  if (empty($conf['count'])) {
    if (empty($form_state['count'])) {
      $count = 1;
      $form_state['count'] = $count;
    }
    else {
      $count = $form_state['count'];
    }
  }
  else {
    if (empty($form_state['count'])) {
      $count = $conf['count'];
      $form_state['count'] = $count;
    }
    else {
      $count = $form_state['count'];
    }
  }
  $form['count'] = array(
    '#type' => 'hidden',
    '#value' => $count,
  );
  for ($i = 0; $i < $form_state['count']; $i++) {
    $form['wrapper'][$i] = array(
      '#type' => 'fieldset',
      '#title' => '',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#prefix' => '<div class="wrapper-' . $i . '">',
      '#suffix' => '</div>',
    );
    $form['wrapper'][$i]['entity_reference'] = array(
      '#type' => 'entityreference',
      '#title' => 'Conservation strategy',
      '#default_value' => !empty($conf['wrapper'][$i]['entity_reference']) ? $conf['wrapper'][$i]['entity_reference'] : '',
      '#era_entity_type' => 'node',
      '#era_bundles' => array('strategy'),
    );
    $form['wrapper'][$i]['image'] = array(
      '#type' => 'media',
      '#tree' => TRUE,
      '#title' => t('Image'),
      '#description' => t('Allowed formats: png, jpg, jpeg, gif.'),
      '#media_options' => array(
        'global' => array(
          'file_extensions' => 'png jpg jpeg gif',
          'max_filesize' => '20 MB',
          'file_directory' => '',
          'types' => array('image'),
        ),
      ),
      '#default_value' => !empty($conf['wrapper'][$i]['image']) ? $conf['wrapper'][$i]['image'] : '',
      '#required' => FALSE,
      '#pp_crop_styles' => array('conservation_strategy_slideshow'),
    );
    $form['wrapper'][$i]['icon'] = array(
      '#type' => 'media',
      '#tree' => TRUE,
      '#title' => t('Icon'),
      '#description' => t('Allowed formats: png, jpg, jpeg, gif.'),
      '#media_options' => array(
        'global' => array(
          'file_extensions' => 'png jpg jpeg gif',
          'max_filesize' => '20 MB',
          'file_directory' => '',
          'types' => array('image'),
        ),
      ),
      '#default_value' => !empty($conf['wrapper'][$i]['icon']) ? $conf['wrapper'][$i]['icon'] : '',
      '#required' => FALSE,
      '#pp_crop_styles' => array('conservation_slideshow_icon'),
    );
    $form['wrapper'][$i]['title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#size' => 50,
      '#default_value' => !empty($conf['wrapper'][$i]['title']) ? $conf['wrapper'][$i]['title'] : '',
    );
    $form['wrapper'][$i]['summary'] = array(
      '#type' => 'text_format',
      '#title' => t('Summary'),
      '#rows' => 5,
      '#default_value' => !empty($conf['wrapper'][$i]['summary']['value']) ? $conf['wrapper'][$i]['summary']['value'] : '',
      '#format' => 'full_html',
    );
    $form['wrapper'][$i]['learn_more_link'] = array(
      '#title' => t('Learn more link'),
      '#type' => 'link_field',
      '#field_name' => 'learn_more_link',
      '#default_value' => !empty($conf['wrapper'][$i]['learn_more_link']) ? $conf['wrapper'][$i]['learn_more_link'] : '',
    );
    $form['wrapper'][$i]['entity_reference_project'] = array(
      '#type' => 'entityreference',
      '#title' => 'Featured project',
      '#default_value' => !empty($conf['wrapper'][$i]['entity_reference_project']) ? $conf['wrapper'][$i]['entity_reference_project'] : '',
      '#era_entity_type' => 'node',
      '#era_bundles' => array('project'),
    );
  }
  $form['wrapper']['add_group'] = array(
    '#type' => 'submit',
    '#value' => t('Add more conservation strategies'),
    '#submit' => array('cons_landing_slideshow_add_group'),
  );

  return $form;
}

/**
 * Submit callback.
 */
function cons_landing_slideshow_edit_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      if ($key == 'wrapper') {
        foreach ($form_state['values']['wrapper'] as $i => $val) {
          if (!$val['entity_reference']) {
            unset($form_state['values']['wrapper'][$i]);
          }
        }
      }
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Edit form submit for add group.
 */
function cons_landing_slideshow_add_group($form, &$form_state) {
  $form_state['count']++;
  $form_state['rebuild'] = TRUE;
}

/**
 * Run-time rendering of the body of the block (content type).
 *
 * See ctools_plugin_examples for more advanced info.
 */
function cons_landing_slideshow_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  $data = $conf['wrapper'];
  $nodes_array_to_show = array();
  foreach ($data as $key => $value) {
    if (!is_array($value)) {
      continue;
    }
    if (!$node = _i18n_node_load($value['entity_reference']['entity_id'])) {
      continue;
    }

    // Set title.
    $title = empty($value['title']) ? $node->title : $value['title'];
    $nodes_array_to_show[$key]['title_link'] = l($title, 'node/' . $node->nid, array(
      'attributes' => array(
        'title' => $node->title,
        'class' => array('conservation-slide-headline'),
      ),
    ));

    // Set image.
    $image_fid = $value['image'];
    if (empty($image_fid)) {
      $field_items = field_get_items('node', $node, 'field_hero_image');
      if (isset($field_items[0]['fid'])) {
        $image_fid = $field_items[0]['fid'];
      }
    }
    $nodes_array_to_show[$key]['hero_image'] = '';
    if (!empty($image_fid)) {
      $file = file_load($image_fid);
      $nodes_array_to_show[$key]['hero_image'] = image_style_url('conservation_strategy_slideshow', nas_alters_local_image_uri($file->uri));
    }
    // Set icon.
    $nodes_array_to_show[$key]['icon'] = '';
    if (isset($value['icon']) && !empty($value['icon'])) {
      $file = file_load($value['icon']);
      $nodes_array_to_show[$key]['icon'] = image_style_url('conservation_slideshow_icon', nas_alters_local_image_uri($file->uri));
    }
    // Set link.
    if (empty($value['learn_more_link']['title']) || empty($value['learn_more_link']['url'])) {
      $link = l(t('Learn more »'), 'node/' . $node->nid);
    }
    else {
      $link = l(t($value['learn_more_link']['title']), $value['learn_more_link']['url']);
    }
    $nodes_array_to_show[$key]['learn_more_link'] = $link;
    // Set featured project.
    $featured_nid = FALSE;
    if (!empty($value['entity_reference_project']['entity_id'])) {
      $featured_nid = $value['entity_reference_project']['entity_id'];
    }
    else {
      $view_results = views_get_view_result('conservation_strategy_projects', 'default', $node->nid);
      if (!empty($view_results[0]->field_conservation_strategy_node_nid)) {
        $featured_nid = $view_results[0]->field_conservation_strategy_node_nid;
      }
    }
    if ($featured_nid && $featured_node = _i18n_node_load($featured_nid)) {
      $nodes_array_to_show[$key]['featured_node']['hero_image'] = '';
      $field_items = field_get_items('node', $featured_node, 'field_hero_image');
      if (!empty($field_items[0]['fid']) && $file = file_load($field_items[0]['fid'])) {
        $nodes_array_to_show[$key]['featured_node']['hero_image'] = image_style_url('conservation_slideshow_featured_project', nas_alters_local_image_uri($file->uri));
      }
      $nodes_array_to_show[$key]['featured_node']['title'] = l($featured_node->title, 'node/' . $featured_node->nid);
      $nodes_array_to_show[$key]['featured_node']['summary'] = '';
      $field_items = field_get_items('node', $featured_node, 'field_project_description');
      if (!empty($field_items[0]['value'])) {
        $nodes_array_to_show[$key]['featured_node']['summary'] = $field_items[0]['value'];
      }
    }
    // Increase text size if Featured project is not available.
    $summary_count = 500;
    if (!isset($nodes_array_to_show[$key]['featured_node'])) {
      $summary_count = 1000;
    }
    // Set summary.
    $summary = $value['summary']['value'];
    $nodes_array_to_show[$key]['summary'] = text_summary($summary, NULL, $summary_count);
  }

  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);

  $content = theme('cons_landing_slideshow', array(
    'nodes_array_to_show' => $nodes_array_to_show,
    'contextual_links' => $contextual_links,
  ));

  $block->content = $content;
  return $block;
}
