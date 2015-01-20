<?php
/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<?php print render($content['top']); ?>
<?php print render($content['menu_bar']); ?>

<section class="global-content getoutside">
  <?php print render($content['main']); ?>

  <?php if (!empty($content['bird_guide'])): ?>
  <div class="bird-card-set bg-bone-white">
    <?php print render($content['bird_guide']); ?>
  </div>
  <?php endif; ?>

  <section class="card-set bg-1">
    <?php print render($content['cards']); ?>
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