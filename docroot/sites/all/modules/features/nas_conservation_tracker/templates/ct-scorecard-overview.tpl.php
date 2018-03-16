<?php
/**
 * TPL file for CT content type.
 */
?>
<div class="tabs ct-item-nav-conservation" ng-cloak data-ng-controller="Tabs">
    <div class="row">
        <div class="menu-wrap columns large-6">
            <div class="mobile-active {{isActiveTab}}" for="{{isActiveTab}}" ng-click="toggle = ! toggle">{{isActiveTab}}</div>
            <ul ng-class="{'open' : toggle }" ng-click="toggle = ! toggle">
                <li ng-repeat="tab in tabs" class="{{tab.active}}">
                    <a ui-sref="{{ tab.route }}"
                       class="{{tab.heading}} {{tab.active}}">{{ tab.heading }}</a>
                </li>
            </ul>
        </div>
        <div class="text-wrap columns large-6">
            <div class="text-wrap__content  hide-for-tiny hide-for-medium hide-for-small" ng-cloak>
                <div class="threats" ng-class="{'active': isActiveTab === 'threats'}">
                    <h4>Threats</h4>
                    <p><?php print $data['settings']['threats']['tagLine'] ?></p>
                </div>
                <div class="actions" ng-class="{'active': isActiveTab === 'actions'}">
                    <h4>Actions</h4>
                    <p><?php print $data['settings']['actions']['tagLine'] ?></p>
                </div>
                <div class="response"  ng-class="{'active': isActiveTab === 'response'}">
                    <h4>Response</h4>
                    <p><?php print $data['settings']['response']['tagLine'] ?></p>
                </div>
                <div class="partners"  ng-class="{'active': isActiveTab === 'partners'}">
                    <h4>Partners</h4>
                    <p><?php print $data['settings']['partners']['tagLine'] ?></p>
                </div>
            </div>
        </div>
    </div>
</div>

<div class="global-content with-padding tabs-ng-content" data-ng-controller="Content">
    <div id="scorecard-overview" class="row">
        <div class="js-preloader" ng-show="startLoad"></div>
        <div ng-repeat="(key, value) in tab.settings.tabs" tabs-repeat-directive>
            <div class="bird-page body-item {{value}}-tab-wrapper" ng-cloak  ng-class="{'active': isActive === value}">

                <div class="title-wrap">
                    <div class="title-wrap__title columns large-12"><h3 ng-bind-html="tab.settings.overview.title"></h3></div>
                </div>
                <div class="body-wrap columns large-7">
                    <div class="body-wrap__body-text">
                        <p ng-bind-html="tab.settings.overview.description"></p>
                    </div>
                </div>
                <div class="video-wrap columns large-5">
                    <div class="video-wrap__item help-img-full">
                        <a class="{{tab.settings.overview.preparedLink.class}}" href="{{tab.settings.overview.preparedLink.href}}" target="{{tab.settings.overview.preparedLink.target}}">
                            <img ng-if="tab.settings.overview.thumbnail !== ''"
                                 src={{tab.settings.overview.thumbnail}} alt="">
                        </a>
                    </div>
                </div>
                <div class="partners-wrap columns" ng-show="{{value === 'partners'}}">
                    <div class="partners-wrap__partner partner large-4 medium-12 columns" ng-repeat="partner in tab.settings.overview.partners">
                        <div class="partner__state"><p><span>State:</span> {{partner.state}}</p></div>
                        <div class="partner__name"><p>{{partner.name}}</p></div>
                        <div class="partner__chapter"  ng-if="partner.chapter.length > 0"></div>
                    </div>
                </div>
                <div data-html2canvas-ignore="true" ng-if="value !== 'partners'" class="title-wrap__print  columns large-3  hide-for-tiny hide-for-medium hide-for-small">
                    <div ng-show="pdfLoading" id="pdf-loading">PDF Loading...</div>
                    <a href="#" class="img-block print"></a>
                    <div class="img-block download" ng-click="toggle_wrap = !toggle_wrap">Download</div>
                    <div class="show-options" ng-class="{'js-show-wrap' : toggle_wrap}">
                        <a href="" ng-click="downloadPdf()" id="download-pdf" class="">PDF</a>
                        <a href="/conservation-tracker/csv/{{value}}/<?php print $data['id'] ?>" id="download-csv" class="">CSV</a>
                    </div>
                </div>
            </div>
        </div>
    </div>
    {{tabLoaded()}}
</div>

