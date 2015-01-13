<?php
/**
 * @file
 * Template implementation to display the value of a field.
 */
?>
<?php foreach ($items as $delta => $item): ?>
  <span class="hero-slug">
    <?php print render($item); ?>
  </span>
<?php endforeach; ?>