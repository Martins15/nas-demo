<?php

/**
 * @file
 * Class for the Panelizer node entity plugin.
 */

module_load_include('class.php', 'panelizer', 'plugins/entity/PanelizerEntityNode');

/**
 * Panelizer Entity node plugin class.
 *
 * Handles node specific functionality for Panelizer.
 */
class PanelizerEntityNodeLayoutThumb extends PanelizerEntityNode {
  /**
   * Attach form fields
   */
  public function hook_field_attach_form($entity, &$form, &$form_state, $langcode) {
    parent::hook_field_attach_form($entity, $form, $form_state, $langcode);
    panelizer_layout_thumb_field_alter($this, $entity, $form, $form_state, $langcode);
  }
}
