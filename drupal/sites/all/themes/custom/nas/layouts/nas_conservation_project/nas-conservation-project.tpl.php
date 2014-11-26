<?php
/**
 * @file
 * Template implementation to display the panel's layout.
 *
 * Custom variables:
 * $color_mode_gradient string - Used as class for hero tag.
 * $color_mode_text string - Used as class for hero tag.
 */
?>

<div class="hero <?php print !empty($color_mode_gradient) ? $color_mode_gradient : 'dark'; ?>-gradient <?php print !empty($color_mode_text) ? $color_mode_text : 'light'; ?>-text">
  <div class="hero-image">
    <?php print $content['hero_image']; ?>
  </div>
  <div class="row">
    <div class="hero-header">
      <div class="column">
        <?php print $content['strategy_icon']; ?>
        <h4 class="hero-slug"><?php print $content['strategy']; ?></h4>
        <h2 class="hero-title big<?php if ($content['strategy_icon']): ?> with-icon<?php endif; ?>"><?php print $content['title']; ?></h2>
        <p class="hero-blurb<?php if ($content['strategy_icon']): ?> with-icon<?php endif; ?>"><?php print $content['subtitle']; ?></p>
      </div>
    </div>
  </div>
</div>
<div class="hero-attribution row">
  <?php if (!empty($content['hero_attribution'])): ?>
    <p class="column">Photo: <?php print $content['hero_attribution']; ?></p>
  <?php endif; ?>
</div>
<section class="global-content with-padding">
  <div class="row">
    <div class="large-8 columns text-container">
      <?php print $content['body']; ?>
    </div>
    <div class="large-4 columns sidebar">
      <section class="sidebar-section">
        <?php if (!empty($page_link)): ?>
        <div class="social-sharing align-right">
          <span class="social-sharing-caption small">Share this project</span>
            <a target="_blank" href="http://twitter.com/share?url=/&amp;text=<?php print $page_link; ?>" class="social-sharing-icon blue small"><i class="icon-twitter"></i></a>
            <a target="_blank" href="http://www.facebook.com/sharer/sharer.php?u=<?php print $page_link; ?>" class="social-sharing-icon blue small"><i class="icon-facebook"></i></a>
            <a href="mailto:?subject=<?php print $page_title; ?>&body=<?php print $page_link; ?>" class="social-sharing-icon blue small"><i class="icon-mail"></i></a>
        </div>
        <?php endif; ?>
      </section>
      <div class="row">
        <?php print $content['right']; ?>
        <section class="sidebar-section medium-6 large-12 columns">
          <div class="sidebar-section editorial-card">
            <div class="editorial-card-photo">
              <a href="#"><img src="<?php print base_path() . drupal_get_path('theme', 'nas') . '/img/'; ?>editorial-card-13.jpg" alt=""></a>
            </div>
            <div class="editorial-card-banner green"><i class="icon-map"></i> Local Chapters &amp; Centers</div>
            <div class="editorial-card-content">
              <ul class="no-bullets item-margin">
                <li>
                  <h5 class="editorial-card-title blue close-heading"><a href="#">Anchorage Audubon Society</a></h5>
                  <small>(Anchorage, AK)</small>
                </li>
                <li>
                  <h5 class="editorial-card-title blue close-heading"><a href="#">Arctic Audubon Society</a></h5>
                  <small>(Fairbanks, AK)</small>
                </li>
                <li>
                  <h5 class="editorial-card-title blue close-heading"><a href="#">Kodiak Audubon Society</a></h5>
                  <small>(Kodiak, AK)</small>
                </li>
              </ul>
              <hr />
              <a href="#" class="editorial-card-link sans">See all</a>
            </div>
          </div>
        </section>
      </div>
    </div>
  </div>
  <?php print $content['bottom']; ?>

  <section class="card-set bg-gray">
    <div class="row space-top">
      <div class="column">
        <h2 class="thin">Explore Other Conservation Projects</h2>
      </div>
    </div>
    <div class="row card-set-wrapper">
      <div class="clearfix card-set-scroller">
        <div class="tiny-4 columns">
          <div class="editorial-card">
            <div class="editorial-card-photo">
              <a href="#"><img src="<?php print base_path() . drupal_get_path('theme', 'nas') . '/img/'; ?>editorial-card-10.jpg" alt=""></a>
            </div>
            <div class="editorial-card-content">
              <a href="#" class="editorial-card-slug">Seas &amp; Shores</a>
              <h3 class="editorial-card-title"><a href="#">Here’s the Name of a Conservation Project</a></h3>
              <p>Along with the title, we should include a short description of the project. </p>
            </div>
          </div>
        </div>
        <div class="tiny-4 columns">
          <div class="editorial-card">
            <div class="editorial-card-photo">
              <a href="#"><img src="<?php print base_path() . drupal_get_path('theme', 'nas') . '/img/'; ?>editorial-card-11.jpg" alt=""></a>
            </div>
            <div class="editorial-card-content">
              <a href="#" class="editorial-card-slug">Seas &amp; Shores</a>
              <h3 class="editorial-card-title"><a href="#">Another Current Seas &amp; Shores Project</a></h3>
              <p>Along with the title, we should include a short description of the project. </p>
            </div>
          </div>
        </div>
        <div class="tiny-4 columns">
          <div class="editorial-card">
            <div class="editorial-card-photo">
              <a href="#"><img src="<?php print base_path() . drupal_get_path('theme', 'nas') . '/img/'; ?>editorial-card-12.jpg" alt=""></a>
            </div>
            <div class="editorial-card-content">
              <a href="#" class="editorial-card-slug">Seas &amp; Shores</a>
              <h3 class="editorial-card-title"><a href="#">Another Current Seas &amp; Shores Project</a></h3>
              <p>Along with the title, we should include a short description of the project. </p>
            </div>
          </div>
        </div>
      </div>
    </div>
    <div class="row space-bottom double">
      <div class="card-set-dots">
        <div class="dot active"></div>
        <div class="dot"></div>
        <div class="dot"></div>
      </div>
    </div>
  </section>
  <section class="card-set bg-1">
    <div class="row">
      <div class="column">
        <h1 class="card-set-heading pea-green">These birds need your help</h1>
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
              <img src="<?php print base_path() . drupal_get_path('theme', 'nas') . '/img/'; ?>engagement-card-1.jpg" alt="">
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
              <img src="<?php print base_path() . drupal_get_path('theme', 'nas') . '/img/'; ?>engagement-card-2.jpg" alt="">
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
              <img src="<?php print base_path() . drupal_get_path('theme', 'nas') . '/img/'; ?>engagement-card-3.jpg" alt="">
            </div>
          </div>
        </div>
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
        <span class="social-sharing-caption white">Spread the word. It&rsquo;s the least you can do.</span>
        <a class="social-sharing-icon white" href="#"><i class="icon-twitter"></i></a>
        <a class="social-sharing-icon white" href="#"><i class="icon-facebook"></i></a>
        <a class="social-sharing-icon white" href="#"><i class="icon-mail"></i></a>
      </div>
    </div>
  </section>
</section>
