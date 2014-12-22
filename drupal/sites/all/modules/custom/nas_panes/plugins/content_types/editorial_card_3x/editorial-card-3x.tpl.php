<?php
/**
 * @file
 * Template to custom pane flyway_in_the_news.
 *
 * Available variables:
 *  $contextual_links - contextual links.
 *  $additional_classes - additional html classes for wrapper.
 *  $title - pane's title.
 *  $more_link - link to flyway news listing.
 *  $teasers - array of rendered news.
 */
?>

<?php if ($teasers || $contextual_links): ?>
<div class="card-set <?php print $additional_classes; ?> contextual-links-region">
  <?php print $contextual_links; ?>
  <?php if ($title || $more_link): ?>
    <div class="row section-header<?php if (!empty($spacetop)): ?> space-top<?php endif; ?>">
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

  <div class="row space-bottom double">
    <?php foreach ($teasers as $teaser): ?>
      <?php if (is_string($teaser)): ?>
        <?php print $teaser; ?>
      <?php elseif (is_array($teaser)): ?>
        <div class="columns large-4">
          <div class="editorial-card collapse-minimal">
            <div class="editorial-card-photo">
              <?php print $teaser['linked_image']; ?>
            </div>
            <div class="editorial-card-content short">
              <?php print $teaser['category_link']; ?>
              <h4 class="editorial-card-title"><?php print $teaser['title']; ?></h4>
              <?php if (!empty($teaser['excerpt'])): ?>
                <p><?php print $teaser['excerpt']; ?></p>
              <?php endif; ?>
              <p><em><?php print $teaser['readmore_link']; ?></em></p>
            </div>
          </div>
        </div>
      <?php endif; ?>
    <?php endforeach; ?>
  </div>
</div>
<?php endif; ?>