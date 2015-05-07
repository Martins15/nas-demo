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
      <h2 class="guide-bar-title"><?php print $title; ?></h2>
      <div class="guide-bar-attribution">
        <span class="preamble"><?php print $preamble; ?></span>
        <?php if (!empty($link)) : ?>
          <a href="<?php print $link; ?>"><?php print $logo; ?></a>
        <?php else : ?>
          <?php print $logo; ?>
        <?php endif; ?>
      </div>
    </div>
  </div>
</div>
