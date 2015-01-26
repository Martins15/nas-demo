<?php

/**
 * @file
 * Template implementation to display the value of a field.
 */
?>
<?php if (!$label_hidden): ?>
  <h5><?php print $label ?></h5>
<?php endif; ?>
<?php foreach ($items as $delta => $item): ?>
  <p><?php print render($item); ?></p>
<?php endforeach; ?>
