<?php

/**
 * @file
 * template.php
 */

/**
 * Include overriden core functions used through out theme.
 */
include_once 'theme/pager.inc';

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

  // Tell Drupal that there is separate tpl.php files for view modes.
  if (!empty($vars['view_mode'])) {
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['type'] . '__' . $vars['view_mode'];
  }

  // Add node page path.
  $node_path = url('node/' . $vars['node']->nid);
  $vars['node_path'] = $node_path;

  if ($vars['type'] == 'bird') {
    nas_preprocess_node_bird($vars);
  }
  if ($vars['type'] == 'boa') {
    nas_preprocess_node_boa($vars);
  }
  if ($vars['type'] == 'boaf') {
    nas_preprocess_node_boaf($vars);
  }
  if ($vars['type'] == 'article') {
    nas_preprocess_node_article($vars);
  }
  if ($vars['type'] == 'flyway') {
    nas_preprocess_node_flyway($vars);
  }
  if ($vars['type'] == 'magazine_issue') {
    nas_preprocess_node_magazine_issue($vars);
  }
  if ($vars['type'] == 'project') {
    nas_preprocess_node_project($vars);
  }
  if ($vars['type'] == 'slideshow') {
    nas_preprocess_node_slideshow($vars);
  }
  if ($vars['type'] == 'static_page') {
    nas_preprocess_node_static_page($vars);
  }
  if ($vars['type'] == 'strategy') {
    nas_preprocess_node_strategy($vars);
  }
  if ($vars['type'] == 'engagement_cards') {
    nas_preprocess_node_engagement_cards($vars);
  }
  if ($vars['type'] == 'contact') {
    nas_preprocess_node_contact($vars);
  }
}

/**
 * theme_preprocess_node for bird content type.
 */
function nas_preprocess_node_bird(&$vars) {
  $node = $vars['node'];
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
  // Add node page path.
  global $base_url;
  // Add static link.
  $vars['learn_more_link'] = l(t('Learn more about these drawings.'), '');
  // Add Page absolute url.
  $vars['page_link'] = $base_url . '/' . drupal_get_path_alias();
  // Add learn mode link.
  $vars['learn_more_node_link'] = l(t('Learn more »'), 'node/' . $vars['nid']);

  // Add Birds priority link.
  $vars['bird_priority_link'] = l(t('Priority Birds'), 'birds-priority', array('attributes' => array('class' => array('hero-slug'))));
  // Add hero inline links.
  $vars['hero_inline_links'] = theme('item_list', array(
    'items' => array(
      l(t('In the Bird Guide'), ''),
      l(t('More Priority Birds'), 'birds-priority'),
    ),
    'attributes' => array(
      'class' => array(
        'hero-inline-list',
        'inline-list',
      ),
    ),
  ));
  // Add hero image.
  $get_field_hero_image = field_get_items('node', $node, 'field_hero_image');
  if (!empty($get_field_hero_image)) {
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
  }
  // Color mode.
  $get_field_color_mode = field_get_items('node', $node, 'field_color_mode');
  $vars['color_mode'] = 'light-gradient';
  if ($get_field_color_mode[0]['value'] == 'dark') {
    $vars['color_mode'] = 'light-text dark-gradient';
  }
  if ($vars['view_mode'] == 'teaser' || $vars['view_mode'] == 'nas_node_teaser_small') {
    $node_path = 'node/' . $node->nid;
    $vars['title_link'] = l($node->title, $node_path, array('html' => TRUE));
    // Add bird illustration image.
    $get_field_bird_illustration = field_get_items('node', $node, 'field_bird_illustration');
    $image = '';
    if (!empty($get_field_bird_illustration[0]['file']->uri)) {
      $image = theme('image_style', array(
        'style_name' => 'nas_bird_teaser_illustration',
        'path' => $get_field_bird_illustration[0]['file']->uri,
      ));
    }
    $vars['bird_illustration'] = l($image, $node_path, array('html' => TRUE));
  }

  $donate_url = 'https://secure.audubon.org/site/Donation2?df_id=4900&4900.donation=form1&autologin=true&s_src=AUDHP&s_subsrc=BTN?';
  $vars['donate_link'] = l(
    t('Help this bird. Donate today'),
    $donate_url,
    array(
      'attributes' => array(
        'class' => array('button', 'large'),
        'target' => '_blank',
      ),
    )
  );
}

/**
 * Implements THEME_preprocess_node for BOA content type.
 */
function nas_preprocess_node_boa(&$vars) {
  $node = $vars['node'];
  $node_path = 'node/' . $node->nid;
  $vars['title_link'] = l($node->title, $node_path);
  $vars['teaser_list_image'] = '';
  $illustration = '<img src="' . base_path() . drupal_get_path('theme', 'nas') . '/img/boa-bird-1.jpg">';
  if ($field_boa_illustration_items = field_get_items('node', $node, 'field_boa_illustration')) {
    $illustration = theme('image_style', array(
        'style_name' => 'boa_family_species',
        'path' => $field_boa_illustration_items[0]['uri'],
    ));
    $image = theme('image', array(
      'path' => image_style_url('article_teaser_list', $field_boa_illustration_items[0]['uri']),
      'alt' => $node->title,
    ));
    $vars['teaser_list_image'] = l($image, 'node/' . $node->nid, array(
        'html' => TRUE,
        'attributes' => array('title' => $node->title),
      ));
  }
  $vars['bird_illustration'] = l($illustration, $node_path, array('html' => TRUE));

  $vars += array(
    'conservation_status' => '',
    'scientific_name' => '',
    'state_name' => '',
    'plate_number' => '',
  );

  if ($status_items = field_get_items('node', $node, 'field_boa_status')) {
    $vars['conservation_status'] = check_plain(taxonomy_term_load($status_items[0]['tid'])->name);
  }
  if ($field_scientific_name_items = field_get_items('node', $node, 'field_boa_sciname')) {
    $vars['scientific_name'] = $field_scientific_name_items[0]['safe_value'];
  }
  if ($state_items = field_get_items('node', $node, 'field_state')) {
    $state_term = taxonomy_term_load($state_items[0]['tid']);
    $vars['state_name'] = check_plain($state_term->field_iso_code[LANGUAGE_NONE][0]['safe_value']);
  }
  if ($plate_items = field_get_items('node', $node, 'field_boa_plate')) {
    $vars['plate_number'] = check_plain($plate_items[0]['value']);
  }

  $vars['sort_name'] = '';
  // BOA index page sortings.
  if (arg(0) == 'boa' && arg(1) == '') {
    $vars['sort_name'] = $vars['scientific_name'];
    if (isset($_GET['sort_by'])) {
      switch ($_GET['sort_by']) {
        case 'field_boa_plate_value':
          $vars['sort_name'] = $vars['plate_number'];
          break;

        case 'name':
          $vars['sort_name'] = $vars['state_name'];
          break;
      }
    }
  }
}

/**
 * Implements THEME_preprocess_node for Contact content type.
 */
function nas_preprocess_node_contact(&$vars) {
  $node = $vars['node'];
  $node_path = 'node/' . $node->nid;
  $vars['title_link'] = l($node->title, $node_path);

  // Only load all these data if rendering teaser.
  if ($vars['view_mode'] == 'teaser') {
    // Default illustration.
    if ($field_image_items = field_get_items('node', $node, 'field_image')) {
      $image = theme('image_style', array(
        'style_name' => 'our_leadership',
        'path' => $field_image_items[0]['uri'],
        'alt' => $node->title,
      ));
    }
    $vars['linked_image'] = l($image, $node_path, array(
      'html' => TRUE,
      'attributes' => array('title' => check_plain($node->title)),
    ));

    $vars['contact_title'] = '';
    if ($field_contact_title_items = field_get_items('node', $node, 'field_contact_title')) {
      $vars['contact_title'] = $field_contact_title_items[0]['safe_value'];
    }
  }
}

/**
 * Implements THEME_preprocess_node for BOA Family content type.
 */
function nas_preprocess_node_boaf(&$vars) {
  $node = $vars['node'];
  $node_path = 'node/' . $node->nid;
  $vars['title_link'] = l($node->title, $node_path);

  // Only load all these data if rendering teaser.
  if (in_array($vars['view_mode'], array('nas_node_teaser_small', 'teaser'))) {
    // Default illustration.
    $illustration = '<img src="' . base_path() . drupal_get_path('theme', 'nas') . '/img/boa-bird-1.jpg">';
    if ($boa = _nas_boa_family_birds($node->nid)) {
      if ($field_boa_illustration_items = field_get_items('node', $boa, 'field_boa_illustration')) {
        $illustration = theme('image_style', array(
            'style_name' => 'boa_family_species',
            'path' => $field_boa_illustration_items[0]['uri'],
        ));
      }
    }
    $vars['bird_illustration'] = l($illustration, $node_path, array('html' => TRUE));

    $vars['scientific_name'] = '';
    if ($field_scientific_name_items = field_get_items('node', $node, 'field_scientific_name')) {
      $vars['scientific_name'] = $field_scientific_name_items[0]['safe_value'];
    }
  }
}

/**
 * Helper function to group BOA by BOA families and get first BOA of BOA Family.
 *
 * @param $boaf_nid int
 *   BOA Family node's nid.
 *
 * @return mixed
 *   array - BOA nids groupped by BOA Family nids if $nid is omitted.
 *   object - first BOA node of BOA Family with specific nid.
 *   FALSE - if there is no such BOA node.
 */
function _nas_boa_family_birds($nid = FALSE) {
  static $boa_family_birds = array();

  if (!$boa_family_birds) {
    $menu = menu_tree_all_data('boa');
    foreach ($menu as $boaf_link) {
      // Skip non node links.
      if ($boaf_link['link']['router_path'] !== 'node/%') {
        continue;
      }
      list(, $boaf_nid) = explode('/', $boaf_link['link']['link_path']);
      // Loop thru genera links.
      foreach ($boaf_link['below'] as $genus_link) {
        // Skip non node links.
        if ($boaf_link['link']['router_path'] !== 'node/%') {
          continue;
        }
        // Loop thru birds links.
        foreach ($genus_link['below'] as $bird_link) {
          // Skip non node links.
          if ($boaf_link['link']['router_path'] !== 'node/%') {
            continue;
          }
          list(, $bird_nid) = explode('/', $bird_link['link']['link_path']);
          $boa_family_birds[$boaf_nid][] = $bird_nid;
        }
      }
    }
  }

  if ($nid) {
    return isset($boa_family_birds[$nid][0]) ? node_load($boa_family_birds[$nid][0]) : FALSE;
  }

  return $boa_family_birds;
}

/**
 * theme_preprocess_node for magazine-issue content type.
 */
function nas_preprocess_node_magazine_issue(&$vars) {
  $node = $vars['node'];

  $vars['title'] = check_plain($node->title);
  $vars['url'] = url('node/' . $node->nid);
  if ($vars['view_mode'] == 'teaser') {
    $vars['title_link'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
  }
}

/**
 * theme_preprocess_node for article content type.
 */
function nas_preprocess_node_article(&$vars) {
  $node = $vars['node'];
  if ($vars['view_mode'] == 'teaser') {
    $vars['by_line'] = '';
    if ($field_items = field_get_items('node', $node, 'field_author')) {
      $author_node = node_load($field_items[0]['target_id']);
      $vars['by_line'] = 'By ' . $author_node->title;
    }
  }

  if ($vars['view_mode'] == 'teaser_author_page' || $vars['view_mode'] == 'search_result') {
    $vars['article_date'] = '';
    if ($field_items = field_get_items('node', $node, 'field_article_date')) {
      $vars['article_date'] = format_date(strtotime($field_items[0]['value']), 'nas_date');
    }
  }

  $editorial_cards_view_modes = array(
    'editorial_card_3x',
    'editorial_card_4x',
    'nas_teaser_related_news',
    'teaser',
    'teaser_author_page',
    'search_result',
  );
  if (in_array($vars['view_mode'], $editorial_cards_view_modes)) {
    nas_preprocess_nodes_editorial_cards($vars);
    return;
  }

  $vars['image_src'] = FALSE;
  $vars['linked_image'] = '';
  $vars['teaser_list_image'] = '';
  if ($hero_image_items = field_get_items('node', $node, 'field_hero_image')) {
    $hero_image = $hero_image_items[0]['file'];
    $vars['image_src'] = image_style_url('in_the_news', $hero_image->uri);
    $image = theme('image', array(
      'path' => image_style_url('article_teaser', $hero_image->uri),
      'alt' => $node->title,
    ));
    $vars['linked_image'] = l($image, 'node/' . $node->nid, array(
        'html' => TRUE,
        'attributes' => array('title' => $node->title),
      ));

    $image = theme('image', array(
        'path' => image_style_url('article_teaser_list', $hero_image->uri),
        'alt' => $node->title,
      ));
    $vars['teaser_list_image'] = l($image, 'node/' . $node->nid, array(
        'html' => TRUE,
        'attributes' => array('title' => $node->title),
      ));
  }

  $subtitle_modes = array(
    'nas_node_teaser_small',
    'nas_teaser_flyway_landing',
    'static_page_related_teaser',
    'about_page_related_teaser',
    'conservation_strategy_featured_teaser',
  );
  if (in_array($vars['view_mode'], $subtitle_modes)) {
    $vars['subtitle'] = '';
    if (!empty($node->field_subtitle[LANGUAGE_NONE][0]['safe_value'])) {
      $vars['subtitle'] = $node->field_subtitle[LANGUAGE_NONE][0]['safe_value'];
    }
  }

  if ($vars['view_mode'] == 'nas_teaser_from_network') {
    nas_preprocess_node_article_news_from_network($vars);
    return;
  }

  $vars['title'] = check_plain($node->title);
  $vars['url'] = url('node/' . $node->nid);
  list($blue_text_link_text, $blue_text_link_url) = nas_panes_get_blue_text_link($node);
  $vars['blue_text_link_url'] = $blue_text_link_url;
  $vars['blue_text_link_text'] = ucwords($blue_text_link_text);
  $vars['custom_link_text'] = t('Read more');
  $custom_link_title_item = field_get_items('node', $node, 'field_link_title');
  if (!empty($custom_link_title_item)) {
    $vars['custom_link_text'] = drupal_ucfirst($custom_link_title_item[0]['safe_value']);
  }
  if ($vars['type'] == 'article') {
    // Looks terrible.
    $vars['title_link'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
  }

  if ($vars['view_mode'] == 'nas_node_related_features') {
    if (!empty($vars['content']['field_menu_section'])) {
      _nas_related_features_attach_menu_section_class($vars['content']['field_menu_section']);
    }
  }
}

/**
 * Preprocess function for editorial card teasers view modes.
 */
function nas_preprocess_nodes_editorial_cards(&$vars) {
  $node = $vars['node'];
  $vars['linked_image'] = '';
  $vars['teaser_list_image'] = '';
  $image_uri = FALSE;
  if ($image_items = field_get_items('node', $node, 'field_editorial_card_image')) {
    $image_uri = $image_items[0]['uri'];
  }
  elseif ($vars['type'] === 'slideshow' && $image_items = field_get_items('node', $node, 'field_images')) {
    $image_uri = $image_items[0]['uri'];
  }
  if ($image_uri) {
    $image = theme('image', array(
      'path' => image_style_url('article_teaser', $image_uri),
      'alt' => $node->title,
    ));
    $vars['linked_image'] = l($image, 'node/' . $node->nid, array(
        'html' => TRUE,
        'attributes' => array('title' => $node->title),
      ));
    $editorial_listings_view_modes = array(
      'nas_teaser_related_news',
      'teaser',
      'teaser_author_page',
      'search_result',
    );
    if (in_array($vars['view_mode'], $editorial_listings_view_modes)) {
      $image = theme('image', array(
        'path' => image_style_url('article_teaser_list', $image_uri),
        'alt' => $node->title,
      ));
      $vars['teaser_list_image'] = l($image, 'node/' . $node->nid, array(
          'html' => TRUE,
          'attributes' => array('title' => $node->title),
        ));
    }
  }

  $title = $node->title;
  if (!empty($node->field_editorial_card_title[LANGUAGE_NONE][0]['value'])) {
    $title = $node->field_editorial_card_title[LANGUAGE_NONE][0]['value'];
  }
  $vars['title'] = check_plain($title);
  $vars['title_link'] = l($title, 'node/' . $node->nid);

  $vars['subtitle'] = '';
  if (!empty($node->field_editorial_card_subtitle[LANGUAGE_NONE][0]['safe_value'])) {
    $vars['subtitle'] = $node->field_editorial_card_subtitle[LANGUAGE_NONE][0]['safe_value'];
  }
  elseif ($vars['type'] == 'slideshow' && !empty($node->field_slideshow_subtitle[LANGUAGE_NONE][0]['safe_value'])) {
    $vars['subtitle'] = $node->field_slideshow_subtitle[LANGUAGE_NONE][0]['safe_value'];
  }
  elseif ($vars['type'] !== 'project' && !empty($node->field_subtitle[LANGUAGE_NONE][0]['safe_value'])) {
    $vars['subtitle'] = $node->field_subtitle[LANGUAGE_NONE][0]['safe_value'];
  }
  elseif ($vars['type'] !== 'project' && !empty($node->body[LANGUAGE_NONE][0]['value'])) {
    $vars['subtitle'] = text_summary($node->body[LANGUAGE_NONE][0]['value'], 'full_html', 150);
  }
  elseif ($vars['type'] === 'project' && !empty($node->field_project_description[LANGUAGE_NONE][0]['safe_value'])) {
    $vars['subtitle'] = $node->field_project_description[LANGUAGE_NONE][0]['safe_value'];
  }

  $vars['url'] = url('node/' . $node->nid);

  if ($vars['type'] == 'project') {
    $vars['strategy_link'] = '';
    if (!empty($node->field_conservation_strategy[LANGUAGE_NONE][0]['target_id'])) {
      $nid = $node->field_conservation_strategy[LANGUAGE_NONE][0]['target_id'];
      if ($strategy = node_load($nid)) {
        $vars['strategy_link'] = l($strategy->title, 'node/' . $nid, array('attributes' => array('class' => array('editorial-card-slug'))));
      }
    }
  }
  else {
    list($blue_text_link_text, $blue_text_link_url) = nas_panes_get_blue_text_link($node);
    $vars['blue_text_link_url'] = $blue_text_link_url;
    $vars['blue_text_link_text'] = ucwords($blue_text_link_text);
  }

  $vars['custom_link_text'] = t('Read more');
  if ($custom_link_title_items = field_get_items('node', $node, 'field_link_title')) {
    $vars['custom_link_text'] = drupal_ucfirst($custom_link_title_items[0]['safe_value']);
  }
}

/**
 * theme_preprocess_node for Flyway content type.
 */
function nas_preprocess_node_flyway(&$vars) {
  $node = $vars['node'];
  $vars['title'] = check_plain($node->title);
  $vars['url'] = url('node/' . $node->nid);
  $vars['title_link'] = l($node->title, 'node/' . $node->nid);
  $vars['summary'] = '';
  if ($field_items = field_get_items('node', $node, 'field_flyway_body')) {
    $vars['summary'] = text_summary($field_items[0]['safe_value'], 'full_html', '150');
  }
}

/**
 * theme_preprocess_node for Static page content type.
 */
function nas_preprocess_node_static_page(&$vars) {
  if (in_array($vars['view_mode'], array('editorial_card_3x', 'editorial_card_4x', 'search_result'))) {
    nas_preprocess_nodes_editorial_cards($vars);
    return;
  }
  $node = $vars['node'];
  $vars['image_src'] = FALSE;
  $vars['linked_image'] = '';
  $vars['teaser_list_image'] = '';
  if ($hero_image_items = field_get_items('node', $node, 'field_hero_image')) {
    $hero_image = $hero_image_items[0]['file'];
    $vars['image_src'] = image_style_url('in_the_news', $hero_image->uri);
    $image = theme('image', array(
      'path' => image_style_url('article_teaser', $hero_image->uri),
      'alt' => $node->title,
    ));
    $vars['linked_image'] = l($image, 'node/' . $node->nid, array(
        'html' => TRUE,
        'attributes' => array('title' => $node->title),
      ));
    $image = theme('image', array(
      'path' => image_style_url('article_teaser_list', $hero_image->uri),
      'alt' => $node->title,
    ));
    $vars['teaser_list_image'] = l($image, 'node/' . $node->nid, array(
        'html' => TRUE,
        'attributes' => array('title' => $node->title),
      ));
  }

  $vars['dateline'] = format_date($node->created, 'nas_date');

  $vars['subtitle'] = '';
  if (!empty($node->field_subtitle[LANGUAGE_NONE][0]['safe_value'])) {
    $vars['subtitle'] = $node->field_subtitle[LANGUAGE_NONE][0]['safe_value'];
  }

  $vars['title'] = check_plain($node->title);
  $vars['url'] = url('node/' . $node->nid);
  $vars['title_link'] = l($node->title, 'node/' . $node->nid);
  list($blue_text_link_text, $blue_text_link_url) = nas_panes_get_blue_text_link($node);
  $vars['blue_text_link_url'] = $blue_text_link_url;
  $vars['blue_text_link_text'] = ucwords($blue_text_link_text);
  $vars['custom_link_text'] = t('Read more');
}

/**
 * theme_preprocess_node for Conservation strategy content type.
 */
function nas_preprocess_node_strategy(&$vars) {
  $node = $vars['node'];
  $vars['image_src'] = FALSE;
  $vars['linked_image'] = '';
  $vars['teaser_list_image'] = '';
  if ($hero_image_items = field_get_items('node', $node, 'field_hero_image')) {
    $hero_image = $hero_image_items[0]['file'];
    $image = theme('image', array(
      'path' => image_style_url('article_teaser_list', $hero_image->uri),
      'alt' => $node->title,
    ));
    $vars['teaser_list_image'] = l($image, 'node/' . $node->nid, array(
        'html' => TRUE,
        'attributes' => array('title' => $node->title),
      ));
  }

  $vars['title'] = check_plain($node->title);
  $vars['url'] = url('node/' . $node->nid);
  $vars['title_link'] = l($node->title, 'node/' . $node->nid);
}

/**
 * theme_preprocess_node for Conservation Project content type.
 */
function nas_preprocess_node_project(&$vars) {
  if (in_array($vars['view_mode'], array('editorial_card_3x', 'editorial_card_4x', 'search_result'))) {
    nas_preprocess_nodes_editorial_cards($vars);
    return;
  }

  $node = $vars['node'];
  $vars['image_src'] = FALSE;
  $vars['linked_image'] = '';
  $vars['teaser_list_image'] = '';

  if ($hero_image_items = field_get_items('node', $node, 'field_hero_image')) {
    $hero_image = $hero_image_items[0]['file'];
    $vars['image_src'] = image_style_url('in_the_news', $hero_image->uri);
    $image = theme('image', array(
      'path' => image_style_url('article_teaser', $hero_image->uri),
      'alt' => $node->title,
    ));
    $vars['linked_image'] = l($image, 'node/' . $node->nid, array(
        'html' => TRUE,
        'attributes' => array('title' => $node->title),
      ));
    $image = theme('image', array(
      'path' => image_style_url('article_teaser_list', $hero_image->uri),
      'alt' => $node->title,
    ));
    $vars['teaser_list_image'] = l($image, 'node/' . $node->nid, array(
        'html' => TRUE,
        'attributes' => array('title' => $node->title),
      ));
  }

  $vars['strategy_link'] = '';
  if (!empty($node->field_conservation_strategy[LANGUAGE_NONE][0]['target_id'])) {
    $nid = $node->field_conservation_strategy[LANGUAGE_NONE][0]['target_id'];
    if ($strategy = node_load($nid)) {
      $vars['strategy_link'] = l($strategy->title, 'node/' . $nid, array('attributes' => array('class' => array('editorial-card-slug'))));
    }
  }

  if (in_array($vars['view_mode'], array('nas_node_teaser_small', 'nas_node_project_teaser', 'search_result'))) {
    $vars['description'] = '';
    if (!empty($node->field_project_description[LANGUAGE_NONE][0]['safe_value'])) {
      $vars['description'] = $node->field_project_description[LANGUAGE_NONE][0]['safe_value'];
    }
  }

  $vars['title_link'] = l($node->title, 'node/' . $node->nid);
}

/**
 * Preprocess function for view mode 'nas_teaser_from_network' of article nodes.
 */
function nas_preprocess_node_article_news_from_network(&$vars) {
  $node = $vars['node'];
  $vars['title'] = l($node->title, 'node/' . $node->nid);
  $vars['blue_link'] = '';
  if (!empty($node->field_menu_section[LANGUAGE_NONE][0]['taxonomy_term'])) {
    $term = $node->field_menu_section[LANGUAGE_NONE][0]['taxonomy_term'];
    $vars['blue_link'] = l($term->name, 'taxonomy/term/' . $term->tid, array('attributes' => array('class' => array('editorial-card-slug'))));
  }
}

/**
 * theme_preprocess_node for engagement cards content type.
 */
function nas_preprocess_node_engagement_cards(&$vars) {
  $node = $vars['node'];
  if ($field_link_items = field_get_items('node', $node, 'field_link')) {
    $vars['button'] = l($field_link_items[0]['title'], $field_link_items[0]['url'], array(
      'attributes' => array(
        'class' => array(
        'button',
        'tomato',
        'large',
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

  // Disable aggregation for main styles.
  // IE8 can't recognize breakpoints when use @import for styles.
  // @todo should be improved. Maybe affect to performance.
  $css['sites/all/themes/custom/nas/css/app.css']['preprocess'] = FALSE;
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
  // To Do: 1) create some general function for handling header classes.
  if (arg(0) == 'node' && is_numeric(arg(1))) {
    $node = node_load(arg(1));
    if (isset($node->panelizer) && $node->panelizer['page_manager']->name == 'node:article:big_image') {
      $class = &drupal_static('nas_header_class');
      $class = 'transparent dark-bg';
    }
    if (isset($node->panelizer) && $node->panelizer['page_manager']->name == 'node:article:fullscreen_image') {
      $get_field_magazine_issue = field_get_items('node', $node, 'field_magazine_issue');
      if (empty($get_field_magazine_issue)) {
        $class = &drupal_static('nas_header_class');
        $class = 'transparent dark-bg';
      }
    }
  }
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
  $button_tag = array('edit-nas-search-btn', 'edit-nas-search-btn--2', 'edit-submit-search-form', 'edit-submit-nas-bird-guide');
  $element = $variables['element'];
  if (in_array($element['#id'], $button_tag)) {
    $element['#attributes']['type'] = 'submit';
    element_set_attributes($element, array('id', 'name'));
    $element['#attributes']['class'][] = 'form-' . $element['#button_type'];
    return '<button' . drupal_attributes($element['#attributes']) . '>' . $element['#value'] . '</button>';
  }

  return theme_button($variables);
}

/*
 * Implements theme_image().
 * remove height and width to make image responsible
 */
function nas_image($variables) {
  $attributes = $variables['attributes'];
  $attributes['src'] = file_create_url($variables['path']);
  $add_attributes = array('alt', 'title');

  // These styles shouldn't have width and height for responsive design.
  $remove_attr_for = array(
    'hero_mobile',
    'hero_image',
    'bio_image',
    'front_flyway_image',
    'conservation_strategy_icon',
    'boa_family_species',
    'magazine_issue_cover',
    'our_leadership',
    'wysiwyg_slide',
  );
  if (isset($variables['style_name']) && !in_array($variables['style_name'], $remove_attr_for)) {
    $add_attributes = array_merge($remove_attr_for, array('width', 'height'));
  }

  foreach ($add_attributes as $key) {
    if (isset($variables[$key])) {
      $attributes[$key] = $variables[$key];
    }
  }

  return '<img' . drupal_attributes($attributes) . ' />';
}

/*
 * Implements template_preprocess_field().
 */
function nas_preprocess_field(&$variables, $hook) {
  $element = $variables['element'];
  $bundle = $element['#bundle'];
  $entity_type = $element['#entity_type'];

  // Call the preprocess functions if exist.
  $function = 'nas_preprocess_field_' . $element['#field_name'];
  $function_bundle = 'nas_preprocess_field_' . $element['#field_name'] . '_' . $bundle;
  $function_viewmode = 'nas_preprocess_field_' . $element['#field_name'] . '__' . $element['#view_mode'];
  $function_bundle_viewmode = 'nas_preprocess_field_' . $element['#field_name'] . '_' . $bundle . '__' . $element['#view_mode'];

  if (function_exists($function)) {
    $function($variables);
  }
  if (function_exists($function_bundle)) {
    $function_bundle($variables);
  }
  if (function_exists($function_viewmode)) {
    $function_viewmode($variables);
  }
  if (function_exists($function_bundle_viewmode)) {
    $function_bundle_viewmode($variables);
  }

  $variables['theme_hook_suggestions'][] = $hook . '__' . $element['#field_name'] . '__' . $element['#view_mode'];
  $variables['theme_hook_suggestions'][] = $hook . '__' . $element['#field_name'] . '__' . $bundle . '__' . $element['#view_mode'];

  if (!isset($element['#object']->panelizer['page_manager']->name)) {
    return;
  }
  // Adds additional hook sugestion to theme individualy fields for different panelizer styles.
  $panelizer_style = $element['#object']->panelizer['page_manager']->name;
  $panelizer_style = str_replace($entity_type . ':' . $bundle . ':', '', $panelizer_style);
  if ($panelizer_style) {
    $hook_sugestion = $hook . '__' . $element['#field_name'] . '__'
        . $bundle . '__' . $panelizer_style;
    $variables['theme_hook_suggestions'][] = $hook_sugestion;
    if (isset($element['#pane_region'])) {
      $variables['theme_hook_suggestions'][] = $hook_sugestion . '__' . $element['#pane_region'] . '_region';
    }
  }
}

/*
 * Implements template_preprocess_panels_pane().
 */
function nas_preprocess_panels_pane(&$vars) {
  if (is_array($vars['content'])) {
    // Will be used for theme_hook_suggestions in preprocess field.
    $vars['content']['#pane_region'] = $vars['pane']->panel;
  }
}


/**
 * Preprocess function for field_magazine_issue_article.
 */
function nas_preprocess_field_field_magazine_issue_article(&$vars) {
  $element = $vars['element'];
  $date = nas_extract_magazine_date($element[0]['#markup']);
  $vars += $date;
  $get_field_magazine_issue = field_get_items('node', $element['#object'], 'field_magazine_issue');
  $vars['href'] = url('node/' . $get_field_magazine_issue[0]['target_id']);
}

/**
 * Implements theme_field().
 *
 * Override theming of date field of press release.
 */
function nas_field__field_article_date__article($variables) {
  if (!isset($variables['element'][0]['#markup']) || $variables['element']['#view_mode'] != '_custom_display') {
    return '';
  }
  return '<section class="clearfix article-sidebar-section article-meta hide-for-tiny hide-for-small hide-for-medium">'
    . '<small class="article-date">' . check_plain($variables['element']['#title']) . ' ' . strip_tags($variables['element'][0]['#markup']) . '</small>'
    . '</section>';
}

/**
 * Implements theme_field().
 */
function nas_field__field_author__article($variables) {
  $output = '';
  $published = '';
  $node = $variables['element']['#object'];
  $node_wrapper = entity_metadata_wrapper('node', $node);

  foreach ($variables['items'] as $item) {
    $entities = entity_load('node', array_values($item));
    foreach ($entities as $id => $entity) {
      $path = url('node/' . $id);
      $image_field = field_get_items('node', $entity, 'field_image');
      if ($image_field) {
        $image_file = file_load($image_field[0]['fid']);
        $image = theme('image_style', array(
          'style_name' => 'thumbnail',
          'path' => $image_file->uri,
          'attributes' => array(
            'class' => array(
              'article-author-image',
            ),
          ),
        ));
        $output .= '<a href="' . $path . '">' . $image . '</a>';
      }

      $output .= '<a href="' . $path . '">';
      $output .= '<h5 class="article-author-name">';
      $output .= check_plain($entity->title);
      $output .= '</h5></a>';
    }
  }

  // Set published date from issue magazine title.
  $magazine_issue = $node_wrapper->field_magazine_issue->value();
  if (!empty($magazine_issue->title)) {
    $published = $magazine_issue->title;
  }

  // Set published date based on created date or field_article_date.
  if (empty($published)) {
    $created = $node->created;
    $article_date = $node_wrapper->field_article_date->value();
    if (!empty($article_date)) {
      $created = strtotime($node->field_article_date[LANGUAGE_NONE][0]['value']);
    }
    $published = date('M d, Y', $created);
  }

  $output .= '<small class="article-date">' . t('Published @date', array('@date' => $published)) . '</small>';
  return $output;
}

/**
 * Preprocess function for field_related_bird field for nodes of type contact.
 */
function nas_preprocess_field_field_related_bird_contact(&$variables) {
  $name = '';
  $name = strtok($variables['element']['#object']->title, ' ') . "'s ";
  $variables['label'] = check_plain($name . 'Favorite Birds');
}

/**
 * Preprocess function for bio_image image style images.
 */
function nas_preprocess_image_style(&$vars) {
  if ($vars['style_name'] == 'bio_image') {
    $vars['attributes']['class'] = array('bio-image');
  }
  if ($vars['style_name'] == 'conservation_strategy_icon') {
    $vars['attributes']['class'] = array('hero-icon');
  }
}

/**
 * Override theme_panels_default_style_render_region().
 */
function nas_panels_default_style_render_region($vars) {
  return implode('', $vars['panes']);
}

/**
 * Preprocess function for views exposed forms.
 */
function nas_preprocess_views_exposed_form(&$variables) {
  if ($variables['form']['#id'] != 'views-exposed-form-nas-bird-guide-nas-bird-guide-fav-birds') {
    return;
  }

  // Preprocess fulltext search field.
  $fulltext = $variables['form']['search_api_views_fulltext'];
  $fulltext['#printed'] = FALSE;
  $fulltext['#theme'] = 'searchfield';
  $fulltext['#attributes']['placeholder'] = array('Search for a bird in the guide...');
  $fulltext['#theme_wrappers'] = array_filter($fulltext['#theme_wrappers'], function ($item) {
    return $item !== 'form_element';
  });
  _form_set_class($fulltext, array('bird-guide-search-input', 'radius'));

  $variables['widgets']['filter-search_api_views_fulltext']->widget = drupal_render($fulltext);
}

/**
 * Preprocess function for nas_article_fullscreen theme.
 */
function nas_preprocess_nas_article_fullscreen(&$variables) {
  // Replace substitutions.
  $color_mode = ctools_context_keyword_substitute($variables['settings']['color_mode'], array(), $variables['display']->context);

  // @Improve
  //   Since replacement may be a field rendered value we have no access to
  //   machine value. Thanks God human values for color_mode field are
  //   Uppercased machine values. This does matter for particular situation.
  $color_mode = strtolower(trim($color_mode));

  // Allowed values are limited to 'dark' and 'light'. Default value is 'dark'.
  $color_mode = in_array($color_mode, array('dark', 'light')) ? $color_mode : 'dark';

  $variables['color_mode_gradient'] = $color_mode;
  // Text color mode is inversion of gradient color mode
  $variables['color_mode_text'] = $color_mode == 'dark' ? 'light' : 'dark';
}

/**
 * Preprocess function for nas_static_page_1col theme.
 */
function nas_preprocess_nas_static_page_1col(&$variables) {
  $node = $variables['display']->context['panelizer']->data;
  $variables['color_mode_gradient'] = 'dark';
  if (!empty($node->field_color_mode[LANGUAGE_NONE][0]['value'])) {
    $variables['color_mode_gradient'] = $node->field_color_mode[LANGUAGE_NONE][0]['value'];
  }
  $variables['color_mode_text'] = $variables['color_mode_gradient'] == 'dark' ? 'light' : 'dark';
}

/**
 * Preprocess function for nas_static_page_2col theme.
 */
function nas_preprocess_nas_static_page_2col(&$variables) {
  $node = $variables['display']->context['panelizer']->data;
  $variables['color_mode_gradient'] = 'dark';
  if (!empty($node->field_color_mode[LANGUAGE_NONE][0]['value'])) {
    $variables['color_mode_gradient'] = $node->field_color_mode[LANGUAGE_NONE][0]['value'];
  }
  $variables['color_mode_text'] = $variables['color_mode_gradient'] == 'dark' ? 'light' : 'dark';
}

/**
 * Preprocess function for nas_article_fullscreen theme.
 */
function nas_preprocess_nas_flyway(&$variables) {
  // Replace substitutions.
  $background_image_url = ctools_context_keyword_substitute($variables['settings']['background_image'], array(), $variables['display']->context);
  $variables['background_image'] = $background_image_url;

  // Add image credit.
  $variables['image_credit'] = '';
  if (!empty($variables['display']->context['panelizer']->data)) {
    $node = $variables['display']->context['panelizer']->data;
    if (!empty($node->field_background_image[LANGUAGE_NONE][0]['field_file_credit'][LANGUAGE_NONE][0]['safe_value'])) {
      $variables['image_credit'] = $node->field_background_image[LANGUAGE_NONE][0]['field_file_credit'][LANGUAGE_NONE][0]['safe_value'];
    }
  }

  // Replace substitutions.
  $color_mode = ctools_context_keyword_substitute($variables['settings']['color_mode'], array(), $variables['display']->context);

  // @Improve
  //   Since replacement may be a field rendered value we have no access to
  //   machine value. Thanks God human values for color_mode field are
  //   Uppercased machine values. This does matter for particular situation.
  $color_mode = strtolower(trim($color_mode));

  // Allowed values are limited to 'dark' and 'light'. Default value is 'light'.
  $color_mode = in_array($color_mode, array('dark', 'light')) ? $color_mode : 'light';

  $variables['color_mode_text'] = $color_mode == 'dark' ? 'light' : 'dark';
}

/**
 * Implements hook_preprocess_panels_nas_frontpage().
 */
function nas_preprocess_panels_nas_frontpage(&$variables) {
  // Set featured frontpage backgroudimage variable.
  $featured_frontpage_image = &drupal_static('featured_frontpage_image');
  $variables['frontpage_backgroundimage'] = $featured_frontpage_image;

  // Set featured frontpage mobile content variable.
  $featured_frontpage_mobile_content = &drupal_static('featured_frontpage_mobile_content');
  $variables['featured_frontpage_mobile_content'] = $featured_frontpage_mobile_content;
}

/**
 * Implements THEME_preprocess_views_view.
 */
function nas_preprocess_views_view(&$vars) {
  $view = $vars['view'];
  // View to be preprocessed
  $needs_preprocess = array('related_birds', 'flyway_related_birds');
  if (in_array($view->name, $needs_preprocess)) {
    if (!empty($view->args[0]) && $node = node_load($view->args[0])) {
      $vars['title'] = check_plain($node->title) . '\'s Priority Birds';
    }
  }

  $vars['equalizer'] = FALSE;
  $class = $view->display_handler->get_option('css_class');
  $class_array = explode(' ', $class);
  if (in_array('equalizer', $class_array)) {
    $vars['equalizer'] = TRUE;
  }
}

/**
 * Implements hook_preprocess_field_field_images_slideshow().
 */
function nas_preprocess_field_field_images_slideshow(&$variables) {
  $variables['images'] = array();
  $node = $variables['element']['#object'];

  // Get title and subtitle to display on first and last slide.
  $variables['title'] = $node->title;
  $variables['subtitle'] = !empty($node->field_slideshow_subtitle[LANGUAGE_NONE][0]['value']) ? check_plain($node->field_slideshow_subtitle[LANGUAGE_NONE][0]['value']) : '';
  $variables['page_link'] = url('node/' . $node->nid, array('absolute' => TRUE));

  // Collects images and pass them to template.
  if (!empty($variables['element']['#items'])) {
    $overlay_image = FALSE;
    foreach ($variables['element']['#items'] as $delta => $image) {
      // Add regular slide.
      $content_image = array(
        'url' => image_style_url('slideshow', $image['uri']),
        // Additional fields to display on each slide.
        'credit' => !empty($image['field_file_credit'][LANGUAGE_NONE][0]['value']) ? $image['field_file_credit'][LANGUAGE_NONE][0]['value'] : '',
        'caption' => !empty($image['field_file_caption'][LANGUAGE_NONE][0]['value']) ? $image['field_file_caption'][LANGUAGE_NONE][0]['value'] : '',
        'alt' => !empty($image['field_file_image_alt_text'][LANGUAGE_NONE][0]['value']) ? check_plain($image['field_file_image_alt_text'][LANGUAGE_NONE][0]['value']) : '',
        'title' => !empty($image['field_file_image_title_text'][LANGUAGE_NONE][0]['value']) ? check_plain($image['field_file_image_title_text'][LANGUAGE_NONE][0]['value']) : '',
        // First or last slide.
        'first' => FALSE,
        'last' => FALSE,
      );
      $variables['images'][] = $content_image;

      // If it's first image.
      if ($delta == 0) {
        $overlay_image = $content_image;
      }
    }

    // Attach first and last slide.
    if (!empty($overlay_image)) {
      $overlay_image['first'] = TRUE;
      $overlay_image['last'] = FALSE;
      array_unshift($variables['images'], $overlay_image);

      $overlay_image['last'] = TRUE;
      $overlay_image['first'] = FALSE;
      array_push($variables['images'], $overlay_image);
    }
  }
}

/**
 * Preprocess function for nas_conservation_project theme.
 */
function nas_preprocess_nas_conservation_project(&$vars) {
  $vars['color_mode_gradient'] = 'dark';
  if (!empty($vars['display']->context['panelizer']->data->field_color_mode[LANGUAGE_NONE][0]['value'])) {
    $vars['color_mode_gradient'] = $vars['display']->context['panelizer']->data->field_color_mode[LANGUAGE_NONE][0]['value'];
  }
  $vars['color_mode_text'] = $vars['color_mode_gradient'] == 'dark' ? 'light' : 'dark';

  global $base_url;
  // Add Page absolute url.
  $vars['page_link'] = $base_url . '/' . drupal_get_path_alias();

  // Add Page title.
  $vars['page_title'] = drupal_get_title();
}

/**
 * Implements theme_preprocess_node().
 *
 * For slideshow content type.
 */
function nas_preprocess_node_slideshow(&$vars) {
  if (in_array($vars['view_mode'], array('editorial_card_3x', 'editorial_card_4x'))) {
    nas_preprocess_nodes_editorial_cards($vars);
    return;
  }

  $node = $vars['node'];
  if ($vars['view_mode'] == 'teaser' || $vars['view_mode'] == 'nas_node_related_features') {
    // Add slideshow main image.
    $vars['slideshow_image'] = '';
    $image_items = field_get_items('node', $node, 'field_images');
    if (!empty($image_items[0]['uri'])) {
      $output_image = theme('image_style', array(
          'style_name' => 'slideshow_teaser',
          'path' => $image_items[0]['uri'],
        ));

      $vars['slideshow_image'] = l($output_image, 'node/' . $node->nid, array('html' => TRUE));
    }

    if (!empty($vars['content']['field_menu_section'])) {
      _nas_related_features_attach_menu_section_class($vars['content']['field_menu_section']);
    }
  }
}

/**
 * Attach "editorial-card-slug" class to taxonomy link.
 */
function _nas_related_features_attach_menu_section_class(&$field) {
  foreach (element_children($field) as $key) {
    $field[$key]['#attributes']['class'][] = 'editorial-card-slug';
  }
}

/**
 * Returns parsed date.
 */
function nas_extract_magazine_date($string) {
  // @todo should be improved.
  $data = array();
  $str = $string;
  $str = explode('-', trim($str));
  $first_month = $str[0];
  $str[1] = explode(' ', trim($str[1]));
  $second_month = $str[1][0];
  $data['first_month_part_1'] = substr($first_month, 0, 3);
  $data['first_month_part_2'] = substr($first_month, 3);
  $data['sec_month_part_1'] = substr($second_month, 0, 3);
  $data['sec_month_part_2'] = substr($second_month, 3);
  $data['year'] = $str[1][1];

  return $data;
}