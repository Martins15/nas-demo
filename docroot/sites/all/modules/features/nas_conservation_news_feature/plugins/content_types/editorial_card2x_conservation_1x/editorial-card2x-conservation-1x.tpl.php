<?php

/**
 * @file
 * Template for custom pane 2 editorial cards and 1 Conservation News block.
 *
 * Available variables:
 * - $teasers: Array of rendered news.
 * - $more_link: Link to flyway news listing.
 * - $additional_classes: Additional html classes for wrapper.
 * - $space_top: Flag indicating to add additional top padding.
 * - $space_between: Flag indicating to add additional padding between rows.
 * - $space_bottom: Flag indicating to add additional bottom padding.
 */
?>

<?php if ($teasers): ?>
  <div class="editorial-card-3x editorial-card-2x-conservation-news-block <?php print $additional_classes; ?> <?php print !empty($space_bottom) ? $space_bottom : ''; ?><?php print $space_top ? ' space-top' : ''; ?>">
    <?php if ($title || $more_link): ?>
      <div class="row section-header<?php print $space_between ? ' space-bottom' : ''; ?>">
        <?php if ($title): ?>
          <div class="column">
            <h2 class="thin">
              <?php print $title; ?>
              <?php if ($more_link): ?>
                <small class="hide-for-large hide-for-xlarge right">
                  <?php print $more_link; ?>
                </small>
              <?php endif; ?>
            </h2>
          </div>
        <?php endif; ?>
        <?php if ($more_link): ?>
          <div class="column hide-for-tiny hide-for-small hide-for-medium">
            <ul class="section-nav inline-list">
              <li class="first"><?php print $more_link; ?></li>
            </ul>
          </div>
        <?php endif; ?>
      </div>
    <?php endif; ?>

    <div class="row card-set" data-equalizer data-equalizer-mq="large-up">
      <?php foreach ($teasers as $teaser): ?>
        <?php print $teaser; ?>
      <?php endforeach; ?>
    </div>
  </div>
<?php endif; ?>
