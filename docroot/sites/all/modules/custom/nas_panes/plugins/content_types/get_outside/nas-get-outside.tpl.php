<?php
/**
 * @file
 * Featured Bird template file.
 *
 * Available variables:
 * - $image_path: path to the hero image.
 * - $contextual_links: rendered contextual links.
 * - $color_classes: color classes for text.
 * - $text_array: array of titles and texts.
 */
?>

<div class="breakout-section no-hero contextual-links-region" style="background-image: url(<?php print $image_path; ?>); background-color: #444444">
  <?php print $contextual_links; ?>
  <div class="breakout-section-content <?php print $color_classes; ?>">
    <div class="row space-top space-bottom double">
      <div class="columns large-5 text-container">
        <h1 class="thin"><?php print $title; ?></h1>
        <br>
        <?php foreach ($text_array as $value) : ?>
        <h2 class="thin close-heading"><?php print $value['title']; ?></h2>
        <?php print $value['text']['value']; ?>
        <?php endforeach; ?>
      </div>
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
