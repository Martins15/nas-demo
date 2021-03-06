<?php
/**
 * TPL file for CT content type.
 */
?>
<aside class="ct-scorecard-main map-items bird-page">
  <div>
    <?php print $form; ?>
    <a href="#" class="controls-link"><span class="border"></span> </a>
  </div>
  <div id="charts" class="wrap-map-diagram">
    <?php print $map; ?>
    <div class="help-wrap-items-map-items">
      <div id="charts-actions" class="diagram-wrap help-bg-white columns map-item large-8">
        <div class="map-item__inner-help">
          <div class="diagram-wrap__title">
            <h4 class="map-title">
              <span class="map-span-title">
                Action Categories
              </span>
              <span class="tooltip" data-html2canvas-ignore="true">
                <span class="icon"></span>
                <span class="text" id="tooltip-text"><?php print $tooltip; ?></span>
              </span>
            </h4>
            <?php /*<div class="trigger">
              <h5>Display Actions</h5>
              <div class="switch">
                <input type="checkbox" class="form-switch" id="checkActions">
                <label for="checkActions"></label>
              </div>
            </div>*/ ?>
            <p><span
                id="site-count-copy">Sites in selected/visible area(s): </span><span
                id="site-count">0</span></p>
          </div>
          <div class="diagram-item">
            <?php print $actions; ?>
          </div>
        </div>
      </div>
      <div id="charts-objectives" class="objectives-wrap help-bg-white columns map-item large-8">
        <div class="map-item__inner-help">
          <div class="objectives-wrap__title">
            <h4 class="map-title">
              Objectives
              <span class="tooltip" data-html2canvas-ignore="true">
                <span class="icon"></span>
                <span class="text"
                      id="tooltip-objectives-text"><?php print $tooltip_objectives; ?></span>
              </span>
            </h4>
          </div>
          <div class="objectives-wrap__wrap-items">
            <?php print $objectives; ?>
          </div>
        </div>
      </div>
      <div class="progress-wrap map-item large-8 columns">
        <div class="map-item__inner-help">
          <div class="progress-wrap__title">
            <h4 class="map-title">Overall Progress</h4></div>
          <div class="progress-item">
            <p style="width:71%" data-value="71"></p>
            <progress max="100" value="71" class="html5"></progress>
          </div>
        </div>
      </div>
      <div class="rating-wrap map-item large-8  columns">
        <div class="map-item__inner-help">
          <div class="rating-wrap__title"><h4 class="map-title">Rate this report</h4></div>
          <div id="rating-ajax-wrapper">
            <p>Please comment on the quality of this report. Suggestions for improvement are much appreciated. All comments will be anonymous unless you opt to provide your name.</p>
            <?php print $rating_form; ?>
          </div>
        </div>
      </div>
    </div>
  </div>
</aside>
<div id="scorecard-footnotes" data-ng-controller="Content">
    <div class="help-wrap-footnotes"
         ng-if="tab.settings.overview.footnotes.length > 0">
        <div class="row"
        <div class="columns"
        <a id="footnotes"></a>
        <div ng-bind-html="tab.settings.overview.footnotes" id="footnotes-content"></div>
    </div>
</div>
