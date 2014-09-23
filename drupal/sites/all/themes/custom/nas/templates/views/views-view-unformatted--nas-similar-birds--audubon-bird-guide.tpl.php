<?php

/**
 * @file
 * Custom view template to display Explore Similar Birds.
 *
 * @ingroup views_templates
 */
?>

<div class="row section-header">
  <div class="columns">
    <h2 class="thin"><?php print $view->display[$view->current_display]->display_options['title']; ?></h2>
  </div>
  <div class="columns">
    <ul class="section-nav inline-list">
      <li class="hide-for-small hide-for-tiny"><?php print l(t('Explore Our Bird Guide'), 'bird-guide'); ?></li>
      <!-- (Design Change) First phase will not have a “Identify a Bird” section/link. -->
      <!-- <li><?php //print l(t('Identify a Bird'), ''); ?></li> -->
      <li><?php print l(t('Adopt a Bird'), '<front>',  array('attributes' => array('class' => array('cta')))); ?></li>
    </ul>
  </div>
</div>
<div class="bird-card-set">
  <div class="row">
    <?php foreach ($rows as $id => $row): ?>
      <div class="columns tiny-3">
      <?php print $row; ?>
      </div>
    <?php endforeach; ?>
  </div>
</div>
