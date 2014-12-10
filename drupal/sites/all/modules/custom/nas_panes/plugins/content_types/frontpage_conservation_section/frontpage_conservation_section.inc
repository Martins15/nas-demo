<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Frontpage. Conservation section.'),
  'description' => t('Provides Full background image area with conservations.'),
  'category' => 'NAS',
  'edit form' => 'frontpage_conservation_section_edit_form',
  'render callback' => 'frontpage_conservation_section_render',
);

/**
 * An edit form for the pane's settings.
 */
function frontpage_conservation_section_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['#tree'] = TRUE;

  $form['image'] = array(
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
    '#default_value' => $conf['image'],
    '#required' => FALSE,
    '#pp_crop_styles' => array('get_outside'),
  );

  $form['color_mode'] = array(
    '#type' => 'radios',
    '#title' => t('Color mode'),
    '#options' => array(
      'dark' => t('Dark'),
      'light' => t('Light'),
    ),
    '#default_value' => !empty($conf['color_mode']) ? $conf['color_mode'] : 'dark',
    '#description' => t('You can choose if the image you uploaded is dark or light so that proper font styles were applied to header content.'),
  );

  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'frontpage_conservation_section', 'nas_panes', 'plugins/content_types/frontpage_conservation_section');

  $form['wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => '',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#prefix' => '<div class="wrapper">',
    '#suffix' => '</div>',
  );

  for ($i = 1; $i <= 3; $i++) {
    $form['wrapper'][$i]['reference'] = array(
      '#title' => t('Reference @delta', array('@delta' => $i)),
      '#type' => 'entityreference',
      '#default_value' => !empty($conf['wrapper'][$i]['reference']['entity_id']) ? $conf['wrapper'][$i]['reference']['entity_id'] : '',
      '#era_entity_type' => 'node',
    );
    $form['wrapper'][$i]['top_link'] = array(
      '#title' => t('Top link'),
      '#type' => 'link_field',
      '#field_name' => 'top_link',
      '#default_value' => !empty($conf['wrapper'][$i]['top_link']) ? $conf['wrapper'][$i]['top_link'] : '',
    );
    $form['wrapper'][$i]['text'] = array(
      '#type' => 'text_format',
      '#title' => t('Text'),
      '#rows' => 5,
      '#default_value' => !empty($conf['wrapper'][$i]['text']['value']) ? $conf['wrapper'][$i]['text']['value'] : '',
      '#format' => 'full_html',
    );
    $form['wrapper'][$i]['bot_link'] = array(
      '#title' => t('Bottom link'),
      '#type' => 'link_field',
      '#field_name' => 'bot_link',
      '#default_value' => !empty($conf['wrapper'][$i]['bot_link']) ? $conf['wrapper'][$i]['bot_link'] : '',
      '#description' => t('Leave link empty to use node link.'),
    );
  }

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved.
 */
function frontpage_conservation_section_edit_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 */
function frontpage_conservation_section_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  $hero_image_path = '';
  if (!empty($conf['image'])) {
    $hero_image = file_load($conf['image']);
    $hero_image_path = image_style_url(NAS_GET_OUTSIDE_IMAGE_STYLE, $hero_image->uri);
  }

  $contextual_links = nas_panes_build_page_contextual_links('frontpage_conservation_section', NAS_PANES_FRONTPAGE_PAGE_MANAGER_CACHE_KEY, 'page_frontpage2_panel_context');

  $content = array();

  foreach ($conf['wrapper'] as $delta => $item) {
    $content[$delta] = array();
    if (!empty($item['reference']['entity_id'])) {
      $node = node_load($item['reference']['entity_id']);
      if ($node) {
        $content[$delta]['title'] = $node->title;
        $content[$delta]['nid'] = $node->nid;
        $content[$delta]['node_url'] = url('node/' . $node->nid, array('absolute' => TRUE));
      }
    }

    $content[$delta]['top_link'] = $item['top_link'];
    $content[$delta]['bot_link'] = $item['bot_link'];
    if (empty($content[$delta]['bot_link']['url']) && !empty($content[$delta]['node_url'])) {
      $content[$delta]['bot_link']['url'] = $content[$delta]['node_url'];
    }
    $content[$delta]['text'] = $item['text']['value'];
  }

  $content = theme('frontpage_conservation_section', array(
      'title' => $conf['override_title'] ? $conf['override_title_text'] : $conf['title'],
      'image_path' => $hero_image_path,
      'contextual_links' => $contextual_links,
      'content' => $content,
      'color_mode' => $conf['color_mode'],
      'text_color' => $conf['color_mode'] == 'dark' ? 'light' : 'dark',
  ));

  $block->content = $content;
  return $block;
}
