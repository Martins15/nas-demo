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
<div class="hero-attribution row">
  <div class="column"><span class="hero-attribution-text extra"><?php print $content['header_hero_attr_text']; ?></span></div>
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
      <div class="article-text large-push-2 large-10 columns reflow-body">
        <aside class="article-aside reflow reflow-into-body">
          <?php print $content['right']; ?>
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
        </aside>
        <?php print $content['main']; ?>
      </div>
      <div class="article-sidebar large-pull-10 large-2 columns">
        <?php print $content['social']; ?>
        <section class="clearfix article-sidebar-section article-meta hide-for-tiny hide-for-small hide-for-medium">
          <?php print $content['author']; ?>
        </section>
        <section class="clearfix article-sidebar-section article-related-birds reflow reflow-into-body" data-reflow-class="article-aside half-width">
          <?php print $content['birds']; ?>
        </section>
        <?php print $content['left']; ?>
      </div>
    </div>
  </article>
  <section class="card-set">
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
      <div class="card-set-dots">
        <div class="dot active"></div>
        <div class="dot"></div>
        <div class="dot"></div>
      </div>
    </div>
    <div class="row">
      <div class="card-set-social social-sharing">
        <span class="social-sharing-caption pea-green">Spread the word. It&rsquo;s the least you can do.</span>
        <a class="social-sharing-icon pea-green" href="#"><i class="icon-twitter"></i></a>&nbsp;<a class="social-sharing-icon pea-green" href="#"><i class="icon-facebook"></i></a>&nbsp;<a class="social-sharing-icon pea-green" href="#"><i class="icon-mail"></i></a>
      </div>
    </div>
  </section>
</section>