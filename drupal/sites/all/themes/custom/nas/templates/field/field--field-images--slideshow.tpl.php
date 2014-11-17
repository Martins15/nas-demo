<?php
/**
 * @file
 * Template implementation to display slideshow images.
 */
?>

<div class="slideshow clearfix standalone">
  <div class="slideshow-indicator row">
    <div class="column large-offset-9 large-3">
      <p><i class="ss-icon icon-chevron-left inactive slideshow-control prev"></i> <span class="indicator-current">1</span> of <span class="indicator-total"><?php print count($images); ?></span> <i class="ss-icon icon-chevron-right slideshow-control next"></i></p>
      <p class="social-sharing align-right hide-for-small hide-for-tiny">
        <a href="#" class="social-sharing-icon white small"><i class="icon-twitter"></i></a>
        <a href="#" class="social-sharing-icon white small"><i class="icon-facebook"></i></a>
        <a href="#" class="social-sharing-icon white small"><i class="icon-pinterest"></i></a>
        <a href="#" class="social-sharing-icon white small"><i class="icon-mail"></i></a>
      </p>
    </div>
  </div>
  <a href="#" class="slideshow-button slideshow-control prev hide-for-tiny hide-for-small"></a>
  <a href="#" class="slideshow-button slideshow-control next hide-for-tiny hide-for-small"></a>
  <div id="slideshow-wrapper" class="slideshow-wrapper">
    <div class="slideshow-scroller">
      <?php if (!empty($images)) : ?>
        <?php foreach ($images as $image) : ?>
          <?php if ($image['first']) : ?>

            <div class="slide title-slide">
              <div class="slide-img">
                <img src="<?php print $image['url']; ?>" alt="<?php print $image['alt']; ?>" title="<?php print $image['title']; ?>" />
              </div>
              <div class="title-slide-content row">
                <div class="columns large-10 large-offset-1 text-container">
                  <h1 class="thin"><?php print $title; ?></h1>
                  <p class="deck"><?php print $subtitle; ?></p>
                  <p><a href="#" class="title-slide-button button pea-green xlarge slideshow-control next">View Slideshow</a></p>
                  <div class="social-sharing align-left hide-for-small hide-for-medium hide-for-tiny">
                    <span class="social-sharing-caption white">Share this</span>
                    <a href="#" class="social-sharing-icon white"><i class="icon-twitter"></i></a>
                    <a href="#" class="social-sharing-icon white"><i class="icon-facebook"></i></a>
                    <a href="#" class="social-sharing-icon white"><i class="icon-pinterest"></i></a>
                    <a href="#" class="social-sharing-icon white"><i class="icon-mail"></i></a>
                  </div>
                </div>
              </div>
            </div>

          <?php elseif ($image['last']) : ?>

            <div class="slide end-slide">
              <div class="slide-img">
                <img src="<?php print $image['url']; ?>" alt="<?php print $image['alt']; ?>" title="<?php print $image['title']; ?>" />
              </div>
              <div class="end-slide-content row">
                <div class="column">
                  <div class="columns large-6 large-offset-1 text-container hide-for-small hide-for-tiny hide-for-medium">
                    <h1 class="thin"><?php print $title; ?></h1>
                    <p class="deck"><?php print $subtitle; ?></p>
                    <p><a href="#" class="end-slide-button button pea-green xlarge slideshow-control restart"><i class="icon-spin-widdershins"></i>Restart Slideshow</a></p>
                    <ul class="inline-list end-slide-links">
                      <li><?php print l(t('In the Bird Guide'), 'bird-guide'); ?></li>
                      <li><?php print l(t('In the News'), 'news'); ?></li>
                    </ul>
                    <div class="social-sharing align-left hide-for-small hide-for-medium hide-for-tiny">
                      <span class="social-sharing-caption white">Share this</span>
                      <a href="#" class="social-sharing-icon white"><i class="icon-twitter"></i></a>
                      <a href="#" class="social-sharing-icon white"><i class="icon-facebook"></i></a>
                      <a href="#" class="social-sharing-icon white"><i class="icon-pinterest"></i></a>
                      <a href="#" class="social-sharing-icon white"><i class="icon-mail"></i></a>
                    </div>
                  </div>
                  <div class="columns tiny-12 small-8 small-offset-2 medium-6 medium-offset-3 large-4 large-offset-0 end text-container">
                    <div class="engagement-card">
                      <div class="engagement-card-content no-min-height">
                        <h3 class="engagement-card-headline">Improve Crane Habitats</h3>
                        <p>Restoration efforts continue on improve winter homes for whooping cranes.</p>
                        <div class="engagement-card-cta">
                          <a href="#" class="button tomato large">Donate Today</a>
                        </div>
                      </div>
                      <div class="engagement-card-photo hide-for-small hide-for-tiny hide-for-medium">
                        <img src="<?php print base_path() . path_to_theme() . '/img/engagement-card-3.jpg'; ?>" alt="">
                      </div>
                    </div>
                  </div>
                </div>
              </div>
            </div>

          <?php else : ?>

            <div class="slide">
              <div class="slide-img">
                <img src="<?php print $image['url']; ?>" alt="<?php print $image['alt']; ?>" title="<?php print $image['title']; ?>" />
              </div>
              <div class="row">
                <div class="large-9 columns">
                  <div class="slide-caption"><?php print $image['caption']; ?> <?php print $image['credit']; ?></div>
                </div>
              </div>
            </div>

          <?php endif; ?>
        <?php endforeach; ?>
      <?php endif; ?>
    </div>
  </div>
</div>
