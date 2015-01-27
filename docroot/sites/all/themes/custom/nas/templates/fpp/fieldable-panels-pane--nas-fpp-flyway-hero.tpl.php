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

<div class="hero dark-gradient dark-gradient-bottom light-text bg-respond contextual-links-region">
  <?php print $contextual_links; ?>
  <div class="hero-image">
    <?php foreach ($flyway_hero_items as $delta => $hero_item): ?>
      <img class="hero-alt-img<?php print $delta === 1 ? ' current' : ''; ?>" data-point-id="<?php print $delta; ?>" src="<?php print $hero_item['background']; ?>">
    <?php endforeach; ?>
  </div>
  <div class="row">
    <div class="hero-header">
      <div class="column">
        <?php if ($blue_text_link): ?>
          <?php print $blue_text_link; ?>
        <?php endif; ?>
        <h2 class="hero-title"><?php print $title; ?></h2>
      </div>
    </div>
  </div>
  <div class="row">
    <div class="hero-card-column large-4 medium-6">
      <div class="breakout-section-box">
        <div class="flyway-minimap">
          <?php foreach ($flyway_hero_items as $delta => $hero_item): ?>
            <a href="#" data-point-id="<?php print $delta; ?>" data-point-bg="<?php print $hero_item['background']; ?>" class="flyway-minimap-point<?php print $delta === 1 ? ' current' : ''; ?>" style="<?php print $hero_item['map_coordinates'] ?>"><?php print $delta; ?></a>
          <?php endforeach; ?>
          <img src="<?php print $minimap; ?>" alt="">
        </div>
        <?php foreach ($flyway_hero_items as $delta => $hero_item): ?>
          <div class="flyway-content" data-point-id="<?php print $delta; ?>" <?php print $delta !== 1 ? 'style="display:none;' : ''; ?>>
            <?php if (!empty($hero_item['subtitle_title'])): ?>
            <a href="<?php print $hero_item['subtitle_url']; ?>" class="editorial-card-slug"><?php print $hero_item['subtitle_title']; ?></a>
            <?php endif; ?>
            <h3 class="thin editorial-card-title"><?php print $hero_item['bird_title']; ?></h3>
            <p class="serif"><em><?php print $hero_item['description']; ?> <a href="<?php print $hero_item['bird_url']; ?>">More »</a></em></p>
          </div>
        <?php endforeach; ?>
      </div>
    </div>
  </div>
</div>
<?php foreach ($flyway_hero_items as $delta => $hero_item): ?>
  <?php if (!empty($hero_item['credit'])) : ?>
    <div class="hero-attribution row flyway-hero-attribution<?php print $delta === 1 ? ' current' : ''; ?>" data-point-id="<?php print $delta; ?>">
      <p class="column"><span class="hero-attribution-text"><?php print $hero_item['credit']; ?></span></p>
    </div>
  <?php endif; ?>
<?php endforeach; ?>
