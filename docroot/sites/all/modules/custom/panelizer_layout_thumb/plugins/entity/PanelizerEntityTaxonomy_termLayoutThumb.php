<?php
/**
 * @file
 * Class for the Panelizer taxonomy term entity plugin.
 */
module_load_include('class.php', 'panelizer', 'plugins/entity/PanelizerEntityTaxonomyTerm');

/**
 * Panelizer Entity taxonomy term plugin class.
 *
 * Handles taxonomy term specific functionality for Panelizer.
 */
class PanelizerEntityTaxonomy_termLayoutThumb extends PanelizerEntityTaxonomyTerm {
  /**
   * Attach form fields
   */
  public function hook_field_attach_form($entity, &$form, &$form_state, $langcode) {
    parent::hook_field_attach_form($entity, $form, $form_state, $langcode);
    panelizer_layout_thumb_field_alter($this, $entity, $form, $form_state, $langcode);
  }
}
