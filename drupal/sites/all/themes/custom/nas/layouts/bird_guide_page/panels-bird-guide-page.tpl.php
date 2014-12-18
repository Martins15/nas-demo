<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<?php print $content['header']; ?>

<div class="bird-guide-search show">
  <div class="row">
    <div class="columns large-12 bird-guide-search-form">
      <?php print $content['bird_guide_search']; ?>
    </div>
  </div>
</div>
<section class="global-content">
  <div class="bird-card-grid">
    <?php print $content['bird_card_grid']; ?>
  </div>
  <?php print $content['in_the_news']; ?>
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