<?php

/**
 * @file
 * This template is used to print a single grouping in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $grouping: The grouping instruction.
 * - $grouping_level: Integer indicating the hierarchical level of the grouping.
 * - $rows: The rows contained in this grouping.
 * - $title: The title of this grouping.
 * - $content: The processed content output that will normally be used.
 */
?>
<div class="boa-item columns tiny-6 medium-4 large-3 bg-boa-bejge views-row">
  <div class="row section-header space-top">
    <div class="column">
      <h2 class="thin boa-family-set-title"><?php print $title; ?></h2>
    </div>
  </div>
  <div class="boa-bird-card-container clearfix">
    <?php print $content; ?>
  </div>
</div>
