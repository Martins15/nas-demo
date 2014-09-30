<?php

/**
 * @file
 * template.php
 */

/**
 * Implements hook_html_head_alter().
 */
function nas_html_head_alter(&$head_elements) {
  if (empty($head_elements['X-UA-Compatible'])) {
    $head_elements['X-UA-Compatible'] = array(
      '#type' => 'html_tag',
      '#tag' => 'meta',
      '#attributes' => array(
        'http-equiv' => 'X-UA-Compatible',
        'content'    => 'IE=edge,chrome=1',
      ),
      '#weight' => -999999,
    );
  }
}

/**
 * Implements hook_preprocess_node().
 */
function nas_preprocess_node(&$vars) {
  global $base_url;

  $node = $vars['node'];
  // Tell Drupal that there is separate tpl.php files for view modes.
  if (!empty($vars['view_mode'])) {
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['type'] . '__' . $vars['view_mode'];
  }

  if ($vars['type'] == 'bird') {
    drupal_add_js(path_to_theme() . '/js/vendor/owl-carousel/owl.carousel.min.js', array(
      'group' => JS_THEME,
      'every_page' => FALSE,
    ));
    drupal_add_js(path_to_theme() . '/js/nas/owl-settings.js', array(
      'group' => JS_THEME,
      'every_page' => FALSE,
    ));
    $get_field_bird_priority = field_get_items('node', $node, 'field_bird_priority');
    $vars['bird_priority'] = (bool) $get_field_bird_priority[0]['value'];
    // Get author of illustration.
    $get_field_bird_illustration_author = field_get_items('node', $node, 'field_bird_illustration');
    // We need the text until fields are not yet filled.
    $vars['bird_illustration_author'] = t('Illustration © David Allen Sibley.');
    if (!empty($get_field_bird_illustration_author)) {
      $bird_illustration_author = field_view_field('file', $get_field_bird_illustration_author[0]['file'], 'field_file_credit');
      if (isset($bird_illustration_author[0])) {
        $vars['bird_illustration_author'] = t('Illustration ©') . '&nbsp;' . $bird_illustration_author[0]['#markup'];
      }
    }
    // Add static link.
    $vars['learn_more_link'] = l(t('Learn more about these drawings.'), '');
    // Add Node Page absolute url.
    $vars['page_link'] = $base_url . '/' . drupal_get_path_alias();
    // Add learn mode link.
    $vars['learn_more_node_link'] = l(t('Learn more »'), $base_url . $vars['node_url']);
    // Add Birds priority link.
    $vars['bird_priority_link'] = l(t('Priority Birds'), '', array('attributes' => array('class' => array('hero-slug'))));
    // Add hero inline links.
    $vars['hero_inline_links'] = theme('item_list', array(
      'items' => array(
        l(t('In the Bird Guide'), ''),
        l(t('More Priority Birds'), ''),
      ),
      'attributes' => array(
        'class' => array(
          'hero-inline-list',
          'inline-list'
        ),
      ),
    ));
    // Add hero image.
    $get_field_hero_image = field_get_items('node', $node, 'field_hero_image');
    $vars['hero_image'] = theme('image_style', array(
      'style_name' => 'hero_image',
      'path' => $get_field_hero_image[0]['file']->uri,
      'attributes' => array(
        'class' => array(
          'hide-for-tiny',
          'hide-for-small',
        ),
      ),
    ));
    $vars['hero_mobile'] = theme('image_style', array(
      'style_name' => 'hero_mobile',
      'path' => $get_field_hero_image[0]['file']->uri,
      'attributes' => array(
        'class' => array(
          'hide-for-medium',
          'hide-for-large',
          'hide-for-xlarge',
        ),
      ),
    ));
    // Color mode.
    $get_field_color_mode = field_get_items('node', $node, 'field_color_mode');
    $vars['color_mode'] = 'light-gradient';
    if ($get_field_color_mode[0]['value'] == 'dark') {
      $vars['color_mode'] = 'light-text dark-gradient';
    }
  }
}

/**
 * Implements hook_preprocess_page().
 */
function nas_preprocess_page(&$vars) {
  $vars['header_classes'] = 'global-header';
  if (drupal_is_front_page()) {
    $vars['header_classes'] .= ' transparent dark-text light-bg';
  }
}

/**
 * Implements hook_css_alter().
 */
function nas_css_alter(&$css) {
  unset($css[drupal_get_path('module', 'system') . '/system.theme.css']);
  unset($css[drupal_get_path('module', 'panels') . '/css/panels.css']);
  unset($css[libraries_get_path('soundmanager2') . '/demo/play-mp3-links/css/inlineplayer.css']);
  unset($css[drupal_get_path('module', 'colorbox') . '/styles/plain/colorbox_style.css']);
}

/**
 * Implements hook_preprocess_site_template_small_header().
 */
function nas_preprocess_site_template_small_header(&$vars) {
  $vars['footer_logo'] = theme('image', array(
      'path' => base_path() . path_to_theme() . '/img/footer-logo.png',
      'attributes' => array('class' => 'footer-logo'),
    )
  );
}

/**
 * Implements hook_preprocess_site_template_big_header().
 */
function nas_preprocess_site_template_big_header(&$vars) {
  $vars['footer_logo'] = theme('image', array(
      'path' => base_path() . path_to_theme() . '/img/footer-logo.png',
      'attributes' => array('class' => 'footer-logo'),
    )
  );
}

/*
 * Implements theme_form_element()
 */
function nas_form_element($variables) {
  $no_wrap = array('nas-mail-subscription-email', 'nas-menu-search-input');
  if (isset($variables['element']['#id']) && in_array($variables['element']['#id'], $no_wrap)) {
    return $variables['element']['#children'];
  }
  return theme_form_element($variables);
}

/**
 * Implements theme_button()
 * used to return <button> tag when needed
 */
function nas_button($variables) {
  $button_tag = array('edit-nas-search-btn');
  $element = $variables['element'];
  if (in_array($element['#id'], $button_tag)) {
    $element['#attributes']['type'] = 'submit';
    $element['#attributes']['class'][] = 'form-' . $element['#button_type'];
    return '<button' . drupal_attributes($element['#attributes']) . '>' . $element['#value'] . '</button>';
  }

  return theme_button($variables);
}