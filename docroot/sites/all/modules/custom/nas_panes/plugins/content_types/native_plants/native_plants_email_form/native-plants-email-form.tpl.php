<?php

/**
 * @file
 * Native Plants Email form template.
 */
?>
<div class="<?php print !empty($context_links) ? 'contextual-links-region' : ''; ?>">
  <?php print $context_links; ?>
  <div class="native-plants-bottom-form-title">
    <div class="row">
      <div class="column tiny-12">
        <h2 class="thin hide-for-tiny hide-for-small" style="color: white;"><?php print $title_desktop; ?></h2>
        <h2 class="thin hide-for-medium hide-for-large hide-for-xlarge" style="color: white;"><?php print $title_mobile; ?></h2>
      </div>
    </div>
  </div>
  <div class="native-plants-bottom-form">
    <div class="row">
      <div class="column medium-7">
        <?php print $description; ?>
      </div>
      <div class="column medium-5">
        <?php print $form; ?>
      </div>
    </div>
  </div>
</div>
