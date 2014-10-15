<?php

/**
 * @file
 * Template implementation to display the value of a field.
 */
?>
<?php foreach ($items as $delta => $item): ?>
  <p class="hero-blurb">
    <?php print render($item); ?>
  </p>
<?php endforeach; ?>