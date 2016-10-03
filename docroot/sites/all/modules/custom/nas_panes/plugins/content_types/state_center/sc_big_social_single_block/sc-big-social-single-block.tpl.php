<?php
/**
 * @file
 * Big social single block template file.
 *
 * Available variables:
 * - $icon_type: Social icon type.
 * - $url: Social icon url.
 * - $text: Social icon text.
 * - $space_top: Flag indicating to add additional top padding.
 * - $space_bottom: Flag indicating to add additional bottom padding.
 */
?>
<div class="row<?php print $space_top ? ' space-top' : ''; ?><?php print $space_bottom ? ' space-bottom' : ''; ?>">
  <div class="social-bar">
    <a class="social-bar-link icon-<?php print $icon_type; ?>" href="<?php print $url; ?>">
      <?php print $text; ?>
    </a>
  </div>
</div>
