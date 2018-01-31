<?php

/**
 * @file
 * This is the task handler plugin for Page manager search tests.
 */

$plugin = array(
  'handler type' => 'context',
  'visible'      => TRUE,
  'title'        => t('Page manager search test'),
  'render'       => 'page_manager_search_test_render',
  'forms'        => array(),
);

/**
 * Render callback for Page manager variant handler.
 *
 * @param object $handler
 *   The Page manager task handler.
 * @param array $base_contexts
 * @param array $args
 * @param bool $test
 *
 * @return array
 *   The page content array.
 */
function page_manager_search_test_render($handler, $base_contexts, $args, $test = TRUE) {
  return array('content' => 'Page manager search test');
}
