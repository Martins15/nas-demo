<?php
/**
 * @file
 * Template implementation to display the value of a field.
 */
?>
<?php if (!$label_hidden): ?>
  <h4 class="close-heading"><?php print $label ?></h4>
<?php endif; ?>
<?php foreach ($items as $delta => $item): ?>
  <?php print render($item); ?>
<?php endforeach; ?>
