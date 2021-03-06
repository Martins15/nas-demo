<?php

/**
 * @file
 * Template to custom pane flyway_in_the_news.
 *
 * Available variables:
 *  $contextual_links - contextual links.
 *  $title - pane's title.
 *  $teasers - array of rendered news.
 *  $spacetop - flag indicating to add additional top padding.
 *  $spacebetween - flag indicating to add padding between content and title.
 *  $spacebottom - bottom padding class string.
 */
?>

<?php if ($title || $more_link): ?>
  <div class="row section-header<?php print !empty($spacetop) ? ' space-top' : ''; ?><?php print !empty($spacebetween) ? ' space-bottom' : ''; ?>">
    <?php if ($title): ?>
        <div class="column">
            <h2 class="thin"><?php print $title; ?></h2>
        </div>
    <?php endif; ?>
    <?php if ($more_link): ?>
        <div class="column">
            <ul class="section-nav inline-list">
                <li class="first"><?php print $more_link; ?></li>
            </ul>
        </div>
    <?php endif; ?>
  </div>
<?php endif; ?>

<div class="row <?php print !empty($spacebottom) ? $spacebottom : ''; ?> contextual-links-region editorial-grid-content-wrapper">
  <?php print $contextual_links; ?>
  <div class="column">
    <?php print $content; ?>
  </div>
</div>
