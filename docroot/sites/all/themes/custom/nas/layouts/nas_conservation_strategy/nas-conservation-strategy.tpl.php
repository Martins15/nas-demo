<?php
/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>

<?php print render($content['top']); ?>

<section class="global-content with-padding">
  <div class="row space-bottom conservation-strategy-content text-container">
    <?php print render($content['body']); ?>
  </div>

  <?php print render($content['projects']); ?>

  <?php print render($content['news']); ?>

  <section class="card-set bg-1">
    <?php print $content['cards_set']; ?>
  </section>
</section>
