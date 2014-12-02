<?php

/**
 * @file
 * define ctools content type.
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

  $nodes = node_load_multiple(array(), array('type' => 'strategy'));

  foreach ($nodes as $nid => $node) {
    $form['wrapper'][$nid] = array(
      '#type' => 'fieldset',
      '#title' => '',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#prefix' => '<div class="wrapper-' . $nid .'">',
      '#suffix' => '</div>',
    );
    $form['wrapper'][$nid]['entity_reference'] = array(
      '#type' => 'entityreference',
      '#title' => 'Conservation strategy',
      '#default_value' => $nid,
      '#era_entity_type' => 'node',
      '#era_bundles' => array('strategy'),
    );
    $form['wrapper'][$nid]['image'] = array(
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
      '#default_value' => !empty($conf['wrapper'][$nid]['image']) ? $conf['wrapper'][$nid]['image'] : '',
      '#required' => FALSE,
      '#pp_crop_styles' => array('get_outside'),
    );
    $form['wrapper'][$nid]['title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#size' => 50,
      '#default_value' => !empty($conf['wrapper'][$nid]['title']) ? $conf['wrapper'][$nid]['title'] : '',
    );
    $form['wrapper'][$nid]['summary'] = array(
      '#type' => 'text_format',
      '#title' => t('Summary'),
      '#rows' => 5,
      '#default_value' => !empty($conf['wrapper'][$nid]['summary']['value']) ? $conf['wrapper'][$nid]['summary']['value'] : '',
      '#format' => 'full_html',
    );
    $form['wrapper'][$nid]['learn_more_link'] = array(
      '#title' => t('Learn more link'),
      '#type' => 'link_field',
      '#field_name' => 'learn_more_link',
      '#default_value' => !empty($conf['wrapper'][$nid]['learn_more_link']) ? $conf['wrapper'][$nid]['learn_more_link'] : '',
    );
    $form['wrapper'][$nid]['entity_reference_project'] = array(
      '#type' => 'entityreference',
      '#title' => 'Featured project',
      '#default_value' => !empty($conf['wrapper'][$nid]['entity_reference_project']) ? $conf['wrapper'][$nid]['entity_reference_project'] : '',
      '#era_entity_type' => 'node',
      '#era_bundles' => array('project'),
    );
  }

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function cons_landing_slideshow_edit_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info.
 */
function cons_landing_slideshow_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  $nodes = node_load_multiple(array(), array('type' => 'strategy'));
  $data = $conf['wrapper'];

  $nodes_array_to_show = array();
  foreach ($nodes as $nid => $node) {
    if (!isset($data[$nid])) {
      continue;
    }
    //Set title.
    $nodes_array_to_show[$nid]['title'] = $data[$nid]['title'];
    if (empty($data[$nid]['title'])) {
      $nodes_array_to_show[$nid]['title'] = $node->title;
    }
    //Set image.
    $image_fid = $data[$nid]['image'];
    if (empty($image_fid)) {
      $get_field_hero_image = field_get_items('node', $node, 'field_hero_image');
      if (isset($get_field_hero_image[0]['fid'])) {
        $image_fid = $get_field_hero_image[0]['fid'];
      }
    }
    $nodes_array_to_show[$nid]['hero_image'] = '';
    if (!empty($image_fid)) {
      $file = file_load($image_fid);
      $nodes_array_to_show[$nid]['hero_image'] = image_style_url('conservation_strategy_slideshow', $file->uri);
    }
    //Set icon.
    $get_field_image = field_get_items('node', $node, 'field_image');
    if (isset($get_field_image[0]['fid'])) {
      $file = file_load($get_field_image[0]['fid']);
      $nodes_array_to_show[$nid]['image'] = image_style_url('conservation_slideshow_icon', $file->uri);
    }
    //Set link.
    if (empty($data[$nid]['learn_more_link']['title']) || empty($data[$nid]['learn_more_link']['url'])) {
      $link = l(t('Learn more »'), 'node/' . $nid);
    }
    else {
      $link = l(t($data[$nid]['learn_more_link']['title']), $data[$nid]['learn_more_link']['url']);
    }
    $nodes_array_to_show[$nid]['learn_more_link'] = $link;
    //Set featured project.
    if ($data[$nid]['entity_reference_project'] && !empty($data[$nid]['entity_reference_project']['entity_id'])) {
      $featured_nid = $data[$nid]['entity_reference_project']['entity_id'];
    }
    if (!empty($featured_nid) && $featured_node = node_load($featured_nid)) {
      $get_field_hero_image = field_get_items('node', $featured_node, 'field_hero_image');
      $nodes_array_to_show[$nid]['featured_node']['hero_image'] = '';
      if (isset($get_field_hero_image[0]['fid'])) {
        $file = file_load($get_field_hero_image[0]['fid']);
        $nodes_array_to_show[$nid]['featured_node']['hero_image'] = image_style_url('conservation_slideshow_featured_project', $file->uri);
      }
      $nodes_array_to_show[$nid]['featured_node']['title'] = l($featured_node->title, 'node/' . $featured_node->nid);
      $get_body = field_get_items('node', $featured_node, 'body');
      $nodes_array_to_show[$nid]['featured_node']['summary'] = '';
      if (!empty($get_body[0]['value'])) {
        $nodes_array_to_show[$nid]['featured_node']['summary'] = text_summary($get_body[0]['value'], NULL, 150);
      }
    }
    unset($featured_nid);
    //Increase text size if Featured project is not available.
    $summary_count = 500;
    if (!isset($nodes_array_to_show[$nid]['featured_node'])) {
      $summary_count = 1000;
    }
    //Set summary.
    $summary = $data[$nid]['summary']['value'];
    if (empty($summary)) {
      $get_body = field_get_items('node', $node, 'body');
      if (isset($get_body[0]['value'])) {
        $summary = $get_body[0]['value'];
      }
    }
    $nodes_array_to_show[$nid]['summary'] = text_summary($summary, NULL, $summary_count);
  }

  $contextual_links = '';
  if (user_access('access contextual links') && user_access('edit NAS panes')) {
    ctools_include('modal');
    ctools_modal_add_js();
    // Add ajax-responder so ctools_ajax_command_reload() will work.
    ctools_add_js('ajax-responder');
    // We expect Get outside pane to be only on Frontpage. If this is not
    // the case we will need to change this select query.
    $pid = db_query('SELECT pid FROM {panels_pane} WHERE type = :type', array(':type' => 'cons_landing_slideshow'))->fetchField();
    if (empty($pid)) {
      nas_panes_save_conservation_landing_page();
      $pid = db_query('SELECT pid FROM {panels_pane} WHERE type = :type', array(':type' => 'cons_landing_slideshow'))->fetchField();
    }
    $links = array(
      'edit' => array(
        'title' => t('Edit'),
        'href' => 'panels/ajax/editor/edit-pane/panel_context:' . NAS_PANES_CONSERVATION_LANDING_PAGE_MANAGER_CACHE_KEY . '::page_conservation_landing_panel_context::::/' . $pid,
        'query' => array('reload' => 'true'),
        'attributes' => array('class' => array('ctools-use-modal')),
      ),
    );
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

  $content = theme('cons_landing_slideshow', array(
    'nodes_array_to_show' => $nodes_array_to_show,
    'contextual_links' => $contextual_links,
  ));

  $block->content = $content;
  return $block;
}
