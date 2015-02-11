<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>

<?php print $content['guide_bar']; ?>

<section class="global-content birds-family-section">
  <div class="row column">
    <div class="common-name">
      <?php print $content['title']; ?>
    </div>
    <div class="scientific-name">
      <?php print $content['scientific_name']; ?>
    </div>
    <div class="family-description">
      <?php print $content['description']; ?>
    </div>
  </div>
  <div class="bird-card-grid">
    <?php print $content['main']; ?>
    <div class="row space-bottom"></div>
  </div>

  <section class="card-set bg-1">
    <?php print $content['cards']; ?>
  </section>
</section>
