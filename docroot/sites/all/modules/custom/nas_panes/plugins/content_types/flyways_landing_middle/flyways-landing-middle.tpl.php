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
      <div id="flyway-map-<?php print $i; ?>" class="flyway-path-map<?php print $i == 1 ? ' current' : ''; ?>">
        <img src="<?php print $flyway[$i]['map_image']; ?>" alt="<?php print $flyway[$i]['flyway']; ?>">
        <a href="#" id="flyway-point-<?php print $i; ?>" class="flyway-megamap-point">
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
          <a href="#flyway-map-<?php print $j; ?>"><span class="dot<?php print $j == $i ? ' active' : ''; ?>"></span></a>
          <?php endfor; ?>
        </div>
      </div>
      <?php endfor; ?>
    </div>
  </div>
  <div class="medium-6 medium-pull-6 columns text-container">
    <?php foreach ($flyway as $key => $value): ?>
    <div id="flyway-path-description-<?php print $key; ?>" class="flyway-path-description<?php print $key == 1 ? ' current' : ''; ?>">
      <h1><?php print $value['title']; ?></h1>
      <div class="deck"><?php print $value['subtitle']; ?></div>
      <p><?php print $value['summary']; ?></p>
    </div>
    <?php endforeach; ?>
  </div>
</div>
<div class="row space-top text-container contextual-links-region">
  <?php print $contextual_links; ?>
  <?php foreach ($flyway as $key => $f): ?>
    <div id="flyway-path-columns-<?php print $key; ?>" class="flyway-path-columns<?php print $key == 1 ? ' current' : ''; ?>">
    <?php for ($i = 1; $i <= 3; $i++): ?>
      <div class="medium-4 columns">
        <h3 class=""><?php print $f['columns'][$i]['title']; ?></h3>
        <p><?php print $f['columns'][$i]['text']; ?></p>
      </div>
    <?php endfor; ?>
    </div>
  <?php endforeach; ?>
</div>
