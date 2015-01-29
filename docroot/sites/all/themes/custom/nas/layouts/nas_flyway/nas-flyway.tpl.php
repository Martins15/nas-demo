<?php
/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>

<?php print $content['header']; ?>

<section class="global-content">
  <div class="breakout-section fixed-height"
  <?php if (!empty($background_image)): ?>
       style="background-image: url(<?php print $background_image; ?>)"
  <?php endif; ?>>
    <div class="breakout-section-content <?php print !empty($color_mode_text) ? $color_mode_text : 'dark'; ?>-text">
      <div class="row text-container space-top">
        <div class="column">
          <h1 class="thin"><?php print $content['secondary_title']; ?></h1>
          <div class="deck"><?php print $content['subtitle']; ?></div>
        </div>
        <?php print $content['body']; ?>
      </div>
    </div>
    <?php if(!empty($image_credit)) : ?>
      <div class="hero-attribution breakout-hero-attribution row">
        <p class="column"><span class="hero-attribution-text"><?php print $image_credit; ?></span></p>
      </div>
    <?php endif; ?>
  </div>

  <?php print $content['bottom']; ?>

  <section class="card-set bg-1">
    <?php print $content['cards_set']; ?>
  </section>
</section>