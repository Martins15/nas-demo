<?php
/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>

<?php print $content['header']; ?>

<section class="global-content with-padding">
  <div class="breakout-section fixed-height"
  <?php if (!empty($background_image)): ?>
       style="background-image: url(<?php print $background_image; ?>)"
  <?php endif; ?>>
    <div class="breakout-section-content <?php print !empty($color_mode_text) ? $color_mode_text : 'dark'; ?>-text">
      <div class="row text-container">
        <div class="column">
          <h1 class="thin"><?php print $content['secondary_title']; ?></h1>
          <div class="deck"><?php print $content['subtitle']; ?></div>
        </div>
        <?php print $content['body']; ?>
      </div>
    </div>
  </div>

  <?php print $content['bottom']; ?>

  <section class="card-set bg-1">
    <?php print $content['cards_set']; ?>
    <div class="row">
      <div class="card-set-social social-sharing">
        <span class="social-sharing-caption white">Spread the word. It’s the least you can do.</span>
        <a class="social-sharing-icon white" href="#"><i class="icon-twitter"></i></a>
        <a class="social-sharing-icon white" href="#"><i class="icon-facebook"></i></a>
        <a class="social-sharing-icon white" href="#"><i class="icon-mail"></i></a>
      </div>
    </div>
  </section>
</section>