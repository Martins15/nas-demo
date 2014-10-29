<?php
/**
 * @file
 * Featured Bird template file.
 *
 * Available variables:
 * - $flyway_[1-4]: array with values for slides.
 */
?>
<div class="row contextual-links-region">
  <?php print $contextual_links; ?>
  <div class="medium-6 medium-push-6 columns">
    <div id="flyway-map" class="flyway-paths">
      <?php for ($i = 1; $i <= NAS_FLYWAYS_NUMBER; $i++): ?>
      <div id="flyway-map-<?php print $i; ?>" class="flyway-path-map<?php if ($i == 1): ?> current<?php endif; ?>">
        <img src="<?php print $flyway[$i]['map_image']; ?>" alt="<?php print $flyway[$i]['flyway']; ?>">
        <a href="#" id="flyway-point-<?php print $i; ?>" class="flyway-megamap-point"">
          <div class="portrait">
            <img src="<?php print $flyway[$i]['bird_image']; ?>" alt="<?php print $flyway[$i]['bird_title']; ?>">
          </div>
          <div class="name">
            <div class="bird"><?php print $flyway[$i]['bird_title']; ?></div>
            <div class="flyway"><?php print $flyway[$i]['flyway']; ?></div>
          </div>
        </a>
        <div class="flyway-path-dots">
          <?php for ($j = 1; $j <= NAS_FLYWAYS_NUMBER; $j++): ?>
          <a href="#flyway-map-<?php print $j; ?>" class="dot<?php if ($j == $i): ?> active<?php endif; ?>"></a>
          <?php endfor; ?>
        </div>
      </div>
      <?php endfor; ?>
    </div>
  </div>
  <div class="medium-6 medium-pull-6 columns text-container">
    <h1><?php print $flyway[1]['title']; ?></h1>
    <div class="deck"><?php print $flyway[1]['subtitle']; ?></div>
    <p><?php print $flyway[1]['summary']; ?></p>
  </div>
</div>
