<?php
/**
 * @file
 * List preview template.
 */
?>
<div class="row grey-pane">
  <div class="column large-4">
    <h4 class="thin"><?php print format_plural($count, 'Your list of @count plant is on its way.', 'Your list of @count plants is on its way.'); ?></h4>
    <?php print $permalink; ?>
  </div>
  <div class="column large-8 hide-for-small hide-for-tiny hide-for-medium">
    <div class="grey-pane--list-items">
      <?php print $list; ?>
    </div>
  </div>
</div>
