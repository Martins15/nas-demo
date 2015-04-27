<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div class="columns boa-bird-card-set bg-boa-bejge">
  <?php if (!empty($title)): ?>
  <div class="row section-header space-top">
    <div class="column">
      <h2 class="thin boa-family-set-title"><?php print $title; ?></h2>
    </div>
  </div>
  <?php endif; ?>
  <div class="row boa-bird-card-container">
    <?php foreach ($rows as $row): ?>
      <?php print $row; ?>
    <?php endforeach; ?>
  </div>
</div>
