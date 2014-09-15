<?php

/**
 * @file
 * Custom view template to display Explore Similar Birds.
 *
 * @ingroup views_templates
 */
?>

<div class="bird-card-set bg-bone-white">
  <div class="row section-header space-top">
    <div class="columns">
      <h2 class="thin"><?php print $view->display[$view->current_display]->display_options['title']; ?></h2>
    </div>
    <div class="columns">
      <ul class="section-nav inline-list">
        <li><?php print l(t('The Bird Guide'), '<front>'); ?></li>
        <li><?php print l(t('Adopt a Bird'), '<front>'); ?></li>
      </ul>
    </div>
  </div>
  <div class="row bird-card-container">
    <div class="bird-card-scroller">
    <?php foreach ($rows as $id => $row): ?>
      <div class="columns tiny-3">
        <figure class="bird-card">
          <?php print $row; ?>
        </figure>
      </div>
    <?php endforeach; ?>
    </div>
  </div>
  <div class="row indicator space-bottom">
    <div class="column">
      <p><i class="indicator-left icon-arrow-left disabled"></i>&nbsp;&nbsp;&nbsp;<i class="indicator-right icon-arrow-right"></i></p>
    </div>
  </div>
</div>