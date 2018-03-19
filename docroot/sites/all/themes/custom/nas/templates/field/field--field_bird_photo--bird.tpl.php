<?php

/**
 * @file
 * Template implementation to display the value of a field.
 */
?>
<?php if (!$label_hidden): ?>
  <?php print $label ?>
<?php endif; ?>
<ul>
  <?php foreach ($items as $delta => $item): ?>
    <li>
      <?php if (!empty($image_urls)): ?>
        <a class="colorbox" href="<?php print $image_urls[$delta]; ?>">
          <?php print render($item); ?>
        </a>
      <?php else: ?>
        <?php print render($item); ?>
      <?php endif; ?>
    </li>
  <?php endforeach; ?>
</ul>
