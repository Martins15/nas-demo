<?php
/**
 * @file
 * Our Leadership list template file.
 */
?>

<div class="row space-top<?php if (!empty($contextual_links)): ?> contextual-links-region<?php endif; ?>" data-equalizer>
  <?php print $contextual_links; ?>
  <div class="column">
    <h2 class="thin"><?php print $title; ?></h2>
  </div>
  <?php foreach ($items as $item): ?>
    <?php print $item; ?>
  <?php endforeach; ?>
</div>
