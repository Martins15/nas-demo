<?php
/**
 * @file
 * Template to custom pane boa_hero.
 *
 * Available variables:
 *  $title - title of the block.
 *  $body - body text.
 *  $image_path - path to John Audubon image.
 *  $summary - summary text for right sidebar.
 *  $link - url to Learn more about John J Audubon.
 */
?>

<div class="row boa-ja-content-block">
  <div class="large-8 columns text-container contextual-links-region">
    <?php print $contextual_links; ?>
    <h2 class="thin"><?php print $title; ?></h2>
    <?php print $body; ?>
  </div>
  <div class="large-4 columns">
    <div class="editorial-card">
      <div class="editorial-card-photo">
        <a href="<?php print $link; ?>"><img src="<?php print $image_path; ?>" alt="" /></a>
      </div>
      <div class="editorial-card-content">
        <h3 class="editorial-card-title"><a href="<?php print $link; ?>"><?php print $name; ?></a></h3>
        <?php print $summary; ?>
      </div>
    </div>
  </div>
</div>
