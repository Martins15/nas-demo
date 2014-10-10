<?php

/**
 * @file
 * Template implementation to display the value of a field.
 */
?>
<?php foreach ($items as $delta => $item): ?>
  <p class="deck">
    <?php print render($item); ?>
  </p>
<?php endforeach; ?>