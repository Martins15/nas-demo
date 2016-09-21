<?php
/**
 * @file
 * Free HTML block template file.
 *
 * Available variables:
 * - $title: pane title.
 * - $image: pane image.
 * - $body: HTML from wysiwyg.
 */
?>
<div class="columns large-4">
  <div class="sidebar-section editorial-card">
    <div class="editorial-card-photo">
      <?php print $image; ?>
    </div>
    <div class="editorial-card-banner green">
      <i class="icon-map"></i> <?php print $title; ?>
    </div>
    <div class="editorial-card-content">
      <?php print $body; ?>
    </div>
  </div>
</div>
