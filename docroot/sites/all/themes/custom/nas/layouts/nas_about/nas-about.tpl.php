<?php
/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<?php print render($content['top']); ?>
<?php print render($content['menu_bar']); ?>

<section <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?> class="global-content with-padding">
  <?php print render($content['main']); ?>
  <section class="card-set bg-1">
    <?php print render($content['cards']); ?>
  </section>
</section>
