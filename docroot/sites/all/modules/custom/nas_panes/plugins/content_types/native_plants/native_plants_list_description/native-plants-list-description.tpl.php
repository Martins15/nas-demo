<?php
/**
 * @file
 * Native Plants List description template.
 */
?>
<div class="row">
  <div class="columns large-8 large-push-2">
    <h3 class="thin"><?php print $title; ?></h3>
  </div>
</div>
<div class="row">
  <div class="text-container columns large-8 large-push-2">
    <?php print $text_top; ?>
    <p><?php print l($permalink, $permalink); ?></p>
    <div class="row share-pane space-bottom">
      <div class="column medium-4 large-5 share-pane--icons">
        <span style="margin-right: 30px;">Share your list</span>
        <a class="social-sharing-icon blue small" target="_blank" href="<?php print $twitter_url; ?>"><i class="icon-twitter"></i></a>
        <a class="social-sharing-icon blue small" target="_blank" href="http://www.facebook.com/sharer/sharer.php?u=<?php print $permalink; ?>"><i class="icon-facebook"></i></a>
      </div>
    </div>
    <?php print $text_bottom; ?>
  </div>
</div>