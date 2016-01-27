<div class="map-header clearfix row">
  <div class="map-caption-left">
    <h2><?php print t("How climate change could affect this bird's range", array(), array('langcode' => $langcode)); ?></h2>
    <?php if (!empty($canvas_text)): ?>
      <?php print $canvas_text; ?>
    <?php endif; ?>
  </div>
  <div class="map-caption-right">
    <small><?php print t('Read more: !link', array('!link' => l('climate.audubon.org', '//climate.audobon.org')), array('langcode' => $langcode)); ?></small>
  </div>
</div>
<div class="map-canvas">
  <div class="map-image"></div>
</div>
<div class="row">
  <div class="column">
    <div class="container">
      <div class="clearfix">
        <div class="map-share">
          <div id="share"></div>
          <div class="social-sharing hide-for-medium hide-for-small hide-for-tiny">
            <span class="social-sharing-caption small"><?php print t('Help this map take flight.', array(), array('langcode' => $langcode)); ?></span>
            <br class="hide-for-small hide-for-tiny">
            <div class="bird-share-menu">
              <a class="social-sharing-icon blue small"><i class="icon-twitter"></i></a>
              <a class="social-sharing-icon blue small"><i class="icon-facebook"></i></a>
              <a class="social-sharing-icon blue small"><i class="icon-pinterest"></i></a>
              <a class="social-sharing-icon blue small"><i class="icon-mail"></i></a>
            </div>
          </div>
          <small class="focal-bird-tag hide-for-large hide-for-xlarge"><?php print $bird_category; ?></small>
          <h1 class="focal-bird-name hide-for-large hide-for-xlarge"><?php print $title; ?></h1>
          <div class="map-description hide-for-large hide-for-xlarge">
            <p><?php print $description; ?></p><a class="open-bird-detail-popup"><?php print $link_text; ?></a>
          </div>
        </div>
      </div>
      <div id="bird-detail-popup" class="climate-flyway-overlay element-hidden">
        <a class="close"></a>
        <div class="flyway-description">
          <p class="focal-bird-map-guide-first">
            <?php print t('Each map is a visual guide to where a particular bird species may find the climate conditions it needs to survive in the future. We call this the bird’s <strong>“climatic range.”</strong>', array(), array('langcode' => $langcode)); ?>
          </p>
          <p class="focal-bird-map-guide">
            <img class="flyway-img-right" src="/<?php print $img_path; ?>/help-colors.png" typeof="foaf:Image">
            <span><?php print t('The colors indicate the season in which the bird may find suitable conditions— <span class="focal-color-blue">blue</span> for winter, <span class="focal-color-yellow">yellow</span> for summer (breeding), and <span class="focal-color-green">green</span> for where they overlap (indicating their presence year-round).', array(), array('langcode' => $langcode)); ?>
          </p>
          <p class="focal-bird-map-guide">
            <img class="flyway-img-right" src="/<?php print $img_path; ?>/help-gradient.png" typeof="foaf:Image">
            <span><?php print t('The darker the shaded area, the more likely it is the bird species will find suitable climate conditions to survive there.', array(), array('langcode' => $langcode)); ?></span>
          </p>
          <p class="focal-bird-map-guide">
            <img class="flyway-img-left" src="/<?php print $img_path; ?>/help-kappa.gif" typeof="foaf:Image">
            <span><?php print t('The outline of the approximate current range for each season remains fixed in each frame, allowing you to compare how the range will expand, contract, or shift in the future.', array(), array('langcode' => $langcode)); ?></span>
          </p>
          <p class="focal-bird-map-guide">
            <img class="flyway-img-left" src="/<?php print $img_path; ?>/help-years.png" typeof="foaf:Image">
            <span><?php print t('The first frame of the animation shows where the bird can find a suitable climate today (<a href="#">based on data from 2000</a>). The next three frames predict where this bird’s suitable climate may shift in the future—one frame each for 2020, 2050, and 2080.', array(), array('langcode' => $langcode)); ?></span>
          </p>
          <p class="focal-bird-map-guide">
            <img class="flyway-img-left" src="/<?php print $img_path; ?>/help-play.png" typeof="foaf:Image">
            <span><?php print t('You can play or pause the animation with the orange button in the lower left, or select an individual frame to study by clicking on its year.', array(), array('langcode' => $langcode)); ?></span>
          </p>
        </div>
      </div>
      <div class="map-elements">
        <div class="map-description hide-for-tiny hide-for-small hide-for-medium">
          <?php print $description; ?> <a class="open-bird-detail-popup"><?php print $link_text; ?></a>
        </div>
        <div class="map-legend">
          <div class="map-legend-point">
            <span class="swatch image point-winter"></span>
            <span><?php print t('Winter', array(), array('langcode' => $langcode)); ?></span>
          </div>
          <div class="map-legend-point">
            <span class="swatch image point-summer"></span>
            <span><?php print t('Summer', array(), array('langcode' => $langcode)); ?></span>
          </div>
          <br class="hide-for-large hide-for-xlarge">
          <div class="map-legend-point">
            <span class="swatch" style="background-color: #3CA6DB"></span>
            <span><?php print t('Winter Range', array(), array('langcode' => $langcode)); ?></span>
          </div>
          <div class="map-legend-point">
            <span class="swatch" style="background-color: #FAE45D"></span>
            <span><?php print t('Summer Range', array(), array('langcode' => $langcode)); ?></span>
          </div>
          <div class="map-legend-point">
            <span class="swatch" style="background-color: #899B3D"></span>
            <span><?php print t('Both Seasons', array(), array('langcode' => $langcode)); ?></span>
          </div>
        </div>
        <div class="controls">
          <div class="map-control map-timeline">
            <a class="map-button map-pause"></a>
            <a data-step="1" class="map-timeline-point"><?php print '2000'; ?></a>
            <a data-step="2" class="map-timeline-point"><?php print '2020'; ?></a>
            <a data-step="3" class="map-timeline-point"><?php print '2050'; ?></a>
            <a data-step="4" class="map-timeline-point"><?php print '2080'; ?></a>
          </div>
        </div>
        <a class="map-control map-zoom"><span class="map-button map-binoculars"></span> <?php print t('Zoom <span class="inactive">In</span><span class="active">Out</span>', array(), array('langcode' => $langcode)); ?></a>
        <div class="social-sharing hide-for-large hide-for-xlarge">
          <span class="social-sharing-caption small"><?php print t('Help this map take flight.', array(), array('langcode' => $langcode)); ?></span>
          <br class="hide-for-medium hide-for-small hide-for-tiny">
          <div class="bird-share-menu">
            <a class="social-sharing-icon blue small"><i class="icon-twitter"></i></a>
            <a class="social-sharing-icon blue small"><i class="icon-facebook"></i></a>
            <a class="social-sharing-icon blue small"><i class="icon-pinterest"></i></a>
            <a class="social-sharing-icon blue small"><i class="icon-mail"></i></a>
          </div>
        </div>
      </div>
    </div>
  </div>
</div>

