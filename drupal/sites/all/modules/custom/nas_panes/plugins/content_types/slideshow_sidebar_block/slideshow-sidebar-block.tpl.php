<?php
/**
 * @file
 * Slideshow Sidebad Block template file.
 */
?>

<section class="sidebar-section medium-6 large-12 editorial-card slideshow-sidebar-block <?php print !empty($contextual_links) ? 'contextual-links-region' : ''; ?>">
  <?php print $contextual_links; ?>

  <div class="editorial-card-photo">
    <img src="<?php print base_path() . drupal_get_path('theme', 'nas'); ?>/img/editorial-card-13.jpg">
  </div>

  <div class="editorial-card-banner gray"><i class="icon-slides"></i> <?php print $block_title; ?></div>
  <div class="editorial-card-content">
    <h3 class="editorial-card-title"><?php print $slideshow; ?></h3>
  </div>
</section>
