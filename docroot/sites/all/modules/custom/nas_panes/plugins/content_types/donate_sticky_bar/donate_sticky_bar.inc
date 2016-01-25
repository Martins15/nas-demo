<?php
/**
 * @file
 * Donate sticky bar at the bottom of the page.
 */

$plugin = array(
  'title' => t('Donate sticky bar'),
  'description' => t('Donate sticky bar at the bottom of the page.'),
  'category' => 'NAS',
  'edit form' => 'donate_sticky_bar_edit_form',
  'no title override' => TRUE,
  'render callback' => 'donate_sticky_bar_render',
  'hook theme' => 'donate_sticky_bar_theme',
  'defaults' => array(
    'variation' => 'form',
    'text' => 'Birds and their habitats need your help — <strong>Donate Now</strong>',
    'form_placeholder' => '$ Gift Amount',
    'form_button_text' => 'Next',
    'link_link_text' => 'Donate Now',
    'form_link' => 'https://secure.audubon.org/site/Donation2',
    'link_link' => 'https://secure.audubon.org/site/Donation2?df_id=8431&amp;8431.donation=form1&amp;s_src=2015_AUDHP_giving-tuesday_donation-bar',
    'form_elements' => '<input type="hidden" name="df_id" value="6960">
<input type="hidden" name="6960.donation" value="form1">
<input type="hidden" name="s_src" value="2015_AUDHP_donationbar-donate_test">
<input type="hidden" name="s_subsrc" value="website">
<input type="hidden" name="set.DonationLevel" value="9466">
<input type="hidden" name="OptimizelyDonationBar" value="clicked">',
  ),
);

/**
 * Configuration form.
 */
function donate_sticky_bar_edit_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  $form['global_configuration'] = array(
    '#type' => 'checkbox',
    '#title' => t('Global configuration'),
    '#description' => t('Check it to set the properties globally for all panes of this type.'),
  );
  $form['variation'] = array(
    '#type' => 'radios',
    '#title' => t('Choose variation'),
    '#options' => array(
      'form' => t('Donation form'),
      'link' => t('Donation link'),
    ),
    '#default_value' => $conf['variation'],
  );
  $form['text'] = array(
    '#type' => 'textfield',
    '#title' => t('Donate bar text'),
    '#default_value' => $conf['text'],
  );

  $form['form_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Link to post form to'),
    '#default_value' => $conf['form_link'],
    '#states' => array(
      'visible' => array(':input[name="variation"]' => array('value' => 'form')),
    ),
  );
  $form['link_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Link to send user to'),
    '#default_value' => $conf['link_link'],
    '#states' => array(
      'visible' => array(':input[name="variation"]' => array('value' => 'link')),
    ),
  );

  $form['form_placeholder'] = array(
    '#type' => 'textfield',
    '#title' => t('Placeholder text'),
    '#default_value' => $conf['form_placeholder'],
    '#states' => array(
      'visible' => array(':input[name="variation"]' => array('value' => 'form')),
    ),
  );

  $form['form_button_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Button text'),
    '#default_value' => $conf['form_button_text'],
    '#states' => array(
      'visible' => array(':input[name="variation"]' => array('value' => 'form')),
    ),
  );
  $form['link_link_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Link text'),
    '#default_value' => $conf['link_link_text'],
    '#states' => array(
      'visible' => array(':input[name="variation"]' => array('value' => 'link')),
    ),
  );

  $form['form_elements'] = array(
    '#type' => 'textarea',
    '#title' => t('Special form elements'),
    '#default_value' => $conf['form_elements'],
    '#states' => array(
      'visible' => array(':input[name="variation"]' => array('value' => 'form')),
    ),
    '#rows' => 7,
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function donate_sticky_bar_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (array_key_exists($key, $form_state['values'])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }

  // Form build ID is required for contextual links.
  $form_state['conf']['form_build_id'] = $form_state['values']['form_build_id'];

  // Update all donate_sticky_bar panes with global configuration.
  if ($form_state['values']['global_configuration']) {
    $panel_type = 'donate_sticky_bar';
    $configs = db_select('panels_pane', 'pp')
      ->fields('pp', array('pid', 'configuration'))
      ->condition('pp.type', $panel_type)
      ->execute()
      ->fetchAll();

    foreach ($configs as $config_data) {
      $config = unserialize($config_data->configuration);
      foreach (array_keys($form_state['plugin']['defaults']) as $key) {
        $config[$key] = $form_state['values'][$key];
      }

      db_update('panels_pane')
        ->fields(array('configuration' => serialize($config)))
        ->condition('type', $panel_type)
        ->condition('pid', $config_data->pid)
        ->execute();
    }
  }
}

/**
 * Render callback.
 */
function donate_sticky_bar_render($subtype, $conf, $args, $context) {
  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $context);

  $block = new stdClass();
  switch ($conf['variation']) {
    case 'form':
      $block->content = array(
        '#markup' => theme('donate_sticky_bar_form', array(
          'text' => filter_xss(t($conf['text'])),
          'form_link' => filter_xss($conf['form_link']),
          'form_placeholder' => filter_xss(t($conf['form_placeholder'])),
          'form_button_text' => filter_xss(t($conf['form_button_text'])),
          'form_elements' => $conf['form_elements'],
          'contextual_links' => $contextual_links,
        )),
      );
      break;

    case 'link':
      $block->content = array(
        '#markup' => theme('donate_sticky_bar_link', array(
          'text' => filter_xss(t($conf['text'])),
          'link_link' => filter_xss($conf['link_link']),
          'link_link_text' => filter_xss(t($conf['link_link_text'])),
          'contextual_links' => $contextual_links,
        )),
      );
      break;
  }

  if ($plugin = ctools_get_plugins('ctools', 'content_types', $subtype)) {
    $block->content['#attached'] = array(
      'css' => array(
        $plugin['path'] . '/css/donate_sticky_bar.css',
      ),
      'js' => array(
        $plugin['path'] . '/js/donate_sticky_bar.js',
      ),
    );
  }
  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function donate_sticky_bar_theme(&$theme, $plugin) {
  $theme['donate_sticky_bar_form'] = array(
    'variables' => array(
      'text' => '',
      'form_link' => '',
      'form_placeholder' => '',
      'form_button_text' => '',
      'form_elements' => '',
      'contextual_links' => '',
    ),
    'template' => 'donate-sticky-bar-form',
    'path' => $plugin['path'],
  );
  $theme['donate_sticky_bar_link'] = array(
    'variables' => array(
      'text' => '',
      'link_link' => '',
      'link_link_text' => '',
      'contextual_links' => '',
    ),
    'template' => 'donate-sticky-bar-link',
    'path' => $plugin['path'],
  );
}
