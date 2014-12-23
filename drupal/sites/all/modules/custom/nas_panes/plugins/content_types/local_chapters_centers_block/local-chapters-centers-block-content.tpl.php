<?php
/**
 * @file
 * Local Chapters & Centers content template file.
 */
?>

<ul class="no-bullets item-margin">
  <?php foreach($locations as $location) : ?>
  <li>
    <h5 class="editorial-card-title blue close-heading"><?php print $location['link']; ?></h5>
    <small>(<?php print $location['subtitle']; ?>)</small>
  </li>
  <?php endforeach; ?>
</ul>
