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
  if ($vars['type'] == 'article') {
    nas_preprocess_node_article($vars);
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
    $vars['bird_illustration'] = l(theme('image_style', array(
      'style_name' => 'nas_bird_teaser_illustration',
      'path' => $get_field_bird_illustration[0]['file']->uri,
    )), $node_path, array('html' => TRUE));
  }
}

/**
 * theme_preprocess_node for article content type.
 */
function nas_preprocess_node_article(&$vars) {
  $node = $vars['node'];
  $hero_image_items = field_get_items('node', $node, 'field_hero_image');
  $hero_image = $hero_image_items[0]['file'];
  $vars['image_src'] = image_style_url('in_the_news', $hero_image->uri);

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
    $vars['title_link'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
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
  $button_tag = array('edit-nas-search-btn', 'edit-submit-nas-bird-guide');
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
  //this styles shouldn't have width and height for responsive design
  $remove_attr_for = array('hero_mobile', 'hero_image');

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
  if (!isset($element['#object']->panelizer['page_manager']->name)) {
    return;
  }
  // Adds additional hook sugestion to theme individualy fields for different panelizer styles.
  $panelizer_style = $element['#object']->panelizer['page_manager']->name;
  $bundle = $element['#bundle'];
  $e_type = $element['#entity_type'];
  $panelizer_style = str_replace($e_type . ':' . $bundle . ':', '', $panelizer_style);
  if ($panelizer_style) {
    $hook_sugestion = $hook . '__' . $element['#field_name'] . '__'
        . $bundle . '__' . $panelizer_style;
    $variables['theme_hook_suggestions'][] = $hook_sugestion;
    if (isset($element['#pane_region'])) {
      $variables['theme_hook_suggestions'][] = $hook_sugestion . '__' . $element['#pane_region'] . '_region';
    }
  }
  // Call the preprocess functions if exist.
  $function = 'nas_preprocess_field_' . $element['#field_name'];
  $function_bundle = 'nas_preprocess_field_' . $element['#field_name'] . '_' . $bundle;
  if (function_exists($function)) {
    $function($variables);
  }
  if (function_exists($function_bundle)) {
    $function_bundle($variables);
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
  // Prepare markup for supporting responsive features.
  $str = $element[0]['#markup'];
  $str = explode('-', $str);
  $first_month = $str[0];
  $str[1] = explode(' ', $str[1]);
  $second_month = $str[1][0];
  $vars['first_month_part_1'] = substr($first_month, 0, 3);
  $vars['first_month_part_2'] = substr($first_month, 3);
  $vars['sec_month_part_1'] = substr($second_month, 0, 3);
  $vars['sec_month_part_2'] = substr($second_month, 3);
  $vars['year'] = $str[1][1];
}

/*
 * Implements theme_field().
 */
function nas_field__field_author__article($variables) {
  $output = '';
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

      $output .= '<a href="' . $path . '">'
          . '<h5 class="article-author-name">' . check_plain($entity->title)
          . '</h5></a>';
    }
  }
  $published = date('M d, Y', $variables['element']['#object']->created);
  $output .= '<small class="article-date">' . t('Published @date', array('@date' => $published)) . '</small>';
  return $output;
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
  $form = $variables['form'];
  if ($form['#id'] === 'views-exposed-form-nas-bird-guide-nas-bird-guide-fav-birds') {
    $fulltext = $form['search_api_views_fulltext'];
    $fulltext['#theme'] = 'searchfield';
    $fulltext['#printed'] = FALSE;
    $fulltext['#attributes']['placeholder'] = array('Search for a bird in the guide...');
    $fulltext['#attributes']['type'] = array('search');
    _form_set_class($fulltext, array('bird-guide-search-input', 'radius'));
    $fulltext['#theme_wrappers'] = array_filter($fulltext['#theme_wrappers'], function ($item) {
      return $item !== 'form_element';
    });
    $variables['widgets']['filter-search_api_views_fulltext']->widget = drupal_render($fulltext);
  }
}