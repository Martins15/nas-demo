<?php
/**
 * @file
 * Local Chapters & Centers content template file.
 */
?>
<div id="upcoming-events-content-wrapper">
  <ul class="no-bullets item-margin">
    <?php foreach($locations as $location) : ?>
      <li>
		<small><?php print $location['time']; ?></small>
        <h5 class="editorial-card-title blue close-heading"><?php print $location['link']; ?></h5>
        <small><?php print $location['city'] . ', ' . $location['state']; ?></small>
        <?php if ($location['order'] == 0) print '<hr>'; ?>
      </li>
    <?php endforeach; ?>
  </ul>
</div>
