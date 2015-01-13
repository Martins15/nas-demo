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
<div class="curtain-content light-text">
  <div class="row space-bottom contextual-links-region">
    <?php print $contextual_links; ?>
    <div class="column medium-6 medium-offset-6">
      <div class="curtain-card">
        <?php print $blue_text_link; ?>
        <h2 class="curtain-card-headline"><?php print $title_link; ?></h2>
        <p class="curtain-card-blurb">
          <?php print $summary; ?>
        </p>
      </div>
    </div>
  </div>
  <div class="row">
    <div class="column">
      <div class="curtain-attribution">
        <p class="title"><?php print $image_caption ?></p>
        <p class="credit"><?php print $image_credit ?></p>
      </div>
    </div>
  </div>
</div>
<a href="#" class="curtain-arrow"></a>
