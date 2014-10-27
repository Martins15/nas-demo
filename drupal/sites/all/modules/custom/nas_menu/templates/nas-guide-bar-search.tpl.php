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
      <a class="guide-bar-search toggle-bird-guide-search" href="#"><i class="icon-binoculars white"></i><i class="icon-binoculars black"></i> Find a Bird</a>
      <div class="guide-bar-attribution">
        <span class="preamble"><?php print $preamble; ?></span>
        <?php print $logo; ?>
      </div>
    </div>
  </div>
</div>
<div class="bird-guide-search">
  <div class="row">
    <div class="columns large-9 bird-guide-search-form">
      <?php print $exposed_form; ?>
    </div>
    <div class="columns large-3 interactive-guide">
      <p class="preamble">
        <span class="small">Saw a bird?</span> <span class="large">Identify it.</span>
      </p>
      <a href="#" class="interactive-guide-button button blue">Our <span class="hide-for-small hide-for-tiny">Interactive </span>Guide</a>
    </div>
  </div>
</div>