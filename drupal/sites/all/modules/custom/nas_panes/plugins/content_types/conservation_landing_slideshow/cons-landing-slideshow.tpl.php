<?php
/**
 * @file
 * COnservation landing slideshow tpl file.
 *
 * Available variables:
 * - $contextual_links: rendered contextual links.
 * - $nodes_array_to_show: array of all images, titles, links, etc.
 */
?>
<section class="conservation-slider contextual-links-region">
  <?php print $contextual_links; ?>
  <div class="conservation-indicator row">
    <div class="column">
    <?php $active = TRUE;?>
    <?php foreach ($nodes_array_to_show as $node): ?>
      <a class="conservation-indicator-icon <?php $active ? print 'active' : ''; ?>"><img src="<?php print $node['image']; ?>" alt=""></a>
      <?php $active = FALSE; ?>
    <?php endforeach; ?>
    </div>
  </div>
  <div class="conservation-wrapper">
    <div class="conservation-scroller">
    <?php foreach ($nodes_array_to_show as $node): ?>
      <div class="slide">
        <div class="conservation-slide-image" style="background-image: url(<?php print $node['hero_image']; ?>)"> </div>
        <div class="conservation-slide-text text-container">
          <div class="row">
            <div class="column text-container">
              <h2 class="conservation-slide-headline thin"><?php print $node['title']; ?></h2>
              <?php print $node['summary']; ?>
              <p><em><?php print $node['learn_more_link']; ?></em></p>
              <?php if (isset($node['featured_node'])): ?>
              <div class="editorial-card index">
                <div class="small-4 large-2 columns hide-for-small hide-for-tiny">
                  <div class="editorial-card-photo">
                    <img src="<?php print $node['featured_node']['hero_image']; ?>" alt="">
                  </div>
                </div>
                <div class="small-8 large-8 end columns">
                  <div class="editorial-card-content">
                    <img class="editorial-card-inline-photo" src="<?php print base_path() . drupal_get_path('theme', 'nas') . '/img/editorial-card-index-9.jpg'; ?>" alt="">
                    <a class="editorial-card-slug"><?php print t('Featured Project'); ?></a>
                    <h4 class="editorial-card-title"><?php print $node['featured_node']['title']; ?></h4>
                    <?php print $node['featured_node']['summary']; ?>
                  </div>
                </div>
              </div>
              <?php endif; ?>
            </div>
          </div>
        </div>
      </div>
    <?php endforeach; ?>
    </div>
    <a class="conservation-slider-button prev"></a>
    <a class="conservation-slider-button next"></a>
  </div>
</section>