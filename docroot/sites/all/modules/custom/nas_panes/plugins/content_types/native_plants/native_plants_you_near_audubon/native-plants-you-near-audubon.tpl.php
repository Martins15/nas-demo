<?php

/**
 * @file
 * Template for Native Plants You Near Audubon pane.
 */
?>
<div class="row current-location<?php print !empty($context_links) ? ' contextual-links-region' : ''; ?> <?php print $classes; ?>"
     data-ng-controller="NativePlantsResourcesController as resourceC">
  <div class="current-location-loading animate-results-loading data-ng-hide" data-ng-show="!resourceC.storage.data_loaded">
    <div class="svg-throbber"></div>
    <h3 class="thin"><?php print t('Your results are loading...'); ?></h3>
  </div>
  <div class="ng-hide animate-results-loading" data-ng-show="resourceC.storage.data_loaded && resourceC.storage.data.resources.length">
    <?php print $context_links; ?>
    <div class="columns" data-ng-repeat="resource in resourceC.storage.data.resources | limitTo : 1">
      <h3 class="thin">
        <span class="icon icon-marker"></span><?php print $description; ?>
      </h3>
    </div>
  </div>
</div>
