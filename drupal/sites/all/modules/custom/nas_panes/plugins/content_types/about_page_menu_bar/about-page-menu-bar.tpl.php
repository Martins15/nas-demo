<?php
/**
 * @file
 * About Page Menu Bar template file.
 */
?>

<section class="category-nav strip-nav">
  <div class="row">
    <div class="columns">
      <ul class="inline-list" >
        <?php foreach ($items as $item): ?>
          <li><?php print $item; ?></li>
        <?php endforeach; ?>
      </ul>
    </div>
  </div>
</section>
