<div class="map-header clearfix row">
  <div class="map-caption-left">
    <h2><?php print t("How climate change could affect this bird's range"); ?></h2>
    <?php if (!empty($canvas_text)): ?>
      <?php print $canvas_text; ?>
    <?php endif; ?>
  </div>
  <div class="map-caption-right">
    <small><?php print t('Read more: !link', array('!link' => l('climate.audubon.org', '//climate.audobon.org'))); ?></small>
  </div>
</div>
<div class="map-canvas">
  <div class="map-image"></div>
</div>
<div class="row">
  <div class="column">
    <div class="container">
      <?php if (!empty($popup_text)): ?>
        <div id="bird-detail-popup" class="climate-flyway-overlay element-hidden">
          <a class="close"></a>
          <div class="flyway-description">
            <?php print $popup_text; ?>
          </div>
        </div>
      <?php endif; ?>
      <div class="map-share">
        <div id="share"></div>
        <div class="social-sharing hide-for-medium hide-for-small hide-for-tiny">
          <span class="social-sharing-caption small"><?php print t('Help this map take flight.') ?></span>
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
          <?php print $map_short_description_mobile; ?>
        </div>
      </div>
      <div class="map-elements">
        <div class="map-description hide-for-tiny hide-for-small hide-for-medium">
          <?php print $map_short_description_desktop; ?>
        </div>
        <div class="map-legend">
          <div class="map-legend-point">
            <span class="swatch image"></span>
            <span><?php print t('Winter') ?></span>
          </div>
          <div class="map-legend-point">
            <span class="swatch image"></span>
            <span><?php print t('Summer') ?></span>
          </div>
          <br class="hide-for-large hide-for-xlarge">
          <div class="map-legend-point">
            <span class="swatch" style="background-color: #3CA6DB"></span>
            <span><?php print t('Winter Range') ?></span>
          </div>
          <div class="map-legend-point">
            <span class="swatch" style="background-color: #FAE45D"></span>
            <span><?php print t('Summer Range') ?></span>
          </div>
          <div class="map-legend-point">
            <span class="swatch" style="background-color: #899B3D"></span>
            <span><?php print t('Both Seasons') ?></span>
          </div>
        </div>
        <div class="controls">
          <div class="map-control map-timeline">
            <a class="map-button map-pause"></a>
            <a data-step="1" class="map-timeline-point"><?php print t('2000'); ?></a>
            <a data-step="2" class="map-timeline-point"><?php print t('2020'); ?></a>
            <a data-step="3" class="map-timeline-point"><?php print t('2050'); ?></a>
            <a data-step="4" class="map-timeline-point"><?php print t('2080'); ?></a>
          </div>
        </div>
        <a class="map-control map-zoom"><span class="map-button map-binoculars"></span> <?php print t('Zoom <span class="inactive">In</span><span class="active">Out</span>'); ?></a>
        <div class="social-sharing hide-for-large hide-for-xlarge">
          <span class="social-sharing-caption small"><?php print t('Help this map take flight.') ?></span>
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

