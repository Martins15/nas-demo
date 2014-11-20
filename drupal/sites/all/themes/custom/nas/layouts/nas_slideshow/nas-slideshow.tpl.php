<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>

<section class="global-content">

  <?php print $content['slideshow']; ?>
  <?php print $content['bottom']; ?>

  <div class="row section-header">
    <div class="column">
      <h2 class="thin">Related Features</h2>
    </div>
  </div>
  <div class="row feature-set dark space-bottom">
    <div class="columns small-6 large-3">
      <div class="editorial-card dark feature">
        <div class="editorial-card-photo">
          <img src="../../img/feature-1.jpg" alt="">
        </div>
        <div class="editorial-card-content">
          <a href="#" class="editorial-card-slug">From the Magazine</a>
          <a href="#">
            <h4 class="editorial-card-title">Why the Passenger Pigeon Went Extinct</h4>
          </a>
        </div>
      </div>
    </div>
    <div class="columns small-6 large-3">
      <div class="editorial-card dark feature">
        <div class="editorial-card-photo">
          <img src="../../img/feature-2.jpg" alt="">
        </div>
        <div class="editorial-card-content">
          <a href="#" class="editorial-card-slug">Slideshow</a>
          <a href="#">
            <h4 class="editorial-card-title">Audubon’s Priority Birds</h4>
          </a>
        </div>
      </div>
    </div>
    <div class="columns small-6 large-3">
      <div class="editorial-card dark feature">
        <div class="editorial-card-photo">
          <img src="../../img/feature-3.jpg" alt="">
        </div>
        <div class="editorial-card-content">
          <a href="#" class="editorial-card-slug">Story Map</a>
          <a href="#">
            <h4 class="editorial-card-title">Mapping the Arkansas National Wildlife Refuge</h4>
          </a>
        </div>
      </div>
    </div>
    <div class="columns small-6 large-3">
      <div class="editorial-card dark feature">
        <div class="editorial-card-photo">
          <img src="../../img/feature-4.jpg" alt="">
        </div>
        <div class="editorial-card-content">
          <a href="#" class="editorial-card-slug">From the Magazine</a>
          <a href="#">
            <h4 class="editorial-card-title">A Farm Bill that Will Benefit Birds—and Us</h4>
          </a>
        </div>
      </div>
    </div>
  </div>

  <section class="card-set bg-dark-gray">
    <div class="row">
      <div class="column">
        <h1 class="card-set-heading light-gray">Here’s how you can make a difference</h1>
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
        <span class="social-sharing-caption light-gray">Spread the word. It’s the least you can do.</span>
        <a class="social-sharing-icon light-gray" href="#"><i class="icon-twitter"></i></a>
        <a class="social-sharing-icon light-gray" href="#"><i class="icon-facebook"></i></a>
        <a class="social-sharing-icon light-gray" href="#"><i class="icon-mail"></i></a>
      </div>
    </div>
  </section>
</section>
