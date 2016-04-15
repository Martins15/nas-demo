<?php
/**
 * @file
 * Native Plants Audubon near you template.
 */
?>
<div class="breakout-section connect-audubon-near-you<?php print !empty($context_links) ? ' contextual-links-region' : ''; ?>" style="background-image: url(<?php print $image_path; ?>);">
  <?php print $context_links; ?>
  <div class="breakout-section-content fade-to-black light-text" data-equalizer data-equalizer-mq="medium-up">
    <div class="row">
      <div class="column medium-6" data-equalizer-watch>
        <div class="row space-top space-bottom">
          <div class="columns">
            <h2><?php print $title; ?></h2>

            <h3 class="connect-audubon-near-you--title"><?php print $resource['title']; ?></h3>
            <p class="connect-audubon-near-you--address">
              <?php print $resource['address']['rendered']; ?>
              <?php print $resource['phone']; ?>
            </p>
            <?php print $resource['link']['rendered']; ?>
          </div>
        </div>
      </div>

      <div class="breakout-section-box column medium-6 connect-audubon-near-you--services" data-equalizer-watch>
        <h3 class="thin hide-for-tiny hide-for-small"><?php print $services_title_desktop; ?></h3>
        <h3 class="hide-for-medium hide-for-large hide-for-xlarge"><?php print $services_title_mobile; ?></h3>
        <?php print $resource['services']['rendered']; ?>
      </div>
    </div>
  </div>
</div>