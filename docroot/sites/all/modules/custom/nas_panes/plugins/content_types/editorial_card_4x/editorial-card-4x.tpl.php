<?php
/**
 * @file
 * Template to custom pane flyway_in_the_news.
 *
 * Available variables:
 *  $contextual_links - contextual links.
 *  $title - pane's title.
 *  $more_link - link to flyway news listing.
 *  $teasers - array of rendered news.
 */
?>

<?php if ($title || $more_link): ?>
  <div class="row section-header<?php if ($spacetop): ?> space-top<?php endif; ?>">
    <div class="column">
      <?php if ($title): ?>
        <h2 class="thin"><?php print $title; ?></h2>
      <?php endif; ?>
    </div>
    <div class="column">
      <?php if ($more_link): ?>
        <ul class="inline-list section-nav">
          <li><?php print $more_link; ?></li>
        </ul>
      <?php endif; ?>
    </div>
  </div>
<?php endif; ?>
<div class="row<?php if ($spacebetween): ?> space-bottom<?php endif; ?>">
  <?php print $contextual_links; ?>
  <?php foreach ($teasers as $teaser): ?>
    <div class="columns large-3">
      <?php print $teaser; ?>
    </div>
  <?php endforeach; ?>
</div>
