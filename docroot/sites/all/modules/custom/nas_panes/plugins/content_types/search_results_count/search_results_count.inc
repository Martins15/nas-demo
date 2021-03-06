<?php

/**
 * @file
 * Define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Search page: editorial content results count'),
  'description' => t('Provides "Search page: editorial content results count" pane.'),
  'category' => 'NAS',
  'render callback' => 'search_results_count_render',
  'render first' => TRUE,
);

/**
 * Run-time rendering of the body of the block (content type).
 *
 * @see ctools_plugin_examples()
 */
function search_results_count_render($subtype, $conf, $args, $contexts) {
  $view = views_get_view('search_results');
  $view->set_display('other_results');
  $view->execute();
  if (!$view->total_rows) {
    return;
  }

  $sort_links = _search_results_count_render_sort_links();

  $block = new stdClass();
  $block->content = theme('search_results_count', array(
    'title' => t('Articles'),
    'total_rows' => $view->total_rows,
    'current_rows' => count($view->result),
    'sort_links' => $sort_links,
  ));
  return $block;
}

/**
 * Helper function to get sort links.
 *
 * Sort links are available only if 'News' facet is selected.
 *
 * @return array|bool
 *   array of rendered sort links if applicable otherwise FALSE.
 */
function _search_results_count_render_sort_links() {
  // Query parameters for sort links.
  $query = $_GET;
  unset($query['q']);
  unset($query['sort_by']);
  unset($query['sort']);

  $rel_classes = $date_classes = array('color-blue');
  if (isset($_GET['sort']) && $_GET['sort'] == 'rel') {
    $_GET['sort_by'] = 'search_api_relevance';
    $rel_classes[] = 'active';
  }
  else {
    $date_classes[] = 'active';
  }

  $original_q = $_GET['q'];
  // Trick to prevent 'active' class to be added automatically.
  $_GET['q'] = '_' . $_GET['q'];
  $sort_links = array(
    l(t('Relevance'), 'search_results', array(
      'query' => $query + array('sort' => 'rel'),
      'attributes' => array(
        'class' => $rel_classes,
      ),
    )),
    l(t('Date'), 'search_results', array(
      'query' => $query,
      'attributes' => array(
        'class' => $date_classes,
      ),
    )),
  );
  // Revert 'q' back to original state.
  $_GET['q'] = $original_q;

  return $sort_links;
}
