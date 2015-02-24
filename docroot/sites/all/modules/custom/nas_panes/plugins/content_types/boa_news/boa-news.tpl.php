<?php
/**
 * @file
 * Template to custom pane flyway_in_the_news.
 *
 * Available variables:
 *  $contextual_links - contextual links.
 *  $teaser - rendered news teaser.
 */
?>
<?php if(!empty($teaser)): ?>
<section class="bird-guide-section right-col boa-in-the-news">
  <div class="contextual-links-region">
    <?php print $contextual_links; ?>
    <h2 class="thin">In the News</h2>
    <?php print $teaser; ?>
  </div>
</section>
<?php endif; ?>
