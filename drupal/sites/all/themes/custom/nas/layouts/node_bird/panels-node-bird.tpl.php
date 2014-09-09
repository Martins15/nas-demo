<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<section <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?> class="global-content no-padding">
  <div class="bird-guide-container hero large">
    <div class="bird-guide-image">
      <?php print $content['top']; ?>
    </div>
    <div class="row">
      <div class="column">
        <?php print $content['main']; ?>
      </div>
    </div>
  </div>
</section>
