<?php
/**
 * @file
 * Template to custom pane boa_hero.
 *
 * Available variables:
 *  $next_url - url to next BOA.
 *  $next_plate_number - plate number of next BOA.
 *  $next_title - title of next BOA.
 *  $prev_url - url to prvious BOA.
 *  $prev_plate_number - plate number of previous BOA.
 *  $prev_title - title of previouss BOA.
 */
?>

<div class="boa-family-block-pager plate">
    <div class="columns">
      <div class="inner">
        <a href="<?php print $prev_url; ?>" class="previous"></a>
        <span class="previous-text">Plate <?php print $prev_plate_number; ?></span>
        <span class="previous-title"><?php print $prev_title; ?></span>
        <span class="separator"></span>
        <span class="next-text">Plate <?php print $next_plate_number; ?></span>
        <span class="next-title"><?php print $next_title; ?></span>
        <a href="<?php print $next_url; ?>" class="next"></a>
      </div>
    </div>
  </div>
