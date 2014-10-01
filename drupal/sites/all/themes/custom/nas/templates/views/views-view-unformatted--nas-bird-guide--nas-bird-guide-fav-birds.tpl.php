<?php

/**
 * @file
 * Custom view template to display Explore Similar Birds.
 *
 * @ingroup views_templates
 */
?>

<div class="row section-header space-top">
  <div class="columns">
    <h2 class="thin"><?php print $view->display[$view->current_display]->display_options['title']; ?></h2>
  </div>
</div>
<div class="row space-bottom double bird-card-grid-container">
  <?php foreach ($rows as $id => $row): ?>
    <div class="columns tiny-6 medium-4 large-3">
    <?php print $row; ?>
    </div>
  <?php endforeach; ?>
</div>
