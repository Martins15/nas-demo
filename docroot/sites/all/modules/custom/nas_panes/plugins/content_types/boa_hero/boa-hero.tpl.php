<?php
/**
 * @file
 * Template to custom pane boa_hero.
 *
 * Available variables:
 *  $image - url to the hero image.
 *  $next_url - url to next BOA.
 *  $prev_url - url to prvious BOA.
 */
?>
<?php if (!empty($boa_plate_path)) : ?>
  <a class="bird-guide-image-link ctools-use-modal ctools-modal-boa-plate icon-binoculars white" href="<?php print $boa_plate_path; ?>"></a>
<?php endif; ?>

<div class="bird-guide-image">
  <?php if (!empty($image_path)) : ?>
    <img src="<?php print $image_path; ?>" />
  <?php endif; ?>
</div>

<a href="<?php print $prev_url; ?>" class="boa-previous-plate"></a>
<a href="<?php print $next_url; ?>" class="boa-next-plate"></a>
