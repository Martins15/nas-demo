<?php
/**
 * TPL file for CT content type.
 */
?>
<div class="ct-scorecard-tabs">
    <div class="row">
      <?php foreach ($menu_tree as $item): ?>
        <span class="current-title"><?php print $item['markup']; ?></span>
        <?php if (isset($item['children'])): ?>
          <?php foreach ($item['children'] as $child): ?>
            <?php print $child['markup']; ?>
          <?php endforeach; ?>
        <?php endif; ?>
      <?php endforeach; ?>
    </div>
</div>
