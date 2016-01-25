<?php

/**
 * @file
 * This file contains the main theme functions hooks and overrides.
 */

/**
 * Override or insert variables into the maintenance page template.
 */
function adminimal_preprocess_maintenance_page(&$vars) {
  // While markup for normal pages is split into page.tpl.php and html.tpl.php,
  // the markup for the maintenance page is all in the single
  // maintenance-page.tpl.php template. So, to have what's done in
  // adminimal_preprocess_html() also happen on the maintenance page, it has to be
  // called here.
  adminimal_preprocess_html($vars);
}

/**
 * Override or insert variables into the html template.
 */
function adminimal_preprocess_html(&$vars) {

  // Get adminimal folder path.
  $adminimal_path = drupal_get_path('theme', 'adminimal');

  // Add conditional CSS for IE8 and below.
  drupal_add_css($adminimal_path . '/css/ie.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lte IE 8', '!IE' => FALSE), 'weight' => 999, 'preprocess' => FALSE));

  // Add conditional CSS for IE7 and below.
  drupal_add_css($adminimal_path . '/css/ie7.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lte IE 7', '!IE' => FALSE), 'weight' => 999, 'preprocess' => FALSE));

  // Add conditional CSS for IE6.
  drupal_add_css($adminimal_path . '/css/ie6.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lte IE 6', '!IE' => FALSE), 'weight' => 999, 'preprocess' => FALSE));

  // Add theme name to body class.
  $vars['classes_array'][] = 'adminimal-theme';

  // Add icons to the admin configuration page.
  if (theme_get_setting('display_icons_config')) {
    drupal_add_css($adminimal_path . '/css/icons-config.css', array('group' => CSS_THEME, 'weight' => 10, 'preprocess' => FALSE));
  }

  // Fix the viewport and zooming in mobile devices.
  $viewport = array(
   '#tag' => 'meta',
   '#attributes' => array(
     'name' => 'viewport',
     'content' => 'width=device-width, maximum-scale=1, minimum-scale=1, user-scalable=no, initial-scale=1',
   ),
  );
  drupal_add_html_head($viewport, 'viewport');

}

/**
 * Override or insert variables into the page template.
 */
function adminimal_preprocess_page(&$vars) {
  $vars['primary_local_tasks'] = $vars['tabs'];
  unset($vars['primary_local_tasks']['#secondary']);
  $vars['secondary_local_tasks'] = array(
    '#theme' => 'menu_local_tasks',
    '#secondary' => $vars['tabs']['#secondary'],
  );

}

/**
 * Display the list of available node types for node creation.
 */
function adminimal_node_add_list($variables) {
  $content = $variables['content'];
  $output = '';
  if ($content) {
    $output = '<ul class="admin-list">';
    foreach ($content as $item) {
      $output .= '<li class="clearfix">';
      $output .= '<span class="label">' . l($item['title'], $item['href'], $item['localized_options']) . '</span>';
      $output .= '<div class="description">' . filter_xss_admin($item['description']) . '</div>';
      $output .= '</li>';
    }
    $output .= '</ul>';
  }
  else {
    $output = '<p>' . t('You have not created any content types yet. Go to the <a href="@create-content">content type creation page</a> to add a new content type.', array('@create-content' => url('admin/structure/types/add'))) . '</p>';
  }
  return $output;
}

/**
 * Implements theme_adminimal_block_content().
 *
 * Use unordered list markup in both compact and extended mode.
 */
function adminimal_adminimal_block_content($variables) {
  $content = $variables['content'];
  $output = '';
  if (!empty($content)) {
    $output = system_adminimal_compact_mode() ? '<ul class="admin-list compact">' : '<ul class="admin-list">';
    foreach ($content as $item) {
      $output .= '<li class="leaf">';
      $output .= l($item['title'], $item['href'], $item['localized_options']);
      if (isset($item['description']) && !system_adminimal_compact_mode()) {
        $output .= '<div class="description">' . filter_xss_admin($item['description']) . '</div>';
      }
      $output .= '</li>';
    }
    $output .= '</ul>';
  }
  return $output;
}

/**
 * Implements theme_tablesort_indicator().
 * 
 * Use our own image versions, so they show up as black and not gray on gray.
 */
function adminimal_tablesort_indicator($variables) {
  $style = $variables['style'];
  $theme_path = drupal_get_path('theme', 'adminimal');
  if ($style == 'asc') {
    return theme('image', array('path' => $theme_path . '/images/arrow-asc.png', 'alt' => t('sort ascending'), 'width' => 13, 'height' => 13, 'title' => t('sort ascending')));
  }
  else {
    return theme('image', array('path' => $theme_path . '/images/arrow-desc.png', 'alt' => t('sort descending'), 'width' => 13, 'height' => 13, 'title' => t('sort descending')));
  }
}

/**
 * Implements hook_css_alter().
 */
function adminimal_css_alter(&$css) {
  // Use Seven's vertical tabs style instead of the default one.
  if (isset($css['misc/vertical-tabs.css'])) {
    $css['misc/vertical-tabs.css']['data'] = drupal_get_path('theme', 'adminimal') . '/css/vertical-tabs.css';
  }
  if (isset($css['misc/vertical-tabs-rtl.css'])) {
    $css['misc/vertical-tabs-rtl.css']['data'] = drupal_get_path('theme', 'adminimal') . '/css/vertical-tabs-rtl.css';
  }
  // Use Seven's jQuery UI theme style instead of the default one.
  if (isset($css['misc/ui/jquery.ui.theme.css'])) {
    $css['misc/ui/jquery.ui.theme.css']['data'] = drupal_get_path('theme', 'adminimal') . '/css/jquery.ui.theme.css';
  }
}

/**
 * Implements theme_admin_block().
 * Adding classes to the administration blocks see issue #1869690.
 */
function adminimal_admin_block($variables) {
  $block = $variables['block'];
  $output = '';

  // Don't display the block if it has no content to display.
  if (empty($block['show'])) {
    return $output;
  }

  if (!empty($block['path'])) {
    $output .= '<div class="admin-panel ' . check_plain(str_replace("/", " ", $block['path'])) . ' ">';
  }
  elseif (!empty($block['title'])) {
    $output .= '<div class="admin-panel ' . check_plain(strtolower($block['title'])) . '">';
  }
  else {
    $output .= '<div class="admin-panel">';
  }

  if (!empty($block['title'])) {
    $output .= '<h3 class="title">' . $block['title'] . '</h3>';
  }

  if (!empty($block['content'])) {
    $output .= '<div class="body">' . $block['content'] . '</div>';
  }
  else {
    $output .= '<div class="description">' . $block['description'] . '</div>';
  }

  $output .= '</div>';

  return $output;

}

/**
 * Implements theme_admin_block_content().
 * Adding classes to the administration blocks see issue #1869690.
 */
function adminimal_admin_block_content($variables) {
  $content = $variables['content'];
  $output = '';

  if (!empty($content)) {
    $class = 'admin-list';
    if ($compact = system_admin_compact_mode()) {
      $class .= ' compact';
    }
    $output .= '<dl class="' . $class . '">';
    foreach ($content as $item) {
      if (!isset($item['path'])) {
          $item['path']='';
      }
      $output .= '<div class="admin-block-item ' . check_plain(str_replace("/", "-", $item['path'])) . '"><dt>' . l($item['title'], $item['href'], $item['localized_options']) . '</dt>';
      if (!$compact && isset($item['description'])) {
        $output .= '<dd class="description">' . filter_xss_admin($item['description']) . '</dd>';
      }
      $output .= '</div>';
    }
    $output .= '</dl>';
  }
  return $output;
}

/**
 * Implements theme_table().
 */
function adminimal_table($variables) {
  $header = $variables['header'];
  $rows = $variables['rows'];
  $attributes = $variables['attributes'];
  $caption = $variables['caption'];
  $colgroups = $variables['colgroups'];
  $sticky = $variables['sticky'];
  $empty = $variables['empty'];

  // Add sticky headers, if applicable.
  if (count($header) && $sticky) {
    drupal_add_js('misc/tableheader.js');
    // Add 'sticky-enabled' class to the table to identify it for JS.
    // This is needed to target tables constructed by this function.
    $attributes['class'][] = 'sticky-enabled';
  }

  $output = '<div class="overflow-fix">';
  $output .= '<table' . drupal_attributes($attributes) . ">\n";

  if (isset($caption)) {
    $output .= '<caption>' . $caption . "</caption>\n";
  }

  // Format the table columns:
  if (count($colgroups)) {
    foreach ($colgroups as $number => $colgroup) {
      $attributes = array();

      // Check if we're dealing with a simple or complex column
      if (isset($colgroup['data'])) {
        foreach ($colgroup as $key => $value) {
          if ($key == 'data') {
            $cols = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $cols = $colgroup;
      }

      // Build colgroup
      if (is_array($cols) && count($cols)) {
        $output .= ' <colgroup' . drupal_attributes($attributes) . '>';
        $i = 0;
        foreach ($cols as $col) {
          $output .= ' <col' . drupal_attributes($col) . ' />';
        }
        $output .= " </colgroup>\n";
      }
      else {
        $output .= ' <colgroup' . drupal_attributes($attributes) . " />\n";
      }
    }
  }

  // Add the 'empty' row message if available.
  if (!count($rows) && $empty) {
    $header_count = 0;
    foreach ($header as $header_cell) {
      if (is_array($header_cell)) {
        $header_count += isset($header_cell['colspan']) ? $header_cell['colspan'] : 1;
      }
      else {
        ++$header_count;
      }
    }
    $rows[] = array(array(
      'data' => $empty,
      'colspan' => $header_count,
      'class' => array('empty', 'message'),
    ));
  }

  // Format the table header:
  if (count($header)) {
    $ts = tablesort_init($header);
    // HTML requires that the thead tag has tr tags in it followed by tbody
    // tags. Using ternary operator to check and see if we have any rows.
    $output .= (count($rows) ? ' <thead><tr>' : ' <tr>');
    foreach ($header as $cell) {
      $cell = tablesort_header($cell, $header, $ts);
      $output .= _theme_table_cell($cell, TRUE);
    }
    // Using ternary operator to close the tags based on whether or not there are rows
    $output .= (count($rows) ? " </tr></thead>\n" : "</tr>\n");
  }
  else {
    $ts = array();
  }

  // Format the table rows:
  if (count($rows)) {
    $output .= "<tbody>\n";
    $flip = array(
      'even' => 'odd',
      'odd' => 'even',
    );
    $class = 'even';
    foreach ($rows as $number => $row) {
      // Check if we're dealing with a simple or complex row
      if (isset($row['data'])) {
        $cells = $row['data'];
        $no_striping = isset($row['no_striping']) ? $row['no_striping'] : FALSE;

        // Set the attributes array and exclude 'data' and 'no_striping'.
        $attributes = $row;
        unset($attributes['data']);
        unset($attributes['no_striping']);
      }
      else {
        $cells = $row;
        $attributes = array();
        $no_striping = FALSE;
      }
      if (count($cells)) {
        // Add odd/even class
        if (!$no_striping) {
          $class = $flip[$class];
          $attributes['class'][] = $class;
        }

        // Build row
        $output .= ' <tr' . drupal_attributes($attributes) . '>';
        $i = 0;
        foreach ($cells as $cell) {
          $cell = tablesort_cell($cell, $header, $ts, $i++);
          $output .= _theme_table_cell($cell);
        }
        $output .= " </tr>\n";
      }
    }
    $output .= "</tbody>\n";
  }

  $output .= "</table>\n";
  $output .= "</div>\n";
  return $output;
}

/**
 * Theme the subqueue overview as a sortable list.
 *
 * @ingroup themeable
 */
function adminimal_nodequeue_arrange_subqueue_form_table($variables) {
  $form = $variables['form'];

  $output = '';

  // Get css to hide some of the help text if javascript is disabled.
  drupal_add_css(drupal_get_path('module', 'nodequeue') . '/nodequeue.css');

  $table_id = 'nodequeue-dragdrop-' . $form['#subqueue']['sqid'];
  $table_classes = array(
    'nodequeue-dragdrop',
    'nodequeue-dragdrop-qid-' . $form['#subqueue']['qid'],
    'nodequeue-dragdrop-sqid-' . $form['#subqueue']['sqid'],
    'nodequeue-dragdrop-reference-' . $form['#subqueue']['reference'],
  );
  drupal_add_tabledrag($table_id, 'order', 'sibling', 'node-position');
  drupal_add_js(drupal_get_path('module', 'nodequeue') . '/nodequeue_dragdrop.js');

  $reverse[str_replace('-', '_', $table_id)] = (bool) $form['#queue']['reverse'];
  drupal_add_js(
    array(
      'nodequeue' => array(
        'reverse' => $reverse,
      )
    ),
    array(
      'type' => 'setting',
      'scope' => JS_DEFAULT,
    )
  );

  // Render form as table rows.
  $rows = array();
  $counter = 1;
  foreach (element_children($form) as $key) {
    if (isset($form[$key]['title'])) {
      $row = array();

      $row[] = drupal_render($form[$key]['title']);
      $row[] = drupal_render($form[$key]['author']);
      $row[] = drupal_render($form[$key]['date']);
      $row[] = drupal_render($form[$key]['position']);
      $row[] = (!empty($form[$key]['edit'])) ? drupal_render($form[$key]['edit']) : '&nbsp;';
      $row[] = drupal_render($form[$key]['remove']);
      $row[] = array(
        'data' => $counter,
        'class' => array('position')
      );
      $row[] = $form[$key]['#node']['language'] == 'und' ? 'en' : $form[$key]['#node']['language'];

      $rows[] = array(
        'data'  => $row,
        'class' => array('draggable'),
      );
    }

    $counter++;
  }
  if (empty($rows)) {
    $rows[] = array(array('data' => t('No nodes in this queue.'), 'colspan' => 7));
  }

  // Render the main nodequeue table.
  $header = array(t('Title'), t('Author'), t('Post Date'), t('Position'), array('data' => t('Operations'), 'colspan' => 2), t('Position'), t('Language'));
  $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('id' => $table_id, 'class' => $table_classes)));

  return $output;
}