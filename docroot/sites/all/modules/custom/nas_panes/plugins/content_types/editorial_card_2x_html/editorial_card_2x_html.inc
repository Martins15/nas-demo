<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('2x Editorial Cards & 1 Free HTML'),
  'description' => t('Provides "2x Editorial cards & 1 Free HTML" pane'),
  'category' => 'Editorial cards',
  'edit form' => 'editorial_card_2x_html_edit_form',
  'render callback' => 'editorial_card_2x_html_render',
  'admin title' => 'editorial_card_2x_html_admin_title',
  'admin info' => 'editorial_card_2x_html_admin_info',
  'hook theme' => 'editorial_card_2x_html_theme',
  'defaults' => array(
    'config' => array(
      'editorial' => array(),
      'html' => array(
        'title' => '',
        'image' => 0,
        'url' => '',
        'body' => array(
          'value' => '',
        ),
      ),
      'styles' => array(
        'padding' => array(
          'top' => 0,
          'between' => 0,
          'bottom' => 0,
          'double-bottom' => 0,
        ),
        'additional_classes' => '',
      ),
      'more_link' => array(
        'more_link_text' => '',
        'more_link_url' => '',
      ),
    ),
  ),
  'tags' => array('full_width'),
);

/**
 * Help function to provide administrative title.
 */
function editorial_card_2x_html_admin_title($subtype, $conf, $context = NULL) {
  return t('2x Editorial Cards & 1 Free HTML');
}

/**
 * Callback to provide administrative info.
 *
 * The preview in panels when building a panel.
 */
function editorial_card_2x_html_admin_info($subtype, $conf, $context = NULL) {
  if (empty($conf)) {
    return;
  }
  $block = new stdClass();
  $block->title = t('2x Editorial Cards & 1 Free HTML');
  $block->content = '';
  $items = array();
  if (!empty($conf['config'])) {
    foreach ($conf['config']['editorial'] as $editorial) {
      if (!empty($editorial['entity_label'])) {
        $items[] = $editorial['entity_label'];
      }
    }
    if (!empty($conf['config']['html']['title'])) {
      $items[] = $conf['config']['html']['title'];
    }
  }
  $block->content = theme('item_list', array('items' => $items));
  return $block;
}

/**
 * An edit form for the pane's settings.
 */
function editorial_card_2x_html_edit_form($form, &$form_state) {
  $conf = $form_state['conf']['config'];
  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'editorial_card_2x_html', 'nas_panes', 'plugins/content_types/editorial_card_2x_html');

  $form['#tree'] = TRUE;
  $form['config']['editorial'] = array(
    '#type' => 'fieldset',
    '#title' => t('2x Editorial cards'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  for ($i = 0; $i < 2; $i++) {
    $form['config']['editorial'][$i] = array(
      '#type' => 'entityreference',
      '#title' => t('Editorial card Reference %number', array(
        '%number' => $i + 1,
      )),
      '#default_value' => !empty($conf['editorial'][$i]['entity_id']) ? $conf['editorial'][$i]['entity_id'] : 0,
      '#era_entity_type' => 'node',
      '#era_bundles' => array(
        'article',
        'event',
        'static_page',
        'slideshow',
      ),
    );
  }
  $form['config']['html'] = array(
    '#type' => 'fieldset',
    '#title' => t('HTML block'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['config']['html']['image'] = array(
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
    '#default_value' => $conf['html']['image'],
    '#required' => TRUE,
  );
  $form['config']['html']['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Green title'),
    '#default_value' => $conf['html']['title'],
  );
  $form['config']['html']['url'] = array(
    '#title' => t('URL'),
    '#type' => 'link_field',
    '#delta' => 0,
    '#field_name' => 'url',
    '#language' => LANGUAGE_NONE,
    '#field_parents' => array(),
    '#default_value' => $conf['html']['url'],
  );
  $form_state['field']['url'][LANGUAGE_NONE] = array(
    'instance' => array(
      'settings' => array(
        'title' => 'none',
        'url' => 'optional',
        'attributes' => array(),
      ),
    ),
  );
  $form['config']['html']['body'] = array(
    '#type' => 'text_format',
    '#format' => 'full_html',
    '#rows' => 4,
    '#title' => t('Body'),
    '#default_value' => $conf['html']['body']['value'],
  );

  $form['config']['more_link'] = array(
    '#type' => 'fieldset',
    '#title' => t('More Link'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#tree' => TRUE,
  );
  $form['config']['more_link']['more_link_text'] = array(
    '#type' => 'textfield',
    '#title' => t('More link text'),
    '#default_value' => $conf['more_link']['more_link_text'],
  );
  $form['config']['more_link']['more_link_url'] = array(
    '#type' => 'textfield',
    '#title' => t('More link URL'),
    '#default_value' => $conf['more_link']['more_link_url'],
  );

  $form['config']['styles'] = array(
    '#type' => 'fieldset',
    '#title' => t('Styles'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#tree' => TRUE,
  );
  $form['config']['styles']['additional_classes'] = array(
    '#type' => 'textfield',
    '#title' => t('Additional classes'),
    '#default_value' => $conf['styles']['additional_classes'],
  );
  $form['config']['styles']['padding'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Padding'),
    '#options' => array(
      'top' => t('Top padding'),
      'between' => t('Additional space between title and content'),
      'bottom' => t('Bottom padding'),
      'double-bottom' => t('Double bottom padding'),
    ),
    '#default_value' => $conf['styles']['padding'],
  );

  return $form;
}

/**
 * Submit handler for "2x Editorial Cards + 1 FREE HTML block" form.
 */
function editorial_card_2x_html_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 *
 * See ctools_plugin_examples for more advanced info.
 */
function editorial_card_2x_html_render($subtype, $conf, $args, $context) {
  $more_link = '';
  $config = $conf['config'];
  if (!empty($config['more_link']['more_link_text']) &&
    !empty($config['more_link']['more_link_url'])
  ) {
    $more_link = l($config['more_link']['more_link_text'], $config['more_link']['more_link_url']);
  }

  $teasers = array();
  foreach ($config['editorial'] as $item) {
    if (!empty($item['entity_id']) && $node = node_load($item['entity_id'])) {
      $build = node_view($node, 'editorial_card_3x');
      $teasers[] = drupal_render($build);
    }
  }
  if (!empty($config['html'])) {
    $html = $config['html'];
    $img = '';
    if (!empty($html['image']) && $image = file_load($html['image'])) {
      $img = theme('image', array(
        'path' => image_style_url('article_teaser', $image->uri),
        'alt' => $html['title'],
      ));
    }
    $title = $html['title'];
    if (!empty($html['url']['url'])) {
      $img = l($img, $html['url']['url'], array('html' => TRUE));
      $title = l($title, $html['url']['url']);
    }

    $teasers[] = theme('editorial_card_html_block', array(
      'image' => $img,
      'title' => $title,
      'body' => $html['body']['value'],
    ));
  }

  $title = '';
  if (!empty($conf['override_title_text']) && !empty($teasers)) {
    $title = ctools_context_keyword_substitute($conf['override_title_text'], array(), array($context));
  }
  $space_bottom = '';
  if ($config['styles']['padding']['double-bottom']) {
    $space_bottom = 'space-bottom double';
  }
  elseif ($config['styles']['padding']['bottom']) {
    $space_bottom = 'space-bottom';
  }

  $block = new stdClass();
  $block->content = theme('editorial_card_2x_html', array(
    'teasers' => $teasers,
    'title' => $title,
    'more_link' => $more_link,
    'additional_classes' => !empty($config['styles']['additional_classes']) ? $config['styles']['additional_classes'] : '',
    'space_top' => $config['styles']['padding']['top'],
    'space_between' => $config['styles']['padding']['between'],
    'space_bottom' => $space_bottom,
  ));

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function editorial_card_2x_html_theme(&$theme, $plugin) {
  $theme['editorial_card_2x_html'] = array(
    'variables' => array(
      'teasers' => NULL,
      'title' => NULL,
      'more_link' => NULL,
      'additional_classes' => NULL,
      'space_top' => NULL,
      'space_between' => NULL,
      'space_bottom' => NULL,
    ),
    'template' => 'editorial-card-2x-html',
    'path' => $plugin['path'],
  );
  $theme['editorial_card_html_block'] = array(
    'variables' => array(
      'image' => '',
      'title' => array(),
      'body' => '',
    ),
    'template' => 'editorial-card-html-block',
    'path' => $plugin['path'],
  );
}
