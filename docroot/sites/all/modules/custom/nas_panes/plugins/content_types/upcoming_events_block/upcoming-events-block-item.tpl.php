<?php

/**
 * @file
 * Local Chapters & Centers content template file.
 */
?>
<div id="upcoming-events-content-wrapper">
  <ul class="no-bullets item-margin">
    <?php if (is_array($locations)): ?>
      <?php foreach($locations as $location) : ?>
        <li>
          <?php if ($location['order'] == 1): ?>
            <hr>
          <?php endif; ?>
          <small><?php print $location['time']; ?></small>
          <h5 class="editorial-card-title blue close-heading"><?php print $location['link']; ?></h5>
          <small><?php print $location['city'] . ', ' . $location['state']; ?></small>
        </li>
      <?php endforeach; ?>
    <?php endif; ?>
  </ul>
</div>
