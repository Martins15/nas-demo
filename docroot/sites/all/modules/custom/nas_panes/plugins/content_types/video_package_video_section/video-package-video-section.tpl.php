<?php

/**
 * @file
 * Template for Video Package Video Section.
 */
?>

<!-- Video package video section -->
<div id="<?php print $hash; ?>" class="clearfix video-container">
    <video muted playsinline class="main-video-item"
           poster="<?php print $poster; ?>"
           data-src="<?php print $video; ?>"
           data-thumb-src="<?php print $thumbnail_video; ?>"
           data-thumb-poster="<?php print $thumbnail_poster; ?>"
           data-short-title="<?php print $title_short; ?>">
        <source src="" type="video/mp4">
    </video>
    <div class="video-content column white-text hide-for-small hide-for-tiny hide-for-medium" data-top="<?php print $top; ?>"
         data-bottom="<?php print $bottom; ?>">
      <h1><?php print $title_long; ?></h1>
    </div>
    <div class="video-content column white-text hide-for-large hide-for-xlarge" data-top="<?php print $top; ?>"
         data-bottom="<?php print $bottom; ?>">
        <h1><?php print $title_long; ?></h1>
    </div>
</div>

<?php if (!empty($video_credit)) : ?>
<div class="row video-caption-container">
  <div class="large-9 column">
    <div class="video-caption">
        <span class="credit-intro"><?php print t('Video:') ?></span>
        <span class="credit-value"><?php print $video_credit; ?></span>
    </div>
  </div>
</div>
<?php endif; ?>
<!-- /Video package video section -->
