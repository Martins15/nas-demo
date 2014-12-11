<?php
/**
 * @file
 * About Page Intro template file.
 */
?>

<div class="row">
  <div class="column">
    <h2 class="thin">
      <?php print $title; ?>
    </h2>
  </div>
</div>
<div class="row text-container <?php print !empty($contextual_links) ? 'contextual-links-region' : ''; ?>">
  <?php print $contextual_links; ?>
  <div class="columns medium-6">
    <?php print $left_column; ?>
  </div>
  <div class="columns medium-6">
    <?php print $right_column; ?>
  </div>
</div>
