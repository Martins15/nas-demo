<?php
/**
 * @file
 * List preview template.
 */
?>

<div class="row share-pane space-top space-bottom">
  <div class="column large-push-1 medium-8 large-6">
    <?php print $text; ?>
  </div>
  <div class="column large-push-1 medium-4 large-5 share-pane--icons">
    <span class="hide-for-small hide-for-tiny"><?php print $label_desktop; ?></span>
    <span class="hide-for-medium hide-for-large hide-for-xlarge"><?php print $label_mobile; ?></span>
    <a class="social-sharing-icon blue small" target="_blank" href="<?php print $twitter_url; ?>"><i class="icon-twitter"></i></a>
    <a class="social-sharing-icon blue small" target="_blank" href="http://www.facebook.com/sharer/sharer.php?u=<?php print $permalink; ?>"><i class="icon-facebook"></i></a>
  </div>
</div>
