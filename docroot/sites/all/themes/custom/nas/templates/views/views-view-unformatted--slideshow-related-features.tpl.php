<?php

/**
 * @file
 * Custom view template to display Related Features block.
 */
?>

<div class="row section-header">
  <div class="column">
    <h2 class="thin"><?php print $view->get_title(); ?></h2>
  </div>
</div>

<div class="row feature-set dark space-bottom">
  <?php foreach ($rows as $id => $row): ?>
    <div class="columns small-6 large-3">
      <?php print $row; ?>
    </div>
  <?php endforeach; ?>
</div>
