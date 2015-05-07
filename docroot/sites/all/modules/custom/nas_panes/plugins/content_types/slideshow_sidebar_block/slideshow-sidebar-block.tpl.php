<?php
/**
 * @file
 * Slideshow Sidebad Block template file.
 */
?>

<section class="sidebar-section medium-6 large-12 editorial-card slideshow-sidebar-block <?php print !empty($contextual_links) ? 'contextual-links-region' : ''; ?>">
  <?php print $contextual_links; ?>

  <div class="editorial-card-photo">
    <?php print $image; ?>
    <div class="editorial-card-banner gray overlap-banner">
      <i class="icon-slides"></i>
      <?php print $block_title; ?>
      <?php if ($logo) : ?>
        <div class="icon-wrapper"><?php print $logo; ?></div>
      <?php endif; ?>
    </div>
  </div>

  <div class="editorial-card-content editorial-slideshow">
    <h3 class="editorial-card-title"><?php print $slideshow; ?></h3>
    <?php if (!empty($link)) : ?>
      <?php print $link; ?>
    <?php endif; ?>
  </div>
  
</section>
