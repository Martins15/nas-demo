<?php

/**
 * @file
 * Upcoming Events block template file.
 */
?>

<section class="sidebar-section medium-6 large-12 columns local-cnc upcoming-events-block">
  <div class="sidebar-section editorial-card <?php print !empty($contextual_links) ? 'contextual-links-region' : ''; ?>">
    <?php print $contextual_links; ?>

    <div class="editorial-card-photo">
      <?php print $image; ?>
    </div>

    <div class="editorial-card-banner green"><i class="icon-calendar"></i> <?php print $title; ?></div>

    <div class="editorial-card-content">
      <div class="upcoming-events-content-layout">
        <?php print $content; ?>
      </div>
      <?php if (!empty($bottom_link)) : ?>
        <hr />
        <?php print $bottom_link; ?>
      <?php endif; ?>
    </div>
  </div>
</section>
