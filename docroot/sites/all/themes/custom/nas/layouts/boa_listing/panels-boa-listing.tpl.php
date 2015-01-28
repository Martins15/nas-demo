<?php
/**
 * @file
 * Template implementation to display BOA layout.
 */
?>
<?php print $content['header']; ?>
</header>
<section class="global-content">
  <?php print $content['main']; ?>
  <section class="card-set bg-1">
    <?php print render($content['cards']); ?>
  </section>
</section>