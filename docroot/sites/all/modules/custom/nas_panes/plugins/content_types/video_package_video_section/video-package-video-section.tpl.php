<?php

/**
 * @file
 * Template for Video Package Video Section.
 */
?>

<!-- Video package video section -->
<div id="<?php print $hash; ?>" class="clearfix video-container">
  <video muted playsinline class="main-video-item" poster="<?php print $poster; ?>"
         data-src="<?php print $video; ?>"
         data-thumb-src="<?php print $thumbnail_video; ?>"
         data-thumb-poster="<?php print $thumbnail_poster; ?>"
         data-short-title="<?php print $title_short; ?>">
    <source src="" type="video/mp4">
  </video>
  <div class="video-content column white-text" data-top="<?php print $top; ?>" data-bottom="<?php print $bottom; ?>">
    <h1><?php print $title_long; ?></h1>
  </div>
</div>
<!-- /Video package video section -->
