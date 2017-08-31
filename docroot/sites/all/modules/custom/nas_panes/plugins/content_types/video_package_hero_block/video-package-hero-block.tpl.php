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
  <!-- todo: white-text -->
  <div class="video-content column white-text" data-top="" data-bottom="">
    <div class="hide-for-small hide-for-tiny hide-for-medium">
      <span class="small">what's at</span>
      <span class="large">stake</span>
    </div>
    <div class="hide-for-large hide-for-xlarge">
      <h1>What's at stake</h1>
    </div>
  </div>
</div>
<!-- /Video package: Hero video -->
