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
                    <p>Anthropogenic pressures on birds, habitats they rely on, and/or an entire ecosystem{{settings.threats.tagLine}}</p>
                </div>
                <div class="actions" ng-class="{'active': isActiveTab === 'actions'}">
                    <h4>Actions</h4>
                    <p>Conservation interventions by Audubon field staff and partners as classifed by the Conservation Measures Partnership{{settings.actions.tagLine}}</p>
                </div>
                <div class="responses"  ng-class="{'active': isActiveTab === 'responses'}">
                    <h4>Responses</h4>
                    <p>Quantifying the effectiveness of our conservation actions using scientifically-sound metrics{{settings.responses.tagLine}}</p>
                </div>
                <div class="partners"  ng-class="{'active': isActiveTab === 'partners'}">
                    <h4>Partners</h4>
                    <p>Our work is co-developed and often led by partner organizations and stakeholders {{settings.partners.tagLine}}</p>
                </div>
            </div>
        </div>
    </div>
</div>

<div class="global-content with-padding tabs-ng-content"
     data-ng-controller="Content">
    <div class="row">
        <div class="bird-page body-item" ng-cloak
             ng-class="{'active': isActive === 'responses'}">
            <div class="title-wrap">
                <div class="title-wrap__title columns tiny-9"><h3>{{responses.data.settings.responses.title}}</h3></div>
                <div class="title-wrap__print  columns large-3 hide-for-medium hide-for-small">
                  <a href="#" class="img-block print"></a> <a href="#" class="img-block download">Download</a><span>?</span>
                </div>
            </div>
            <div class="body-wrap columns large-8">
                <div class="body-wrap__body-text">
                    <p ng-bind-html="responses.data.settings.responses.description"></p>
                </div>
            </div>
            <div class="video-wrap columns large-4">
                <div class="video-wrap__item help-img-full">
                    <img ng-if="responses.data.settings.responses.image !== ''"
                         src={{responses.data.settings.responses.image}} alt="">
                </div>
            </div>
        </div>
        <div class="bird-page body-item" ng-cloak
             ng-class="{'active': isActive === 'actions'}">
            <div class="title-wrap">
                <div class="title-wrap__title columns tiny-9"><h3>{{actions.data.settings.actions.title}}</h3></div>
                <div class="title-wrap__print  columns large-3 hide-for-medium hide-for-small">
                  <a href="#" class="img-block print"></a> <a href="#" class="img-block download">Download</a><span>?</span>
                </div>
            </div>
            <div class="body-wrap columns large-8">
                <div class="body-wrap__body-text">
                    <p ng-bind-html="actions.data.settings.actions.description"></p>
                </div>
            </div>
            <div class="video-wrap columns large-4">
                <div class="video-wrap__item help-img-full">
                    <img src={{actions.data.settings.actions.image}} alt="">
                </div>
            </div>
        </div>
        <div class="bird-page body-item" ng-cloak
             ng-class="{'active': isActive === 'threats'}">
            <div class="title-wrap">
                <div class="title-wrap__title columns tiny-9"><h3>{{threats.data.settings.threats.title}}</h3></div>
                <div class="title-wrap__print  columns large-3 hide-for-medium hide-for-small">
                  <a href="#" class="img-block print"></a> <a href="#" class="img-block download">Download</a><span>?</span>
                </div>
            </div>
            <div class="body-wrap columns large-8">
                <div class="body-wrap__body-text">
                    <p ng-bind-html="threats.data.settings.threats.description"></p>
                </div>
            </div>
            <div class="video-wrap columns large-4">
                <div class="video-wrap__item help-img-full">
                    <img src={{threats.data.settings.threats.image}} alt="">
                </div>
            </div>
        </div>
        <div class="bird-page body-item" ng-cloak
             ng-class="{'active': isActive === 'partners'}">
            <div class="title-wrap">
                <div class="title-wrap__title columns tiny-9"><h3>{{partners.data.settings.partners.title}}</h3></div>
                <div class="title-wrap__print  columns large-3 hide-for-medium hide-for-small">
                  <a href="#" class="img-block print"></a> <a href="#" class="img-block download">Download</a><span>?</span> 
                </div>
            </div>
            <div class="body-wrap columns large-8">
                <div class="body-wrap__body-text">
                    <p ng-bind-html="partners.data.settings.partners.description"></p>
                </div>
            </div>
            <div class="video-wrap columns large-4">
                <div class="video-wrap__item help-img-full">
                    <img src={{partners.data.settings.partners.image}} alt="">
                </div>
            </div>
        </div>
    </div>
</div>


<!--<div class="ct-scorecard-overview row">-->
<!--    <div class="bird-page body-item">-->
<!--        <div class="title-wrap">-->
<!--            <div class="title-wrap__title columns tiny-10">-->
<!--                <h3>--><?php //print $title; ?><!--</h3></div>-->
<!--            <div class="title-wrap__print  columns large-2 hide-for-medium hide-for-small">-->
<!--                Download-->
<!--            </div>-->
<!--        </div>-->
<!--        <div class="body-wrap columns large-8">-->
<!--            <div class="body-wrap__body-text">-->
<!--                <p>--><?php //print $description; ?><!--</p>-->
<!--            </div>-->
<!--        </div>-->
<!--        <div class="video-wrap columns large-4">-->
<!--            <div class="video-wrap__item help-img-full">-->
<!--              --><?php //print $media; ?>
<!--            </div>-->
<!--        </div>-->
<!--    </div>-->
<!--</div>-->