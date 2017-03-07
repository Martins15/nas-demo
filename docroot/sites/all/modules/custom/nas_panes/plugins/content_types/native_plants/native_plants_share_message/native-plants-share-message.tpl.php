<?php

/**
 * @file
 * Native Plants Share message template.
 */
?>
<div class="native-plants__socials vertical-spacing--bottom--half<?php print !empty($context_links) ? ' contextual-links-region' : ''; ?> <?php print $classes; ?>">
  <?php print $context_links; ?>
  <div class="row">
    <div class="column medium-10">
      <h1 class="hide-for-medium hide-for-small hide-for-tiny"><?php print $title_desktop; ?></h1>
      <h1 class="hide-for-large hide-for-xlarge"><?php print $title_mobile; ?></h1>
    </div>
    <div class="column medium-6">
      <textarea cols="30" rows="2"><?php print $share_text; ?></textarea>
    </div>
    <div class="column medium-6 social-sharing-block">
      <a class="social-sharing-icon blue small facebook" target="_blank" href="http://www.facebook.com/sharer/sharer.php?u=<?php print $share_url; ?>"><i class="icon-facebook"></i></a>
      <a class="social-sharing-icon blue small twitter" target="_blank" href="<?php print $twitter_url; ?>"><i class="icon-twitter"></i></a>
    </div>
  </div>
</div>
