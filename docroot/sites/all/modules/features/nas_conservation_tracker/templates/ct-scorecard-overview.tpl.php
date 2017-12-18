<?php
/**
 * TPL file for CT content type.
 */
?>
<div class="tabs ct-item-nav-conservation" ng-cloak data-ng-controller="Tabs">
    <div class="row">
        <div class="menu-wrap columns large-6">
            <ul>
                <li
                        ng-repeat="tab in tabs"
                        ui-sref="{{ tab.route }}"
                        class="{{tab.heading}} {{tab.active}}">{{ tab.heading }}
                </li>
            </ul>
        </div>
        <div class="text-wrap columns large-6">
            <div class="text-wrap__content" ng-cloak data-ng-controller="Content">
                <div ng-repeat="item in content">
                    <h4>{{item.title}}<h4>
                            <p>{{item.text}}<p>
                </div>
            </div>
        </div>
</div>
</div>


<div class="ct-scorecard-overview row">
  <div class="bird-page body-item">
    <div class="title-wrap">
      <div class="title-wrap__title columns tiny-10"><h3><?php print $title; ?></h3></div>
      <div class="title-wrap__print  columns large-2 hide-for-medium hide-for-small">
        Download
      </div>
    </div>
    <div class="body-wrap columns large-8">
      <div class="body-wrap__body-text">
        <p><?php print $description; ?></p>
      </div>
    </div>
    <div class="video-wrap columns large-4">
      <div class="video-wrap__item help-img-full">
        <?php print $media; ?>
      </div>
    </div>
  </div>
</div>