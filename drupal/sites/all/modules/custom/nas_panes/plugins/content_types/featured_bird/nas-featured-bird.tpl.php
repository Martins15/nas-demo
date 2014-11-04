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
 * - $color: color scheme for gradient.
 * - $color_classes: color classes for text.
 */
?>
<div class="hero <?php print $color_classes; ?>">
  <div class="hero-image">
    <img src="<?php print $image_path_mobile; ?>" alt="" class="hide-for-medium hide-for-large hide-for-xlarge">
    <img src="<?php print $image_path; ?>" alt="" class="hide-for-tiny hide-for-small">
  </div>
  <div class="row">
    <div class="hero-header">
      <div class="column medium-8 large-9 contextual-links-region">
        <?php print $contextual_links; ?>
        <a class="hero-slug" href="<?php print $url; ?>"><?php print t('Featured Bird'); ?></a>
        <h2 class="hero-title"><?php print $name; ?></h2>
      </div>
      <div class="hero-card-column column hide-for-small hide-for-tiny medium-4 large-3">
        <figure class="bird-card">
          <div class="bird-card-illustration">
            <a href="<?php print $url; ?>"><img src="<?php print $illustration_path; ?>" alt=""></a>
          </div>
          <figcaption class="bird-card-caption">
            <h4 class="common-name"><a href="<?php print $url; ?>"><?php print $name; ?></a></h4>
            <p class="scientific-name"><?php print $scientific_name; ?></p>
          </figcaption>
          <a href="#" class="icon-sound-full bird-card-audio"></a>
        </figure>
      </div>
    </div>
  </div>
</div>
<div class="hero-attribution align-left row">
  <p class="column">Photo: <?php print $image_string; ?></p>
</div>
