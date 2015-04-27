<?php
/**
 * @file
 * Featured Frontpage (hero image variant) template file.
 *
 * Available variables:
 * - $title_link: the (sanitized) title with link.
 * - $slug_link: the (sanitized) slug link.
 * - $hero_image: rendered hero image.
 * - $contextual_links: rendered contextual links.
 * - $attribution: hero image attribution.
 */
?>

<div class="hero dark-gradient light-text">
  <div class="hero-image">
    <?php print $hero_image; ?>
  </div>
  <div class="row">
    <div class="hero-header contextual-links-region">
      <?php print $contextual_links; ?>
      <div class="column">
        <?php if (!empty($slug_link)): ?>
        <h4 class="hero-slug"><?php print $slug_link; ?></h4>
        <?php endif; ?>
        <h2 class="hero-title"><?php print $title_link; ?></h2>
      </div>
    </div>
  </div>
  <?php if ($attribution): ?>
    <div class="hero-attribution">
      <p class="column">
      <span class="hero-attribution-text">
        <?php print $attribution; ?>
      </span>
      </p>
    </div>
  <?php endif; ?>
</div>

