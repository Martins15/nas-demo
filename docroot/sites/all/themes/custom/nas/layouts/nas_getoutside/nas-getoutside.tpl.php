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
  </section>
</section>
