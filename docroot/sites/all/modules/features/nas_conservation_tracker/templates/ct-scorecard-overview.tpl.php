<?php
/**
 * TPL file for CT content type.
 */
?>
<div class="ct-scorecard-overview row">
  <div class="bird-page body-item">
    <div class="title-wrap">
      <div class="title-wrap__title columns tiny-10"><h3><?php print $title; ?></h3></div>
      <div class="title-wrap__print  columns large-2 hide-for-medium hide-for-small">
        Download
      </div>
    </div>
    <div class="body-wrap columns large-8">
      <div class="body-wrap__body-text">
        <p><?php print $description; ?></p>
      </div>
    </div>
    <div class="video-wrap columns large-4">
      <div class="video-wrap__item help-img-full">
        <?php print $media; ?>
      </div>
    </div>
  </div>
</div>