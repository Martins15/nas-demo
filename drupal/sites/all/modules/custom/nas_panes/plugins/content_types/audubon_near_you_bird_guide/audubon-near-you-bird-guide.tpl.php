<?php
/**
 * @file
 * Audubon Near You Bird Guide template file.
 */
?>

<div class="bird-card-set bg-bone-white">
  <div class="row section-header space-top">
    <div class="columns">
      <h2 class="thin"><?php print t('Birds Near You'); ?></h2>
    </div>
    <div class="columns">
      <?php print $links; ?>
    </div>
  </div>
  <?php print $content; ?>
</div>
