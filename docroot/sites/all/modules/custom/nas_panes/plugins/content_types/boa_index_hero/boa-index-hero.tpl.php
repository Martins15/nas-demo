<?php
/**
 * @file
 * Featured Bird template file.
 *
 * Available variables:
 * - $image_path: path to the hero image.
 * - $color: title color scheme.
 * - $title: page's title.
 * - $contextual_links: contextual links.
 */
?>

<div class="hero dark-gradient <?php print $color; ?>-text">
  <div class="hero-image">
    <img src="<?php print $image_path; ?>" alt="">
  </div>
  <div class="row">
    <div class="hero-header contextual-links-region">
      <?php print $contextual_links; ?>
      <div class="columns large-centered">
        <h1 class="hero-title"><?php print $title; ?></h1>
      </div>
    </div>
  </div>
</div>