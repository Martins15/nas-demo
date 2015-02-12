<?php

/**
 * @file
 * Template implementation to display the value of a field.
 */
?>
<?php
  $item = array_shift($items);
?>

<?php print render($item); ?>
<?php if (!empty($item['#attributions'])): ?>
<figcaption class="article-aside-caption">
  <?php print $item['#attributions']; ?>
</figcaption>
<?php endif; ?>