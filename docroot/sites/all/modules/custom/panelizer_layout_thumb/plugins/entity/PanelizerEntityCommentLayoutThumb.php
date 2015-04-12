<?php

/**
 * @file
 * Class for the Panelizer comment entity plugin.
 */
module_load_include('class.php', 'panelizer', 'plugins/entity/PanelizerEntityComment');

/**
 * Panelizer Entity comment plugin class.
 *
 * Handles comment specific functionality for Panelizer.
 */
class PanelizerEntityCommentLayoutThumb extends PanelizerEntityComment {
  /**
   * Attach form fields
   */
  public function hook_field_attach_form($entity, &$form, &$form_state, $langcode) {
    parent::hook_field_attach_form($entity, $form, $form_state, $langcode);
    panelizer_layout_thumb_field_alter($this, $entity, $form, $form_state, $langcode);
  }
}
