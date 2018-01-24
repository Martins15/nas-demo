<?php
/**
 * TPL file for CT content type.
 */
?>
<section class="ct-strategies-main">
    <div class="ct-strategies-tabs-wrap" ng-app="nasCtStrategies" ng-controller="tabs">
      <tabset>
        <tab ng-repeat="tab in tabs" heading="{{tab.name}}" class="{{tab.link}}" select="getContent($index)" active="tab.active" disabled="tab.disabled">
          <tab-heading ng-class="getClass($index)">
            {{tab.name}}
          </tab-heading>
          <div ng-hide="!tab.isLoaded">
            <div>
              <h4>{{tab.name}}</h4>
              <div>
                <p>{{tab.tagline}}</p>
              </div>
            </div>
            <div id="strategy-breakdown-left">
              <h5>Strategy Breakdown</h5>
              <div ng-if="tab.subTabs.overview">
                {{tab.subTabs.overview.title}}
              </div>
              <div ng-if="tab.subTabs.goals">
                {{tab.subTabs.goals.title}}
              </div>
              <div ng-if="tab.subTabs.partners">
                {{tab.subTabs.partners.title}}
              </div>
              <div ng-if="tab.subTabs.initiatives">
                {{tab.subTabs.initiatives.title}}
                <ul>
                  <li ng-repeat="initiative in tab.subTabs.initiatives.list">{{initiative}}</li>
                </ul>
              </div>
              <div ng-if="tab.subTabs.priority_species">
                {{tab.subTabs.priority_species.title}}
                <ul>
                  <li ng-repeat="species in tab.subTabs.priority_species.list">{{species}}</li>
                </ul>
              </div>
              <div ng-if="tab.subTabs.priority_landscapes">
                {{tab.subTabs.priority_landscapes.title}}
                <ul>
                  <li ng-repeat="landscape in tab.subTabs.priority_landscapes.list">{{landscape}}</li>
                </ul>
              </div>
            </div>
            <div id="strategy-breakdown-right">
              <div ng-if="tab.subTabs.overview">
                <div class="progress-wrap map-item large-8">
                  <div class="map-item__inner-help">
                    <div class="progress-wrap__title">
                      <h4 class="map-title">Overall Progress</h4></div>
                    <div class="progress-item">
                      <p style="width:{{tab.subTabs.overview.progress}}%" data-value="{{tab.subTabs.overview.progress}}"></p>
                      <progress max="100" value="{{tab.subTabs.overview.progress}}" class="html5"></progress>
                    </div>
                  </div>
                </div>
                <p>{{tab.subTabs.overview.description}}</p>
              </div>
              <div ng-if="tab.subTabs.goals">
                {{tab.subTabs.goals.title}}
                <ul>
                  <li ng-repeat="goalGroup in tab.subTabs.goals.goals">
                    {{goalGroup.group}}
                    <ul ng-if="goalGroup.list">
                      <li ng-repeat="goal in goalGroup.list">{{goal}}</li>
                    </ul>
                  </li>
                </ul>
              </div>
              <div ng-if="tab.subTabs.partners">
                {{tab.subTabs.partners.title}}
                <ul>
                  <li ng-repeat="partner in tab.subTabs.partners.list">{{partner}}</li>
                </ul>
              </div>
            </div>
          </div>
          <div ng-hide="tab.isLoaded">Loading...</div>
        </tab>
      </tabset>
    </div>
</section>