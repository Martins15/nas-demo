<?php
/**
 * @file
 * Event Page Registration block template file.
 */
?>
<div class="events-registration-block clearfix">
  <div class="column">
    <?php print $image;?>
    <h2 class="thin"><?php print $title; ?></h2>
    <p><?php print $date_city_province; ?></p>
    <div class="reg-notes"><?php print $reg_notes; ?></div>
    <?php print $button; ?>
  </div>
</div>
