<?php
/**
 * @file
 * Featured Bird template file.
 *
 * Available variables:
 * - $contextual_links: contextual links.
 * - $column[1-4]: array with title and text of the column.
 */
?>
<div class="row space-top text-container contextual-links-region">
  <?php print $contextual_links; ?>
  <?php for ($i = 1; $i <=3; $i++): ?>
  <div class="medium-4 columns">
    <h3 class=""><?php print $column[$i]['title']; ?></h3>
    <p><?php print $column[$i]['text']; ?></p>
  </div>
  <?php endfor; ?>
</div>
