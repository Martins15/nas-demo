<?php
/**
 * @file
 * About Page Map template file.
 */
?>

<div class="row space-top">
  <div class="column">
    <?php if (!empty($title)) : ?>
      <h2 class="thin centered"><?php print $title; ?></h2>
    <?php endif; ?>
  </div>
</div>
<div class="inline-map <?php print !empty($contextual_links) ? 'contextual-links-region' : ''; ?>">
  <?php print $contextual_links; ?>
  <div class="inline-map-canvas">
    <div class="inline-map-mask"></div>
    <?php print $map; ?>
  </div>
</div>
