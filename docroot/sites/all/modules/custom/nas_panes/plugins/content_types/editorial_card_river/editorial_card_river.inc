<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Editorial teasers river-like listings'),
  'description' => t('Provides "Editorial teasers river-like listings" pane'),
  'category' => 'Editorial cards',
  'edit form' => 'editorial_card_river_edit_form',
  'render callback' => 'editorial_card_river_render',
  'required context' => new ctools_context_optional(t('Node'), 'node'),
  'admin title' => 'editorial_card_river_admin_title',
  'admin info' => 'editorial_card_river_admin_info',
);

function editorial_card_river_admin_title($subtype, $conf, $context = NULL) {
  $output = t('Editorial teasers river-like listing');
  return $output;
}

/**
 * Callback to provide administrative info (the preview in panels when building
 * a panel).
 */
function editorial_card_river_admin_info($subtype, $conf, $context = NULL) {
  $presets = _editorial_card_river_presets();

  $block = new stdClass();
  $block->title = $presets[$conf['preset']]['title'];
  $block->content = $presets[$conf['preset']]['title'];
  return $block;
}

/**
 * An edit form for the pane's settings.
 */
function editorial_card_river_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['#tree'] = TRUE;

  // Do not show context selector if configuration form is called from page.
  if (isset($_GET['nas-panes-from-page'])) {
    $form['context']['#prefix'] = '<div style="display:none;">';
    $form['context']['#suffix'] = '</div>';
  }

  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'editorial_card_river', 'nas_panes', 'plugins/content_types/editorial_card_river');

  $presets = _editorial_card_river_presets();
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
  $form['donate_caption'] = array(
    '#type' => 'textfield',
    '#title' => t('Donate caption'),
    '#default_value' => !empty($conf['donate_caption']) ? $conf['donate_caption'] : 'Remember that Audubon depends on your support to do the conservation work that we do.',
  );
  $form['donate_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Donate URL'),
    '#default_value' => !empty($conf['donate_path']) ? $conf['donate_path'] : '',
  );

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function editorial_card_river_edit_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function editorial_card_river_render($subtype, $conf, $args, $context) {
  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $context);

  $more_link = '';
  if (!empty($conf['more_link_text']) && !empty($conf['more_link_url'])) {
    $more_link = l($conf['more_link_text'], $conf['more_link_url']);
  }

  $presets = _editorial_card_river_presets();
  $preset = $presets[$conf['preset']];
  foreach ($preset['content'] as $key => $item) {
    switch ($item['type']) {
      case 'view':
        $args = _editorial_card_river_get_view_args($item['options']['args'], $context);
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

  // Block specific logic. Donate block should be shown only if there are items
  // in bottom view.
  if (empty($content['bottom'])) {
    unset($content['donate']);
    unset($content['bottom']);
  }

  $block = new stdClass();
  $block->content = theme('editorial_card_river', array(
    'content' => implode(' ', $content),
    'title' => !empty($conf['override_title_text']) ? check_plain($conf['override_title_text']) : '',
    'more_link' => $more_link,
    'contextual_links' => $contextual_links,
  ));

  return $block;
}

function _editorial_card_river_presets() {
  $presets = array(
    // To be used on news page
    'news_listing' => array(
      'title' => t('News listing'),
      'content' => array(
        'top' => array(
          'type' => 'view',
          'options' => array(
            'view' => 'nas_news',
            'display' => 'articles_list_top',
            'args' => array(),
          ),
        ),
        'donate' => array(
          'type' => 'donate',
        ),
        'bottom' => array(
          'type' => 'view',
          'options' => array(
            'view' => 'nas_news',
            'display' => 'articles_list_bot',
            'args' => array(),
          ),
        ),
      ),
    ),
    // To be used on Author page.
    'author_page_listing' => array(
      'title' => t('Author page listing'),
      'content' => array(
        'top' => array(
          'type' => 'view',
          'options' => array(
            'view' => 'nas_articles',
            'display' => 'articles_by_author',
            'args' => array('entity:node'),
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
function _editorial_card_river_get_view_args($settings, $context) {
  $args = array();
  foreach ($settings as $require_context) {
    if (in_array($require_context, $context->type)) {
      $args[] = $context->argument;
    }
  }
  return $args;
}