<?php

/**
 * @file
 * Custom view template to display Bird in the News.
 *
 * @ingroup views_templates
 */
?>
<div class="row">
  <?php foreach ($rows as $id => $row): ?>
  <div class="large-4 columns">
    <div class="editorial-card collapse-minimal">
      <?php print $row; ?>
    </div>
  </div>
  <?php endforeach; ?>
</div>
