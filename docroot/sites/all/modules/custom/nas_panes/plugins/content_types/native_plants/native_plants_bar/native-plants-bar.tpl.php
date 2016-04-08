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
        <span class="hide-for-tiny hide-for-small"><?php print $title_desktop; ?></span>
        <span class="hide-for-medium hide-for-large hide-for-xlarge"><?php print $title_mobile; ?></span>
      </div>
    </div>
  </div>
</div>