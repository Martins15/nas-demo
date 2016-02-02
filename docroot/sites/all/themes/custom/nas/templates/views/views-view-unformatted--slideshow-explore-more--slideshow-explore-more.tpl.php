<?php

/**
 * @file
 * Custom view template to display Explore More Photography block.
 */
?>

<div class="row section-header">
  <div class="column">
    <h2 class="thin"><?php print t($view->get_title()); ?></h2>
  </div>
  <div class="column">
    <ul class="inline-list section-nav">
      <li></li>
    </ul>
  </div>
</div>

<div class="row feature-set dark space-bottom">
  <?php foreach ($rows as $id => $row): ?>
    <div class="columns small-6 large-3">
      <?php print $row; ?>
    </div>
  <?php endforeach; ?>
</div>
