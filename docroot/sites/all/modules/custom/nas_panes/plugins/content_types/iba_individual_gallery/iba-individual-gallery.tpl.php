<?php
/**
 * @file
 * IBA Photo GAllery.
 *
 * Available variables:
 * - $images: (array) contains images from referenced to IBA Birds.
 */
?>
<section class="iba-photo-gallery">
	<h4><i class="icon-camera"></i> Photo Gallery</h4>
	<div class="thumb-strip clearfix">
	  <a class="thumb-strip-prev"><i class="icon-chevron-left"></i></a>
	  <div class="thumb-strip-wrapper">
			<ul>
			<?php foreach ($images as $image): ?>
	  		<li><?php print $image; ?></li>
			<?php endforeach; ?>
			</ul>
		</div>
	  <a class="thumb-strip-next"><i class="icon-chevron-right"></i></a>
	</div>
</section>
