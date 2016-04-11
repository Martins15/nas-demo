<?php
/**
 * @file
 * Template for the Native Plants Nurseries near you.
 */
?>
<div class="row space-top where-to-buy-section<?php print !empty($context_links) ? ' contextual-links-region' : ''; ?>">
  <?php print $context_links; ?>
  <div class="column medium-4">
    <h3 class="thin"><?php print $title; ?></h3>
    <?php print $description; ?>
  </div>
  <div class="column medium-8">
    <div class="row">
      <?php foreach ($nurseries as $nursery): ?>
        <div class="column medium-6 nursery">
          <div class="row">
            <div class="column tiny-3">
              <p class="label"><?php print t('Nursery'); ?></p>
            </div>
            <div class="column tiny-9">
              <p><?php print $nursery['title'] ?></p>
            </div>
          </div>
          <div class="row">
            <div class="column tiny-3">
              <p class="label"><?php print t('Address'); ?></p>
            </div>
            <div class="column tiny-9">
              <p>
                <?php print $nursery['address']['thoroughfare']; ?><br/>
                <?php print $nursery['address']['locality']
                  . ', ' . $nursery['address']['administrative_area']
                  . ' ' . $nursery['address']['postal_code']; ?>
              </p>
            </div>
          </div>
        </div>
      <?php endforeach; ?>
    </div>
  </div>
</div>