<?php

/**
 * @file
 * Template for the Native Plants Nurseries near you.
 */
?>
<div class="row where-to-buy__section <?php print $classes; ?><?php print !empty($context_links) ? ' contextual-links-region' : ''; ?>">
  <?php print $context_links; ?>
  <div class="large-4 medium-6 columns">
    <h2 class="thin"><?php print $title; ?></h2>
    <?php print $description; ?>
  </div>
  <?php if ($nurseries_show): ?>
    <div class="large-8 medium-6 columns">
      <?php foreach (array_chunk($nurseries_show, 3) as $row): ?>
        <div class="row">
          <?php foreach ($row as $nursery): ?>
            <div class="large-4 medium-12 columns">
              <div class="address">
                <h4><?php print $nursery['title'] ?></h4>
                <p><?php print $nursery['address']['rendered']; ?></p>
                <?php if (!empty($nursery['phone'])): ?>
                  <p><?php print $nursery['phone']; ?></p>
                <?php endif; ?>
                <?php if (!empty($nursery['link']['url'])): ?>
                  <a target="_blank" href="<?php print $nursery['link']['url']; ?>"><?php print $nursery['link']['print']; ?></a>
                <?php endif; ?>
              </div>
            </div>
          <?php endforeach; ?>
        </div>
      <?php endforeach; ?>

    <?php if (!empty($nurseries_hidden)): ?>
      <?php foreach (array_chunk($nurseries_hidden, 3) as $row): ?>
        <div class="row hidden hide">
          <?php foreach ($row as $nursery): ?>
          <div class="large-4 medium-12 columns">
            <div class="address">
              <h4><?php print $nursery['title'] ?></h4>
              <p><?php print $nursery['address']['rendered']; ?></p>
              <?php if (!empty($nursery['phone'])): ?>
                <p><?php print $nursery['phone']; ?></p>
              <?php endif; ?>
              <?php if (!empty($nursery['link']['url'])): ?>
                <a target="_blank"
                   href="<?php print $nursery['link']['url']; ?>"><?php print $nursery['link']['print']; ?></a>
              <?php endif; ?>
            </div>
          </div>
          <?php endforeach; ?>
        </div>
      <?php endforeach; ?>
      <div class="row">
        <div class="large-12 medium-12 columns">
          <a class="show-more-nurseries" href="#">Show more »</a>
        </div>
      </div>
    <?php endif; ?>

  <?php endif; ?>

</div>
