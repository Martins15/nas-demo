<?php
/**
 * @file
 * Template implementation to display the value of a field.
 */
?>

<div class="field-name-field-bird-audio"<?php print $content_attributes; ?>>
  <?php foreach ($items as $delta => $item): ?>
    <?php print render($item); ?>
  <?php endforeach; ?>
</div>
