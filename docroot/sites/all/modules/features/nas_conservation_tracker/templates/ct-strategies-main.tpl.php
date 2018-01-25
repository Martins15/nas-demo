<?php
/**
 * TPL file for CT content type.
 */
?>
<section class="ct-strategies-main">
    <div class="ct-strategies-tabs-wrap" ng-app="nasCtStrategies"
         ng-controller="tabs">
        <tabset>
            <tab ng-repeat="tab in tabs" heading="{{tab.name}}"
                 class="{{tab.link}}" select="getContent($index)"
                 active="tab.active" disabled="tab.disabled">
                <tab-heading class="link" ng-class="getClass($index)">
                    {{tab.name}}
                </tab-heading>
                <div ng-hide="!tab.isLoaded">
                    <div class="text-wrap columns large-6">
                        <h4>{{tab.name}}</h4>
                        <div>
                            <p>{{tab.tagline}}</p>
                        </div>
                    </div>
                    <div class="wrap-strategy-breakdown">
                        <div id="strategy-breakdown-left">
                            <h5>Strategy Breakdown</h5>
                            <div ng-if="tab.subTabs.overview" ng-class="{ active: isSet(1) }">
                                <span class="item-menu" ng-click="setTab(1)">{{tab.subTabs.overview.title}}</span>
                            </div>
                            <div ng-if="tab.subTabs.goals" ng-class="{ active: isSet(2) }">
                                <span class="item-menu" ng-click="setTab(2)">{{tab.subTabs.goals.title}}</span>
                            </div>
                            <div ng-if="tab.subTabs.partners" ng-class="{ active: isSet(3) }">
                                <span class="item-menu" ng-click="setTab(3)">{{tab.subTabs.partners.title}}</span>
                            </div>
                            <div ng-if="tab.subTabs.initiatives" ng-class="{ active: isSet(4) }">
                                <span class="item-menu" ng-click="setTab(4)">{{tab.subTabs.initiatives.title}}</span>
                            </div>
                            <div ng-if="tab.subTabs.priority_species" ng-class="{ active: isSet(5) }">
                                <span class="item-menu" ng-click="setTab(5)">{{tab.subTabs.priority_species.title}}</span>
                            </div>
                            <div ng-if="tab.subTabs.priority_landscapes" ng-class="{ active: isSet(6) }">
                                <span class="item-menu" ng-click="setTab(6)">{{tab.subTabs.priority_landscapes.title}}</span>
                            </div>
                        </div>
                        <div id="strategy-breakdown-right">
                            <div ng-if="tab.subTabs.overview" ng-show="isSet(1)">
                                <div class="progress-wrap map-item large-8">
                                    <div class="map-item__inner-help">
                                        <div class="progress-wrap__title">
                                            <h4 class="map-title">Overall
                                                Progress</h4></div>
                                        <div class="progress-item">
                                            <p style="width:{{tab.subTabs.overview.progress}}%"
                                               data-value="{{tab.subTabs.overview.progress}}"></p>
                                            <progress max="100"
                                                      value="{{tab.subTabs.overview.progress}}"
                                                      class="html5"></progress>
                                        </div>
                                    </div>
                                </div>
                                <p>{{tab.subTabs.overview.description}}</p>
                            </div>
                            <div ng-if="tab.subTabs.goals" ng-show="isSet(2)">
                                {{tab.subTabs.goals.title}}
                                <ul>
                                    <li ng-repeat="goalGroup in tab.subTabs.goals.goals">
                                        {{goalGroup.group}}
                                        <ul ng-if="goalGroup.list">
                                            <li ng-repeat="goal in goalGroup.list">
                                                {{goal}}
                                            </li>
                                        </ul>
                                    </li>
                                </ul>
                            </div>
                            <div ng-if="tab.subTabs.partners" ng-show="isSet(3)">
                                {{tab.subTabs.partners.title}}
                                <ul>
                                    <li ng-repeat="partner in tab.subTabs.partners.list">
                                        {{partner}}
                                    </li>
                                </ul>
                            </div>
                            <div ng-if="tab.subTabs.initiatives" ng-show="isSet(4)">
                                {{tab.subTabs.initiatives.title}}
                                <ul>
                                    <li ng-repeat="initiative in tab.subTabs.initiatives.list">
                                        {{initiative}}
                                    </li>
                                </ul>
                            </div>
                            <div ng-if="tab.subTabs.priority_species" ng-show="isSet(5)">
                                {{tab.subTabs.priority_species.title}}
                                <ul>
                                    <li ng-repeat="species in tab.subTabs.priority_species.list">
                                        {{species}}
                                    </li>
                                </ul>
                            </div>
                            <div ng-if="tab.subTabs.priority_landscapes" ng-show="isSet(6)">
                                {{tab.subTabs.priority_landscapes.title}}
                                <ul>
                                    <li ng-repeat="landscape in tab.subTabs.priority_landscapes.list">
                                        {{landscape}}
                                    </li>
                                </ul>
                            </div>
                        </div>
                    </div>
                </div>
                <div ng-hide="tab.isLoaded">Loading...</div>
            </tab>
        </tabset>
    </div>
</section>