<?php

/**
 * @file
 * Template for Full-width Hero block.
 *
 * Available variables:
 * - $title: Node title.
 * - $subtitle: Node subtitle.
 * - $category_link: Node category.
 * - $hero_image: Hero image from Node.
 * - $caption: Caption from Node.
 */
?>

<!-- Hero block. Full-width, title overlay variant -->
<?php if ($hero_image): ?>
  <div class="hero <?php print $color_mode_gradient; ?>-gradient <?php print $color_mode_text; ?>-text expand">
    <div class="hero-image">
      <?php print $hero_image; ?>
    </div>
    <div class="row">
      <div class="hero-header hide-for-medium hide-for-small hide-for-tiny">
        <div class="columns large-10 large-centered">
          <?php print $category_link; ?>
          <h2 class="hero-title"><?php print $title; ?></h2>
          <?php if ($subtitle): ?>
            <p class="hero-blurb">
              <?php print $subtitle; ?>
            </p>
          <?php endif; ?>
        </div>
      </div>
    </div>
  </div>
<?php endif; ?>

<?php if ($caption): ?>
  <div class="hero-caption">
    <div class="row">
      <div class="caption large-10 large-centered columns">
        <p>
          <?php print $caption; ?>
        </p>
      </div>
    </div>
  </div>
<?php endif; ?>

<header class="article-header row article-full-width article-full-width-header hide-for-large hide-for-xlarge">
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
<!-- /Hero block. Full-width, title overlay variant -->