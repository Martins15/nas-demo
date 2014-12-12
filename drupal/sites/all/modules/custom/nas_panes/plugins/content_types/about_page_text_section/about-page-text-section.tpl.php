<?php
/**
 * @file
 * About Page Text Section template file.
 */
?>

<div class="about-text-section <?php print !empty($contextual_links) ? 'contextual-links-region' : ''; ?>">
  <?php print $contextual_links; ?>
  <?php foreach ($sections as $section) : ?>
    <div class="row space-top double">
      <div class="column">
        <?php if (!empty($section['section_title'])) : ?>
          <h1 class="thin"><?php print $section['section_title']; ?></h1>
        <?php endif; ?>
      </div>
    </div>
    <div class="row text-container space-bottom">
      <?php if (!empty($section['left_column']['value'])) : ?>
        <div class="columns medium-6">
          <?php print $section['left_column']['value']; ?>
        </div>
      <?php endif; ?>

      <?php if (!empty($section['right_column']['value'])) : ?>
        <div class="columns medium-6">
          <?php print $section['right_column']['value']; ?>
        </div>
      <?php endif; ?>

      <?php if (!empty($section['full_width_text']['value'])) : ?>
        <div class="columns">
          <?php print $section['full_width_text']['value']; ?>
        </div>
      <?php endif; ?>
    </div>
  <?php endforeach; ?>
</div>
