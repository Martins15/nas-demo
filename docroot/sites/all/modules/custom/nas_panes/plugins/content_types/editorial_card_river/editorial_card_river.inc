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

/**
 * Title callback.
 */
function editorial_card_river_admin_title($subtype, $conf, $context = NULL) {
  $output = t('Editorial teasers river-like listing');
  return $output;
}

/**
 * Callback to provide administrative info.
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

  $menu_section_options = _nas_panes_get_menu_section_options();
  $form['preset'] = array(
    '#type' => 'select',
    '#options' => $options,
    '#title' => t('Listing view mode'),
    '#default_value' => !empty($conf['preset']) ? $conf['preset'] : '',
    '#description' => t("News listing shows article teasers with byline and 'Author listing' shows article teasers with date line and is dedicated only for Author's page placements"),
  );

  $form['context']['#states'] = array(
    'visible' => array(
      ':input[name="preset"]' => array('value' => 'author_page_listing'),
    ),
  );

  $form['filter'] = array(
    '#type' => 'container',
  );

  $form['filter']['help'] = array(
    '#markup' => t('Select Menu section or/and Editorial section term(s) you would like to filter articles appearing in this listing by:'),
  );

  $filter_state = array(
    'enabled' => array(
      ':input[name="preset"]' => array('value' => 'news_listing'),
    ),
  );
  $form['filter']['menu_section'] = array(
    '#type' => 'select',
    '#title' => t('Menu section'),
    '#options' => $menu_section_options,
    '#multiple' => TRUE,
    '#description' => t("If you'd like all articles tagged with a parent term and all its child terms to be shown in this listing you should only select this parent term. In case you want this listing to show articles tagged with a child term(s) please select one or more child terms with Ctrl+Mouse click"),
    '#size' => count($menu_section_options) / 2,
    '#default_value' => !empty($conf['filter']['menu_section']) ? $conf['filter']['menu_section'] : '',
    '#states' => $filter_state,
  );

  $form['filter']['editorial_section'] = array(
    '#type' => 'entityreference',
    '#title' => t('Editorial section'),
    '#default_value' => !empty($conf['filter']['editorial_section']) ? array_keys($conf['filter']['editorial_section']) : array(),
    '#era_entity_type' => 'taxonomy_term',
    '#era_bundles' => array('section'),
    '#era_cardinality' => -1,
    '#states' => $filter_state,
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
  $form['paddings'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Paddings'),
    '#options' => array(
      'top' => t('Top padding'),
      'between' => t('Additional space between title and content'),
      'bottom' => t('Bottom padding'),
      'double-bottom' => t('Double bottom padding'),
    ),
    '#default_value' => !empty($conf['paddings']) ? $conf['paddings'] : _editorial_card_river_default_paddings_conf(),
  );

  return $form;
}

/**
 * Submit callback.
 */
function editorial_card_river_edit_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Render callback.
 */
function editorial_card_river_render($subtype, $conf, $args, $context) {
  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $context);

  $more_link = '';
  if (!empty($conf['more_link_text']) && !empty($conf['more_link_url'])) {
    $more_link = l($conf['more_link_text'], $conf['more_link_url']);
  }
  $show_news_donate = &drupal_static('show_news_donate');
  $show_news_donate = theme('nas_panes_pane_donate_button', array(
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
  $presets = _editorial_card_river_presets();
  $preset = $presets[$conf['preset']];
  foreach ($preset['content'] as $key => $item) {
    switch ($item['type']) {
      case 'view':
        $args = array($item['options']['view'], $item['options']['display']);
        _editorial_card_river_get_view_args($args, $item['options']['args'], $context, $conf);
        $content[$key] = call_user_func_array('views_embed_view', $args);
        break;
    }
  }

  if (empty($conf['paddings'])) {
    $conf['paddings'] = _editorial_card_river_default_paddings_conf();
  }
  $spacebottom = '';
  if ($conf['paddings']['double-bottom']) {
    $spacebottom = 'space-bottom double';
  }
  elseif ($conf['paddings']['bottom']) {
    $spacebottom = 'space-bottom';
  }

  $block = new stdClass();
  $block->content = theme('editorial_card_river', array(
    'content' => implode(' ', $content),
    'title' => !empty($conf['override_title_text']) ? check_plain($conf['override_title_text']) : '',
    'more_link' => $more_link,
    'contextual_links' => $contextual_links,
    'spacetop' => $conf['paddings']['top'],
    'spacebetween' => $conf['paddings']['between'],
    'spacebottom' => $spacebottom,
  ));

  return $block;
}

/**
 * Returns array of presets.
 */
function _editorial_card_river_presets() {
  $presets = array(
    // To be used on news page.
    'news_listing' => array(
      'title' => t('News listing'),
      'content' => array(
        'top' => array(
          'type' => 'view',
          'options' => array(
            'view' => 'nas_news',
            'display' => 'articles_list_top',
            'args' => array(
              'menu_section',
              'editorial_section',
            ),
          ),
        ),
        'donate' => array(
          'type' => 'donate',
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
 * Helper function to get arguments to embedded view from existing contexts.
 *
 * @param array $args
 *   Arguments.
 *
 * @param array $settings
 *   Array of required context types.
 *
 * @param array $context
 *   Available context.
 *
 * @param array $conf
 *   Pane configuration.
 *
 * @return array
 *   Array of args to be passed into view.
 */
function _editorial_card_river_get_view_args(&$args, $settings, $context, $conf = array()) {
  foreach ($settings as $require_context) {
    $arg_key = count($args);
    switch ($require_context) {
      case 'menu_section':
        // Apply filter or add default value.
        $args[$arg_key] = 'all';
        if (!empty($conf['filter'][$require_context])) {
          $args[$arg_key] = implode('+', $conf['filter'][$require_context]);
        }
        break;

      case 'editorial_section':
        $args[$arg_key] = 'all';
        if (!empty($conf['filter'][$require_context])) {
          // Apply filter or add default value.
          $editorial_filter = array();
          foreach ($conf['filter'][$require_context] as $reference) {
            if (!empty($reference['entity_id'])) {
              $editorial_filter[] = $reference['entity_id'];
            }
          }
          if (!empty($editorial_filter)) {
            $args[$arg_key] = implode('+', $editorial_filter);
          }
        }
        break;

      default:
        if (is_array($context->type) && in_array($require_context, $context->type)) {
          $args[] = $context->argument;
        }
        break;
    }
  }

  return $args;
}

/**
 * Helper function to provide default panes padding configuration.
 */
function _editorial_card_river_default_paddings_conf() {
  return array(
    'top' => 'top',
    'between' => 'between',
    'bottom' => 'bottom',
    'double-bottom' => 0,
  );
}
