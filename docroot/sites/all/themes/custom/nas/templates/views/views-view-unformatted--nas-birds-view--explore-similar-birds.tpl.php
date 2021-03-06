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
      <h2 class="thin"><?php print t($view->display[$view->current_display]->display_options['title']); ?></h2>
    </div>
    <div class="columns">
      <ul class="section-nav inline-list">
        <li class="first"><?php print l(t('The Bird Guide'), 'bird-guide'); ?></li>
        <li class="last"><a class="cta" href="https://secure.audubon.org/site/SPageNavigator/2014_Adoption_Catalog_Homepage.html"><?php print t('Adopt a Bird'); ?></a></li>
      </ul>
    </div>
  </div>
  <div class="row bird-card-container">
    <div class="owl-carousel">
    <?php foreach ($rows as $id => $row): ?>
      <?php print $row; ?>
    <?php endforeach; ?>
    </div>
  </div>
</div>
