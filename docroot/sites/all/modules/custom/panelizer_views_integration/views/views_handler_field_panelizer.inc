<?php

/**
 * @file
 * Contains the basic 'node' field handler.
 */

// @codingStandardsIgnoreStart
/**
 * Field handler to provide simple renderer that allows linking to a node.
 * Definition terms:
 * - link_to_node default: Should this field have the checkbox "link to node" enabled by default.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_panelizer extends views_handler_field {

  /**
   * {@inheritdoc}
   */
  public function init(&$view, &$options) {
    parent::init($view, $options);
  }

  /**
   * {@inheritdoc}
   */
  public function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  /**
   * Provide link to node option.
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

}
// @codingStandardsIgnoreEnd
