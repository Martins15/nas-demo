<?php
/**
 * @file
 * Template for the Native Plants Nurseries near you - Angular JS.
 */
?>
<div class="row where-to-buy__section <?php print $classes; ?><?php print !empty($context_links) ? ' contextual-links-region' : ''; ?>"
     data-ng-controller="NativePlantsNurseriesController as nurseriesC"
     data-online="<?php print $online ? 'online' : 'offline'; ?>"
     data-ng-if="tabsC.storage.data.nurseries.<?php print $online ? 'online' : 'offline'; ?>.length">
  <?php print $context_links; ?>
  <div class="large-4 medium-6 columns">
    <h2 class="thin"><?php print $title; ?></h2>
    <?php print $description; ?>
  </div>
  <div class="large-8 medium-6 columns">
    <div class="row"
         data-ng-repeat="row in nurseriesC.rows | limitTo : nurseriesC.rowsLimit">
      <div class="large-4 medium-12 columns"
           data-ng-repeat="nursery in row">
        <div class="address">
          <h4 data-ng-bind="nursery.title"></h4>
          <p data-ng-bind-html="nursery.address.rendered"></p>
          <p data-ng-if="nursery.phone" data-ng-bind="nursery.phone"></p>
          <a target="_blank" data-ng-href="{{nursery.link.url}}"
             data-ng-if="nursery.link.url" data-ng-bind-html="nursery.link.print"></a>
        </div>
      </div>
    </div>

    <div class="row"
         data-ng-if="nurseriesC.rows.length > 3">
      <div class="large-12 medium-12 columns">
        <a class="more" href="#"
           data-ng-if="nurseriesC.rowsLimit"
           data-ng-click="nurseriesC.limitToggle();"><?php print t('Show more') . ' &raquo;'; ?></a>
        <a class="more" href="#"
           data-ng-if="!nurseriesC.rowsLimit"
           data-ng-click="nurseriesC.limitToggle();"><?php print t('Show less') . ' &laquo;'; ?></a>
      </div>
    </div>
  </div>
</div>
