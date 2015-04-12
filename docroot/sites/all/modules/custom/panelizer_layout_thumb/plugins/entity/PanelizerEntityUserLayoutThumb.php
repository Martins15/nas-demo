<?php

/**
 * @file
 * Class for the Panelizer user entity plugin.
 */
module_load_include('class.php', 'panelizer', 'plugins/entity/PanelizerEntityUser');

/**
 * Panelizer Entity user plugin class.
 *
 * Handles user specific functionality for Panelizer.
 */
class PanelizerEntityUserLayoutThumb extends PanelizerEntityUser {
  /**
   * Attach form fields
   */
  public function hook_field_attach_form($entity, &$form, &$form_state, $langcode) {
    parent::hook_field_attach_form($entity, $form, $form_state, $langcode);
    panelizer_layout_thumb_field_alter($this, $entity, $form, $form_state, $langcode);
  }
}
