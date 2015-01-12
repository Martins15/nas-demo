<?php
/**
 * @file
 * Donate card with gradient template file.
 *
 * Available variables:
 * - $title: sanitized title.
 * - $button: array of sanitized button title and url.
 * - $background_image: path to the background image.
 * - $background_image_small: path to the background image for mobile layout.
 * - $subtitle: sanitized subtitle.
 * - $teaser: sanitized teaser text.
 * - $contextual_links: rendered contextual links.
 */
?>

<div class="banner dark-bg bg-respond donate-banner contextual-links-region" style="background-image: url(<?php print $background_image; ?>);" data-bg-small="<?php print $background_image_small; ?>" data-bg-large="<?php print $background_image; ?>">
  <?php print $contextual_links; ?>
  <div class="banner-text">
    <h2 class="banner-title"><?php print $title; ?></h2>
    <p class="banner-blurb"><?php print $subtitle; ?></p>
    <p class="banner-blurb yellow"><?php print $teaser; ?></p>
    <a href="<?php print $button['url']; ?>" class="button xlarge tomato"><?php print $button['title']; ?></a>
  </div>
</div>
