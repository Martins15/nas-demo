<?php
/**
 * @file
 * Template to custom pane Magazine Issue. Featured Articles.
 *
 * Available variables:
 *  $contextual_links - contextual links.
 *  $teasers - array of rendered articles.
 */
?>

<div class="row events-listing-featured contextual-links-region">
  <?php print $contextual_links; ?>
  <?php foreach ($teasers as $teaser): ?>
  <div class="large-6 columns">
    <?php print $teaser; ?>
  </div>
  <?php endforeach; ?>
</div>
