<?php
/**
 * @file
 * Conservation Strategy News template file.
 */
?>

<div class="row section-header space-top double">
  <?php if (!$hide_title) : ?>
    <div class="column">
      <h2 class="thin"><?php print $title; ?></h2>
    </div>
  <?php endif; ?>
</div>
<div class="row <?php print !empty($contextual_links) ? 'contextual-links-region' : ''; ?>">
  <?php print $contextual_links; ?>
  <div class="sidebar large-push-8 large-4 columns">
    <?php foreach ($featured_news as $item) : ?>
      <?php print $item; ?>
    <?php endforeach; ?>
  </div>

  <div class="large-8 large-pull-4 columns index-list">
    <?php print $news_list; ?>
  </div>
</div>
