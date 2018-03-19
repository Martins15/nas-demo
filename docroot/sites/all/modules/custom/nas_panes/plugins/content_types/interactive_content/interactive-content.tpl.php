<?php

/**
 * @file
 * Interactive content template file.
 */
?>

<div class="text-container">
  <div class="item-with-diagram">
    <?php if (!empty($title)): ?>
      <h2><?php print $title ?></h2>
    <?php endif; ?>
    <?php if (!empty($description)): ?>
      <div class="wrap-help diagram-wrap">
        <div class="columns large-6 small-text">
          <?php print $description ?>
        </div>
        <div class="columns large-6 diagram-item">
          <?php print $assets ?>
        </div>
      </div>
    <?php else:; ?>
      <?php print $assets ?>
    <?php endif; ?>
  </div>
</div>
