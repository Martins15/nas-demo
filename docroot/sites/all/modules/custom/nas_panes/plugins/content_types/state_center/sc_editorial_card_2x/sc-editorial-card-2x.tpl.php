<?php
/**
 * @file
 * Editorial cards two columns template file.
 */
?>

<div class="row banner-set">
  <?php foreach ($items as $item) : ?>
    <div class="large-6 columns">
      <div<?php print $item['wrap_attr']; ?>>
        <?php if ($item['gradient']): ?>
          <div class="banner-gradient-overlay-horizontal"></div>
        <?php endif; ?>
        <div class="banner-text full-width">
          <?php print $item['top_link_markup']; ?>
          <h2 class="banner-title"><?php print $item['title_link']; ?></h2>
          <ul class="banner-links inline-list">
            <?php if (!empty($item['bottom_link_markup'])) : ?>
              <li><?php print $item['bottom_link_markup'] ?></li>
            <?php endif; ?>
          </ul>
        </div>
      </div>
    </div>
  <?php endforeach; ?>
</div>
