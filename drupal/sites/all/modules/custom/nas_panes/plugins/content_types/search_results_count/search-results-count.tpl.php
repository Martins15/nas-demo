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
  <!--
  <div class="section-nav inline-list filter-list">
    <span>Sort by:</span>
    <li><a class="color-blue active" href="#">Relevance</a></li>
    <li><a class="color-blue" href="#">Date</a></li>
  </div>
  -->
</div>