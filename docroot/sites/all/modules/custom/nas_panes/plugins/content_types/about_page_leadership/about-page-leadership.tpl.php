<?php
/**
 * @file
 * About Page Leadership template file.
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
  <div class="columns">
    <?php print $full_width_text; ?>
  </div>
</div>
