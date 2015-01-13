<?php

/**
 * @file
 * Custom view template to display News from the Network.
 *
 * @ingroup views_templates
 */
?>

<div class="row section-header space-top">
  <div class="column">
    <h2 class="thin"><?php print $view->display[$view->current_display]->display_title; ?></h2>
  </div>
  <div class="column">
    <ul class="inline-list section-nav">
      <li><?php print l(t('Find the Audubon Chapter Near You »'), ''); ?></a></li>
    </ul>
  </div>
</div>
<div class="row space-bottom">
  <?php foreach ($rows as $id => $row): ?>
  <div class="columns large-3">
    <?php print $row; ?>
  </div>
  <?php endforeach; ?>
</div>
