<?php

/**
 * @file
 * Template implementation to display the FPP layout.
 *
 * Custom variables:
 * - $links: Top links.
 * @see template_preprocess_fieldable_panels_pane()
 */
?>
<div class="row section-header">
  <div class="columns">
    <h2 class="thin"><?php print $title; ?></h2>
  </div>
  <div class="columns">
    <?php print $links; ?>
  </div>
</div>
<div class="bird-card-set <?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="row">
    <?php print $fields; ?>
  </div>
</div>
