<?php
/**
 * @file
 * Search page editorial results count pane template.
 */
?>

<div class="columns">
  <h2>Articles</h2>
  <?php if ($total_rows): ?>
    <p class="sub-heading">Showing 1–<span class="search-counter"><?php print $current_rows; ?></span> of <?php print $total_rows; ?> results</p>
  <?php else: ?>
    <p class="sub-heading">No content was found to match your search. Try modifying your search criteria and try again.</p>
  <?php endif; ?>
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