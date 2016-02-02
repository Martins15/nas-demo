<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */

  // Get rendered Donate pane and place it after 6th news.
  $show_news_donate = &drupal_static('show_news_donate');
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div<?php if ($classes_array[$id]) { print ' class="page-' . $view->query->pager->current_page . ' ' . $classes_array[$id] .'"';  } ?>>
    <?php print $row; ?>
  </div>
  <?php if ($id == 5 && !empty($show_news_donate)): ?>
    <?php print $show_news_donate; ?>
  <?php endif; ?>
<?php endforeach; ?>