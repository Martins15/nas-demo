<?php
/**
 * @file
 * Featured Bird template file.
 *
 * Available variables:
 * - $title: block's title.
 * - $links: array of links.
 * - $content: content of the view.
 */
?>

<div class="boa-bird-card-set bg-boa-bejge" id="boa-index-plates">
  <div class="row section-header">
    <div class="columns">
      <h2 class="thin"><?php print $title; ?></h2>
    </div>
    <div class="columns">
      <ul class="section-nav inline-list">
        <?php foreach ($links as $link): ?>
          <li><?php print $link; ?></li>
        <?php endforeach; ?>
      </ul>
    </div>
  </div>
  <?php print $content; ?>
</div>