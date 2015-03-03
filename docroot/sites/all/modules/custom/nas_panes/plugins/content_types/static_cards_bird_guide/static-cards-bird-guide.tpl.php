<?php
/**
 * @file
 * Static cards Bird Guide template file.
 */
?>

<div class="row section-header <?php print !empty($contextual_links) ? 'contextual-links-region' : ''; ?>">
  <?php print $contextual_links; ?>
  <div class="columns">
    <h2 class="thin"><?php print $title; ?></h2>
  </div>
  <div class="columns">
    <?php print $links; ?>
  </div>
</div>
<div class="bird-card-set">
  <div class="row bird-card-container">
    <div class="bird-card-scroller">
      <?php foreach ($items as $item) : ?>
        <div class="columns tiny-3">
          <?php print render($item); ?>
        </div>
      <?php endforeach; ?>
    </div>
  </div>
  <div class="row indicator">
    <div class="column">
      <p><i class="indicator-left icon-arrow-left disabled"></i>&nbsp;&nbsp;&nbsp;<i class="indicator-right icon-arrow-right"></i></p>
    </div>
  </div>
</div>
