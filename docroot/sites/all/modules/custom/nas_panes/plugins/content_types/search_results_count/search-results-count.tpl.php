<?php
/**
 * @file
 * Search page editorial results count pane template.
 */
?>

<div class="columns">
  <h2><?php print $title; ?></h2>
  <p class="sub-heading">
    <?php print t('Showing 1–!current of @total results', array(
        '!current' => '<span class="search-counter">' . $current_rows .'</span>',
        '@total' => $total_rows,
      )); ?>
  </p>
</div>
<div class="columns">
  <?php if ($sort_links): ?>
  <div class="section-nav inline-list filter-list">
    <span>Sort by:</span>
    <?php foreach ($sort_links as $link): ?>
      <li><?php print $link; ?></li>
    <?php endforeach; ?>
  </div>
  <?php endif; ?>
</div>