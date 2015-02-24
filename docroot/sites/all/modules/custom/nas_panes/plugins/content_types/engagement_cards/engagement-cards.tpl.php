<?php
/**
 * @file
 * Template to custom pane engagement_cards.
 *
 * Available variables:
 *  $title - title.
 *  $contextual_links - contextual links.
 *  $teasers - array of rendered cards.
 */
?>
<div class="row contextual-links-region">
<?php print $contextual_links; ?>
  <div class="column">
    <h1 class="card-set-heading pea-green"><?php print $title; ?></h1>
  </div>
</div>
<div class="row card-set-wrapper">
  <div class="clearfix card-set-scroller">
  <?php foreach ($teasers as $teaser): ?>
    <div class="tiny-4 columns">
      <?php print $teaser; ?>
    </div>
  <?php endforeach; ?>
  </div>
</div>
<div class="row">
  <div class="card-set-dots light">
    <div class="dot active"></div>
    <div class="dot"></div>
    <div class="dot"></div>
  </div>
</div>
<div class="row">
  <div class="card-set-social social-sharing">
    <span class="social-sharing-caption white"><?php print t('Spread the word. It’s the least you can do.'); ?></span>
    <a class="social-sharing-icon white" target="_blank" href="http://twitter.com/share?url=/&amp;text=<?php print t('Join me and help save %23birds. Learn more about @audubonsociety\'s work to protect the habitat that supports us all: http://audubon.org'); ?>"><i class="icon-twitter"></i></a>
    <a class="social-sharing-icon white" target="_blank" href="http://www.facebook.com/sharer/sharer.php?u=http://audubon.org"><i class="icon-facebook"></i></a>
  </div>
</div>
