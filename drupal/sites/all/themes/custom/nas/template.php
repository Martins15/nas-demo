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
  if(!empty($vars['view_mode'])) {
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['type'] . '__' . $vars['view_mode'];
  }

  if ($vars['type'] == 'bird') {
    drupal_add_js(path_to_theme() . '/js/vendor/owl-carousel/owl.carousel.min.js', array(
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
      'attributes' => array('class' => array(
        'hero-inline-list',
        'inline-list'
        ),
      ),
    ));
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

/**
 * Implements hook_preprocess_fieldable_panels_pane().
 */
function nas_preprocess_fieldable_panels_pane(&$vars) {
  $fpp = $vars['elements']['#fieldable_panels_pane'];
  // Preprocess section for nas_editorial_cards FPP.
  if ($vars['elements']['#bundle'] == 'nas_editorial_cards') {
    $get_field_column_count = field_get_items('fieldable_panels_pane', $fpp, 'field_column_count');
    $vars['classes_array'][] = 'large-' . $get_field_column_count[0]['value'];
    $vars['editorial_card_photo'] = field_view_field('fieldable_panels_pane', $fpp, 'field_image', array('label' => 'hidden'));
    $get_field_link = field_get_items('fieldable_panels_pane', $fpp, 'field_link');
    $vars['editorial_card_slug'] = l($get_field_link[0]['title'], $get_field_link[0]['url'], array('attributes' => array('class' => array('editorial-card-slug'))));
    $vars['editorial_card_title'] = l($fpp->title, $get_field_link[0]['url'], array('attributes' => array('class' => array('editorial-card-title'))));
    $get_field_links = field_get_items('fieldable_panels_pane', $fpp, 'field_links');
    foreach ($get_field_links as $link) {
      $vars['editorial_card_links'][] = l($link['title'], $link['url'], array('attributes' => array('class' => array('editorial-card-link'))));
    }
    $vars['editorial_card_summary'] = field_view_field('fieldable_panels_pane', $fpp, 'field_summary', array('label' => 'hidden'));
  }
  // Preprocess section for nas_featured_content_cards FPP.
  if ($vars['elements']['#bundle'] == 'nas_featured_content_cards') {
    $get_field_image = field_get_items('fieldable_panels_pane', $fpp, 'field_image');
    $vars['banner_image'] = file_create_url($get_field_image[0]['file']->uri);
    $get_field_link = field_get_items('fieldable_panels_pane', $fpp, 'field_link');
    $vars['banner_slug'] = l($get_field_link[0]['title'], $get_field_link[0]['url'], array('attributes' => array('class' => array('banner-slug'))));
    $vars['banner_title'] = $fpp->title;
    $get_field_links = field_get_items('fieldable_panels_pane', $fpp, 'field_links');
    foreach ($get_field_links as $link) {
      $items[] = l($link['title'], $link['url']);
    }
    $vars['banner_links'] = theme('item_list', array(
      'items' => $items,
      'attributes' => array('class' => array(
        'banner-links',
        'inline-list'
        ),
      ),
    ));
    $get_field_summary = field_get_items('fieldable_panels_pane', $fpp, 'field_summary');
    $vars['banner_summary'] = strip_tags($get_field_summary[0]['value']);
  }
  // Preprocess section for nas_fpp_bird_guide FPP.
  if ($vars['elements']['#bundle'] == 'nas_fpp_bird_guide') {
    $get_field_related_bird = field_get_items('fieldable_panels_pane', $fpp, 'field_related_bird');
    foreach ($get_field_related_bird as $value) {
      $args[] = $value['target_id'];
    }
    $args = implode(' ', $args);
    $vars['birds_view'] = views_embed_view('nas_similar_birds', 'audubon_bird_guide', $args);
  }
}
