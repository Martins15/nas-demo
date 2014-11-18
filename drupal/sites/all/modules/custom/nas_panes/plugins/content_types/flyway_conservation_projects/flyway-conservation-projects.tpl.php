<?php
/**
 * @file
 * Template to custom pane flyway_in_the_news.
 *
 * Available variables:
 *  $contextual_links - contextual links.
 *  $title - pane's title.
 *  $more_link - link to flyway news listing.
 *  $teasers - array of rendered news.
 */
?>

<div class="card-set contextual-links-region">
  <?php print $contextual_links; ?>
  <div class="row section-header">
    <div class="column">
      <h2 class="thin"><?php print $title; ?></h2>
    </div>
    <div class="column">
      <ul class="section-nav inline-list">
        <li><?php print $more_link; ?></li>
      </ul>
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
</div>
