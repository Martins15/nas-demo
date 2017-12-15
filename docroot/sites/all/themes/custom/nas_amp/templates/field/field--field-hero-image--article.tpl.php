<?php

/**
 * @file
 * Template implementation to display the value of a field.
 */
?>
<?php print render($items); ?>
<div class="caption">
  <?php print $items[0]['#item']['hero_caption']; ?>
</div>
