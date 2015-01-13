<?php

/**
 * @file
 * Template implementation to display the value of a field.
 */
?>
<?php if (!$label_hidden): ?>
  <?php print $label ?>
<?php endif; ?>
<?php foreach ($items as $delta => $item): ?>
  <?php print render($item); ?>
<?php endforeach; ?>
