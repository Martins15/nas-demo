<?php
/**
 * @file
 * Static cards two columns template file.
 */
?>

<div class="row banner-set <?php print !empty($contextual_links) ? 'contextual-links-region' : ''; ?>">
  <?php print $contextual_links; ?>

  <?php foreach ($items as $item) : ?>
    <div class="large-6 columns">
      <div class="banner <?php print $item['color_mode']; ?>-bg bg-respond" style="background-image: url(<?php print $item['image_url']; ?>);" data-bg-small="<?php print $item['image_url_mobile']; ?>" data-bg-large="<?php print $item['image_url']; ?>">
        <div class="banner-text full-width">
          <?php if (!empty($item['top_link']['url']) && !empty($item['top_link']['title'])) : ?>
            <a href="<?php print $item['top_link']['url']; ?>" class="banner-slug"><?php print $item['top_link']['title']; ?></a>
          <?php endif; ?>
          <h2 class="banner-title"><?php print $item['title']; ?></h2>
          <ul class="banner-links inline-list">
            <?php if (!empty($item['bottom_link']['url']) && !empty($item['bottom_link']['title'])) : ?>
            <li><a href="<?php print $item['bottom_link']['url']; ?>"><?php print $item['bottom_link']['title']; ?></a></li>
            <?php endif; ?>
          </ul>
        </div>
      </div>
    </div>
  <?php endforeach; ?>
</div>
