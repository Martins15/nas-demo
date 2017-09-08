<?php

/**
 * @file
 * Template for Video Package Hero block.
 *
 * Available variables:
 * - $image: Image url.
 * - $video: Video url.
 */
?>

<!-- Video Package: Hero video-->
<div class="clearfix video-container main-video">
  <video muted playsinline class="main-video-item" autoplay poster="<?php print $image; ?>">
    <source src="<?php print $video; ?>" type="video/mp4">
  </video>
  <div class="video-content column white-text" data-top="<?php print $top; ?>" data-bottom="<?php print $bottom; ?>">
    <h1><?php print $title_long; ?></h1>
  </div>
</div>
<!-- /Video package: Hero video -->
