<?php
/**
 * @file
 * Featured Bird template file.
 *
 * Available variables:
 * - $contextual_links: contextual links.
 * - $background_image: url to background image.
 * - $title: title of the block.
 * - $summary: summary text.
 * - $read_more_link: url of the learn more link.
 */
?>
<section class="breakout-section black-bg contextual-links-region">
  <?php print $contextual_links; ?>
  <div class="breakout-section-hero margin-bottom" style="background-image: url(<?php print $background_image; ?>)">
    <div class="row">
      <div class="column">
        <h1 class="breakout-section-headline"><?php print $title; ?></h1>
      </div>
    </div>
  </div>
  <div class="breakout-section-content">
    <div class="row space-bottom">
      <div class="column">
        <div class="deck"><?php print $summary; ?> <a href="<?php print $read_more_link; ?>">Learn more »</a></div>
      </div>
    </div>
  </div>
  <?php if ($attribution): ?>
  <div class="hero-attribution">
    <p class="column">
      <span class="hero-attribution-text">
        <?php print $attribution; ?>
      </span>
    </p>
  </div>
  <?php endif; ?>
</section>
