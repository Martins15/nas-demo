<?php
/**
 * @file
 * Audubon Near You Bird Guide content template file.
 */
?>

<div class="bird-card-set" id="audubon-near-you--birds--wrapper">
    <?php if (empty($items)) : ?>
  <div class="row bird-card-container space-bottom">
    <div class="columns space-bottom">
      <?php if (empty($hide_empty_text) && empty($filter_active)) : ?>
        <?php print t('Select your state above'); ?>
      <?php endif; ?>

      <?php if (!empty($filter_active)) : ?>
        <?php print t('No Birds found in this location. Select your state above to look up for other location'); ?>
      <?php endif; ?>
    </div>
  </div>
<?php else : ?>
  <div class="row bird-card-container">
    <div class="bird-card-scroller">
      <?php foreach ($items as $item) : ?>
        <div class="columns tiny-3">
          <?php print render($item); ?>
        </div>
      <?php endforeach; ?>
    </div>
  </div>
  <div class="row indicator space-bottom">
    <div class="column">
      <p><i class="indicator-left icon-arrow-left disabled"></i>&nbsp;&nbsp;&nbsp;<i class="indicator-right icon-arrow-right"></i></p>
    </div>
  </div>
<?php endif; ?>
</div>
