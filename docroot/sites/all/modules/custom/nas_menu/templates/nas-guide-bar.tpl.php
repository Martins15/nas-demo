<?php
/**
 * @file
 * Template for guide bar.
 * 
 * Available variables:
 * - $attributes: attributes like class and style if available.
 * - $title: guide bar title
 * - $preamble: text displayed before logo
 * - $logo: img tag with log
 */
?>

<div<?php print $div_attributes; ?>>
  <div class="row">
    <?php print $contextual_links; ?>
    <div class="column">
      <?php if (!empty($link)) : ?>
        <a href="<?php print $link; ?>"><h2 class="guide-bar-title"><?php print $title; ?></h2></a>
      <?php else : ?>
        <h2 class="guide-bar-title"><?php print $title; ?></h2>
      <?php endif; ?>
      <div class="guide-bar-attribution">
        <span class="preamble"><?php print $preamble; ?></span>
        <?php print $logo; ?>
      </div>
    </div>
  </div>
</div>