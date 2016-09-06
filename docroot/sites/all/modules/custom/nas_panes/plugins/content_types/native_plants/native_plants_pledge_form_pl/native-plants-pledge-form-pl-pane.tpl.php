<?php
/**
 * @file
 * Template for Native Plants pledge form pane.
 */
?>
<div class="<?php print $classes; ?><?php print !empty($context_links) ? ' contextual-links-region' : ''; ?>">
  <?php print $context_links; ?>
  <div class="row">
    <div class="column large-8 large-push-2">
      <?php print $form; ?>
    </div>
  </div>
</div>
