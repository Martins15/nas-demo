<?php

/**
 * @file
 * Template for custom pane progress bar.
 *
 * Available variables:
 * - $grid_size: Grid set size.
 * - $images: All images.
 * - $rows: Rows number.
 * - $columns: Columns number.
 * - $gallery_caption: Gallery caption.
 * - $output_placeholder: A flag indicated if it's required to output the
 *   gallery markup for the lightbox.
 * - $mobile_fallback: Type of mobile fallback.
 * - $mobile_fallback_image: Mobile fallback single image path.
 */
?>

<!-- Grid gallery <?php print $grid_size; ?> -->

<div class="grid-gallery <?php print 'grid-gallery-' . $grid_size; ?>
  <?php if ($mobile_fallback): ?>
    hide-for-tiny hide-for-small
  <?php endif; ?>">
  <div class="row grid-gallery__thumbs">
  <?php foreach ($images as $image): ?>
    <div class="columns <?php print $image['class_column']; ?>">
      <a class="grid-gallery__lightbox white" href="<?php print $image['lightbox_path']; ?>" data-gallery="#grid-gallery">
        <div title="<?php print t('Expand'); ?>" class="grid-gallery__expand"></div>
        <img class="grid-gallery__image"
             src="<?php print $image['thumbnail_path']; ?>"
             title="<?php print htmlspecialchars($image['title']); ?>"
             data-credit="<?php print htmlspecialchars($image['credit']); ?>"
             data-title="<?php print htmlspecialchars($image['caption']); ?>">
      </a>
    </div>
  <?php endforeach; ?>
  </div>

  <?php if ($gallery_caption): ?>
    <div class="row grid-gallery__caption">
      <div class="columns large-12">
        <?php print $gallery_caption; ?>
      </div>
    </div>
  <?php endif; ?>
</div>

<?php if ($output_placeholder): ?>
<div id="grid-gallery" class="blueimp-gallery nas-blueimp-gallery blueimp-gallery-controls" data-title-element=".title">
  <div class="slides"></div>
  <a class="close"></a>
  <div class="title-wrapper title-wrapper-alternative">
    <div class="title-wrapper-inner">
      <div class="title"></div>
    </div>
  </div>
  <div class="description">
    <div class="row">
      <div class="columns">
        <div class="credit"></div>
        <a class="prev">&lt;</a>
        <a class="next">&gt;</a>
        <span class="total"></span>
      </div>
    </div>
    <div class="row">
      <div class="columns">
        <div class="title-wrapper">
          <div class="title-wrapper-inner">
            <div class="title"></div>
          </div>
        </div>
        <a class="play-pause"></a>
        <ol class="indicator" style="display: none;"></ol>
      </div>
    </div>
  </div>
</div>
<?php endif; ?>

<?php if ($mobile_fallback == 'slideshow'): ?>
  <div class="grid-gallery-slideshow-wrapper">
    <div class="slideshow clearfix">
      <div class="slideshow-indicator row">
        <div class="column large-offset-9 large-3">
          <p>
            <i class="ss-icon icon-chevron-left inactive slideshow-control prev"></i>
            <span class="indicator-current">1</span> of
            <span class="indicator-total"><?php print count($images); ?></span>
            <i class="ss-icon icon-chevron-right slideshow-control next"></i>
          </p>
        </div>
      </div>
      <a href="#" class="slideshow-button slideshow-control prev hide-for-tiny hide-for-small"></a>
      <a href="#" class="slideshow-button slideshow-control next hide-for-tiny hide-for-small"></a>
      <div class="slideshow-wrapper">
        <div class="slideshow-scroller">
          <?php foreach ($images as $image): ?>
          <div class="slide">
            <div class="slide-img">
              <img src="<?php print $image['thumbnail_path']; ?>" />
            </div>
            <div class="row">
              <div class="large-9 columns">
                <div class="slide-caption">
                  <?php print $image['attributes']; ?>
                </div>
              </div>
            </div>
          </div>
          <?php endforeach; ?>
        </div>
      </div>
    </div>
  </div>
<?php endif; ?>

<?php if ($mobile_fallback == 'single'): ?>
  <div class="grid-gallery grid-gallery-single-image hide-for-medium hide-for-large hide-for-xlarge">
    <div class="row grid-gallery__thumbs">
      <div class="columns">
        <img src="<?php print $mobile_fallback_image; ?>" width="300" height="300" title="" />
      </div>
    </div>
    <?php if ($gallery_caption): ?>
    <div class="row grid-gallery__caption">
      <div class="columns large-12">
        <?php print $gallery_caption; ?>
      </div>
    </div>
    <?php endif; ?>
  </div>

<?php endif; ?>
<!-- /Grid gallery -->
