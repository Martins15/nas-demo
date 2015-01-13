<?php
/**
 * @file
 * Template to custom pane flyway_in_the_news.
 *
 * Available variables:
 *  $contextual_links - contextual links.
 *  $title - pane's title.
 *  $teasers - array of rendered news.
 */
?>

<div class="row feature-set contextual-links-region">
  <?php print $contextual_links; ?>
  <div class="column"><h2 class="thin"><?php print $title; ?></h2></div>
  <?php foreach ($teasers as $teaser): ?>
  <div class="columns small-6 large-3">
    <?php print $teaser; ?>
  </div>
  <?php endforeach; ?>
</div>
