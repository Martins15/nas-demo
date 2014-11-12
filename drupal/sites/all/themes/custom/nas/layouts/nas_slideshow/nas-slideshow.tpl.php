<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>

<section class="global-content">
  <div class="slideshow clearfix standalone">
    <div class="slideshow-indicator row">
      <div class="column large-offset-9 large-3">
        <p><i class="ss-icon icon-chevron-left inactive slideshow-control prev"></i> <span class="indicator-current">1</span> of <span class="indicator-total">10</span> <i class="ss-icon icon-chevron-right slideshow-control next"></i></p>
        <p class="social-sharing align-right hide-for-small hide-for-tiny">
          <a href="#" class="social-sharing-icon white small"><i class="icon-twitter"></i></a>
          <a href="#" class="social-sharing-icon white small"><i class="icon-facebook"></i></a>
          <a href="#" class="social-sharing-icon white small"><i class="icon-pinterest"></i></a>
          <a href="#" class="social-sharing-icon white small"><i class="icon-mail"></i></a>
        </p>
      </div>
    </div>
    <a href="#" class="slideshow-button slideshow-control prev hide-for-tiny hide-for-small"></a>
    <a href="#" class="slideshow-button slideshow-control next hide-for-tiny hide-for-small"></a>
    <div id="slideshow-wrapper" class="slideshow-wrapper">
      <div class="slideshow-scroller">
        <div class="slide title-slide">
          <div class="slide-img">
            <img src="<!-- @path slideshow-2.jpg -->" alt="" />
          </div>
          <div class="title-slide-content row">
            <div class="columns large-10 large-offset-1 text-container">
              <h1 class="thin"><?php print $content['title']; ?></h1>
              <p class="deck"><?php print $content['subtitle']; ?></p>
              <p><a href="#" class="title-slide-button button pea-green xlarge slideshow-control next">View Slideshow</a></p>
              <div class="social-sharing align-left hide-for-small hide-for-medium hide-for-tiny">
                <span class="social-sharing-caption white">Share this</span>
                <a href="#" class="social-sharing-icon white"><i class="icon-twitter"></i></a>
                <a href="#" class="social-sharing-icon white"><i class="icon-facebook"></i></a>
                <a href="#" class="social-sharing-icon white"><i class="icon-pinterest"></i></a>
                <a href="#" class="social-sharing-icon white"><i class="icon-mail"></i></a>
              </div>
            </div>
          </div>
        </div>
        <div class="slide">
          <div class="slide-img">
            <img src="<!-- @path slideshow-1.jpg -->" alt="" />
          </div>
          <div class="row">
            <div class="large-9 columns">
              <div class="slide-caption">The whooper's black primary feathers are unmistakable, but they aren't visible when its wings are folded. Photograph by Blake Gordon</div>
            </div>
          </div>
        </div>
        <div class="slide">
          <div class="slide-img">
            <img src="<!-- @path slideshow-2.jpg -->" alt="" />
          </div>
          <div class="row">
            <div class="large-9 columns">
              <div class="slide-caption">The 115,000-acre Aransas National Wildlife Refuge, the winter home of most of the only self-sustaining wild population of whooping cranes. Photograph by Blake Gordon</div>
            </div>
          </div>
        </div>
        <div class="slide portrait">
          <div class="slide-img">
            <img src="<!-- @path slideshow-3.jpg -->" alt="" />
          </div>
          <div class="row">
            <div class="large-9 columns">
              <div class="slide-caption">A whooper in the Aransas National Wildlife Refuge moves with a smooth, stately elegance, giving the appearance of effortless gliding, its legs straight, its head and neck erect. Photograph by Blake Gordon</div>
            </div>
          </div>
        </div>
        <div class="slide">
          <div class="slide-img">
            <img src="<!-- @path slideshow-4.jpg -->" alt="" />
          </div>
          <div class="row">
            <div class="large-9 columns">
              <div class="slide-caption">For centuries the cranes have wintered in the Aransas Refuge, though the habitat has changed over time--in part to benefit these ancient birds, as with this manmade island. Photograph by Blake Gordon</div>
            </div>
          </div>
        </div>
        <div class="slide">
          <div class="slide-img">
            <img src="<!-- @path slideshow-5.jpg -->" alt="" />
          </div>
          <div class="row">
            <div class="large-9 columns">
              <div class="slide-caption">Two cranes used the managed wetlands on the Myrtle Foester-Whitmire tract in the Aransas National Wildlife Refuge all winter. Photograph by Blake Gordon</div>
            </div>
          </div>
        </div>
        <div class="slide">
          <div class="slide-img">
            <img src="<!-- @path slideshow-6.jpg -->" alt="" />
          </div>
          <div class="row">
            <div class="large-9 columns">
              <div class="slide-caption">Photograph by Blake Gordon</div>
            </div>
          </div>
        </div>
        <div class="slide portrait">
          <div class="slide-img">
            <img src="<!-- @path slideshow-7.jpg -->" alt="" />
          </div>
          <div class="row">
            <div class="large-9 columns">
              <div class="slide-caption">Photograph by Blake Gordon</div>
            </div>
          </div>
        </div>
        <div class="slide">
          <div class="slide-img">
            <img src="<!-- @path slideshow-8.jpg -->" alt="" />
          </div>
          <div class="row">
            <div class="large-9 columns">
              <div class="slide-caption">Photograph by Blake Gordon</div>
            </div>
          </div>
        </div>
        <div class="slide end-slide">
          <div class="slide-img">
            <img src="<!-- @path slideshow-8.jpg -->" alt="" />
          </div>
          <div class="end-slide-content row">
            <div class="column">
              <div class="columns large-6 large-offset-1 text-container hide-for-small hide-for-tiny hide-for-medium">
                <h1 class="thin"><?php print $content['title']; ?></h1>
                <p class="deck"><?php print $content['subtitle']; ?></p>
                <p><a href="#" class="end-slide-button button pea-green xlarge slideshow-control restart"><i class="icon-spin-widdershins"></i>Restart Slideshow</a></p>
                <ul class="inline-list end-slide-links">
                  <li><?php print l(t('In the Bird Guide'), 'bird-guide'); ?></li>
                  <li><?php print l(t('In the News'), 'news'); ?></li>
                </ul>
                <div class="social-sharing align-left hide-for-small hide-for-medium hide-for-tiny">
                  <span class="social-sharing-caption white">Share this</span>
                  <a href="#" class="social-sharing-icon white"><i class="icon-twitter"></i></a>
                  <a href="#" class="social-sharing-icon white"><i class="icon-facebook"></i></a>
                  <a href="#" class="social-sharing-icon white"><i class="icon-pinterest"></i></a>
                  <a href="#" class="social-sharing-icon white"><i class="icon-mail"></i></a>
                </div>
              </div>
              <div class="columns tiny-12 small-8 small-offset-2 medium-6 medium-offset-3 large-4 large-offset-0 end text-container">
                <div class="engagement-card">
                  <div class="engagement-card-content no-min-height">
                    <h3 class="engagement-card-headline">Improve Crane Habitats</h3>
                    <p class="hide-for-tiny">Restoration efforts continue on improve winter homes for whooping cranes.</p>
                    <div class="engagement-card-cta">
                      <a href="#" class="button tomato large">Donate Today</a>
                    </div>
                  </div>
                  <div class="engagement-card-photo hide-for-small hide-for-tiny hide-for-medium">
                    <img src="<?php print base_path() . path_to_theme() . '/img/engagement-card-3.jpg'; ?>" alt="">
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
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
  <div class="row section-header">
    <div class="column">
      <h2 class="thin">Explore More Photography</h2>
    </div>
    <div class="column">
      <ul class="inline-list section-nav">
        <li><a href="#">See More Slideshows</a></li>
      </ul>
    </div>
  </div>
  <div class="row feature-set dark space-bottom">
    <div class="columns small-6 large-3">
      <div class="editorial-card dark feature">
        <div class="editorial-card-photo">
          <img src="../../img/feature-1.jpg" alt="">
        </div>
        <div class="editorial-card-content">
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
