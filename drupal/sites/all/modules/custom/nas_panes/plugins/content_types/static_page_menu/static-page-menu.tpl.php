<?php
/**
 * @file
 * Template to custom pane static_page_menu.
 *
 * Available variables:
 *  $title - pane's title.
 *  $items - array of menu items.
 */
?>

<section class="category-nav strip-nav without-border">
  <div class="row">
    <div class="columns">
      <ul class="inline-list" >
        <?php foreach ($items as $item): ?>
          <li><?php print $item; ?></li>
        <?php endforeach; ?>
      </ul>
    </div>
  </div>
</section>
