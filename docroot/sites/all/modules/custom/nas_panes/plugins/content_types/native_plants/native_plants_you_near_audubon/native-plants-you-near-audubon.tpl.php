<?php
/**
 * @file
 * Template for Native Plants You Near Audubon pane.
 */
?>
<div class="row current-location<?php print !empty($context_links) ? ' contextual-links-region' : ''; ?> <?php print $classes; ?>">
  <?php print $context_links; ?>
  <div class="columns">
    <h3 class="thin">
      <span class="icon icon-marker"></span><?php print $description; ?>
    </h3>
  </div>
</div>
