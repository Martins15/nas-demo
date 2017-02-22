<?php
/**
 * @file
 * Native Plants Audubon near you template - Angular JS.
 */
?>
<div class="native-plants-audubon-near-you connect-audubon-near-you row<?php print !empty($context_links) ? ' contextual-links-region' : ''; ?>"
     data-ng-controller="NativePlantsResourcesController as resourcesC">
  <?php print $context_links; ?>
  <div class=" vertical-spacing--bottom clearfix"
       data-ng-repeat="resource in resourcesC.storage.data.resources | limitTo : 3">
    <div class="column medium-4">
      <h2 class="connect-audubon-near-you--title text--blue"
          data-ng-bind="resource.title"></h2>
      <p class="connect-audubon-near-you--address"
         data-ng-bind-html="resourcesC.iconMap + resource.address.rendered + '<br/>' + resource.phone">
      </p>
      <div data-ng-bind-html="resource.link.rendered"></div>
    </div>
    <div class="column medium-8 connect-audubon-near-you--services">
      <h3 class="thin hide-for-tiny hide-for-small"><?php print $services_title_desktop; ?></h3>
      <h3 class="thin hide-for-medium hide-for-large hide-for-xlarge"><?php print $services_title_mobile; ?></h3>
      <div data-ng-bind-html="resource.services.rendered"></div>
    </div>
  </div>
</div>
