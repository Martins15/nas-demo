<?php
/**
 * @file
 * About Page Learn More template file.
 */
?>

<div class="card-set bg-bone-white <?php print !empty($contextual_links) ? 'contextual-links-region' : ''; ?>">
  <?php print $contextual_links; ?>
  <div class="row section-header">
    <div class="column">
      <h2 class="thin"><?php print $title; ?></h2>
    </div>
  </div>
  <div class="row space-bottom text-container">
    <?php foreach ($items as $item) : ?>
      <div class="columns large-4">
        <?php print render($item); ?>
      </div>
    <?php endforeach; ?>
  </div>
</div>
