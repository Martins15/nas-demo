<?php
/**
 * @file
 * Featured Frontpage template file.
 *
 * Available variables:
 * - $title_link: the (sanitized) title with link.
 * - $blue_text_link: the (sanitized) blue text above the title with link.
 * - $image_path: path to the hero image of the bird.
 * - $image_path_mobile: path to the hero image of the bird mobile image style.
 * - $image_string: sanitized caption + credits of the hero image.
 * - $contextual_links: rendered contextual links.
 */
?>
<div class="row">
  <div class="editorial-card editorial-card-package full-width contextual-links-region">
    <?php print $contextual_links; ?>
    <div class="row">
      <div class="small-12 large-8 columns">
        <div class="editorial-card-photo">
          <?php print $linked_image; ?>
        </div>
      </div>
      <div class="small-12 large-4 columns">
        <div class="editorial-card-content no-min-height">
          <?php if (!empty($references[0]['blue_text_link'])): ?>
            <?php print $references[0]['blue_text_link']; ?>
          <?php endif; ?>
          <h3 class="editorial-card-title"><?php print $references[0]['title_link']; ?></h3>
          <?php if (!empty($references[1]['blue_text_link'])): ?>
            <?php print $references[1]['blue_text_link']; ?>
          <?php endif; ?>
          <h4><?php print $references[1]['title_link']; ?></h4>
          <div class="editorial-card-cta">
            <?php print $button; ?>
          </div>
        </div>
      </div>
    </div>
  </div>
</div>