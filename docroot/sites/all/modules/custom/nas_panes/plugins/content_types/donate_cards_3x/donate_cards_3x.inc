<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Donate cards (3x)'),
  'description' => t('Provides "Donate cards (3x)" pane'),
  'category' => 'Donate panes',
  'edit form' => 'donate_cards_3x_edit_form',
  'render callback' => 'donate_cards_3x_render',
);

/**
 * An edit form for the pane's settings.
 */
function donate_cards_3x_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['#tree'] = TRUE;

  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'donate_cards_3x', 'nas_panes', 'plugins/content_types/donate_cards_3x');

  $form['additional_classes'] = array(
    '#type' => 'textfield',
    '#title' => t('Additional classes'),
    '#default_value' => !empty($conf['additional_classes']) ? $conf['additional_classes'] : '',
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
    '#default_value' => !empty($conf['paddings']) ? $conf['paddings'] : _donate_cards_3x_default_paddings_conf(),
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
    '#submit' => array('donate_cards_3x_change_number_of_items'),
    '#ajax' => array(
      'wrapper' => 'donate-cards-3x-refs',
    ),
  );

  $form['refs'] = array(
    '#type' => 'container',
    '#id' => 'donate-cards-3x-refs',
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
    $form['refs'][$i]['title'] = array(
      '#prefix' => t('To display card fill Title.'),
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
      '#type' => 'textarea',
      '#default_value' => !empty($conf['refs'][$i]['excerpt']) ? $conf['refs'][$i]['excerpt'] : '',
    );
  }

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function donate_cards_3x_edit_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Edit form submit for changing number of references.
 */
function donate_cards_3x_change_number_of_items($form, &$form_state) {
  return $form['refs'];
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function donate_cards_3x_render($subtype, $conf, $args, $context) {
  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $context);

  $teasers = array();
  foreach ($conf['refs'] as $ref) {
    // Title and url are required to show card.
    if (empty($ref['title'])) {
      continue;
    }
    $teaser = array(
      'linked_image' => '',
      'title' => $ref['title'],
      'url' => $ref['url'],
      'excerpt' => !empty($ref['excerpt']) ? check_plain($ref['excerpt']) : '',
    );
    if (!empty($ref['image'])) {
      if ($file = file_load($ref['image'])) {
        $image = theme('image', array(
          'path' => image_style_url('article_teaser', $file->uri),
          // TODO: replace with image's alt.
          'alt' => $ref['title'],
        ));
        $teaser['linked_image'] = $image;
        if (!empty($ref['url'])) {
          $teaser['linked_image'] = l($image, $ref['url'], array(
            'html' => TRUE,
            'attributes' => array('title' => $ref['title']),
          ));
        }
      }
    }
    if (!empty($ref['url'])) {
      $teaser['title'] = l($ref['title'], $ref['url'], array(
          'attributes' => array('title' => $ref['title']),
        ));
    }

    $teasers[] = $teaser;
  }
  $teasers = array_slice($teasers, 0, !empty($conf['count']) ? $conf['count'] : 3);

  $title = '';
  if (!empty($conf['override_title_text']) && !empty($teasers)) {
    $title = ctools_context_keyword_substitute($conf['override_title_text'], array(), array($context));
  }

  if (empty($conf['paddings'])) {
    $conf['paddings'] = _donate_cards_3x_default_paddings_conf();
  }
  $spacebottom = '';
  if ($conf['paddings']['double-bottom']) {
    $spacebottom = 'space-bottom double';
  }
  elseif ($conf['paddings']['bottom']) {
    $spacebottom = 'space-bottom';
  }

  $block = new stdClass();
  $block->content = theme('donate_cards_3x', array(
    'teasers' => $teasers,
    'title' => check_plain($title),
    'additional_classes' => !empty($conf['additional_classes']) ? $conf['additional_classes'] : '',
    'contextual_links' => $contextual_links,
    'spacetop' => $conf['paddings']['top'],
    'spacebetween' => $conf['paddings']['between'],
    'spacebottom' => $spacebottom,
  ));

  return $block;
}

/**
 * Helper function to provide default panes padding configuration.
 */
function _donate_cards_3x_default_paddings_conf() {
  return array(
    'top' => 0,
    'between' => 0,
    'bottom' => 0,
    'double-bottom' => 'double-bottom',
  );
}