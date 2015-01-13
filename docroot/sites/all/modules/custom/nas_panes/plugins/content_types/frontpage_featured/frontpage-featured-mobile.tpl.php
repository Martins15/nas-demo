<?php
/**
 * @file
 * Featured Frontpage mobile template file.
 *
 * Available variables:
 * - $title_link: the (sanitized) title with link.
 * - $blue_text_link: the (sanitized) blue text above the title with link.
 * - $image_path: path to the hero image of the bird.
 * - $contextual_links: rendered contextual links.
 */
?>
<div class="curtain-fallback" style="background-image: url(<?php print $image_path; ?>)">
  <div class="curtain-fallback-content">
    <div class="columns contextual-links-region">
      <?php print $contextual_links; ?>
      <div class="curtain-card no-border">
        <?php print $blue_text_link; ?>
        <h3 class="curtain-card-headline"><?php print $title_link; ?></h3>
        <p><?php print $summary; ?></p>
      </div>
    </div>
  </div>
</div>
