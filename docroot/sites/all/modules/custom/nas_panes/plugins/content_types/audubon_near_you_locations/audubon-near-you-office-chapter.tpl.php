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
      <?php if (empty($hide_empty_text) && empty($filter_active)) : ?>
        <?php print t('Select your state above'); ?>
      <?php endif; ?>

      <?php if (!empty($filter_active)) : ?>
        <?php print t('No Chapters found in this location. Select your state above to look up for other location'); ?>
      <?php endif; ?>
    <?php else : ?>
      <?php foreach ($items as $item) : ?>
        <article class="node-<?php print $item['nid']; ?>">
          <h1 class="title-article"><?php print $item['title']; ?><span><?php print $item['subtitle']; ?></span></h1>
          <div class="content-article">
            <?php print $item['body']; ?>
          </div>
          <div class="contact-name">
            <?php print $item['first_name']; ?>
            <?php print $item['last_name']; ?>
          </div>
          <div class="contact-phone">
            <?php print $item['phone']; ?>
          </div>
          <div class="contact-email">
            <?php print $item['email']; ?>
          </div>
          <div class="address">
            <?php print $item['address']['thoroughfare']; ?>
            <?php print $item['address']['postal_code']." - "; ?>
            <?php print $item['address']['locality']." - "; ?>
            <?php print $item['address']['administrative_area']." - "; ?>
            <?php print $item['address']['country']; ?>
          </div>
          <div class="site-link">
            <?php print $item['site_link'] ?>
          </div>
        </article>
      <?php endforeach; ?>
    <?php endif; ?>
  </div>
</div>
