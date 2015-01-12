<?php
/**
 * @file
 * Audubon Near You. Offices & Chapters template file.
 */
?>

<div id="audubon-near-you--office-chapter--wrapper">
  <div class="large-6 columns">
    <h2 class="title-block"><?php print t('Offices & Chapters'); ?></h2>
    <?php if (empty($items)) : ?>
      <?php if (empty($hide_empty_text)) : ?>
        <?php print t('Enter your zip code above'); ?>
      <?php endif; ?>
    <?php else : ?>
      <?php foreach ($items as $item) : ?>
        <article>
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
