<?php

/**
 * @file
 * Custom view template to display Popular Stories side block for News Landing.
 *
 * @ingroup views_templates
 */
?>

<div class="sidebar-section popular-stories story-list <?php print $classes; ?>">
  <?php print render($title_suffix); ?>
  <h3 class="story-list-header"><?php print t($view->display[$view->current_display]->display_options['title']); ?></h3>
  <?php print $rows; ?>
</div>
