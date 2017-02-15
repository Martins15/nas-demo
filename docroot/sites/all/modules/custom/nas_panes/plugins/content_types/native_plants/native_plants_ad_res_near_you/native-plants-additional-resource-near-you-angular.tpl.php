<?php
/**
 * @file
 * Template for the Native Plants Additional Resources near you - Angular JS.
 */
?>
<div class="row where-to-buy__section <?php print $classes; ?><?php print !empty($context_links) ? ' contextual-links-region' : ''; ?>"
     data-ng-controller="NativePlantsAdditionalResourcesController as addResourcesC">
  <?php print $context_links; ?>
  <div class="large-4 medium-6 columns">
    <h2 class="thin"><?php print $title; ?></h2>
    <?php print $description; ?>
  </div>
  <div class="large-8 medium-6 columns">
    <div class="row"
         data-ng-repeat="row in addResourcesC.rows | limitTo : addResourcesC.rowsLimit">
      <div class="large-6 medium-12 columns"
           data-ng-repeat="resource in row">
        <div class="address">
          <h4 data-ng-bind="resource.title"></h4>
          <p data-ng-bind-html="resource.address.rendered"></p>
          <p data-ng-if="resource.phone" data-ng-bind="resource.phone"></p>
          <a target="_blank" data-ng-href="{{resource.link.url}}"
             data-ng-if="resource.link.url" data-ng-bind-html="resource.link.print"></a>
        </div>
      </div>
    </div>

    <div class="row"
         data-ng-if="addResourcesC.rows.length > 1">
      <div class="large-12 medium-12 columns">
        <a class="more" href="javascript:void(0)"
           data-ng-if="addResourcesC.rowsLimit"
           data-ng-click="addResourcesC.limitToggle();"><?php print t('Show more') . ' &raquo;'; ?></a>
        <a class="more" href="javascript:void(0)"
           data-ng-if="!addResourcesC.rowsLimit"
           data-ng-click="addResourcesC.limitToggle();"><?php print t('Show less') . ' &laquo;'; ?></a>
      </div>
    </div>
  </div>
</div>
