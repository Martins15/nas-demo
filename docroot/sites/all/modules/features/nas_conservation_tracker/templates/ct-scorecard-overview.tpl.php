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
            <div class="text-wrap__content" ng-cloak>
                <div class="threats" ng-class="{'active': isActiveTab === 'threats'}">
                    <h4>Threats</h4>
                    <p><?php print $data['settings']['threats']['tagLine'] ?></p>
                </div>
                <div class="actions" ng-class="{'active': isActiveTab === 'actions'}">
                    <h4>Actions</h4>
                    <p><?php print $data['settings']['actions']['tagLine'] ?></p>
                </div>
                <div class="responses"  ng-class="{'active': isActiveTab === 'responses'}">
                    <h4>Responses</h4>
                    <p><?php print $data['settings']['responses']['tagLine'] ?></p>
                </div>
                <div class="partners"  ng-class="{'active': isActiveTab === 'partners'}">
                    <h4>Partners</h4>
                    <p><?php print $data['settings']['partners']['tagLine'] ?></p>
                </div>
            </div>
        </div>
    </div>
</div>

<div class="global-content with-padding tabs-ng-content"
     data-ng-controller="Content">
    <div class="row">
        <div ng-repeat="(key, value) in tab.settings.tabs">
            <div class="bird-page body-item" ng-cloak  ng-class="{'active': isActive === value}">

                <div class="title-wrap">
                    <div class="title-wrap__title columns tiny-9"><h3>{{tab.settings.overview.title}}</h3></div>
                    <div class="title-wrap__print  columns large-3 hide-for-medium hide-for-small">
                        <a href="#" class="img-block print"></a> <a href="#" class="img-block download">Download</a><span>?</span>
                    </div>
                </div>
                <div class="body-wrap columns large-8">
                    <div class="body-wrap__body-text">
                        <p ng-bind-html="tab.settings.overview.description"></p>
                    </div>
                </div>
                <div class="video-wrap columns large-4">
                    <div class="video-wrap__item help-img-full">
                        <img ng-if="tab.settings.overview.thumbnail !== ''"
                             src={{tab.settings.overview.thumbnail}} alt="">
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>