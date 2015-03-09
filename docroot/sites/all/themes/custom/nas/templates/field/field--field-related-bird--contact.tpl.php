<?php
/**
 * @file
 * Template implementation to display "Related Birds" field of contact nodes.
 */
?>
<div class="bird-card-set">
  <div class="row section-header">
    <div class="columns">
      <h2 class="thin"><?php print $label; ?></h2>
    </div>
    <div class="columns">
      <ul class="section-nav inline-list">
        <li class="first"><?php print l(t('The Bird Guide'), 'bird-guide'); ?></li>
        <li class="last"><a class="orange" href="https://secure.audubon.org/site/SPageNavigator/2014_Adoption_Catalog_Homepage.html">Adopt a Bird</a></li>
      </ul>
    </div>
  </div>
  <div class="row bird-card-container space-bottom">
    <div class="bird-card-scroller" style="transition: 0ms cubic-bezier(0.1, 0.57, 0.1, 1); -webkit-transition: 0ms cubic-bezier(0.1, 0.57, 0.1, 1); transform: translate(0px, 0px) translateZ(0px);">
      <?php foreach ($items as $delta => $item): ?>
        <div class="columns tiny-3">
          <?php print render($item); ?>
        </div>
      <?php endforeach; ?>
    </div>
  </div>
  <div class="row indicator space-bottom double">
    <div class="column">
      <p><i class="indicator-left icon-arrow-left disabled"></i>&nbsp;&nbsp;&nbsp;<i class="indicator-right icon-arrow-right"></i></p>
    </div>
  </div>
</div>