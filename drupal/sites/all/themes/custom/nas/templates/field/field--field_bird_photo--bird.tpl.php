<?php

/**
 * @file field.tpl.php
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
