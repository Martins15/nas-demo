<?php
/**
 * @file
 * Template for Native Plants tabs selector pane.
 */
?>
<div class="row<?php print !empty($context_links) ? ' contextual-links-region' : ''; ?> <?php print $classes; ?>">
  <?php print $context_links; ?>
  <div class="columns">
    <ul class="tabs js-tabs hide-for-tiny hide-for-small hide-for-medium" data-tab>
      <li class="tab-title active">
        <a href="#best_results" class="js-ajax-tab js-tab"><?php print $tab1_title; ?></a>
      </li>
      <li class="tab-title">
        <a href="#full_results" class="js-ajax-tab js-tab"><?php print $tab2_title; ?></a>
      </li>
      <li class="tab-title">
        <a href="#local_results" class="js-ajax-tab js-tab"><?php print $tab3_title; ?></a>
      </li>
      <li class="tab-title">
        <a href="#next_steps" class="js-ajax-tab js-tab"><?php print $tab4_title; ?></a>
      </li>
    </ul>
  </div>
</div>
