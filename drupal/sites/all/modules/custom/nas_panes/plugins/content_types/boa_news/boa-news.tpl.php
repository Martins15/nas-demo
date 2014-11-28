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

<section class="bird-guide-section boa-in-the-news">
  <div class="columns contextual-links-region">
    <?php print $contextual_links; ?>
    <h2 class="thin">In the News</h2>
    <?php print $teaser; ?>
  </div>
</section>
