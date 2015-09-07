<?php
/**
 * @file
 * Template implementation to display BOA layout.
 */
?>
<?php print $content['header']; ?>
<!--</header>-->
<?php print $content['hero']; ?>
<section class="global-content no-padding">
  <?php print $content['main']; ?>
  <section class="card-set bg-1">
    <?php print render($content['cards']); ?>
  </section>
</section>
