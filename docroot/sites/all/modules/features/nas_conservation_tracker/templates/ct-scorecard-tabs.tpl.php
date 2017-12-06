<?php
/**
 * TPL file for CT content type.
 */
?>
<div class="ct-scorecard-tabs">
  <?php foreach ($menu_tree as $item): ?>
    <?php print $item['markup']; ?>
    <?php foreach ($item['children'] as $child): ?>
      <?php print $child; ?>
    <?php endforeach; ?>
  <?php endforeach; ?>
  <?php foreach ($tabs as $tab): ?>
    <?php print $tab; ?>
  <?php endforeach; ?>
</div>
