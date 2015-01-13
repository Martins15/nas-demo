<?php
/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<?php print $content['header']; ?>

<?php print $content['main']; ?>
<div class="audubon-near-you--global-content-wrapper">
  <section class="global-content no-padding blocks-events">
    <div class="row">
      <?php print $content['locations']; ?>
    </div>
  </section>
  <?php print $content['birds']; ?>
  <?php print $content['news']; ?>
</div>
