<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <div class="magazine-issue-year columns">
    <h2><?php print $title; ?></h2>
  </div>
<?php endif; ?>
<div class="magazin-issues-list">
<?php foreach ($rows as $id => $row): ?>
  <div class="large-4 medium-6 small-6 tiny-6 columns magazine-issue<?php if ($classes_array[$id]) { print ' ' . $classes_array[$id];} ?>" >
    <?php print $row; ?>
  </div>
<?php endforeach; ?>
</div>
