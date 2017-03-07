<?php

/**
 * @file
 * Custom theme implementation to display a node.
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>" <?php print $attributes; ?>>
  <div class="magazin-issue-cover editorial-card-photo">
    <?php print render($content['field_issue_cover']); ?>
  </div>
  <div class="magazin-issue-title">
    <?php print $title_link; ?>
  </div>
  <div class="magazin-issue-article">
    <h4><?php print render($magazine_issue_article); ?></h4>
  </div>
</div>
