<?php
/**
 * @file
 * Template to custom pane boa_family_species.
 *
 * Available variables:
 *  $prev_link - previous family link.
 *  $prev_text_link - previous family link.
 *  $prev_title_link - previous family title link.
 *  $next_link - next family link.
 *  $next_text_link - next family link.
 *  $next_title_link - next family title link.
 */
?>

<div class="boa-family-block-pager family">
  <div class="columns">
    <div class="inner">
      <?php print $prev_link; ?>
      <span class="previous-text"><?php print $prev_text_link; ?></span>
      <span class="previous-title"><?php print $prev_title_link; ?></span>
      <span class="separator"></span>
      <span class="next-text"><?php print $next_text_link; ?></span>
      <span class="next-title"><?php print $next_title_link; ?></span>
      <?php print $next_link; ?>
    </div>
  </div>
</div>
