<?php
/**
 * @file
 * Native plants nurseries map template.
 */
?>

<div class="breakout-section">
  <div class="row">
    <div class="column">
      <h3 class="thin"><?php print $title; ?></h3>
    </div>
  </div>
  <div class="inline-map ">
    <div class="inline-map-canvas">
      <div class="inline-map-mask"></div>
      <?php print $map; ?>
    </div>
  </div>
</div>