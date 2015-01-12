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
  <div class="row section-header<?php if ($spacetop): ?> space-top<?php endif; ?><?php if ($spacebetween): ?> space-bottom<?php endif; ?>">
    <?php if ($title): ?>
    <div class="column">
      <h2 class="thin"><?php print $title; ?></h2>
    </div>
    <?php endif; ?>
    <?php if ($more_link): ?>
    <div class="column">
      <ul class="section-nav inline-list">
        <li><?php print $more_link; ?></li>
      </ul>
    </div>
    <?php endif; ?>
  </div>
<?php endif; ?>

<div class="row <?php print $spacebottom; ?> contextual-links-region">
  <?php print $contextual_links; ?>
  <?php foreach ($references as $reference): ?>
    <div class="columns large-3">
      <div class="editorial-card collapse-minimal">
        <div class="editorial-card-photo">
          <?php print $reference['image_link']; ?>
        </div>
        <div class="editorial-card-content short">
          <?php print $reference['category']; ?>
          <h4 class="editorial-card-title"><?php print $reference['title_link']; ?></h4>
        </div>
      </div>
    </div>
  <?php endforeach; ?>
</div>
