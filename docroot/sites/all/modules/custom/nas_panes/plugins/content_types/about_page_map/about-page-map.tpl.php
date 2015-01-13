<?php
/**
 * @file
 * About Page Map template file.
 */
?>

<?php if (!empty($title)) : ?>
<div class="row space-top">
  <div class="column">
    <h2 class="thin centered"><?php print $title; ?></h2>
  </div>
</div>
<?php endif; ?>
<div class="inline-map <?php print !empty($contextual_links) ? 'contextual-links-region' : ''; ?>">
  <?php print $contextual_links; ?>
  <div class="inline-map-canvas">
    <div class="inline-map-mask"></div>
    <?php print $map; ?>
  </div>
</div>
