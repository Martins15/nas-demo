<?php
/**
 * @file
 * Static cards three columns template file.
 */
?>

<div class="row space-bottom <?php print !empty($contextual_links) ? 'contextual-links-region' : ''; ?>">
  <?php print $contextual_links; ?>
  <?php foreach ($items as $item) : ?>
    <div class="large-4 columns">
      <div class="editorial-card">
        <div class="editorial-card-photo">
          <?php print $item['image_markup']; ?>
        </div>
        <div class="editorial-card-content short">
          <?php if (!empty($item['top_link_markup'])) : ?>
            <?php print $item['top_link_markup']; ?>
          <?php endif; ?>
          <h4 class="editorial-card-title">
            <?php print $item['title_markup']; ?>
          </h4>
          <?php if (!empty($item['bottom_link_markup'])) : ?>
            <p>
              <em>
                <?php print $item['bottom_link_markup']; ?>
              </em>
            </p>
          <?php endif; ?>
        </div>
      </div>
    </div>
  <?php endforeach; ?>
</div>
