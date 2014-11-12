<?php

/**
 * @file
 * Template implementation to display the Flyway Hero FPP layout.
 *
 * Custom variables:
 * - $links: Top links.
 * - $flyway_hero_items: Hero gallery items
 * - $blue_text_link: "Blue text link"
 * @see template_preprocess_fieldable_panels_pane()
 */
?>

<section class="category-nav strip-nav contextual-links-region">
  <?php print $contextual_links; ?>
  <div class="row">
    <div class="columns">
      <ul class="inline-list" >
        <li class="strip-nav-header"><?php print $title; ?></li>
        <?php foreach ($links as $link): ?>
        <li><?php print $link; ?></li>
        <?php endforeach; ?>
      </ul>
    </div>
  </div>
</section>
