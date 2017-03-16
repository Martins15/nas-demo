<?php

/**
 * @file
 * Big social owl block template file.
 *
 * Available variables:
 * - $left_icon_type: Left social icon type.
 * - $left_url: Left social icon url.
 * - $left_text: Left social icon text.
 * - $right_icon_type: Right social icon type.
 * - $right_url: Right social icon url.
 * - $right_text: Right social icon text.
 * - $image_src: Path to image.
 * - $space_top: Flag indicating to add additional top padding.
 * - $space_bottom: Flag indicating to add additional bottom padding.
 */
?>
<style type="text/css">
  .social-bar.double:after {
    background-image: url('<?php print $image_src; ?>');
  }
</style>
<div class="row<?php print $space_top ? ' space-top' : ''; ?><?php print $space_bottom ? ' space-bottom' : ''; ?>">
  <div class="social-bar double">
    <div class="row">
      <div class="columns medium-6 large-4">
        <a class="social-bar-link icon-<?php print $left_icon_type; ?>" href="<?php print $left_url; ?>">
          <?php print $left_text; ?>
        </a>
      </div>
      <div class="columns medium-6 large-4 large-offset-4">
        <a class="social-bar-link icon-<?php print $right_icon_type; ?>" href="<?php print $right_url; ?>">
          <?php print $right_text; ?>
        </a>
      </div>
    </div>
  </div>
</div>
