<?php
/**
 * @file
 * About Page Success Section template file.
 */
?>

<section class="breakout-section">
  <div class="row">
    <div class="breakout-section-side column large-6">
      <div class="breakout-section-box collapse-minimal text-container <?php print !empty($contextual_links) ? 'contextual-links-region' : ''; ?>">
        <?php print $contextual_links; ?>
        <?php if (!empty($title)) : ?>
          <h2 class="thin"><?php print $title; ?></h2>
        <?php endif; ?>
        <?php print $text; ?>
      </div>
    </div>
  </div>
  <div class="breakout-section-hero tall" style="background-image: url(<?php print $image; ?>)">
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
</section>
