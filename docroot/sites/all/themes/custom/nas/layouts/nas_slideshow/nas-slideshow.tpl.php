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
    <div class="row">
      <div class="card-set-social social-sharing">
        <span class="social-sharing-caption light-gray">Spread the word. It’s the least you can do.</span>
        <a class="social-sharing-icon light-gray" href="#"><i class="icon-twitter"></i></a>
        <a class="social-sharing-icon light-gray" href="#"><i class="icon-facebook"></i></a>
        <a class="social-sharing-icon light-gray" href="#"><i class="icon-mail"></i></a>
      </div>
    </div>
  </section>
</section>
<?php if (arg(0) !== 'node'): ?>
<?php print $content['slide_card']; ?>
<?php endif;?>
