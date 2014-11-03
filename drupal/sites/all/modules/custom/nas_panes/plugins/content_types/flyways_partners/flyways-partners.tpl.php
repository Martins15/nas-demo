<?php
/**
 * @file
 * Featured Bird template file.
 *
 * Available variables:
 * - $contextual_links: contextual links.
 * - $column[1-3]: array with title and text of the column.
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
</section>
