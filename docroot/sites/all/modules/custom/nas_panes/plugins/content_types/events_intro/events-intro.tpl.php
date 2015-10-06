<?php
/**
 * @file
 * Event Page Intro template file.
 */
?>
<p class="deck"><?php print $date_city_province; ?></p>
<?php if (!empty($featured_image)): ?>
<div class="featured-image">
  <?php print $featured_image; ?>
</div>
<?php endif; ?>
<?php if (!empty($address)): ?>
<div class="location-details">
  <h4><?php print t('Location Details'); ?></h4>
  <?php if (!empty($location_name)): ?>
    <p class="additional"><?php print $location_name; ?></p>
  <?php endif; ?>
  <p><?php print $address; ?></p>
</div>
<?php endif; ?>
