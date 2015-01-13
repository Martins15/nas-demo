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

<div class="row magazine-issue-other-issues contextual-links-region">
  <?php print $contextual_links; ?>
   <h2 class="thin"><?php print t('Other Issues'); ?></h2>
  <?php foreach ($teasers as $teaser): ?>
  <div class="large-3 columns">
    <?php print $teaser; ?>
  </div>
  <?php endforeach; ?>
</div>
