<?php
/**
 * @file
 * Template of Article layout with Fullscreen image.
 *
 * Available variables:
 *  - $color_mode_text: text color mode for hero image.
 *  - $color_mode_gradient: gradient color mode for hero image.
 *
 * @impove
 *   These variables only available when rendering in NAS theme, so have to be
 *   sure they are initialized or notices will be generated in panels edit
 *   interface.
 *
 * @see nas_preprocess_nas_article_fullscreen()
 */
?>
<?php print $content['magazine_bar']; ?>
<div class="hero <?php print !empty($color_mode_gradient) ? $color_mode_gradient : 'dark'; ?>-gradient <?php print !empty($color_mode_text) ? $color_mode_text : ''; ?>-text expand">
  <div class="hero-image">
    <?php print $content['big_image']; ?>
  </div> 
  <div class="row">
    <div class="hero-header hide-for-medium hide-for-small hide-for-tiny">
      <div class="columns large-10 large-centered">
        <?php print $content['header_hero']; ?>
      </div>
    </div>
  </div>
</div>
<?php if (trim($content['header_hero_attr_text'])): ?>
<div class="hero-attribution-fullscreen row">
  <div class="column"><span class="hero-attribution-text extra"><?php print $content['header_hero_attr_text']; ?></span></div>
</div>
<?php endif; ?>
<?php if (trim($content['header_hero_caption_text'])): ?>
<div class="hero-caption grey-bar">
  <div class="row">
    <div class="caption large-10 large-centered columns">
      <?php print $content['header_hero_caption_text']; ?>
    </div>
  </div>
</div>
<?php endif; ?>
<section class="global-content">
  <article class="article">
    <header class="article-header row">
      <div class="large-10 large-centered columns hide-for-large hide-for-xlarge">
        <?php print $content['header']; ?>
        <div class="article-meta clearfix hide-for-large hide-for-xlarge">
          <?php print $content['mobile_author']; ?>
        </div>
      </div>
    </header>
    <div class="article-body row">
      <div class="article-sidebar large-2 columns">
        <?php print $content['social']; ?>
        <section class="clearfix article-sidebar-section article-meta hide-for-tiny hide-for-small hide-for-medium">
          <?php print $content['author']; ?>
        </section>
        <section class="clearfix article-sidebar-section article-related-birds reflow reflow-into-body" data-reflow-class="article-aside half-width">
          <?php print $content['birds']; ?>
        </section>
        <?php print $content['left']; ?>
      </div>
      <div class="article-text large-10 columns reflow-body">
        <aside class="article-aside reflow reflow-into-body">
          <?php print $content['right']; ?>
        </aside>
        <?php print $content['main']; ?>
      </div>
    </div>
  </article>
  <section class="card-set">
    <?php print $content['card_set']; ?>

  </section>
  <?php print $content['article_more_features']; ?>
</section>