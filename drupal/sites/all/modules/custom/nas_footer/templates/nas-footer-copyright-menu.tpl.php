<?php
/**
 * @file
 * Template for footer coyright menu.
 */
?>


<span class="footer-copyright-links">
  <?php foreach ($menu_tree as $menu_item) : ?>
    <?php print l($menu_item['link']['link_title'], $menu_item['link']['link_path']); ?>
  <?php endforeach; ?>
</span>