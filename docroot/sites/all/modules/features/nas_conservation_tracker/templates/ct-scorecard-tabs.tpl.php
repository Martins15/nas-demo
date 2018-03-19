<?php
/**
 * TPL file for CT content type.
 */
?>
<div class="ct-scorecard-tabs">
    <div class="ct-scorecard-tabs__help">
  <div class="row">
    <?php foreach ($menu_tree as $item): ?>
     <span class="link-wrapper"> <?php print $item['markup']; ?></span>
      <?php if (isset($item['children'])): ?>
        <div class="link-wrapper menu-has-children">
          <?php print $item['children'][0]['markup']; ?>
          <ul class="custom-dropdown">
          <?php foreach ($item['children'] as $child): ?>
            <li><?php print $child['markup']; ?></li>
          <?php endforeach; ?>
          </ul>
        </div>
      <?php endif; ?>
    <?php endforeach; ?>
  </div>
    </div>
</div>
