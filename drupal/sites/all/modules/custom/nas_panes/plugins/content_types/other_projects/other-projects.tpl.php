<?php
/**
 * @file
 * Template to custom pane other_projects.
 *
 * Available variables:
 *  $contextual_links - contextual links.
 *  $title - pane's title.
 *  $teasers - array of rendered projects.
 */
?>

<section class="card-set bg-gray contextual-links-region">
  <?php print $contextual_links; ?>
  <div class="row space-top">
    <div class="column">
      <h2 class="thin"><?php print $title; ?></h2>
    </div>
  </div>
  <div class="row card-set-wrapper">
    <div class="clearfix card-set-scroller">
      <?php foreach ($teasers as $teaser): ?>
        <?php print $teaser; ?>
      <?php endforeach; ?>
    </div>
  </div>
  <div class="row space-bottom double">
    <div class="card-set-dots">
      <div class="dot active"></div>
      <div class="dot"></div>
      <div class="dot"></div>
    </div>
  </div>
</section>
