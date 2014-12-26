<?php
/**
 * @file
 * BOA Plate Binocular tpl file.
 *
 * Available variables:
 * - $contextual_links: rendered contextual links.
 * - $title: linked title of BOA.
 * - $credits: Illustration credits.
 * - $link: link to BOA node.
 */
?>
<div class="<?php print $class; ?> contextual-links-region" style="background-image: url(<?php print $image_desaturated; ?>);">
  <?php print $contextual_links; ?>
  <a href="#" class="bg-egg icon-binoculars white"></a>
  <div class="bird-card-grid-bg-caption">
    <div class="row">
      <div class="columns large-offset-1 large-3">
        <h2 class="thin"><?php print $title; ?></h2>
      </div>
      <div class="columns large-8">
        <p><?php print $credits; ?></p>
        <p><em><?php print $link; ?></em></p>
      </div>
    </div>
  </div>
