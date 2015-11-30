<?php
/**
 * Variables:
 * - $bird_name - name on the bird.
 */
?>
<div class="columns">
  <h2 class="thin"><?php print t('@bird_name in Action', array('@bird_name' => $bird_name)); ?></h2>
</div>
<div class="columns">
  <ul class="section-nav inline-list hide-for-small hide-for-tiny">
    <li><a href="#"><?php print t('More Video &raquo;'); ?></a></li>
  </ul>
</div>