<?php
/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<?php print render($content['top']); ?>

<section class="global-content with-padding">
  <?php print $content['main']; ?>
  <section class="card-set bg-1">
   <?php print $content['cards_set']; ?>
  </section>
</section>
