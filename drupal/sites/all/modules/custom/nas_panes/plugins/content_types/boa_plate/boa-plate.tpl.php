<?php
/**
 * @file
 * Template to custom pane boa_hero.
 *
 * Available variables:
 *  $image_thumbnail - url to the illustrtion image thumbnail.
 *  $image - url to the illustrtion image.
 *  $link_url - url to Learn more about John J Audubon.
 *  $link_title - title of the link Learn more about John J Audubon.
 */
?>

<section class="bird-guide-section boa-plate-illustration center">
  <img src="<?php print $image_thumbnail; ?>" />
  <a href="<?php print $image; ?>" class="see-full-plate" target="blank"><i class="icon-magnifier"></i> See full plate</a><br />
  <a href="<?php print $link_url; ?>" class="illustration-attribution"><?php print $link_title; ?></a>
</section>
