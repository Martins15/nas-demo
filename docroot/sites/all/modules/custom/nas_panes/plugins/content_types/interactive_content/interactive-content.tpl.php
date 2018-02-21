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
    <div class="wrap-help diagram-wrap row">
      <?php if (!empty($description)): ?>
        <div class="columns large-6 small-text">
          <?php print $description ?>
        </div>
        <div class="columns large-6 diagram-item">
          <?php print $assets ?>
        </div>
      <?php else:; ?>
        <div class="columns diagram-item">
          <?php print $assets ?>
        </div>
      <?php endif; ?>
    </div>
  </div>
</div>
