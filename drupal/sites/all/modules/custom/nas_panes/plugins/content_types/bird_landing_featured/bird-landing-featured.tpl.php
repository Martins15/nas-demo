<?php
/**
 * @file
 * Featured Bird template file.
 *
 * Available variables:
 * - $name: the (sanitized) name of the bird.
 * - $url: url of the link to bird's individual page.
 * - $scientific_name: the (sanitized) scientific name of the bird.
 * - $image_path: path to the hero image of the bird.
 * - $image_path_mobile: path to the hero image of the bird mobile image style.
 * - $image_string: sanitized caption + credits of the hero image.
 * - $illustration_path: path to the illustration image of the bird.
 * - $contextual_links: rendered contextual links.
 */
?>

<div class="hero <?php print $color; ?>-gradient">
  <div class="hero-image">
    <img src="<?php print $image_path_mobile; ?>" alt="" class="hide-for-medium hide-for-large hide-for-xlarge">
    <img src="<?php print $image_path; ?>" alt="" class="hide-for-tiny hide-for-small">
  </div>
  <div class="row">
    <div class="hero-header contextual-links-region">
      <?php print $contextual_links; ?>
      <div class="column">
        <a class="hero-slug" href="<?php print $category_link_url; ?>"><?php print $category; ?></a>
        <h2 class="hero-title"><?php print $name; ?></h2>
      <div class="hero-text">
      <p class="hero-paragraph"><?php print $summary; ?> <a href="<?php print $url; ?>">Learn more »</a></p>
      <ul class="hero-inline-list inline-list">
        <li><?php print $bird_guide_link; ?></li>
        <li><?php print $category_link_more; ?></li>
      </ul>
    </div></div>
    </div>
  </div>
</div>
