<?php
/**
 * @file
 * Conservation Landing Top template file.
 *
 * Available variables:
 * - $hero_image: big image at the top.
 * - $hero_image_mobile: mobile image at the top.
 * - $title: title.
 * - $subtitle: subtitle under the title.
 * - $color_mode_gradient: color mode for gradient.
 * - $color_mode_text: color mode for text.
 * - $credit: credit of the hero image.
 * - $contextual_links: contextual links for configuration.
 */
?>

<div class="hero <?php print $color_mode_gradient; ?>-gradient <?php print $color_mode_text; ?>-text">
  <div class="hero-image">
    <img src="<?php print $hero_image_mobile; ?>" alt="" class="hide-for-medium hide-for-large hide-for-xlarge">
    <img src="<?php print $hero_image; ?>" alt="" class="hide-for-tiny hide-for-small">
  </div>
  <div class="row">
    <div class="hero-header contextual-links-region">
      <?php print $contextual_links; ?>
      <div class="column">
        <h2 class="hero-title big"><?php print $title; ?></h2>
        <p class="hero-blurb"><?php print $subtitle; ?></p>
      </div>
    </div>
  </div>
</div>

<?php if(!empty($credit)) : ?>
  <div class="hero-attribution row">
    <p class="column"><span class="hero-attribution-text"><?php print $credit; ?></span></p>
  </div>
<?php endif; ?>
