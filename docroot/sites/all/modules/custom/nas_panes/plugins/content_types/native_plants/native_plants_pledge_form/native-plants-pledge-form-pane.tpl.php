<?php
/**
 * @file
 * Template for Native Plants pledge form pane.
 */
?>
<div class="native-plants__connect vertical-spacing--top vertical-spacing--bottom--double<?php print !empty($context_links) ? ' contextual-links-region' : ''; ?> <?php print $classes; ?>">
  <?php print $context_links; ?>
  <div class="row">
    <div class="column medium-6">
      <h1 class="hide-for-medium hide-for-small hide-for-tiny"><?php print $title_desktop; ?></h1>
      <h1 class="hide-for-large hide-for-xlarge"><?php print $title_mobile; ?></h1>
    </div>
    <div class="column medium-6">
      <?php print $description; ?>
      <?php print $form; ?>
    </div>
  </div>
</div>
