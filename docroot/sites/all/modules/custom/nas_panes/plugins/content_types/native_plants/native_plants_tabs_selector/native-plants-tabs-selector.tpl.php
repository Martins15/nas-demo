<?php

/**
 * @file
 * Template for Native Plants tabs selector pane.
 */
?>
<div class="row<?php print !empty($context_links) ? ' contextual-links-region' : ''; ?> <?php print $classes; ?>"
     data-ng-controller="NativePlantsTabsController as tabsC">
  <?php print $context_links; ?>
  <div class="columns">
    <ul class="tabs js-tabs hide-for-tiny hide-for-small hide-for-medium" data-tab-responsive>
      <li class="tab-title">
        <a href="#best_results" class="js-ajax-tab js-tab"
           data-ng-click="tabsC.activateTab('best_results')">
          <?php print $tab1_title; ?>
          <span class="counter"
                data-ng-bind-html="tabsC.tabResults(tabsC.storage.results_tier1_filtered.length)"></span>
        </a>
      </li>
      <li class="tab-title">
        <a href="#full_results" class="js-ajax-tab js-tab"
           data-ng-click="tabsC.activateTab('full_results')">
          <?php print $tab2_title; ?>
          <span class="counter"
                data-ng-bind-html="tabsC.tabResults(tabsC.storage.results_filtered.length)"></span>
        </a>
      </li>
      <li class="tab-title">
        <a href="#local_resources" class="js-ajax-tab js-tab"
           data-ng-click="tabsC.activateTab('local_resources')"><?php print $tab3_title; ?></a>
      </li>
      <li class="tab-title">
        <a href="#next_steps" class="js-ajax-tab js-tab"
           data-ng-click="tabsC.activateTab('next_steps')"><?php print $tab4_title; ?></a>
      </li>
    </ul>
  </div>
</div>
