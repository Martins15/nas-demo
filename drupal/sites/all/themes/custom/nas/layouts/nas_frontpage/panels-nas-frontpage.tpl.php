<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<section class="curtain hide-for-ie" style="background-color: #fff; background-image: url(<?php print !empty($frontpage_backgroundimage) ? $frontpage_backgroundimage : ''; ?>)">
  <header class="global-header transparent dark-text light-bg">
    <div class="row">
      <div class="columns">
        <a href="index.html" class="current-parent wordmark">Audubon</a>
        <!-- Only visible on small and medium screens -->
        <a href="#" class="icon-menu header-btn header-btn-menu"></a>
        <a href="#" class="icon-magnifier header-btn header-btn-search"></a>
        <!-- / -->
        <div class="header-search clearfix">
          <input class="header-search-input radius" type="search" placeholder="Search the Audubon network">
          <button class="header-search-button button large pea-green">
            <i class="icon-magnifier"></i>
          </button>
          <a href="#" class="hide-for-tiny hide-for-small hide-for-medium header-search-close icon-close"></a>
        </div>
        <div class="global-nav">
          <ul class="action-nav inline-list clearfix">
            <li class="action-nav-item"><a class="action-nav-link button small tomato" href="#">Donate</a></li>
            <li class="action-nav-item"><a class="action-nav-link button small tomato" href="#">Take Action</a></li>
          </ul>
          <div class="mobile-nav">
            <ul class="primary-nav inline-list">
              <li class="primary-nav-item">
                <a class="primary-nav-toggler" href="news/index.html">News</a>
                <ul class="primary-sub-nav">
                  <li class="primary-sub-nav-item primary-sub-nav-index"><a class="primary-sub-nav-link" href="news/index.html">News Home</a></li>
                  <li class="primary-sub-nav-item"><a class="primary-sub-nav-link" href="#">Birds in the News</a></li>
                  <li class="primary-sub-nav-item"><a class="primary-sub-nav-link" href="#">Inside Audubon</a></li>
                  <li class="primary-sub-nav-item"><a class="primary-sub-nav-link" href="#">[Example Column]</a></li>
                  <li class="primary-sub-nav-item"><a class="primary-sub-nav-link" href="#">[Example Column]</a></li>
                </ul>
              </li>
              <li class="primary-nav-item">
                <a class="primary-nav-toggler" href="#">Features</a>
                <ul class="primary-sub-nav">
                  <li class="primary-sub-nav-item primary-sub-nav-index"><a class="primary-sub-nav-link" href="#">Features Home</a></li>
                  <li class="primary-sub-nav-item"><a class="primary-sub-nav-link" href="#">Maps</a></li>
                  <li class="primary-sub-nav-item"><a class="primary-sub-nav-link" href="#">Videos</a></li>
                  <li class="primary-sub-nav-item"><a class="primary-sub-nav-link" href="#">From the Magazine</a></li>
                </ul>
              </li>
              <li class="primary-nav-item">
                <a class="primary-nav-toggler" href="birds/index.html">Birds</a>
                <ul class="primary-sub-nav">
                  <li class="primary-sub-nav-item primary-sub-nav-index"><a class="primary-sub-nav-link" href="birds/index.html">Birds Home</a></li>
                  <li class="primary-sub-nav-item"><a class="primary-sub-nav-link" href="#">Priority Birds</a></li>
                  <li class="primary-sub-nav-item"><a class="primary-sub-nav-link" href="birds/guide/index.html">Birds of North America Field Guide</a></li>
                  <li class="primary-sub-nav-item"><a class="primary-sub-nav-link" href="#">John James Audubon&rsquo;s Birds of America</a></li>
                  <li class="primary-sub-nav-item"><a class="primary-sub-nav-link" href="#">Webcams</a></li>
                  <li class="primary-sub-nav-item"><a class="primary-sub-nav-link" href="#">The Flyways</a></li>
                </ul>
              </li>
              <li class="primary-nav-item">
                <a class="primary-nav-toggler" href="conservation/index.html">Conservation</a>
                <ul class="primary-sub-nav">
                  <li class="primary-sub-nav-item primary-sub-nav-index"><a class="primary-sub-nav-link" href="conservation/index.html">Conservation Home</a></li>
                  <li class="primary-sub-nav-item"><a class="primary-sub-nav-link" href="#">Working Lands</a></li>
                  <li class="primary-sub-nav-item"><a class="primary-sub-nav-link" href="#">Important Bird Areas</a></li>
                  <li class="primary-sub-nav-item"><a class="primary-sub-nav-link" href="conservation/strategy.html">Seas &amp; Shores</a></li>
                  <li class="primary-sub-nav-item"><a class="primary-sub-nav-link" href="#">Climate &amp; Energy</a></li>
                  <li class="primary-sub-nav-item"><a class="primary-sub-nav-link" href="#">Bird-Friendly Communities</a></li>
                  <li class="primary-sub-nav-item"><a class="primary-sub-nav-link" href="#">Science</a></li>
                  <li class="primary-sub-nav-item"><a class="primary-sub-nav-link" href="#">Advocacy</a></li>
                  <li class="primary-sub-nav-item"><a class="primary-sub-nav-link" href="#">Education</a></li>
                  <li class="primary-sub-nav-item"><a class="primary-sub-nav-link" href="#">International</a></li>
                </ul>
              </li>
              <li class="primary-nav-item">
                <a class="primary-nav-toggler" href="getoutside/index.html">Get Outside</a>
                <ul class="primary-sub-nav">
                  <li class="primary-sub-nav-item primary-sub-nav-index"><a class="primary-sub-nav-link" href="getoutside/index.html">Get Outside Home</a></li>
                  <li class="primary-sub-nav-item"><a class="primary-sub-nav-link" href="#">Birding</a></li>
                  <li class="primary-sub-nav-item"><a class="primary-sub-nav-link" href="#">Photography</a></li>
                  <li class="primary-sub-nav-item"><a class="primary-sub-nav-link" href="#">Travel</a></li>
                  <li class="primary-sub-nav-item"><a class="primary-sub-nav-link" href="#">Activities</a></li>
                  <li class="primary-sub-nav-item"><a class="primary-sub-nav-link" href="#">Events</a></li>
                </ul>
              </li>
              <li class="primary-nav-item">
                <a class="primary-nav-toggler final" href="about/index.html">About<span class="extra-nav-copy"> Us</span></a>
                <ul class="primary-sub-nav">
                  <li class="primary-sub-nav-item primary-sub-nav-index"><a href="#" class="primary-sub-nav-link">About Us Home</a></li>
                  <li class="primary-sub-nav-item"><a href="#" class="primary-sub-nav-link">How to Help</a></li>
                  <li class="primary-sub-nav-item"><a href="#" class="primary-sub-nav-link">Audubon Near You</a></li>
                  <li class="primary-sub-nav-item"><a href="#" class="primary-sub-nav-link">History</a></li>
                  <li class="primary-sub-nav-item"><a href="#" class="primary-sub-nav-link">Press Room</a></li>
                  <li class="primary-sub-nav-item"><a href="#" class="primary-sub-nav-link">Audubon Chapters</a></li>
                  <li class="primary-sub-nav-item"><a href="#" class="primary-sub-nav-link">Diversity &amp; Inclusion</a></li>
                  <li class="primary-sub-nav-item"><a href="#" class="primary-sub-nav-link">Reports &amp; Financials</a></li>
                  <li class="primary-sub-nav-item"><a href="#" class="primary-sub-nav-link">Leadership</a></li>
                  <li class="primary-sub-nav-item"><a href="#" class="primary-sub-nav-link">Careers</a></li>
                  <li class="primary-sub-nav-item"><a href="#" class="primary-sub-nav-link">Contact Us</a></li>
                </ul>
              </li>
              <li class="primary-nav-item primary-nav-search">
                <a href="#">
                  <i class="icon-magnifier"></i>
                </a>
              </li>
            </ul>
            <ul class="secondary-nav inline-list">
              <li><a href="#">Magazine</a></li>
              <li><a href="#">Audubon Near You</a></li>
              <li><a href="#"><span class="show-for-large-up">Get</span> Email Updates</a></li>
            </ul>
          </div>
        </div>
      </div>
    </div>
  </header>
<?php print $content['top']; ?>
</section>
<section class="global-content">
  <?php if (!empty($featured_frontpage_mobile_content)): ?>
    <?php print $featured_frontpage_mobile_content; ?>
  <?php endif; ?>
  <div class="homepage-first-row row space-top double">
    <?php print $content['featured']; ?>
    <div class="columns large-4 medium-6">
      <?php print $content['more_headlines']; ?>
    </div>
  </div>
  <?php print $content['editorial_cards']; ?>
  <?php print $content['conservation_section']; ?>
  <?php print $content['bird_news']; ?>
  <?php print $content['main']; ?>
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
              <img src="<?php print base_path() . path_to_theme(); ?>/img/engagement-card-1.jpg" alt="">
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
              <img src="<?php print base_path() . path_to_theme(); ?>/img/engagement-card-2.jpg" alt="">
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
              <img src="<?php print base_path() . path_to_theme(); ?>/img/engagement-card-3.jpg" alt="">
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
