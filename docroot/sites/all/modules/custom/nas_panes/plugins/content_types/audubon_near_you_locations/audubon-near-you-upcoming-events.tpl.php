<?php
/**
 * @file
 * Audubon Near You. Centers & Sanctuaries template file.
 */
?>

<div id="audubon-near-you--upcoming-events--wrapper">
  <div class="large-4 columns">
    <h2 class="title-block"><?php print t('Upcoming Events'); ?></h2>
    <?php if (empty($items)) : ?>
      <?php if (empty($hide_empty_text) && empty($filter_active)) : ?>
        <?php print t('Select your state above'); ?>
      <?php endif; ?>

      <?php if (!empty($filter_active)) : ?>
        <?php print t('There are no events available in your state currently. Check in with your local chapter or center for more info.'); ?>
      <?php endif; ?>
    <?php else : ?>
      <?php foreach ($items as $item) : ?>
        <article class="node-<?php print $item['nid']; ?>">
          <div class="title-prefix"><?php print $item['time']; ?></div>
          <h1 class="title-article">
            <?php print $item['title']; ?>
            <span><?php print $item['location_name'] . ' (' . $item['city'] . ', ' . $item['state'] . ')'; ?></span>
          </h1>
          <div class="content-article">
            <?php print $item['body']; ?>
            <?php print $item['details_link'] ?>
          </div>
        </article>
      <?php endforeach; ?>
    <?php endif; ?>
  </div>
</div>
