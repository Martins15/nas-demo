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
  <div class="columns tiny-3">
    <?php print render($item); ?>
  </div>
<?php endforeach; ?>
