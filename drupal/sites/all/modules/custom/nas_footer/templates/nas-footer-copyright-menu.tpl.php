<?php
/**
 * @file
 * Template for footer coyright menu.
 */
?>

<span class="footer-copyright-links">
  <?php foreach ($menu_tree as $menu_item) : ?>
  	<?php if ($menu_item['link']['hidden'] == FALSE) : ?>
    	<?php print l($menu_item['link']['link_title'], $menu_item['link']['link_path']); ?>
	<?php endif;?>
  <?php endforeach; ?>
</span>