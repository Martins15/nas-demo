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
  if ($vars['type'] == 'bird') {
    drupal_add_js(path_to_theme() . '/js/vendor/owl-carousel/owl.carousel.min.js', array(
      'group' => JS_THEME,
      'every_page' => FALSE,
    ));
    $get_field_bird_priority = field_get_items('node', $vars['node'], 'field_bird_priority');
    $vars['bird_priority'] = (bool) $get_field_bird_priority[0]['value'];
    // Get author of illustration.
    $get_field_bird_illustration_author = field_get_items('node', $vars['node'], 'field_bird_illustration');
    // We need the text until fields are not yet filled.
    $vars['bird_illustration_author'] = t('Illustration © David Allen Sibley.');
    if (!empty($get_field_bird_illustration_author)) {
      $bird_illustration_author = field_view_field('file', $get_field_bird_illustration_author[0]['file'], 'field_file_credit');
      $vars['bird_illustration_author'] = t('Illustration ©') . '&nbsp;' . $bird_illustration_author[0]['#markup'];
    }
    // Add static link.
    $vars['learn_more_link'] = l(t('Learn more about these drawings.'), '');
    // Add Node Page absolute url.
    $vars['page_link'] = $base_url . '/' . drupal_get_path_alias();
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
