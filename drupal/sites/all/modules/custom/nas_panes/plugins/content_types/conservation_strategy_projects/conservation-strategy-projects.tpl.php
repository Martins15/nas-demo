<?php
/**
 * @file
 * Conservation Strategy Projects template file.
 */
?>

<section class="card-set bg-gray">
  <div class="row space-top">
    <div class="column">
      <h2 class="thin"><?php print $title; ?></h2>
    </div>
  </div>
  <div class="row card-set-wrapper <?php print !empty($contextual_links) ? 'contextual-links-region' : '' ?>">
    <?php print $contextual_links; ?>
    <div class="clearfix card-set-scroller conservation-strategy-projects-block">
      <?php foreach ($teasers as $teaser) : ?>
        <?php print $teaser; ?>
      <?php endforeach; ?>
  </div>
  <div class="row space-bottom">
    <div class="card-set-dots">
      <div class="dot"></div>
      <div class="dot active"></div>
      <div class="dot"></div>
    </div>
  </div>
</section>
