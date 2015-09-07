<?php

/**
 * @file
 * Custom view template to display Flyways Related Birds.
 *
 * @ingroup views_templates
 */
?>

<div class="bird-card-set <?php print $classes; ?>">
  <?php print render($title_suffix); ?>
  <div class="row section-header space-top">
    <div class="columns">
      <h2 class="thin"><?php print $title; ?></h2>
    </div>
    <div class="columns">
      <ul class="section-nav inline-list">
        <li class="first"><?php print l(t('More Priority Birds'), 'birds/priority'); ?></li>
        <li class="last"><a class="cta" href="https://secure.audubon.org/site/SPageNavigator/2014_Adoption_Catalog_Homepage.html"><?php print t('Adopt a Bird'); ?></a></li>
      </ul>
    </div>
  </div>
  <div class="row bird-card-container">
    <div class="bird-card-scroller">
      <?php print $rows; ?>
    </div>
    <div class="row indicator space-bottom">
      <div class="column">
        <p><i class="indicator-left icon-arrow-left disabled"></i>&nbsp;&nbsp;&nbsp;<i class="indicator-right icon-arrow-right"></i></p>
      </div>
    </div>
  </div>
</div>
