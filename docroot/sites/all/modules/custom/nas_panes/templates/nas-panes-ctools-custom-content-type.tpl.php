<?php
/**
 * @file
 * Template for custom content_type.
 */
?>
<?php if (!empty($context_links)): ?>
<div class="<?php print $classes; ?> contextual-links-region">
<?php endif; ?>
  <?php print $context_links; ?>
  <?php print $markup; ?>
<?php if (!empty($context_links)): ?>
</div>
<?php endif; ?>