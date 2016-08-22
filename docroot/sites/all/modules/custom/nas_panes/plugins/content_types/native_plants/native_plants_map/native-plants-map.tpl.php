<?php
/**
 * @file
 * Native plants nurseries map template.
 */
?>

<div class="native-plans-map clearfix vertical-spacing--top--half<?php print !empty($context_links) ? ' contextual-links-region' : ''; ?>">
  <?php print $context_links; ?>
  <div class="row">
    <div class="column">
      <h2 class="thin"><?php print $title; ?></h2>
    </div>
  </div>
  <div class="inline-map row">
    <div class="inline-map-canvas">
      <div class="inline-map-mask"></div>
      <?php print $map; ?>
    </div>
  </div>

  <div class="add-other-nurseries row column vertical-spacing--top--half">
    <a href="#">Have a nursery we should included in our directory? Let us know.</a>
  </div>
</div>
