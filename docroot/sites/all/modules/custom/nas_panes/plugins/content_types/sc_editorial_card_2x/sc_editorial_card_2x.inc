<?php

/**
 * @file
 * Define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Editorial card (2x)'),
  'description' => t('Provides "Editorial card (2x)" pane'),
  'category' => 'S&C Panes',
  'edit form' => 'sc_editorial_card_2x_edit_form',
  'render callback' => 'sc_editorial_card_2x_render',
  'admin title' => 'sc_editorial_card_2x_plus_admin_title',
  'hook theme' => 'sc_editorial_card_2x_plus_theme',
  'defaults' => array(
    'config' => array(
      'items' => array(),
    ),
  ),
);

/**
 * Help function to provide administrative title.
 */
function sc_editorial_card_2x_plus_admin_title($subtype, $conf, $context = NULL) {
  return t('2x Editorial Cards');
}

/**
 * An edit form for the pane's settings.
 */
function sc_editorial_card_2x_edit_form($form, &$form_state) {
  $conf = $form_state['conf']['config'];
  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'sc_editorial_card_2x', 'nas_panes', 'plugins/content_types/sc_editorial_card_2x');
  _nas_sc_panes_hide_pane_title_field($form);
  $form['#tree'] = TRUE;

  for ($i = 0; $i < 2; $i++) {
    $form['config']['items'][$i] = array(
      '#type' => 'fieldset',
      '#title' => t('Item @num', array('@num' => $i + 1)),
      '#tree' => TRUE,
      '#collapsible' => TRUE,
    );

    $form['config']['items'][$i]['top_link'] = array(
      '#title' => t('Header link'),
      '#type' => 'link_field',
      '#delta' => 0,
      '#field_name' => 'top_link',
      '#language' => LANGUAGE_NONE,
      '#field_parents' => array(),
      '#default_value' => !empty($conf['items'][$i]['top_link']) ? $conf['items'][$i]['top_link'] : '',
    );

    $form['config']['items'][$i]['title'] = array(
      '#type' => 'textfield',
      '#title' => t('Main heading'),
      '#default_value' => !empty($conf['items'][$i]['title']) ? $conf['items'][$i]['title'] : '',
    );

    $form['config']['items'][$i]['bottom_link'] = array(
      '#title' => t('Bottom link'),
      '#type' => 'link_field',
      '#delta' => 0,
      '#field_name' => 'bottom_link',
      '#language' => LANGUAGE_NONE,
      '#field_parents' => array(),
      '#default_value' => !empty($conf['items'][$i]['bottom_link']) ? $conf['items'][$i]['bottom_link'] : '',
    );

    $form['config']['items'][$i]['image'] = array(
      '#type' => 'media',
      '#tree' => TRUE,
      '#title' => t('Image'),
      '#description' => t('Click "Browse" to locate the file on your computer or in the site\'s File Library.'),
      '#media_options' => array(
        'global' => array(
          'file_extensions' => 'png jpg jpeg gif',
          'max_filesize' => '20 MB',
          'file_directory' => '',
          'types' => array('image'),
        ),
      ),
      '#default_value' => !empty($conf['items'][$i]['image']) ? $conf['items'][$i]['image'] : 0,
      '#required' => TRUE,
      '#pp_crop_styles' => array(
        'static_cards_two_columns',
        'static_cards_two_columns_mobile',
      ),
    );

    $form['config']['items'][$i]['color_mode'] = array(
      '#type' => 'radios',
      '#title' => t('Color mode'),
      '#options' => array(
        'dark' => t('Dark'),
        'light' => t('Light'),
      ),
      '#default_value' => !empty($conf['items'][$i]['color_mode']) ? $conf['items'][$i]['color_mode'] : 'dark',
      '#description' => t('Choose which color you\'d like the text to appear. For darker images, select Light Text. For lighter images, select Dark text.'),
    );
    $form['config']['items'][$i]['gradient'] = array(
      '#type' => 'checkbox',
      '#title' => t('Add gradient background'),
      '#default_value' => !empty($conf['items'][$i]['gradient']) ? $conf['items'][$i]['gradient'] : 0,
    );
  }

  return $form;
}

/**
 * Submit function, anything in the $form_state[conf] automatically gets saved.
 */
function sc_editorial_card_2x_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 *
 * @see ctools_plugin_examples()
 */
function sc_editorial_card_2x_render($subtype, $conf, $args, $contexts) {
  $config = $conf['config'];
  $block = new stdClass();

  $items = $config['items'];
  foreach ($items as &$item) {
    $item['top_link_markup'] = '';
    if (!empty($item['top_link']['url']) && !empty($item['top_link']['title'])) {
      $item['top_link_markup'] = l($item['top_link']['title'], $item['top_link']['url'], array('attributes' => array('class' => array('banner-slug'))));
    }

    $item['title_link'] = l($item['title'], $item['bottom_link']['url'], array(
      'attributes' => array('title' => $item['title']),
    ));

    $item['bottom_link_markup'] = l($item['bottom_link']['title'], $item['bottom_link']['url']);
    $item['gradient'] = !empty($item['gradient']) ? $item['gradient'] : 0;

    $attributes = array(
      'class' => array('banner', $item['color_mode'] . '-bg bg-respond'),
    );

    $image_object = file_load($item['image']);
    if ($image_object) {
      $image_url = image_style_url('static_cards_two_columns', $image_object->uri);
      $image_url_mobile = image_style_url('static_cards_two_columns_mobile', $image_object->uri);
      $attributes['style'] = 'background-image: url(\'' . $image_url . '\')';
      $attributes['data-bg-small'] = $image_url_mobile;
      $attributes['data-bg-large'] = $image_url;
    }
    $item['wrap_attr'] = drupal_attributes($attributes);
  }

  $block->content = theme('sc_editorial_card_2x', array(
    'items' => $items,
  ));

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function sc_editorial_card_2x_plus_theme(&$theme, $plugin) {
  $theme['sc_editorial_card_2x'] = array(
    'variables' => array(
      'items' => array(),
    ),
    'template' => 'sc-editorial-card-2x',
    'path' => $plugin['path'],
  );
}
