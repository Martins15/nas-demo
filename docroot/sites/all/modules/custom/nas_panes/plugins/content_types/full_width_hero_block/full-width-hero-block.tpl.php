<?php

/**
 * @file
 * Template for Full-width Hero block.
 *
 * Available variables:
 * - $title: Node title.
 * - $subtitle: Node subtitle.
 * - $category_link: Node category.
 */
?>

<!-- Hero block. Full-width, title only variant -->
<header class="article-header row article-full-width article-full-width-header">
  <div class="large-header large-centered columns">

    <?php print $category_link; ?>
    <h1><?php print $title; ?></h1>

    <?php if ($subtitle): ?>
      <p class="deck">
        <?php print $subtitle; ?>
      </p>
    <?php endif; ?>

  </div>
</header>
<!-- /Hero block. Full-width, title below variant -->
