<?php

/**
 * @file
 * Custom view template to display more headines.
 *
 * @ingroup views_templates
 */
?>
<div class="editorial-card <?php print $classes; ?>">
  <?php print render($title_suffix); ?>
  <?php print $rows; ?>
</div>
