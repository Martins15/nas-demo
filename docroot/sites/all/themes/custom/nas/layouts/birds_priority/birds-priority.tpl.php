<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>

<?php print $content['header']; ?>

<section class="global-content">
  <div class="bird-card-grid">
    <?php print $content['main']; ?>
    <div class="row space-bottom"></div>
  </div>

  <section class="card-set bg-1">
    <?php print render($content['cards']); ?>
  </section>
</section>
