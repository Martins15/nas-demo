<?php

/**
 * @file
 * Template for the Donate sticky bar link.
 */
?>
<div class="hide-for-tiny hide-for-small contextual-links-region" id="OptimizelyDonationBar">
  <?php print $contextual_links; ?>
  <p><?php print $text; ?></p>
  <a href="<?php print $link_link; ?>" class="buttonLink"><?php print $link_link_text; ?></a>
</div>
