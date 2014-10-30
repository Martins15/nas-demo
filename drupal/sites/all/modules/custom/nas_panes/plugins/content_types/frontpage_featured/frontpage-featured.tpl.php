<?php
/**
 * @file
 * Featured Frontpage template file.
 *
 * Available variables:
 * - $title_link: the (sanitized) title with link.
 * - $blue_text_link: the (sanitized) blue text above the title with link.
 * - $image_path: path to the hero image of the bird.
 * - $image_path_mobile: path to the hero image of the bird mobile image style.
 * - $image_string: sanitized caption + credits of the hero image.
 * - $contextual_links: rendered contextual links.
 */
?>
    <section class="curtain hide-for-ie" style="background-color: #fff; background-image: url(<?php print $image_path; ?>)">
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

      <div class="curtain-content light-text">
        <div class="row space-bottom contextual-links-region">
          <?php print $contextual_links; ?>
          <div class="column medium-6 medium-offset-6">
            <div class="curtain-card">
              <?php print $blue_text_link; ?>
              <h2 class="curtain-card-headline"><?php print $title_link; ?></h2>
              <p class="curtain-card-blurb">
                <?php print $summary; ?>
              </p>
            </div>
          </div>
        </div>
        <div class="row">
          <div class="column">
            <div class="curtain-attribution">
              <p class="title"><?php print $image_title ?></p>
              <p class="credit"><?php print $image_credit ?></p>
            </div>
          </div>
        </div>
      </div>

      <a href="#" class="curtain-arrow"></a>
    </section>
