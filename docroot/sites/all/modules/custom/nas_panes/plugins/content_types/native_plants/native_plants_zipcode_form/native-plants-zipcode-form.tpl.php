<?php

/**
 * @file
 * Template for Native Plants zipcode form.
 */
?>
<div class="row<?php print !empty($context_links) ? ' contextual-links-region' : ''; ?>">
  <?php print $context_links; ?>
  <div class="columns">
    <h2 class="thin centered hide-for-tiny hide-for-small"><?php print $title_desktop; ?></h2>
    <h2 class="thin hide-for-medium hide-for-large hide-for-xlarge"><?php print $title_mobile; ?></h2>
    <?php print $form; ?>
  </div>
</div>
