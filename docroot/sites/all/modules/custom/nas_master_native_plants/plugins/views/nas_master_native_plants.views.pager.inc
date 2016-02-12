<?php
/**
 * @file
 * Definition of the custom Views pager plugin.
 */

/**
 * NAS Master Native Plants pager plugin handler class.
 */
class nas_master_native_plants_views_pager_plugin extends views_plugin_pager_full {
  public function render($input) {
    $pager_theme = views_theme_functions('nas_master_native_plants_pager', $this->view, $this->display);
    // The 0, 1, 3, 4 index are correct. See theme_pager documentation.
    $tags = array(
      0 => $this->options['tags']['first'],
      1 => $this->options['tags']['previous'],
      3 => $this->options['tags']['next'],
      4 => $this->options['tags']['last'],
    );
    $output = theme($pager_theme, array(
      'tags' => $tags,
      'element' => $this->options['id'],
      'parameters' => $input,
      'quantity' => $this->options['quantity'],
    ));
    return $output;
  }
}
