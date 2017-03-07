<?php

/**
 * @file
 * About Page Map template file.
 *
 * Available variables:
 * - $title: Pane title.
 * - $type: Type of code.
 * - $code: Embed code.
 * - $space_top: Flag indicating to add additional top padding.
 * - $space_bottom: Flag indicating to add additional bottom padding.
 */
?>
<div class="embed-code<?php print $space_top ? ' space-top' : ''; ?><?php print $space_bottom ? ' space-bottom' : ''; ?>">
  <?php if (!empty($title)) : ?>
    <div class="row">
      <div class="column">
        <h2 class="thin centered"><?php print $title; ?></h2>
      </div>
    </div>
  <?php endif; ?>
  <div class="inline-map">
    <div class="inline-map-canvas"<?php print $height ? ' style="height: ' . $height . '; min-height: ' . $height . ';"' : ''; ?>>
      <?php if ($type == 'map'): ?>
        <div class="inline-map-mask"></div>
      <?php endif; ?>
      <?php print $code; ?>
    </div>
  </div>
</div>
