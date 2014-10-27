<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Press Contact'),
  'description' => t('Provides Block with Press Contact for Press Release'),
  'category' => 'NAS',
  'render callback' => 'nas_panes_press_contact_render',
  'all contexts' => TRUE,
);


/**
 * Run-time rendering of the body of the block (content type).
 */
function nas_panes_press_contact_render($subtype, $conf, $args, $contexts) {

  if (!empty($contexts)) {
    $node = reset($contexts)->data;
    if ($node->type !== 'article') {
      return;
    }
    $press_contact_items = field_get_items('node', $node, 'field_pressrelease_contact');
    if (empty($press_contact_items)) {
      return;
    }
  }

  $contacts = array();
  foreach ($press_contact_items as $press_contact_item) {
    $press_contact = node_load($press_contact_item['target_id']);

    $name = check_plain($press_contact->title);

    $position = '';
    if ($position_item = field_get_items('node', $press_contact, 'field_contact_title')) {
      $position = $position_item[0]['safe_value'];
    }

    $office = '';
    if ($office_item = field_get_items('node', $press_contact, 'field_contact_office')) {
      $office = $office_item[0]['safe_value'];
    }

    $address = '';
    if ($address_item = field_get_items('node', $press_contact, 'field_contact_address')) {
      $address = $address_item[0]['safe_value'];
    }

    $phone = '';
    if ($phone_item = field_get_items('node', $press_contact, 'field_contact_phone')) {
      $phone = $phone_item[0]['safe_value'];
    }

    $email = '';
    if ($email_item = field_get_items('node', $press_contact, 'field_contact_email')) {
      $email = $email_item[0]['safe_value'];
    }

    $contacts[] = array(
      'name' => $name,
      'office' => $office,
      'position' => $position,
      'address' => $address,
      'phone' => $phone,
      'email' => $email,
    );
  }

  $block = new stdClass();
  $block->content = theme('nas_panes_press_contact', array(
    'title' => t('Press Contacts'),
    'contacts' => $contacts,
  ));

  return $block;
}
