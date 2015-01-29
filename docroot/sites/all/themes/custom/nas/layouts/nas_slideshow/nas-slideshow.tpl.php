<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>

<section class="global-content">

  <?php print $content['slideshow']; ?>
  <?php print $content['bottom']; ?>

  <section class="card-set bg-dark-gray">
  <?php print $content['cards_set']; ?>
  </section>
</section>
<?php if (arg(0) !== 'node'): ?>
<?php print $content['slide_card']; ?>
<?php endif;?>
