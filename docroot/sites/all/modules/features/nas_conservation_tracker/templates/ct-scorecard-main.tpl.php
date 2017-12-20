<?php
/**
 * TPL file for CT content type.
 */
?>
<aside class="ct-scorecard-main map-items bird-page">
  <div class="row">
    <div class="ct-map" id="ct-map">
      <?php print $map; ?>
    </div>>
    <div class="diagram-wrap help-bg-white columns map-item large-8">
      <div class="map-item__inner-help">
        <div class="diagram-wrap__title">
          <h4 class="map-title">Action Categories</h4>
          <p>Count within map window.</p>
        </div>
        <div class="diagram-item">
          <?php print $actions; ?>
        </div>
      </div>
    </div>
    <div class="objectives-wrap help-bg-white columns map-item large-8">
      <div class="map-item__inner-help">
        <div class="objectives-wrap__title">
          <h4 class="map-title">Objectives</h4></div>
        <div class="objectives-wrap__wrap-items">
          <?php print $objectives; ?>
        </div>
      </div>
    </div>
    <div class="progress-wrap map-item large-8">
      <div class="map-item__inner-help">
        <div class="progress-wrap__title">
          <h4 class="map-title">Overall Progress</h4></div>
        <div class="progress-item">
          <p style="width:71%" data-value="71"></p>
          <progress max="100" value="71" class="html5"></progress>
        </div>
      </div>
    </div>
  </div>
</aside>
