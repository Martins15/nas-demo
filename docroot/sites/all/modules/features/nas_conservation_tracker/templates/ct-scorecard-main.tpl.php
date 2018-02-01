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
  <div class="wrap-map-diagram">
    <?php print $map; ?>
    <div class="help-wrap-items-map-items">
      <div class="diagram-wrap help-bg-white columns map-item large-8">
        <div class="map-item__inner-help">
          <div class="diagram-wrap__title">
            <h4 class="map-title">
              <span class="map-span-title">
                Action Categories
              </span>
              <span class="tooltip">
                <span class="icon"></span>
                <span class="text"
                      id="tooltip-text"><?php print $tooltip; ?></span>
              </span>
            </h4>
            <div class="trigger">
              <h5>Display Actions</h5>
              <div class="switch">
                <input type="checkbox" class="form-switch" id="checkActions">
                <label for="checkActions"></label>
              </div>
            </div>
            <p><span
                id="site-count-copy">Sites in selected/visible area(s): </span><span
                id="site-count">0</span></p>
          </div>
          <div class="diagram-item">
            <?php print $actions; ?>
          </div>
        </div>
      </div>
      <div class="objectives-wrap help-bg-white columns map-item large-8">
        <div class="map-item__inner-help">
          <div class="objectives-wrap__title">
            <h4 class="map-title">
              Objectives
              <span class="tooltip">
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
  </div>
</aside>
