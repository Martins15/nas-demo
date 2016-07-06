<?php
/**
 * @file
 * Audubon Near You. Centers & Sanctuaries template file.
 */
?>

<div id="audubon-near-you--center-sanctuary--wrapper">
  <div class="large-4 columns">
    <h2 class="title-block"><?php print t('Centers & Sanctuaries'); ?></h2>
    <?php if (empty($items)) : ?>
      <?php if (empty($hide_empty_text) && empty($filter_active)) : ?>
        <?php print t('Select your state above'); ?>
      <?php endif; ?>

      <?php if (!empty($filter_active)) : ?>
        <?php print t('No Centers found in this location. Select your state above to look up for other location'); ?>
      <?php endif; ?>
    <?php else : ?>
      <?php foreach ($items as $item) : ?>
        <article class="node-<?php print $item['nid']; ?>">
          <h1 class="title-article"><?php print $item['title']; ?><span><?php print $item['subtitle']; ?></span></h1>
          <div class="content-article">
            <?php print $item['body']; ?>
            <?php print $item['site_link'] ?>
          </div>
        </article>
      <?php endforeach; ?>
    <?php endif; ?>
  </div>
</div>
