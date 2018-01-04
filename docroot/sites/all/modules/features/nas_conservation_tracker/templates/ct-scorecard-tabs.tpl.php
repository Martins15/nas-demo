<?php
/**
 * TPL file for CT content type.
 */
?>
<div class="ct-scorecard-tabs">
  <div class="row">
    <?php foreach ($menu_tree as $item): ?>
      <span class="current-title"><?php print $item['markup']; ?></span>
      <?php if (isset($item['children'])): ?>
        <?php foreach ($item['children'] as $child): ?>
          <?php print $child['markup']; ?>
        <?php endforeach; ?>
      <?php endif; ?>
    <?php endforeach; ?>
  </div>
</div>


<!--<div class="ct-scorecard-tabs">-->
<!--  <div class="row">-->
<!--    <span class="current-title"><a href="/">Conservation Tracker</a></span>-->
<!--    <a href="/" class="active-trail">Landscapes</a>-->
<!--    <a href="/">Species</a>-->
<!--    <a href="/">Strategies</a>-->
<!--    <span class="current-title">Black Oystercatcher</span>-->
<!--  </div>-->
<!--</div>-->

