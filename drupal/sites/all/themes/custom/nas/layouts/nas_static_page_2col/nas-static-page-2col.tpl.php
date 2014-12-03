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

<div class="bg-respond hero small <?php print !empty($color_mode_gradient) ? $color_mode_gradient : 'dark'; ?>-gradient <?php print !empty($color_mode_text) ? $color_mode_text : 'light'; ?>-text expand">
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
  <div class="column"><span class="hero-attribution-text extra">Photo: <?php print $content['header_hero_attr_text']; ?></span></div>
</div>
<?php endif; ?>
<?php print $content['nav_menu']; ?>
<section class="global-content with-padding">
  <div class="row">
    <div class="large-8 columns text-container">
      <header class="article-header row">
        <div class="large-12 large-centered columns hide-for-large hide-for-xlarge">
          <?php print $content['header']; ?>
        </div>
      </header>
      <?php print $content['main']; ?>
    </div>
    <div class="large-4 columns sidebar">
      <div class="engagement-card">
        <div class="engagement-card-content no-min-height">
          <h3 class="engagement-card-headline">Help the Plight of the Albatross</h3>
          <p>These magnificent birds die tragic deaths, becoming entangled in fishing lines.</p>
          <div class="engagement-card-cta">
            <a href="#" class="button tomato xlarge">Endorse New Legislation</a>
          </div>
        </div>
        <div class="engagement-card-photo">
          <img src="<?php print base_path() . path_to_theme() . '/img/'; ?>engagement-card-1.jpg" alt="">
        </div>
      </div>
      <?php print $content['right']; ?>
    </div>
  </div>
  <?php print $content['related']; ?>
  <section class="card-set bg-1">
    <?php print $content['card_set']; ?>
    <div class="row">
      <div class="column">
        <h1 class="card-set-heading">Here&rsquo;s how you can make a difference</h1>
      </div>
    </div>
    <div class="row card-set-wrapper">
      <div class="clearfix card-set-scroller">
        <div class="tiny-4 columns">
          <div class="engagement-card">
            <div class="engagement-card-content">
              <h3 class="engagement-card-headline">Save the Brown Pelican</h3>
              <p>Numerous oil spills along the Gulf Coast have threatened thousands of native birds.</p>
              <div class="engagement-card-cta">
                <a href="#" class="button tomato large">Endorse New Legislation</a>
              </div>
            </div>
            <div class="engagement-card-photo">
              <img src="<?php print base_path() . path_to_theme() . '/img/'; ?>engagement-card-1.jpg" alt="">
            </div>
          </div>
        </div>
        <div class="tiny-4 columns">
          <div class="engagement-card">
            <div class="engagement-card-content">
              <h3 class="engagement-card-headline">Join Audubon’s Volunteers Days</h3>
              <p>Learn how you can make a real, lasting difference in your own community.</p>
              <div class="engagement-card-cta">
                <a href="#" class="button tomato large">Become a Volunteer</a>
              </div>
            </div>
            <div class="engagement-card-photo">
              <img src="<?php print base_path() . path_to_theme() . '/img/'; ?>engagement-card-2.jpg" alt="">
            </div>
          </div>
        </div>
        <div class="tiny-4 columns">
          <div class="engagement-card">
            <div class="engagement-card-content">
              <h3 class="engagement-card-headline">Adopt a Bird: Sandhill Crane</h3>
              <p>Online adoptions allow you to help Audubon protect birds and their habitats.</p>
              <div class="engagement-card-cta">
                <a href="#" class="button tomato large">Adopt a Bird</a>
              </div>
            </div>
            <div class="engagement-card-photo">
              <img src="<?php print base_path() . path_to_theme() . '/img/'; ?>engagement-card-3.jpg" alt="">
            </div>
          </div>
        </div>
      </div>
    </div>
    <div class="row">
      <div class="card-set-dotslight ">
        <div class="dot active"></div>
        <div class="dot"></div>
        <div class="dot"></div>
      </div>
    </div>
    <div class="row">
      <div class="card-set-social social-sharing">
        <span class="social-sharing-caption white">Spread the word. It&rsquo;s the least you can do.</span>
        <a class="social-sharing-icon white" href="#"><i class="icon-twitter"></i></a>
        <a class="social-sharing-icon white" href="#"><i class="icon-facebook"></i></a>
        <a class="social-sharing-icon white" href="#"><i class="icon-mail"></i></a>
      </div>
    </div>
  </section>
</section>