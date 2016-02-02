<?php
/**
 * @file
 * Featured Frontpage template file.
 *
 * Available variables:
 * - $title_link: the (sanitized) title with link.
 * - $blue_text_link: the (sanitized) blue text above the title with link.
 * - $image_path: path to the hero image of the bird.
 * - $image_path_mobile: path to the hero image of the bird mobile image style.
 * - $image_string: sanitized caption + credits of the hero image.
 * - $contextual_links: rendered contextual links.
 */
?>
<div class="curtain-content curtain-package <?php print $curtain_class; ?>">
  <div class="row space-bottom">
    <div class="column medium-6 curtain-featured contextual-links-region">
      <?php print $contextual_links; ?>
      <div class="hero-header">
        <?php print $slug_link; ?>
        <h2 class="hero-title"><?php print $title_link; ?></h2>
        <div class="hero-text">
          <div class="hero-paragraph curtain-summary"><?php print $summary; ?></div>
        </div>
        <?php print $action_link; ?>
      </div>
    </div>
  </div>
  <div class="row space-bottom" data-equalizer>
    <?php foreach ($stories as $story): ?>
      <div class="editorial-card-list-item column medium-4" data-equalizer-watch>
        <?php if ($story['slug_link']): ?>
          <small><?php print $story['slug_link']; ?></small>
        <?php endif; ?>
        <h4 class="close-heading"><?php print $story['title_link']; ?></h4>
      </div>
    <?php endforeach; ?>
  </div>

  <?php if ($attribution_title || $attribution_credit): ?>
  <div class="row">
    <div class="column">
      <div class="curtain-attribution">
        <?php if ($attribution_title): ?>
          <p class="title"><?php print $attribution_title; ?></p>
        <?php endif; ?>
        <?php if ($attribution_credit): ?>
          <p class="credit"><?php print $attribution_credit; ?></p>
        <?php endif; ?>
      </div>
    </div>
  </div>
  <?php endif; ?>
</div>
<a href="#" class="curtain-arrow"></a>
