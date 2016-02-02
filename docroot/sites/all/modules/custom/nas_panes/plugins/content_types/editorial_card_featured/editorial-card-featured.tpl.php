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
  <div class="editorial-card full-width contextual-links-region">
    <?php print $contextual_links; ?>
    <div class="row">
      <div class="small-12 large-8 columns">
        <div class="editorial-card-photo">
          <?php print $linked_image; ?>
        </div>
      </div>
      <div class="small-12 large-4 columns">
        <div class="editorial-card-content">
          <?php if (!empty($blue_text_link_url)): ?>
            <a href="<?php print $blue_text_link_url; ?>" class="editorial-card-slug"><?php print $blue_text_link_text; ?></a>
          <?php endif; ?>
          <h3 class="editorial-card-title"><?php print $title_link; ?></h3>
          <div class="editorial-card-body">
            <?php if (!empty($date)): ?>
              <span class="editorial-card-dateline"><?php print $date; ?></span> &mdash;
            <?php endif; ?>
            <?php print $subtitle; ?>
          </div>
        </div>
      </div>
    </div>
  </div>
</div>