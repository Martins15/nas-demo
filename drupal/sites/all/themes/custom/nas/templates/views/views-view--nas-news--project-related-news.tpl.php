<?php

/**
 * @file
 * Custom view template to display News from the Network.
 *
 * @ingroup views_templates
 */
?>
<div class="<?php print $classes; ?>">
  <div class="row space-top">
    <div class="large-8 columns">
      <h2 class="thin"><?php print $view->get_title(); ?></h2>
    </div>
  </div>
  <div class="row view-content large-8 columns">
    <?php print $rows; ?>
  </div>
  <div class="row">
    <?php if ($pager): ?>
      <?php print $pager; ?>
    <?php endif; ?>
  </div>
</div>