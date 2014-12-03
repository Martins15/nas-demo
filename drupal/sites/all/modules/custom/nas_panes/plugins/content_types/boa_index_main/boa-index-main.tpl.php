<?php
/**
 * @file
 * Featured Bird template file.
 *
 * Available variables:
 * - $title: block's title.
 * - $links: HTML of sort links.
 * - $content: content of the view.
 * - $contextual_links: rendered contextual links.
 */
?>

<div class="boa-bird-card-set bg-boa-bejge">
  <div class="row section-header space-top contextual-links-region">
    <?php print $contextual_links; ?>
    <div class="columns">
      <h2 class="thin"><?php print $title; ?></h2>
    </div>
    <div class="columns">
      <?php print $links; ?>
    </div>
  </div>
  <?php print $content; ?>
</div>