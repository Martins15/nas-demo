<?php

/**
 * @file
 * Template for the Native Plants Additional Resource near you.
 */
?>
<div class="row where-to-buy__section <?php print $classes; ?><?php print !empty($context_links) ? ' contextual-links-region' : ''; ?>">
  <?php print $context_links; ?>
  <div class="large-4 medium-6 columns">
    <h2 class="thin"><?php print $title; ?></h2>
    <?php print $description; ?>
  </div>
  <?php if ($additional_resource_show): ?>
    <div class="large-8 medium-6 columns">
      <?php foreach (array_chunk($additional_resource_show, 2) as $row): ?>
        <div class="row">
          <?php foreach ($row as $resource): ?>
            <div class="large-6 medium-12 columns">
              <div class="address">
                <h4><?php print $resource['title'] ?></h4>
                <?php if (!empty($resource['body'])): ?>
                  <div><?php print $resource['body']; ?></div>
                <?php endif; ?>
                <p><?php print $resource['address']['rendered']; ?></p>
                <?php if (!empty($resource['phone'])): ?>
                  <p><?php print $resource['phone']; ?></p>
                <?php endif; ?>
                <?php if (!empty($resource['link']['url'])): ?>
                  <a target="_blank" href="<?php print $resource['link']['url']; ?>"><?php print $resource['link']['print']; ?></a>
                <?php endif; ?>
              </div>
            </div>
          <?php endforeach; ?>
        </div>
      <?php endforeach; ?>

      <?php if ($additional_resource_hidden): ?>
        <?php foreach (array_chunk($additional_resource_hidden, 2) as $row): ?>
          <div class="row hidden hide">
            <?php foreach ($row as $resource): ?>
              <div class="large-6 medium-12 columns">
                <div class="address">
                  <h4><?php print $resource['title'] ?></h4>
                  <?php if (!empty($resource['body'])): ?>
                    <div><?php print $resource['body']; ?></div>
                  <?php endif; ?>
                  <p><?php print $resource['address']['rendered']; ?></p>
                  <?php if (!empty($resource['phone'])): ?>
                    <p><?php print $resource['phone']; ?></p>
                  <?php endif; ?>
                  <?php if (!empty($resource['link']['url'])): ?>
                    <a target="_blank" href="<?php print $resource['link']['url']; ?>"><?php print $resource['link']['print']; ?></a>
                  <?php endif; ?>
                </div>
              </div>
            <?php endforeach; ?>
          </div>
        <?php endforeach; ?>
        <div class="row">
          <div class="large-12 medium-12 columns">
            <a class="how-more-resources" href="#">Show more »</a>
          </div>
        </div>
      <?php endif; ?>
    </div>
  <?php endif; ?>
</div>
