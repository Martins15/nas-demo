<?php
/**
 * @file
 * Template for Native Plants tabs.
 */
?>
<?php print $content['top']; ?>
<section class="global-content static-page-content">
  <?php print $content['main']; ?>
  <div class="native-plants-tabs js-native-plants-tabs">
    <?php print $content['tab_selector']; ?>
    <div class="tab-content" data-ng-controller="NativePlantsTabsController as tabsC">
      <div class="tab-pane" id="best_results">
        <div class="row">
          <div class="columns">
            <div class="native-plants-search-results clearfix">
              <?php print $content['tab1']; ?>
            </div>
          </div>
        </div>
      </div>
      <div class="tab-pane" id="full_results">
        <div class="row">
          <div class="columns">
            <div class="native-plants-full-results clearfix">
              <?php print $content['tab2']; ?>
            </div>
          </div>
        </div>
      </div>
      <div class="tab-pane" id="local_resources">
        <div class="row">
          <div class="columns">
            <div class="native-plants-local-results clearfix">
              <?php print $content['tab3']; ?>
            </div>
          </div>
        </div>
      </div>
      <div class="tab-pane" id="next_steps">
        <div class="row">
          <div class="columns">
            <div class="native-plants-contact">
              <?php print $content['tab4']; ?>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</section>
<div class="native-plants-bottom">
  <?php print $content['bottom']; ?>
</div>
