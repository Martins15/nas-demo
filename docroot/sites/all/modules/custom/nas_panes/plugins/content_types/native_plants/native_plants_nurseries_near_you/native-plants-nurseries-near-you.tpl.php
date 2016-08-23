<?php
/**
 * @file
 * Template for the Native Plants Nurseries near you.
 */
?>
<div class="clearfix where-to-buy__section__row vertical-spacing--top--half<?php print !empty($context_links) ? ' contextual-links-region' : ''; ?>">
  <?php print $context_links; ?>
  <div class="column medium-4">
    <h2 class="thin"><?php print $title; ?></h2>
    <?php print $description; ?>
  </div>
  <div class="column medium-8 where-to-buy__nurseries">
    <div class="row">
      <?php foreach ($nurseries as $nursery): ?>
        <div class="column large-6 where-to-buy__nursery__row">
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
                <?php print $nursery['address']['rendered']; ?>
              </p>
            </div>
          </div>
          <div class="row">
            <div class="column tiny-3">
              <p class="label"><?php print t('Website'); ?></p>
            </div>
            <div class="column tiny-9">
              <p>
                <a href="https://google.com">https://google.com</a>
              </p>
            </div>
          </div>
        </div>
      <?php endforeach; ?>
    </div>
  </div>
</div>
