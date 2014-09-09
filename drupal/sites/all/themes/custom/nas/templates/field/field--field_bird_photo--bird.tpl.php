<?php
/**
 * @file field.tpl.php
 * Template implementation to display the value of a field.
 */
?>
<?php if (!$label_hidden): ?>
  <?php print $label ?>
<?php endif; ?>
<ul>
<?php foreach ($items as $delta => $item): ?>
  <li><?php print render($item); ?></li>
<?php endforeach; ?>
</ul>
