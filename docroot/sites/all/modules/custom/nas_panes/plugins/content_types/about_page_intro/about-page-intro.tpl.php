<?php

/**
 * @file
 * About Page Intro template file.
 */
?>

<?php if ($title): ?>
  <div class="row<?php print !empty($spacetop) ? ' space-top' : ''; ?><?php print !empty($spacetop) ? ' space-top' : ''; ?><?php print !empty($spacebetween) ? ' space-bottom' : ''; ?>">
    <div class="column">
      <<?php print $title_heading; ?> class="thin">
        <?php print $title; ?>
      </h2>
    </div>
  </div>
<?php endif; ?>

<div class="row <?php print !empty($spacebottom) ? $spacebottom : ''; ?> text-container<?php print !empty($contextual_links) ? ' contextual-links-region' : ''; ?><?php print !empty($spacebottom) ? $spacebottom : ''; ?>">
  <?php print $contextual_links; ?>

  <?php if (!empty($left_column)): ?>
    <div class="columns medium-6">
      <?php print $left_column; ?>
    </div>
  <?php endif; ?>

  <?php if (!empty($right_column)): ?>
    <div class="columns medium-6">
      <?php print $right_column; ?>
    </div>
  <?php endif; ?>

  <?php if (!empty($full_width_text)): ?>
    <div class="columns">
      <?php print $full_width_text; ?>
    </div>
  <?php endif; ?>
</div>
