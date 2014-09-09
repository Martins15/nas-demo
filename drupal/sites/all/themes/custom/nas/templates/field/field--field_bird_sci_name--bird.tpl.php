<?php
/**
 * @file field.tpl.php
 * Template implementation to display the value of a field.
 */
?>
<?php foreach ($items as $delta => $item): ?>
  <?php print render($item); ?>
<?php endforeach; ?>

