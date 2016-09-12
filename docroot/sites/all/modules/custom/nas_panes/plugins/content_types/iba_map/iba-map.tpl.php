<?php
/**
 * @file
 * IBA Map.
 *
 * Available variables:
 * - $src: (string) src to map loaded in iframe.
 */
?>
<div class="iba-map embed-container inline-map ">
  <div class="inline-map-canvas">
    <div class="inline-map-mask"></div>
    <iframe width="500" height="400" frameborder="0" scrolling="no" marginheight="0" marginwidth="0" title="<?php print t('IBA Website Audubon'); ?>" src="<?php print $src; ?>"></iframe>
  </div>
</div>

