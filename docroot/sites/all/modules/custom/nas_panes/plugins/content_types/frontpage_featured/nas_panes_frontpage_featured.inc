<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Frontpage Featured content'),
  'description' => t('Provides Featured block for frontpage'),
  'category' => 'NAS',
  'edit form' => 'frontpage_featured_form',
  'render callback' => 'frontpage_featured_render',
);

/**
 * An edit form for the pane's settings.
 */
function frontpage_featured_form($form, &$form_state) {
  $conf = $form_state['conf'];
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
  ctools_form_include($form_state, 'nas_panes_frontpage_featured', 'nas_panes', 'plugins/content_types/frontpage_featured');

  $variants = array(
    'curtain_simple' => t('Simple curtain'),
    'hero_image' => t('Hero image (no curtain)'),
    'curtain_3stories' => t('Curtain with 3 stories'),
  //    'curtain_package' => t('Curtain with a package of stories'),
  //    'curtain_video' => t('Video curtain'),
  );
  $form['variant'] = array(
    '#type' => 'select',
    '#title' => t('Frontpage variant'),
    '#options' => $variants,
    '#default_value' => !empty($conf['variant']) ? $conf['variant'] : 'curtain_simple',
  );

  _frontpage_featured_simple_curtain_form($form, $form_state, $conf);
  _frontpage_featured_hero_image_form($form, $form_state, $conf);
  _frontpage_featured_curtain_3stories_form($form, $form_state, $conf);

  foreach (array_keys($variants) as $variant) {
    $form[$variant]['#states']['visible']['select[name="variant"]'][] = array('value' => $variant);
  }

  return $form;
}

/**
 * Form builder for simple curtain variant.
 */
function _frontpage_featured_simple_curtain_form(&$form, $form_state, $conf) {
  $form['curtain_simple'] = array(
    '#type' => 'container',
    '#title' => t('Simple curtain fields'),
    '#tree' => TRUE,
  );
  $_conf = !empty($conf['curtain_simple']) ? $conf['curtain_simple'] : array();
  $state = array(
    'required' => array(
      'select[name="variant"]' => array('value' => 'curtain_simple'),
    ),
  );
  $form['curtain_simple']['image'] = array(
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
    '#default_value' => !empty($_conf['image']) ? $_conf['image'] : 0,
    '#states' => $state,
    '#pp_crop_styles' => array('featured_frontpage'),
  );
  $form['curtain_simple']['header_color_mode'] = array(
    '#type' => 'radios',
    '#title' => t('Header color mode'),
    '#options' => array(
      'dark' => t('Dark'),
      'light' => t('Light'),
    ),
    '#default_value' => !empty($_conf['header_color_mode']) ? $_conf['header_color_mode'] : 'dark',
    '#description' => t('You can choose if the image you uploaded is dark or light so that proper font styles were applied to header content.'),
  );
  $form['curtain_simple']['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => !empty($_conf['title']) ? $_conf['title'] : '',
    '#states' => $state,
  );
  $form['curtain_simple']['title_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Title link'),
    '#default_value' => !empty($_conf['title_link']) ? $_conf['title_link'] : '',
  );
  $form['curtain_simple']['blue_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Blue text'),
    '#default_value' => !empty($_conf['blue_text']) ? $_conf['blue_text'] : '',
  );
  $form['curtain_simple']['blue_text_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Blue text link'),
    '#default_value' => !empty($_conf['blue_text_link']) ? $_conf['blue_text_link'] : '',
  );
  $form['curtain_simple']['summary'] = array(
    '#type' => 'textarea',
    '#title' => t('Summary'),
    '#default_value' => !empty($_conf['summary']) ? $_conf['summary'] : '',
  );
}

/**
 * Form builder for hero image variant.
 */
function _frontpage_featured_hero_image_form(&$form, $form_state, $conf) {
  $form['hero_image'] = array(
    '#type' => 'container',
    '#title' => t('Hero image'),
    '#tree' => TRUE,
  );
  $_conf = !empty($conf['hero_image']) ? $conf['hero_image'] : array();
  $state = array(
    'required' => array(
      'select[name="variant"]' => array('value' => 'hero_image'),
    ),
  );
  $form['hero_image']['image'] = array(
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
    '#default_value' => !empty($_conf['image']) ? $_conf['image'] : 0,
    '#pp_crop_styles' => array('hero_image'),
    '#states' => $state,
  );
  $form['hero_image']['header_color_mode'] = array(
    '#type' => 'radios',
    '#title' => t('Header color mode'),
    '#options' => array(
      'dark' => t('Dark'),
      'light' => t('Light'),
    ),
    '#default_value' => !empty($_conf['header_color_mode']) ? $_conf['header_color_mode'] : 'dark',
    '#description' => t('You can choose if the image you uploaded is dark or light so that proper font styles were applied to header content.'),
  );
  $form['hero_image']['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => !empty($_conf['title']) ? $_conf['title'] : '',
    '#states' => $state,
  );
  $form['hero_image']['title_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Title link'),
    '#default_value' => !empty($_conf['title_link']) ? $_conf['title_link'] : '',
  );
  $form['hero_image']['blue_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Slug text'),
    '#default_value' => !empty($_conf['blue_text']) ? $_conf['blue_text'] : '',
  );
  $form['hero_image']['blue_text_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Slug text link'),
    '#default_value' => !empty($_conf['blue_text_link']) ? $_conf['blue_text_link'] : '',
  );
}

/**
 * Form builder for curtain with 3 stories variant.
 */
function _frontpage_featured_curtain_3stories_form(&$form, &$form_state, $conf) {
  $form['curtain_3stories'] = array(
    '#type' => 'container',
    '#title' => t('Hero image'),
    '#tree' => TRUE,
  );
  $_conf = !empty($conf['curtain_3stories']) ? $conf['curtain_3stories'] : array();
  $state = array(
    'required' => array(
      'select[name="variant"]' => array('value' => 'curtain_3stories'),
    ),
  );
  $form['curtain_3stories']['image'] = array(
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
    '#default_value' => !empty($_conf['image']) ? $_conf['image'] : 0,
    '#pp_crop_styles' => array('featured_frontpage'),
    '#states' => $state,
  );
  $form['curtain_3stories']['header_color_mode'] = array(
    '#type' => 'radios',
    '#title' => t('Header color mode'),
    '#options' => array(
      'dark' => t('Dark'),
      'light' => t('Light'),
    ),
    '#default_value' => !empty($_conf['header_color_mode']) ? $_conf['header_color_mode'] : 'dark',
    '#description' => t('You can choose if the image you uploaded is dark or light so that proper font styles were applied to header content.'),
  );
  $form['curtain_3stories']['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => !empty($_conf['title']) ? $_conf['title'] : '',
    '#states' => $state,
  );
  $form['curtain_3stories']['title_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Title link'),
    '#default_value' => !empty($_conf['title_link']) ? $_conf['title_link'] : '',
  );
  $form['curtain_3stories']['action_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Action link text'),
    '#default_value' => !empty($_conf['action_text']) ? $_conf['action_text'] : '',
  );
  $form['curtain_3stories']['action_text_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Action link url'),
    '#default_value' => !empty($_conf['action_text_link']) ? $_conf['action_text_link'] : '',
  );
  $form['curtain_3stories']['articles'] = array(
    '#type' => 'fieldset',
    '#title' => t('Stories'),
    '#tree' => TRUE,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  if (empty($_conf['count'])) {
    if (empty($form_state['curtain_3stories']['count'])) {
      $count = 1;
      $form_state['curtain_3stories']['count'] = $count;
    }
    else {
      $count = $form_state['curtain_3stories']['count'];
    }
  }
  else {
    if (empty($form_state['curtain_3stories']['count'])) {
      $count = $_conf['count'];
      $form_state['curtain_3stories']['count'] = $count;
    }
    else {
      $count = $form_state['curtain_3stories']['count'];
    }
  }
  $form['curtain_3stories']['count'] = array(
    '#type' => 'value',
    '#value' => $count,
  );
  for ($i = 0; $i < $form_state['curtain_3stories']['count']; $i++) {
    $form['curtain_3stories']['articles'][$i] = array(
      '#type' => 'fieldset',
      '#title' => t('Story !num', array('!num' => $i + 1)),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#prefix' => '<div class="wrapper-' . $i .'">',
      '#suffix' => '</div>',
    );
    $form['curtain_3stories']['articles'][$i]['entity_reference'] = array(
      '#type' => 'entityreference',
      '#title' => 'Story reference',
      '#default_value' => !empty($_conf['articles'][$i]['entity_reference']) ? $_conf['articles'][$i]['entity_reference'] : '',
      '#era_entity_type' => 'node',
    );
    $form['curtain_3stories']['articles'][$i]['title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#default_value' => !empty($_conf['articles'][$i]['title']) ? $_conf['articles'][$i]['title'] : '',
    );
    $form['curtain_3stories']['articles'][$i]['slug_link'] = array(
      '#type' => 'link_field',
      '#title' => t('Slug link'),
      '#default_value' => !empty($_conf['articles'][$i]['slug_link']) ? $_conf['articles'][$i]['slug_link'] : '',
    );
  }
  if ($form_state['curtain_3stories']['count'] < 3) {
    $form['curtain_3stories']['articles']['add_more'] = array(
      '#type' => 'submit',
      '#value' => t('Add more stories'),
      '#submit' => array('frontpage_featured_curtain_3stories_add_more'),
    );
  }
}

/**
 * Validation callback.
 */
function frontpage_featured_form_validate($form, $form_state) {
  $values =& $form_state['values'];
  switch ($values['variant']) {
    case 'curtain_simple':
      if (empty($values['curtain_simple']['image'])) {
        form_set_error('curtain_simple][image', t('Image field is required'));
      }
      if (empty($values['curtain_simple']['title'])) {
        form_set_error('curtain_simple][title', t('Title field is required'));
      }
      break;

    case 'hero_image':
      if (empty($values['hero_image']['image'])) {
        form_set_error('hero_image][image', t('Image field is required'));
      }
      if (empty($values['hero_image']['title'])) {
        form_set_error('hero_image][title', t('Title field is required'));
      }
      break;

    case 'curtain_3stories':
      if (empty($values['curtain_3stories']['image'])) {
        form_set_error('curtain_3stories][image', t('Image field is required'));
      }
      if (empty($values['curtain_3stories']['title'])) {
        form_set_error('curtain_3stories][title', t('Title field is required'));
      }
      break;

  }
}

/**
 * Edit form submit for add more.
 */
function frontpage_featured_curtain_3stories_add_more($form, &$form_state) {
  $form_state['curtain_3stories']['count']++;
  $form_state['rebuild'] = TRUE;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function frontpage_featured_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
      // Update frontpage variant.
      if ($key == 'variant') {
        _frontpage_variant($form_state['values'][$key] == 'hero_image' ? 'hero_image' : 'curtain');
      }
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function frontpage_featured_render($subtype, $conf, $args, $contexts) {
  $contextual_links = '';
  if (user_access('frontpage featured pane edit')) {
    $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);
  }

  switch ($conf['variant']) {
    case 'curtain_simple':
      $content = _frontpage_featured_simple_curtain_render($conf['curtain_simple'], $contextual_links);
      break;

    case 'hero_image':
      $content = _frontpage_featured_hero_image_render($conf['hero_image'], $contextual_links);
      break;

    case 'curtain_3stories':
      $content = _frontpage_featured_curtain_3stories_render($conf['curtain_3stories'], $contextual_links);
      break;

  }

  $block = new stdClass();
  $block->content = $content;
  return $block;
}

/**
 * Helper function for rendering 'Simple curtain' pane variant.
 *
 * @param array $conf
 *   Configuration array.
 * @param string $contextual_links
 *   Rendered contextual links.
 *
 * @return string
 *   Rendered HTML markup.
 */
function _frontpage_featured_simple_curtain_render($conf, $contextual_links) {
  $image = file_load($conf['image']);
  $image_path = '';
  if (!empty($image)) {
    $image_path = image_style_url(NAS_FEATURED_FRONTPAGE_IMAGE_STYLE, $image->uri);
    $attribution = _nas_panes_format_image_attribution($image);
  }

  $summary = check_plain($conf['summary']);

  $title_link = l(t($conf['title']), $conf['title_link']);
  $blue_text_link = l(t($conf['blue_text']), $conf['blue_text_link'], array('attributes' => array('classes' => 'curtain-card-slug')));

  $class = &drupal_static('nas_header_class');
  $class = 'dark-text light-bg transparent';
  if (!empty($conf['header_color_mode']) && $conf['header_color_mode'] == 'light') {
    $class = 'light-text dark-bg transparent';
  }

  // Pass image url value to theme
  $featured_frontpage_image = &drupal_static('featured_frontpage_image');
  $featured_frontpage_image = $image_path;
  $content = theme('nas_frontpage_featured', array(
    'attribution' => $attribution,
    'summary' => $summary,
    'title_link' => $title_link,
    'blue_text_link' => $blue_text_link,
    'contextual_links' => $contextual_links,
  ));

  // Pass mobile_content to theme
  $mobile_content = &drupal_static('featured_frontpage_mobile_content');
  $mobile_content = theme('nas_frontpage_featured_mobile', array(
    'image_path' => $image_path,
    'summary' => $summary,
    'title_link' => $title_link,
    'blue_text_link' => $blue_text_link,
    'contextual_links' => $contextual_links,
  ));

  return $content;
}

/**
 * Helper function for rendering 'hero image' pane variant.
 *
 * @param array $conf
 *   Configuration array.
 * @param string $contextual_links
 *   Rendered contextual links.
 *
 * @return string
 *   Rendered HTML markup.
 */
function _frontpage_featured_hero_image_render($conf, $contextual_links) {
  $image = file_load($conf['image']);
  if (!empty($image)) {
    $image_wrapper = entity_metadata_wrapper('file', $image);
    $image_caption = check_plain($image_wrapper->field_file_caption->value()['value']);
    $hero_image = theme('image_style', array(
      'style_name' => 'hero_image',
      'path' => $image->uri,
      'title' => $image_caption,
    ));
    $attribution = _nas_panes_format_image_attribution($image);
  }

  $class = &drupal_static('nas_header_class');
  $class = 'dark-text light-bg transparent';
  if (!empty($conf['header_color_mode']) && $conf['header_color_mode'] == 'light') {
    $class = 'light-text dark-bg transparent';
  }

  $title_link = t($conf['title']);
  if (!empty($conf['title_link'])) {
    $title_link = l(t($conf['title']), $conf['title_link']);
  }
  else {
    $title_link = check_plain($title_link);
  }
  $blue_text_link = '';
  if ($conf['blue_text'] && $conf['blue_text_link']) {
    $blue_text_link = l(t($conf['blue_text']), $conf['blue_text_link'], array('attributes' => array('classes' => 'curtain-card-slug')));
  }

  $content = theme('nas_frontpage_featured__hero_image', array(
    'hero_image' => $hero_image,
    'attribution' => $attribution,
    'title_link' => $title_link,
    'slug_link' => $blue_text_link,
    'contextual_links' => $contextual_links,
  ));

  return $content;
}

/**
 * Helper function for rendering 'hero image' pane variant.
 *
 * @param array $conf
 *   Configuration array.
 * @param string $contextual_links
 *   Rendered contextual links.
 *
 * @return string
 *   Rendered HTML markup.
 */
function _frontpage_featured_curtain_3stories_render($conf, $contextual_links) {
  $image = file_load($conf['image']);
  if (!empty($image)) {
    $image_path = image_style_url(NAS_FEATURED_FRONTPAGE_IMAGE_STYLE, $image->uri);
    $attribution_caption = $attribution_credit = '';
    if ($items = field_get_items('file', $image, 'field_file_caption')) {
      $attribution_caption = trim($items[0]['safe_value']);
    }
    if ($items = field_get_items('file', $image, 'field_file_credit')) {
      $attribution_credit = 'Photo: ' . trim($items[0]['safe_value']);
    }
  }

  // Pass image url value to theme
  $featured_frontpage_image = &drupal_static('featured_frontpage_image');
  $featured_frontpage_image = $image_path;

  $class = &drupal_static('nas_header_class');
  $class = 'dark-text light-bg transparent';
  if (!empty($conf['header_color_mode']) && $conf['header_color_mode'] == 'light') {
    $class = 'light-text dark-bg transparent';
  }

  $title_link = t($conf['title']);
  if ($conf['title_link']) {
    $title_link = l(t($conf['title']), $conf['title_link']);
  }
  else {
    $title_link = check_plain($title_link);
  }
  $action_link = '';
  if ($conf['action_text'] && $conf['action_text_link']) {
    $action_link = l(t($conf['action_text']), $conf['action_text_link'], array(
      'attributes' => array(
        'class' => array('button', 'large', 'expand', 'tomato'),
      )));
  }

  $stories = array();
  foreach ($conf['articles'] as $story) {
    if (!empty($story['entity_reference']) && $node = node_load($story['entity_reference']['entity_id'])) {
      $title = !empty($story['title']) ? $story['title'] : $node->title;
      $slug_link = '';
      if ($story['slug_link']['title'] && $story['slug_link']['url']) {
        $slug_link = l($story['slug_link']['title'], $story['slug_link']['url']);
      }
      elseif ($section = nas_search_get_article_section($node, array(), '', 'node')) {
        $slug_link = l($section->name, 'taxonomy/term/' . $section->tid);
      }
      $stories[] = array(
        'title_link' => l($title, 'node/' . $node->nid),
        'slug_link' => $slug_link,
      );
    }
  }

  // Pass mobile_content to theme
  $mobile_content = &drupal_static('featured_frontpage_mobile_content');
  $mobile_content = theme('nas_frontpage_featured__curtain_3stories_mobile', array(
    'image_path' => $image_path,
    'title_link' => $title_link,
    'stories' => $stories,
    'action_link' => $action_link,
    'contextual_links' => $contextual_links,
  ));

  $content = theme('nas_frontpage_featured__curtain_3stories', array(
    'attribution_title' => $attribution_caption,
    'attribution_credit' => $attribution_credit,
    'title_link' => $title_link,
    'stories' => $stories,
    'action_link' => $action_link,
    'contextual_links' => $contextual_links,
  ));

  return $content;
}
