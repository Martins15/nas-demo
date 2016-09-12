<?php
/**
 * @file
 * Template for Native Plants bar.
 */
?>
<div class="<?php print !empty($context_links) ? 'contextual-links-region' : ''; ?>" style="background-color: #<?php print $background_color; ?>;">
  <?php print $context_links; ?>
  <div class="row">
    <div class="columns">
      <div class="native-plants-green-row">
        <a href="<?php print $title_link; ?>" class="hide-for-tiny hide-for-small"><?php print $title_desktop; ?></a>
        <a href="<?php print $title_link; ?>" class="hide-for-medium hide-for-large hide-for-xlarge"><?php print $title_mobile; ?></a>

        <?php if ($sponsor_logo): ?>
          <div class="sponsor-attribution">
            <?php if ($sponsor_link): ?>
              <a href="<?php print $sponsor_link; ?>" class="sponsor-wrapper">
            <?php else: ?>
              <span class="sponsor-wrapper">
            <?php endif; ?>
            <?php if ($sponsor_preambule): ?>
              <span class="preamble"><?php print $sponsor_preambule; ?></span>
            <?php endif; ?>
              <img class="sponsor-logo" src="<?php print $sponsor_logo; ?>">
            <?php if ($sponsor_link): ?>
              </a>
            <?php else: ?>
              </span>
            <?php endif; ?>
          </div>
        <?php endif; ?>
      </div>
    </div>
  </div>
</div>