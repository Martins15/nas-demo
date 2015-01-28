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
<?php if (!empty($content['hero_image'])): ?>
  <div class="bg-respond hero small <?php print !empty($color_mode_gradient) ? $color_mode_gradient : 'dark'; ?>-gradient <?php print !empty($color_mode_text) ? $color_mode_text : 'light'; ?>-text">
    <div class="hero-image">
      <?php print $content['hero_image']; ?>
    </div>
    <div class="row">
      <div class="hero-header hide-for-medium hide-for-small hide-for-tiny">
        <div class="columns large-12 large-centered">
          <?php print $content['header_hero']; ?>
          <p class="hero-blurb"><?php print $content['subtitle']; ?></p>
        </div>
      </div>
    </div>
  </div>
  <?php if (trim($content['header_hero_attr_text'])): ?>
  <div class="hero-attribution row">
    <div class="column"><span class="hero-attribution-text extra"><?php print $content['header_hero_attr_text']; ?></span></div>
  </div>
  <?php endif; ?>
<?php endif; ?>
<?php print $content['nav_menu']; ?>
<section class="global-content with-padding static-page-content">
  <?php if (empty($content['hero_image']) || arg(0) == 'admin'): ?>
  <header class="row">
    <div class="large-pull-1 large-10 large-centered columns">
      <?php print $content['header_no_image']; ?>
      <p class="deck"><?php print $content['subtitle']; ?></p>
    </div>
  </header>
  <?php endif; ?>
  <?php if (!empty($content['hero_image'])): ?>
  <header class="row hide-for-large hide-for-xlarge">
    <div class="large-12 large-centered columns">
      <div class="clearfix">
        <?php print $content['header']; ?>
        <p class="deck"><?php print $content['subtitle']; ?></p>
      </div>
    </div>
  </header>
  <?php endif; ?>
  <div class="row">
    <div class="text-container columns">
      <?php print $content['main']; ?>
    </div>
  </div>
  <?php print $content['related']; ?>
  <section class="card-set bg-1">
    <?php print $content['card_set']; ?>
  </section>
</section>
