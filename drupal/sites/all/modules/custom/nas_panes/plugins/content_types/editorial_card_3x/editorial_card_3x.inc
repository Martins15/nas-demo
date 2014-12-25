<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Editorial card (3x)'),
  'description' => t('Provides "Editorial card (3x)" pane'),
  'category' => 'Editorial cards',
  'edit form' => 'editorial_card_3x_edit_form',
  'render callback' => 'editorial_card_3x_render',
  'required context' => new ctools_context_optional(t('Node'), 'node'),
  'admin title' => 'editorial_card_3x_admin_title',
  'admin info' => 'editorial_card_3x_admin_info',
);

function editorial_card_3x_admin_title($subtype, $conf, $context = NULL) {
  $presets = _editorial_card_3x_presets();
  $output = t('Editorial card (3x)') . ': ' . $presets[$conf['preset']]['title'];
  return $output;
}

/**
 * Callback to provide administrative info (the preview in panels when building
 * a panel).
 */
function editorial_card_3x_admin_info($subtype, $conf, $context = NULL) {
  $presets = _editorial_card_3x_presets();

  $block = new stdClass();
  $block->title = $presets[$conf['preset']]['title'];
  $block->content = '';
  if ($conf['preset'] == 'manual_override') {
    $items = array();
    foreach ($conf['refs'] as $ref) {
      if (!empty($ref['title'])) {
        $items[] = $ref['title'];
      }
    }
    $block->content = theme('item_list', array('items' => $items));
  }
  return $block;
}

/**
 * An edit form for the pane's settings.
 */
function editorial_card_3x_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['#tree'] = TRUE;

  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'editorial_card_3x', 'nas_panes', 'plugins/content_types/editorial_card_3x');

  $presets = _editorial_card_3x_presets();
  $options = array();
  foreach ($presets as $key => $preset) {
    $options[$key] = $preset['title'];
  }

  $form['preset'] = array(
    '#type' => 'select',
    '#options' => $options,
    '#default_value' => !empty($conf['preset']) ? $conf['preset'] : '',
  );

  $form['more_link_text'] = array(
    '#type' => 'textfield',
    '#title' => t('More link text'),
    '#default_value' => !empty($conf['more_link_text']) ? $conf['more_link_text'] : '',
  );
  $form['more_link_url'] = array(
    '#type' => 'textfield',
    '#title' => t('More link URL'),
    '#default_value' => !empty($conf['more_link_url']) ? $conf['more_link_url'] : '',
  );
  $form['additional_classes'] = array(
    '#type' => 'textfield',
    '#title' => t('Additional classes'),
    '#default_value' => !empty($conf['additional_classes']) ? $conf['additional_classes'] : '',
  );

  // Get default value when count is empty or when it has been update via form.
  if (empty($form_state['storage']['count']) || (!empty($form_state['values']['count']) && $form_state['storage']['count'] != $form_state['values']['count'])) {
    // Update value when form has been submitted.
    if (!empty($form_state['values']['count'])) {
      $form_state['storage']['count'] = $form_state['values']['count'];
    }
    // Get from panel pane configuration.
    elseif (!empty($conf['count'])) {
      $form_state['storage']['count'] = $conf['count'];
    }
    // Default value.
    else {
      $form_state['storage']['count'] = 3;
    }
  }

  $form['count'] = array(
    '#type' => 'select',
    '#title' => t('Number of items'),
    '#options' => array(
      3 => '3',
      6 => '6',
      9 => '9',
      12 => '12',
      15 => '15',
      18 => '18',
    ),
    '#default_value' => $form_state['storage']['count'],
  );
  $form['update_count'] = array(
    '#type' => 'button',
    '#name' => 'update_count_button',
    '#value' => t('Update count'),
    '#submit' => array(
      'editorial_card_3x_change_number_of_items',
    ),
    '#ajax' => array(
      'wrapper' => 'editorial-card-3x-refs',
    ),
  );

  $form['refs'] = array(
    '#type' => 'container',
    '#id' => 'editorial-card-3x-refs',
  );
  for ($i = 1; $i <= $form_state['storage']['count']; $i++) {
    if (empty($conf['refs'][$i])) {
      $conf['refs'][$i] = array();
    }
    $form['refs'][$i] = array(
      '#type' => 'fieldset',
      '#title' => t('Reference %number', array('%number' => $i)),
      '#collapsible' => TRUE,
      '#collapsed' => !array_filter($conf['refs'][$i]),
      '#tree' => TRUE,
    );
    $form['refs'][$i]['image'] = array(
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
      '#default_value' => !empty($conf['refs'][$i]['image']) ? $conf['refs'][$i]['image'] : 0,
    );
    $form['refs'][$i]['category'] = array(
      '#title' => 'Category/Eyebrow',
      '#type' => 'textfield',
      '#default_value' => !empty($conf['refs'][$i]['category']) ? $conf['refs'][$i]['category'] : '',
    );
    $form['refs'][$i]['category_url'] = array(
      '#title' => 'Category/Eyebrow URL',
      '#type' => 'textfield',
      '#default_value' => !empty($conf['refs'][$i]['category_url']) ? $conf['refs'][$i]['category_url'] : '',
    );
    $form['refs'][$i]['title'] = array(
      '#prefix' => t('To display card fill Title and URL.'),
      '#title' => t('Title'),
      '#type' => 'textfield',
      '#default_value' => !empty($conf['refs'][$i]['title']) ? $conf['refs'][$i]['title'] : '',
    );
    $form['refs'][$i]['url'] = array(
      '#title' => 'URL',
      '#type' => 'textfield',
      '#default_value' => !empty($conf['refs'][$i]['url']) ? $conf['refs'][$i]['url'] : '',
    );
    $form['refs'][$i]['excerpt'] = array(
      '#title' => t('Excerpt'),
      '#type' => 'textfield',
      '#default_value' => !empty($conf['refs'][$i]['excerpt']) ? $conf['refs'][$i]['excerpt'] : '',
    );
    $form['refs'][$i]['readmore_label'] = array(
      '#title' => t('Read more link label'),
      '#description' => t('"Read more »" by default'),
      '#type' => 'textfield',
      '#default_value' => !empty($conf['refs'][$i]['readmore_label']) ? $conf['refs'][$i]['readmore_label'] : '',
    );
  }

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function editorial_card_3x_edit_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Edit form submit for changing number of references.
 */
function editorial_card_3x_change_number_of_items($form, &$form_state) {
  return $form['refs'];
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function editorial_card_3x_render($subtype, $conf, $args, $context) {
  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $context);

  $more_link = '';
  if (!empty($conf['more_link_text']) && !empty($conf['more_link_url'])) {
    $more_link = l($conf['more_link_text'], $conf['more_link_url']);
  }

  if ($conf['preset'] != 'manual_override') {
    $presets = _editorial_card_3x_presets();
    $preset = $presets[$conf['preset']];
    foreach ($preset['content'] as $key => $item) {
      $options = !empty($item['options']) ? $item['options'] : array();
      switch ($item['type']) {
        case 'views_results':
          $content[$key] = array();
          $args = _editorial_card_3x_get_view_args($item['options']['args'], $context);
          $view = views_get_view($item['options']['view']);
          if (is_array($args)) {
            $view->set_arguments($args);
          }
          $view->set_display($item['options']['display']);
          $view->items_per_page = !empty($conf['count']) ? $conf['count'] : 3;
          $view->display_handler->options['pager']['options']['items_per_page'] = !empty($conf['count']) ? $conf['count'] : 3;
          $view->pre_execute();
          $view->execute();
          $view_results = $view->result;
          foreach ($view_results as $result) {
            $node = node_load($result->{$options['result_key']});
            $node_view = node_view($node, 'nas_node_teaser_small');
            $content[$key][] = drupal_render($node_view);
          }
          break;

        case 'er_field':
          if ($field_items = field_get_items('node', $context->data, $options['field'])) {
            foreach ($field_items as $item) {
              if (!empty($item['target_id']) && $node = node_load($item['target_id'])) {
                $build = node_view($node, 'nas_node_teaser_small');
                $content[$key][] = drupal_render($build);
              }
            }
          }
          break;

        case 'view':
          $args = _editorial_card_3x_get_view_args($item['options']['args'], $context);
          $content[$key] = views_embed_view($item['options']['view'], $item['options']['display'], implode('', $args));
          break;

        case 'donate':
          $content[$key] = theme('nas_panes_pane_donate_button', array(
            'caption' => $conf['donate_caption'],
            'link' => l(t('Donate'), $conf['donate_path'], array(
              'attributes' => array(
                'class' => array(
                  'button',
                  'tomato',
                  'large',
                ),
              ),
            )),
          ));
          break;
      }
    }
    $teasers = !empty($content['list']) ? $content['list'] : array();
  }
  else {
    $teasers = array();
    foreach ($conf['refs'] as $ref) {
      // Title and url are required to show card.
      if (empty($ref['title']) || empty($ref['url'])) {
        continue;
      }
      $teaser = array(
        'linked_image' => '',
        'title' => check_plain($ref['title']),
        'url' => $ref['url'],
        'category_link' => '',
        'excerpt' => !empty($ref['excerpt']) ? check_plain($ref['excerpt']) : '',
      );
      if (!empty($ref['image'])) {
        if ($file = file_load($ref['image'])) {
          $image = theme('image', array(
            'path' => image_style_url('article_teaser', $file->uri),
            // TODO: replace with image's alt.
            'alt' => $teaser['title'],
          ));
          $teaser['linked_image'] = l($image, $teaser['url'], array(
              'html' => TRUE,
              'attributes' => array('title' => $teaser['title']),
            ));
        }
      }
      if (!empty($ref['category']) && !empty($ref['category_url'])) {
        $teaser['category_link'] = l($ref['category'], $ref['category_url'], array(
          'attributes' => array('class' => array('editorial-card-slug')),
        ));
      }
      $readmore_label = !empty($ref['readmore_label']) ? $ref['readmore_label'] : 'Read more';
      $teaser['readmore_link'] = l($readmore_label, $ref['url'], array(
        'attributes' => array('class' => array('editorial-card-link')),
      ));

      $teasers[] = $teaser;
    }
  }
  $teasers = array_slice($teasers, 0, $conf['count']);

  $title = '';
  if ($conf['override_title']) {
    $title = ctools_context_keyword_substitute($conf['override_title_text'], array(), array($context));
  }

  $block = new stdClass();
  $block->content = theme('editorial_card_3x', array(
    'teasers' => $teasers,
    'title' => $title,
    'more_link' => $more_link,
    'additional_classes' => !empty($conf['additional_classes']) ? $conf['additional_classes'] : '',
    'contextual_links' => $contextual_links,
  ));

  return $block;
}

function _editorial_card_3x_presets() {
  $presets = array(
    'manual_override' => array(
      'title' => t('Manual override'),
    ),
    // To be used on Homepage.
    'most_recent_articles' => array(
      'title' => t('Most recent articles'),
      'content' => array(
        'list' => array(
          'type' => 'views_results',
          'options' => array(
            'view' => 'nas_news',
            'display' => 'page_in_the_news',
            'result_key' => 'nid',
            'args' => array(),
          ),
        ),
      ),
    ),
    'flyway_in_the_news' => array(
      'title' => t('Flyway In the News'),
      'content' => array(
        'list' => array(
          'type' => 'views_results',
          'options' => array(
            'view' => 'nas_news',
            'display' => 'flyway_in_the_news',
            'result_key' => 'nid',
            'args' => array('entity:node'),
          ),
        ),
      ),
    ),
    'bird_in_the_news' => array(
      'title' => t('Bird In the News'),
      'content' => array(
        'list' => array(
          'type' => 'views_results',
          'options' => array(
            'view' => 'nas_news',
            'display' => 'nas_bird_in_the_news_default',
            'result_key' => 'nid',
            'args' => array('entity:node'),
          ),
        ),
      ),
    ),
    'bird_guide_in_the_news' => array(
      'title' => t('Bird Guide: In the News'),
      'content' => array(
        'list' => array(
          'type' => 'views_results',
          'options' => array(
            'view' => 'nas_news',
            'display' => 'page_in_the_news',
            'result_key' => 'nid',
            'args' => array(),
          ),
        ),
      ),
    ),
    'about_page_learn_more' => array(
      'title' => t('About page: Learn more'),
      'content' => array(
        'list' => array(
          'type' => 'views_results',
          'options' => array(
            'view' => 'about_page_learn_more',
            'display' => 'default',
            'result_key' => 'nid',
            'args' => array(),
          ),
        ),
      ),
    ),
    'static_page_related' => array(
      'title' => t('Static page related'),
      'content' => array(
        'list' => array(
          'type' => 'er_field',
          'options' => array(
            'field' => 'field_related',
            'view_mode' => 'static_page_related_teaser',
          ),
        ),
      ),
    ),
  );

  return $presets;
}

/**
 * Helper function to get arguments to embeded view from existing contexts.
 *
 * @param $settings array
 *   Array of required context types.
 * @param $context
 *   Available context.
 *
 * @return array
 *   Array of args to be passed into view.
 */
function _editorial_card_3x_get_view_args($settings, $context) {
  $args = array();
  foreach ($settings as $require_context) {
    if (in_array($require_context, $context->type)) {
      $args[] = $context->argument;
    }
  }
  return $args;
}