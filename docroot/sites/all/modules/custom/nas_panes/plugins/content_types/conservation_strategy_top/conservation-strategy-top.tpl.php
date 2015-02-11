<?php
/**
 * @file
 * Conservation Strategy Top template file.
 *
 * Available variables:
 * - $hero_image: big image at the top.
 * - $hero_image_mobile: hero image for mobile.
 * - $title: title.
 * - $icon: logo icon of the Conservation Strategy.
 * - $credit: credit of the hero image.
 * - $color_mode_gradient: color mode for gradient.
 * - $color_mode_text: color mode for text.
 */
?>

<div class="hero <?php print $color_mode_gradient; ?>-gradient <?php print $color_mode_text; ?>-text">
  <div class="hero-image">
    <img src="<?php print $hero_image_mobile; ?>" alt="" class="hide-for-medium hide-for-large hide-for-xlarge">
    <img src="<?php print $hero_image; ?>" alt="" class="hide-for-tiny hide-for-small">
  </div>
  <div class="row">
    <div class="hero-header">
      <div class="column">
        <?php if (!empty($icon)) : ?>
          <img class="hero-icon" src="<?php print $icon; ?>">
        <?php endif; ?>
        <h4 class="hero-slug"><?php print t('Conservation'); ?></h4>
        <h2 class="hero-title big with-icon"><?php print $title; ?></h2>
      </div>
    </div>
  </div>
</div>

<?php if ($attribution) : ?>
  <div class="hero-attribution row">
    <p class="column"><span class="hero-attribution-text"><?php print $attribution ?></span></p>
  </div>
<?php endif; ?>
