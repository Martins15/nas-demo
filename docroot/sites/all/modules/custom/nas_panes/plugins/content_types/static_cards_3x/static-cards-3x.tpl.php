<?php

/**
 * @file
 * Static cards two columns template file.
 */
?>

<div class="row banner-set static-cards-multiple <?php print !empty($contextual_links) ? 'contextual-links-region' : ''; ?>">
  <?php print $contextual_links; ?>

  <?php foreach ($items as $item) : ?>
    <div class="large-4 columns">
      <div class="banner <?php print $item['color_mode']; ?>-bg bg-respond"
           style="background-image: url(<?php print $item['image_url']; ?>);"
           data-bg-small="<?php print $item['image_url_mobile']; ?>"
           data-bg-large="<?php print $item['image_url']; ?>">
        <?php if ($item['gradient']): ?>
          <div class="banner-gradient-overlay-horizontal"></div>
        <?php endif; ?>
        <a class="image_link" href="<?php print $item['image_link']; ?>"></a>
        <div class="banner-text full-width">
          <?php print $item['top_text']; ?>
          <h2 class="banner-title"><?php print $item['title']; ?></h2>
          <?php print $item['bottom_text'] ?>
        </div>
      </div>
    </div>
  <?php endforeach; ?>
</div>
