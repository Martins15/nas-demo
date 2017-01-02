<?php
/**
 * @file
 * Template for custom pane progress bar.
 *
 * Available variables:
 * - $title: Pane's title.
 * - $starting_point: A starting point number.
 * - $current_status: A current status number.
 * - $goal_number: A goal number.
 * - $percentage: Percentage value.
 * - $label: An optional label for current status.
 */
?>

<div class="progress-bar-wrapper">
  <?php if ($title): ?>
    <div class="row section-header">
      <div class="column">
        <h2 class="thin"><?php print $title; ?></h2>
      </div>
    </div>
  <?php endif; ?>
  <div class="row space-bottom">
    <div class="column">
      <div class="progress-bar-content">
        <div class="progress" style="width:<?php print $percentage; ?>%">
          <span class="progress-label">
            <span class="progress-start"><?php print $starting_point; ?></span>
            <span class="progress-current"><?php print $label; ?></span>
          </span>
        </div>
        <span class="progress-finish"><?php print $goal_number; ?></span>
      </div>
    </div>
  </div>
</div>
