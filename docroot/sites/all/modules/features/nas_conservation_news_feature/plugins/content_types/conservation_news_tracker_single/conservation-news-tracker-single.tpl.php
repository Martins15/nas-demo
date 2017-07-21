<?php

/**
 * @file
 * Template for custom pane 2 editorial cards and 1 engagement card.
 *
 * Available variables:
 * - $teasers: Array of rendered news.
 * - $title: Pane's title.
 * - $more_link: Link to flyway news listing.
 * - $additional_classes: Additional html classes for wrapper.
 * - $space_top: Flag indicating to add additional top padding.
 * - $space_between: Flag indicating to add additional padding between rows.
 * - $space_bottom: Flag indicating to add additional bottom padding.
 */
?>
<div class="conservation-news-block">
  <?php if ($image): ?>
    <div class="conservation-news-image">
      <?php print $image; ?>
    </div>
  <?php endif; ?>
  <?php if ($title && $override_title_heading): ?>
  <<?php print $override_title_heading; ?>
  <?php if ($title_classes): ?>
    class="<?php print $title_classes; ?>"
  <?php endif; ?>
  <?php if ($title_id): ?>
    id="<?php print $title_id; ?>"
  <?php endif; ?>>
  <?php print $title; ?>
  </<?php print $override_title_heading; ?>>
  <?php endif; ?>
  <?php if ($content): ?>
    <?php print $content; ?>
  <?php endif; ?>
</div>