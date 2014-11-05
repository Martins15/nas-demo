<?php
/**
 * @file
 * Featured Bird template file.
 *
 * Available variables:
 * - $hero_image: big image at the top.
 * - $title: title.
 * - $subtitle: subtitle under the title.
 * - $flyway[1-4]: array with values for the slide.
 */
?>
<div class="hero dark-text flyway-megamap" style="background-image: url(<?php print $hero_image; ?>); background-color: #CDEAF2;">
  <div class="row">
    <div class="hero-header contextual-links-region">
      <?php print $contextual_links; ?>
      <div class="column">
        <h1><?php print $title; ?></h1>
        <p class="hero-blurb"><?php print $subtitle; ?></p>
      </div>
    </div>
  </div>
  <div class="flyway-megamap-points-container row">
    <?php for ($i = 1; $i <= NAS_FLYWAYS_NUMBER; $i++): ?>
    <a href="#" id="flyway-point-<?php print $i; ?>" class="flyway-megamap-point" style="<?php print $flyway[$i]['coordinates']; ?>">
      <div class="portrait">
        <img src="<?php print $flyway[$i]['image']; ?>" alt="<?php print $flyway[$i]['bird']; ?>">
      </div>
      <div class="name hide-for-small hide-for-tiny">
        <div class="bird"><?php print $flyway[$i]['bird']; ?></div>
        <div class="flyway"><?php print $flyway[$i]['flyway']; ?></div>
      </div>
    </a>
    <?php endfor; ?>
  </div>
</div>
<div class="flyway-megamap-instructions row">
  <div class="column">
    <h2 class="thin centered"><?php print $bottomtitle; ?></h2>
  </div>
</div>
