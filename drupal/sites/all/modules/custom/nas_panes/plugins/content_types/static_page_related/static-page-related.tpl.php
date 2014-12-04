<?php
/**
 * @file
 * Template to custom pane Static page related.
 *
 * Available variables:
 *  $title - pane's title.
 *  $teasers - array of rendered related articles or static pages.
 */
?>

<div class="row section-header">
  <div class="column">
    <h2 class="thin grey"><?php print $title; ?></h2>
  </div>
</div>

<div class="row space-bottom">
  <?php foreach ($teasers as $teaser): ?>
    <div class="columns large-4">
      <?php print $teaser; ?>
    </div>
  <?php endforeach; ?>
</div>
