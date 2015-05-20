<?php
/**
 * @file
 * Featured Frontpage template file.
 *
 * Available variables:
 * - $title_link: the (sanitized) title with link.
 * - $blue_text_link: the (sanitized) blue text above the title with link.
 * - $image_path: path to the hero image of the bird.
 * - $image_path_mobile: path to the hero image of the bird mobile image style.
 * - $image_string: sanitized caption + credits of the hero image.
 * - $contextual_links: rendered contextual links.
 */
?>

<div class="curtain-content light-text">
  <div class="row space-bottom">
    <div class="column large-6 large-offset-6 contextual-links-region">
      <?php print $contextual_links; ?>
      <div class="curtain-card">
        <?php print $slug_link; ?>
        <h2 class="curtain-card-headline"><?php print $title_link; ?></h2>
        <p class="curtain-card-blurb"><?php print $summary; ?></p>
      </div>
    </div>
  </div>
  <?php if ($attribution_title || $attribution_credit): ?>
    <div class="row">
      <div class="column">
        <div class="curtain-attribution">
          <?php if ($attribution_title): ?>
            <p class="title"><?php print $attribution_title; ?></p>
          <?php endif; ?>
          <?php if ($attribution_credit): ?>
            <p class="credit"><?php print $attribution_credit; ?></p>
          <?php endif; ?>
        </div>
      </div>
    </div>
  <?php endif; ?>
</div>

<a href="#" class="curtain-arrow"></a>

<div class="curtain-video <?php print $position; ?>">
  <video poster="../../img/video-poster.jpg" loop="" autoplay="" src="<?php print $video_source; ?>" muted=""></video>
  <div class="curtain-video-play-button"></div>
</div>
