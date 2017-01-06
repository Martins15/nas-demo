<?php

/**
 * @file
 * Custom view template to display News from the Network.
 *
 * @ingroup views_templates
 */
?>

<div class="row editorial-grid-column space-bottom">
  <?php foreach ($rows as $id => $row): ?>
    <?php print $row; ?>
  <?php endforeach; ?>
</div>
