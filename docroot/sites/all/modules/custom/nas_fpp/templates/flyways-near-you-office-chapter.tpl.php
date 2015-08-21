<?php
/**
 * @file
 * Audubon Near You. Offices & Chapters template file.
 */
?>

<h4 class="editorial-card-title blue"><a href="audubon-near-you"><?php print t('Audubon Near You'); ?></a></h4>
<?php foreach ($items as $item) : ?>
  <div class="editorial-card-list-item">
    <h5 class="editorial-card-title no-margin">
      <?php if ($item['site_address'] != null ): ?>
        <a href="<?php print $item['site_address']; ?>">
        <?php print $item['title']; ?>
          <small class="serif">
            <em><?php print $item['subtitle']; ?></em>
          </small>
         </a>
      <?php else: ?>
        <?php print $item['title']; ?>
        <small class="serif">
          <em><?php print $item['subtitle']; ?></em>
        </small>
       <?php endif; ?>
    </h5>
  </div>
<?php endforeach; ?>
