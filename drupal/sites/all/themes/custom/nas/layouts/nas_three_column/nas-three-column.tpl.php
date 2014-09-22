<?php
/**
 * @file
 * Template of NAS Three Column. Used in Press Release.
 */
?>
<header class="article-header row">
  <div class="large-10 large-centered columns">
    <?php print $content['header']; ?>
  </div>
</header>
<div class="article-body row reflow-body" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="article-text large-push-2 large-10 columns">
    <aside class="medium-12 article-aside small reflow reflow-into-sidebar-bottom" data-reflow-class="full-width">
      <?php print $content['right']; ?>
    </aside>
    <?php print $content['middle']; ?>
  </div>
  <div class="article-sidebar large-pull-10 large-2 columns">
    <?php print $content['left']; ?>
  </div>
</div>