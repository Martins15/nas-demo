<?php
/**
 * @file
 * Search form template.
 */

?>

<ul class="aid-filter">
  <li>
    <a class="toggler" href="#"><?php print $subject; ?></a>
    <ul class="primary-sub-nav">
      <?php foreach ($items as $item): ?>
      <li class="primary-sub-nav-item"><?php print $item['data']; ?></a></li>
      <?php endforeach; ?>
    </ul>
  </li>
</ul>