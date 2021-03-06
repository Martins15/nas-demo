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
    <h2 class="thin"><?php print $view->get_title(); ?></h2>
  </div>
</div>
<div class="view-content row space-bottom double bird-card-grid-container">
  <?php foreach ($rows as $id => $row): ?>
    <div class="page-<?php print $view->query->pager->current_page; ?> views-row columns tiny-6 medium-4 large-3">
    <?php print $row; ?>
    </div>
  <?php endforeach; ?>
</div>
