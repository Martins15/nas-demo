<?php

/**
 * @file
 * Template implementation to display the FPP layout.
 *
 * Custom variables:
 * - $birds_view: View with referenced or random entities.
 * @see template_preprocess_fieldable_panels_pane()
 */
?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print $birds_view; ?>
</div>
