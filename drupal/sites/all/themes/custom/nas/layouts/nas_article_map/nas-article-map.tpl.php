<?php
/**
 * @file
 * Template of Article layout with Map.
 */
?>
<div class="hero small no-padding with-map" style="background-color: #F4F3F0;">
  <div class="hero-map" id="map-canvas">
    <?php print $content['map']; ?>
  </div>
</div>
<section class="global-content">
  <article class="article">
    <header class="article-header row">
      <div class="large-10 large-centered columns">
        <?php print $content['header']; ?>      
        <div class="article-meta clearfix hide-for-large hide-for-xlarge">
          <?php print $content['mobile_author']; ?>
        </div>
      </div>
    </header>
    <div class="article-body row">
      <div class="article-text large-push-2 large-10 columns reflow-body">
        <?php print $content['right']; ?>
        <aside class="article-aside reflow reflow-into-body">
          <div class="engagement-card">
            <div class="engagement-card-content no-min-height">
              <h3 class="engagement-card-headline">Help the Plight of the Albatross</h3>
              <p>These magnificent birds die tragic deaths, becoming entangled in fishing lines.</p>
              <div class="engagement-card-cta">
                <a href="#" class="button tomato large">Endorse New Legislation</a>
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
          <h5><?php print t('Birds in This Story'); ?></h5>
          <?php print $content['birds']; ?>
        </section>
        <?php print $content['left']; ?>
        <section class="clearfix article-sidebar-section popular-stories story-list small reflow reflow-into-bottom">
          <h5>Popular Stories</h5>
          <ul>
            <li><a href="#">With So Many Snowies to Study, Scientists are Discovering How Little We Know About This Bird</a></li>
            <li><a href="#">Photo of the Day: Lilac-Breasted Roller</a></li>
            <li><a href="#">Crows Understand Caw-se and Effect</a></li>
            <li><a href="#">Green Energy: Can We Save the Planet and Save Birds?</a></li>
            <li><a href="#">Nature Photography: Objectivitiy, Manipulation, and Ethics</a></li>
          </ul>
        </section>
      </div>
    </div>
  </article>
  <section class="card-set">
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