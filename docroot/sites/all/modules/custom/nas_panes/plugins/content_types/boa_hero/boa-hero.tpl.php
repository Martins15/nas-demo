<?php
/**
 * @file
 * Template to custom pane boa_hero.
 *
 * Available variables:
 *  $image - url to the hero image.
 *  $next_url - url to next BOA.
 *  $prev_url - url to prvious BOA.
 */
?>

<div class="bird-guide-image">
  <img src="<?php print $image; ?>" />
</div>
<a href="<?php print $prev_url; ?>" class="boa-previous-plate"></a>
<a href="<?php print $next_url; ?>" class="boa-next-plate"></a>
