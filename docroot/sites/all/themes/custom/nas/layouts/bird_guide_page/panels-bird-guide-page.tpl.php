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
  <!-- div opens in the boa-plate-binocular.tpl.php -->
    <?php print $content['bird_card_grid']; ?>
  </div>
  <?php print $content['in_the_news']; ?>
  <section class="card-set bg-1">
    <?php print $content['cards_set']; ?>
  </section>
</section>
