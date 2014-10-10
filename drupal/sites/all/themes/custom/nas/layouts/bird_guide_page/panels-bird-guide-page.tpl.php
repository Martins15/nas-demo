<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
  <?php print $content['header']; ?>
</header>
<div class="bird-guide-search show">
  <div class="row">
    <div class="columns large-12 bird-guide-search-form">
      <?php print $content['bird_guide_search']; ?>
    </div>
  </div>
</div>
<section class="global-content">
  <div class="bird-card-grid">
    <?php print $content['bird_card_grid']; ?>
  </div>
  <?php print $content['in_the_news']; ?>
  <div class="bg-gray">
    <div class="row section-header">
      <div class="column">
        <h2 class="thin">Birds in the News</h2>
      </div>
      <div class="column">
        <ul class="section-nav inline-list hide-for-small hide-for-tiny">
          <li><a href="#">More News »</a></li>
        </ul>
      </div>
    </div>
    <div class="row">
      <div class="columns large-4">
        <div class="editorial-card collapse-minimal">
          <div class="editorial-card-photo">
            <img src="<?php print base_path() . path_to_theme() . '/img/editorial-card-14.jpg'; ?>" />
          </div>
          <div class="editorial-card-content short">
            <a href="" class="editorial-card-slug">In The News</a>
            <h4 class="editorial-card-title">Bird Death Toll Estimates from the BP Oil Spill</h4>
            <p><em><a class="editorial-card-link" href="#">Map of impacted areas</a></em></p>
          </div>
        </div>
      </div>
      <div class="columns large-4">
        <div class="editorial-card collapse-minimal">
          <div class="editorial-card-photo">
            <img src="<?php print base_path() . path_to_theme() . '/img/editorial-card-2.jpg'; ?>" />
          </div>
          <div class="editorial-card-content short">
            <a href="" class="editorial-card-slug">Citizen Science</a>
            <h4 class="editorial-card-title">Latest Data from the 2014 Great Backyard Bird Count</h4>
            <p><em><a href="#" class="editorial-card-link">Exlpore the results</a></em></p>
          </div>
        </div>
      </div>
      <div class="columns large-4">
        <div class="editorial-card collapse-minimal">
          <div class="editorial-card-photo">
            <img src="<?php print base_path() . path_to_theme() . '/img/editorial-card-3.jpg'; ?>" />
          </div>
          <div class="editorial-card-content short">
            <a href="" class="editorial-card-slug">Conservation</a>
            <h4 class="editorial-card-title">Clues to Conserving the Golden Eagle in Its DNA</h4>
            <p><em><a href="#" class="editorial-card-link">Genome sequencing yields new insights</a></em></p>
          </div>
        </div>
      </div>
    </div>
    <div class="row space-bottom double">
      <div class="columns">
        <ul class="section-nav inline-list hide-for-medium hide-for-large hide-for-xlarge">
          <li><a href="#">More News »</a></li>
        </ul>
      </div>
    </div>
  </div>
  <?php print $content['cards_set']; ?>
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
              <img src="<?php print base_path() . path_to_theme() . '/img/engagement-card-1.jpg'; ?>" alt="">
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
              <img src="<?php print base_path() . path_to_theme() . '/img/engagement-card-2.jpg'; ?>" alt="">
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
              <img src="<?php print base_path() . path_to_theme() . '/img/engagement-card-3.jpg'; ?>" alt="">
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
        <span class="social-sharing-caption white">Spread the word. It’s the least you can do.</span>
        <a class="social-sharing-icon white" href="#"><i class="icon-twitter"></i></a>
        <a class="social-sharing-icon white" href="#"><i class="icon-facebook"></i></a>
        <a class="social-sharing-icon white" href="#"><i class="icon-mail"></i></a>
      </div>
    </div>
  </section>
</section>