<?php
/**
 * @file
 * Template to custom pane boa_family_species.
 *
 * Available variables:
 *  $prev_link - previous family link.
 *  $prev_title - previous family title.
 *  $next_link - next family link.
 *  $next_title - next family title.
 */
?>

<div class="boa-family-block-pager">
  <div class="columns">
    <div class="inner">
      <?php print $prev_link; ?>
      <span class="previous-text">Previous Family</span>
      <span class="previous-title"><?php print $prev_title; ?>Tits</span>
      <span class="separator"></span>
      <span class="next-text">Next Family</span>
      <span class="next-title"><?php print $next_title; ?>Hawks</span>
      <?php print $next_link; ?>
    </div>
  </div>
</div>
