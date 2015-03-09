<?php
/**
 * @file
 * Template to custom pane flyway_in_the_news.
 *
 * Available variables:
 *  $contextual_links - contextual links.
 *  $additional_classes - additional html classes for wrapper.
 *  $spacetop - flag indicating to add additional top padding.
 *  $title - pane's title.
 *  $more_link - link to flyway news listing.
 *  $teasers - array of rendered news.
 */
?>

<?php if ($teasers || $contextual_links): ?>
<div class="editorial-card-3x <?php print $additional_classes; ?> <?php print !empty($spacebottom) ? $spacebottom : ''; ?> contextual-links-region">
  <?php print $contextual_links; ?>
  <?php if ($title || $more_link): ?>
    <div class="row section-header<?php if (!empty($spacetop)): ?> space-top<?php endif; ?><?php if (!empty($spacebetween)): ?> space-bottom<?php endif; ?>">
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

  <?php foreach ($chunks as $teasers): ?>
    <div class="row card-set space-bottom">
    <?php foreach ($teasers as $teaser): ?>
      <?php print $teaser; ?>
    <?php endforeach; ?>
    </div>
  <?php endforeach; ?>
</div>
<?php endif; ?>