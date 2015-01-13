<?php
/**
 * @file
 * Template for Gray block with title formatter.
 *
 * Available variables:
 * - $title: the (sanitized) title from formatter settings.
 * - $block_text: sanitized field text.
 */
?>
<div class="page-summary bottom-line">
  <h4 class="page-summary-title"><?php print $title; ?></h4>
  <p class="page-summary-body">
    <?php print $block_text; ?>
  </p>
</div>
