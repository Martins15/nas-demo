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
 *  $original_image_path - path to download full resolution image.
 *  $show_download_link - (boll) indicates if user already subscribed.
 *  $subscribe_link - link to popup with subscribe form.
 */
?>

<section class="bird-guide-section right-col boa-plate-illustration center">
  <img src="<?php print $image_thumbnail; ?>" /><div class="clearfix"></div>
  <a href="<?php print $lightbox_image_path; ?>" class="see-full-plate lightboxzoom" ><i class="icon-magnifier"></i> <?php print t('See full plate'); ?></a><div class="clearfix"></div>
  <div class="download-link">
	  <?php if ($show_download_link): ?>
	  <a href="<?php print $original_image_path; ?>" class="illustration-attribution" target="blank"><?php print t('Download high-resolution file'); ?></a>
	  <?php else: ?>
	  <?php print $subscribe_link; ?>
	  <?php endif; ?>
  </div>
  <div class="clearfix"></div>
  <a href="<?php print $link_url; ?>" class="illustration-attribution"><?php print $link_title; ?></a>
</section>
