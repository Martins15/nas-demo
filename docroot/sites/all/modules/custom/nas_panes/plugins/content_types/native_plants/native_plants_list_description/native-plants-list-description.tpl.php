<?php
/**
 * @file
 * Native Plants List description template.
 */
?>
<div class="<?php print !empty($context_links) ? 'contextual-links-region' : ''; ?>">
  <?php print $context_links; ?>
  <?php if (!empty($title)): ?>
    <div class="row">
      <div class="columns large-8 large-push-2">
        <h3 class="thin"><?php print $title; ?></h3>
      </div>
    </div>
  <?php endif; ?>
  <div class="row">
    <div class="text-container columns large-8 large-push-2">
      <?php print $text; ?>
    </div>
  </div>
</div>
