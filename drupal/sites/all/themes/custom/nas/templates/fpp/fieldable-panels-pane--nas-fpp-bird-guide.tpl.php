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
<div class="bird-card-set"<?php print $attributes; ?>>
  <div class="row bird-card-container">
    <div class="bird-card-scroller">
      <?php print $fields; ?>
    </div>
  </div>
  <div class="row indicator">
    <div class="column">
      <p><i class="indicator-left icon-arrow-left disabled"></i>&nbsp;&nbsp;&nbsp;<i class="indicator-right icon-arrow-right"></i></p>
    </div>
  </div>
</div>
