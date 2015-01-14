<?php
/**
 * @file
 * Template to custom pane Donate cards (3x).
 *
 * Available variables:
 *  $contextual_links - contextual links.
 *  $additional_classes - additional html classes for wrapper.
 *  $spacetop - flag indicating to add additional top padding.
 *  $title - pane's title.
 *  $teasers - array of rendered news.
 */
?>

<?php if ($teasers || $contextual_links): ?>
<div class="editorial-card-3x <?php print $additional_classes; ?> <?php print !empty($spacebottom) ? $spacebottom : ''; ?> contextual-links-region">
  <?php print $contextual_links; ?>
  <?php if ($title): ?>
    <div class="row section-header<?php if (!empty($spacetop)): ?> space-top<?php endif; ?><?php if (!empty($spacebetween)): ?> space-bottom<?php endif; ?>">
      <?php if ($title): ?>
      <div class="column">
        <h2 class="thin"><?php print $title; ?></h2>
      </div>
      <?php endif; ?>
    </div>
  <?php endif; ?>

  <?php foreach ($chunks as $teasers): ?>
    <div class="row card-set space-bottom">
    <?php foreach ($teasers as $teaser): ?>
      <?php if (is_string($teaser)): ?>
        <?php print $teaser; ?>
      <?php elseif (is_array($teaser)): ?>
        <div class="columns large-4">
          <div class="editorial-card<?php if (!$teaser['linked_image']): ?> editorial-card-no-image<?php endif; ?> collapse-minimal">
            <div class="editorial-card-photo">
              <?php print $teaser['linked_image']; ?>
            </div>
            <div class="editorial-card-content short">
              <h4 class="editorial-card-title"><?php print $teaser['title']; ?></h4>
              <?php if (!empty($teaser['excerpt'])): ?>
                <p><?php print $teaser['excerpt']; ?></p>
              <?php endif; ?>
            </div>
          </div>
        </div>
      <?php endif; ?>
    <?php endforeach; ?>
    </div>
  <?php endforeach; ?>
</div>
<?php endif; ?>