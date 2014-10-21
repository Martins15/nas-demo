<?php

/**
 * @file
 * Custom view template to display Explore Similar Birds.
 *
 * @ingroup views_templates
 */
?>

<section class="clearfix article-sidebar-section popular-stories story-list small reflow reflow-into-bottom">
  <h5><?php print $view->display[$view->current_display]->display_options['title']; ?></h5>
  <?php print $rows; ?>
</section>