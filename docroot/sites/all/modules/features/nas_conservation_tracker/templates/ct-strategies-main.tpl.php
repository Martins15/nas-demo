<?php
/**
 * TPL file for CT content type.
 */
?>
<section class="ct-strategies-main">
  <div class="row">
    <div ng-app="nasCtStrategies" ng-controller="tabs">
      <tabset>
        <tab ng-repeat="tab in tabs" heading="{{tab.name}}" select="getContent($index)" active="tab.active" disabled="tab.disabled">

          <div ng-hide="!tab.isLoaded">
            <div>
              <h4>{{tab.name}}</h4>
              <div>
                <p>{{tab.tagline}}</p>
                  {{tab.content}}
              </div>
            </div>
            <div>
              <h5>Strategy Breakdown</h5>
              <div></div>
              <div></div>
              <div></div>
              <div></div>
            </div>
          </div>
          <div ng-hide="tab.isLoaded">Loading...</div>
        </tab>
      </tabset>
    </div>
  </div>
</section>