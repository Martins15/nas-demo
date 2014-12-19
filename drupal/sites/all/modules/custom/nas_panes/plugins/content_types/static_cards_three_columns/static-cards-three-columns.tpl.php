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
          <a href="<?php print $item['image_link']; ?>"><img src="<?php print $item['image_url']; ?>" alt=""></a>
        </div>
        <div class="editorial-card-content short">
          <?php if (!empty($item['top_link']['url']) && !empty($item['top_link']['title'])) : ?>
            <a href="<?php print $item['top_link']['url']; ?>" class="editorial-card-slug"><?php print $item['top_link']['title']; ?></a>
          <?php endif; ?>
          <h4 class="editorial-card-title"><a href="<?php print $item['title']['url']; ?>"><?php print $item['title']['title']; ?></a></h4>
          <?php if (!empty($item['bottom_link']['url']) && !empty($item['bottom_link']['title'])) : ?>
            <p><em><a href="<?php print $item['bottom_link']['url']; ?>" class="editorial-card-link"><?php print $item['bottom_link']['title']; ?></a></em></p>
          <?php endif; ?>
        </div>
      </div>
    </div>
  <?php endforeach; ?>
</div>
