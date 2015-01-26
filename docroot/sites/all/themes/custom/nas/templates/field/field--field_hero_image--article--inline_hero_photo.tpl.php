<?php

/**
 * @file
 * Template implementation to display the value of a field.
 */
?>
<?php
  $item = array_shift($items);
  $caption = render($item['field_file_caption']);
  $credits = render($item['field_file_credit']);
?>

<?php print render($item); ?>
<figcaption class="article-aside-caption">
  <?php print $caption . '&nbsp;' . $credits; ?>
</figcaption>
