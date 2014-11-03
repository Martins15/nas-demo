<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<section class="curtain hide-for-ie" style="background-color: #fff; background-image: url(<?php print $frontpage_backgroudimage; ?>)">
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
  <div class="curtain-fallback" style="background-image: url(<?php print $frontpage_backgroudimage; ?>)">
    <div class="curtain-fallback-content">
      <div class="columns">
        <div class="curtain-card no-border">
          <a href="#" class="curtain-card-slug">Conservation</a>
          <h3 class="curtain-card-headline"><a href="#">Protecting Alaska&rsquo;s Frontier</a></h3>
          <p>
            Audubon&rsquo;s conservation efforts are helping to protect and revitalize the Tongass National Forest.
          </p>
        </div>
      </div>
    </div>
  </div>
  <div class="homepage-first-row row space-top double">
    <div class="columns large-8 medium-6">
      <div class="editorial-card">
        <div class="editorial-card-photo">
          <img src="../img/editorial-card-23.jpg" alt="">
        </div>
        <div class="editorial-card-content short">
          <a href="#" class="editorial-card-slug">Conservation</a>
          <h3 class="editorial-card-title"><a href="#">A Trove of Green Heron Nests Might Just be a Treasure</a></h4>
          <p><a href="#" class="editorial-card-link">Recent discoveries help scientists understand the elusive bird's decline</a></p>
        </div>
      </div>
    </div>
    <div class="columns large-4 medium-6">
      <div class="editorial-card">
        <div class="editorial-card-content has-fixed-banner">
          <h3 class="close-heading">More Headlines</h3>
          <hr>
          <div class="editorial-card-list-item"><h5 class="editorial-card-title no-margin"><a href="#">Migratory Birds May Ferry Mosses Around the World</a></h5></div>
          <div class="editorial-card-list-item"><h5 class="editorial-card-title no-margin"><a href="#">Find a Baby Bird Out of the Nest? Here&rsquo;s What to Do</a></h5></div>
          <div class="editorial-card-list-item"><h5 class="editorial-card-title no-margin"><a href="#">Incubating Bird Eggs Is More Complex Than You Think</a></h5></div>
          <div class="editorial-card-list-item"><h5 class="editorial-card-title no-margin"><a href="#">New Oregon Marine Preserves Protect Birds and Fish</a></h5></div>
          <div class="editorial-card-list-item"><h5 class="editorial-card-title no-margin"><a href="#">Adubon Magazine Artists Win Three American Illustration Awards</a></h5></div>
          <div class="editorial-card-list-item"><h5 class="editorial-card-title no-margin"><a href="#">More News »</a></h5></div>
        </div>
        <div class="editorial-card-banner fixed blue">
          <div class="social-sharing">
            <span class="social-sharing-caption small">Follow us </span>
            <a class="social-sharing-icon white small" href="#"><i class="icon-twitter"></i></a>
            <a class="social-sharing-icon white small" href="#"><i class="icon-facebook"></i></a>
            <a class="social-sharing-icon white small" href="#"><i class="icon-youtube"></i></a>
            <a class="social-sharing-icon white small" href="#"><i class="icon-pinterest"></i></a>
          </div>
        </div>
      </div>
    </div>
  </div>
  <div class="row space-bottom double">
    <div class="columns large-4">
      <div class="editorial-card collapse-minimal">
        <div class="editorial-card-photo">
          <a href="#"><img src="../img/editorial-card-24.jpg" alt=""></a>
        </div>
        <div class="editorial-card-content">
          <a href="#" class="editorial-card-slug">Conservation</a>
          <h4 class="editorial-card-title"><a href="#">Drones Take Off as Wildlife Conservation Tool</a></h3>
          <p><em><a href="" class="editorial-card-link">UAVs could revolutionize ecology</a></em></p>
        </div>
      </div>
    </div>
    <div class="columns large-4">
      <div class="editorial-card collapse-minimal">
        <div class="editorial-card-photo">
          <a href="#"><img src="../img/editorial-card-25.jpg" alt=""></a>
        </div>
        <div class="editorial-card-content">
          <a href="#" class="editorial-card-slug">Birds</a>
          <h4 class="editorial-card-title"><a href="#">Clues to Conserving Golden Eagle Hidden in Its DNA</a></h3>
          <p><em><a href="" class="editorial-card-link">Genome sequencing reveals new insights</a></em></p>
        </div>
      </div>
    </div>
    <div class="columns large-4">
      <div class="editorial-card collapse-minimal">
        <div class="editorial-card-photo">
          <a href="#"><img src="../img/editorial-card-26.jpg" alt=""></a>
        </div>
        <div class="editorial-card-content">
          <a href="#" class="editorial-card-slug">Get Outside</a>
          <h4 class="editorial-card-title"><a href="#">Innovative Technology Gives Birdwatching a Boost</a></h3>
          <p><em><a href="" class="editorial-card-link">Learn about the latest tools</a></em></p>
        </div>
      </div>
    </div>
  </div>

  <section class="breakout-section black-bg">
    <div class="breakout-section-hero margin-bottom" style="background-image: url(../img/breakout-section-3.jpg)">
      <div class="row">
        <div class="column">
          <h1 class="breakout-section-headline">Our conservation work focuses on five key strategies, supported by science, advocacy, and education.</h1>
        </div>
      </div>
    </div>
    <div class="breakout-section-content light-text">
      <div class="row">
        <div class="columns medium-4">
          <div class="editorial-card dark no-border">
            <div class="editorial-card-content">
              <a href="#" class="editorial-card-slug">Strategies</a>
              <a href="#">
                <h4 class="editorial-card-title">Conservation Strategies Across America</h4>
              </a>
              <p>By protecting birds, we&rsquo;re also safeguarding America&rsquo;s great natural heritage for future generations, preservind our shared quality of life and fostering a healthier environment for us all.</p>
              <p><a href="#" class="editorial-card-link sans">Learn More About Our Strategies</a></p>
            </div>
          </div>
        </div>
        <div class="columns medium-4">
          <div class="editorial-card dark no-border">
            <div class="editorial-card-content">
              <a href="#" class="editorial-card-slug">Advocacy</a>
              <a href="#">
                <h4 class="editorial-card-title">Standing Up and Speaking Out for Birds</h4>
              </a>
              <p>Audubon pioneered the idea of Citizen Science with the first Christmas Bird Count. Today the longest-running wildlife census in the world continues to shape and inform our approach to conservation.</p>
              <p><a href="#" class="editorial-card-link sans">Policy Issues &amp; Action</a></p>
            </div>
          </div>
        </div>
        <div class="columns medium-4">
          <div class="editorial-card dark no-border">
            <div class="editorial-card-content">
              <a href="#" class="editorial-card-slug">Education</a>
              <a href="#">
                <h4 class="editorial-card-title">Shaping the Next Generation of Conservationists</h4>
              </a>
              <p>A commitment to education is at the heart of the Audubon tradition. By inspiring more people in more places to value and protect the natural world, we are laying the foundation for future conservation.</p>
              <p><a href="#" class="editorial-card-link sans">Audubon’s Education Programs</a></p>
            </div>
          </div>
        </div>
      </div>
    </div>
  </section>
  <div class="bird-card-set bg-bone-white bg-boa">
    <a href="#" class="bg-egg icon-binoculars white"></a>
    <div class="bird-card-grid-bg-caption">
      <div class="row">
        <div class="columns large-offset-1 large-3">
          <h2 class="thin"><a href="#">Belted Kingfisher</a></h2>
        </div>
        <div class="columns large-8">
          <p>Illustration by John James Audubon circa 1840 from The Birds of America</p>
          <p><em><a href="#">Learn more about the Belted Kingfisher »</a></em></p>
        </div>
      </div>
    </div>
    <div class="row section-header">
      <div class="columns">
        <h2 class="thin">Birds in the News</h2>
      </div>
      <div class="columns">
        <ul class="section-nav inline-list">
          <li class="hide-for-small hide-for-tiny"><a href="#">Explore Our Bird Guide</a></li>
          <li><a href="#">Identify a Bird</a></li>
          <li><a class="cta" href="#">Adopt a Bird</a></li>
        </ul>
      </div>
    </div>
    <div class="row bird-card-container">
      <div class="bird-card-scroller">
        <div class="columns tiny-3">
          <figure class="bird-card">
            <div class="bird-card-illustration">
              <a href="#"><img src="../img/bird-1.png" alt=""></a>
            </div>
            <figcaption class="bird-card-caption">
              <h4 class="common-name"><a href="#">Cactus Wren</a></h4>
              <p class="scientific-name">Campylorhynchus brunneicapillus</p>
            </figcaption>
            <a href="#" class="icon-sound-full bird-card-audio"></a>
          </figure>
          <a href="#" class="editorial-card-slug">Conservation</a>
          <h4 class="editorial-card-title"><a href="#">Saving Western Rivers</a></h4>
        </div>
        <div class="columns tiny-3">
          <figure class="bird-card">
            <div class="bird-card-illustration">
              <a href="#"><img src="../img/bird-2.png" alt=""></a>
            </div>
            <figcaption class="bird-card-caption">
              <h4 class="common-name"><a href="#">Bullock's Oriole</a></h4>
              <p class="scientific-name">Icterus Bullocki</p>
            </figcaption>
            <a href="#" class="icon-sound-full bird-card-audio"></a>
          </figure>
          <a href="#" class="editorial-card-slug">In the News</a>
          <h5 class="editorial-card-title"><a href="#">Newest U.S. Stamps Feature Songbirds</a></h5>
        </div>
        <div class="columns tiny-3">
          <figure class="bird-card">
            <div class="bird-card-illustration">
              <a href="#"><img src="../img/bird-3.png" alt=""></a>
            </div>
            <figcaption class="bird-card-caption">
              <h4 class="common-name"><a href="#">Pileated Woodpecker</a></h4>
              <p class="scientific-name">Dryocopus pileatus</p>
            </figcaption>
            <a href="#" class="icon-sound-full bird-card-audio"></a>
          </figure>
          <a href="#" class="editorial-card-slug">Birds We Love</a>
          <h5 class="editorial-card-title"><a href="#">Common Birds in Decline</a></h5>
        </div>
        <div class="columns tiny-3">
          <figure class="bird-card">
            <div class="bird-card-illustration">
              <a href="#"><img src="../img/bird-4.png" alt=""></a>
            </div>
            <figcaption class="bird-card-caption">
              <h4 class="common-name"><a href="#">Western Scrub‑Jay</a></h4>
              <p class="scientific-name">Aphelocoma californica</p>
            </figcaption>
            <a href="#" class="icon-sound-full bird-card-audio"></a>
          </figure>
          <a href="#" class="editorial-card-slug">Conservation</a>
          <h5 class="editorial-card-title"><a href="#">Champlain Valley Bird Initiative</a></h5>
        </div>
      </div>
    </div>
    <div class="row indicator space-bottom double">
      <div class="column">
        <p><i class="indicator-left icon-arrow-left disabled"></i>&nbsp;&nbsp;&nbsp;<i class="indicator-right icon-arrow-right"></i></p>
      </div>
    </div>
  </div>

  <div class="breakout-section no-hero" style="background-image: url(../img/breakout-section-flyway.jpg); background-color: #444444">
    <div class="breakout-section-content light-text">
      <div class="row space-top space-bottom double">
        <div class="columns large-4">
          <h5 class="close-heading">You are a part of the</h5>
          <h1 class="thin">Pacific Flyway</h1>
          <p><em>Each year more than a billion birds migrate along the Pacific Flyway, which stretches from the North Slope of Alaska to Central and South America.</em></p>
          <br>
          <div class="editorial-card dark no-border">
            <div class="editorial-card-content">
              <h4 class="editorial-card-title blue"><a href="#">About the Flyways</a></h4>
              <p>Audubon follows the birds to our work, organizing our conservation strategies along the four flyways of the Americas.</p>
              <br>
              <a href="" class="editorial-card-link"><em>Learn More</em></a>
            </div>
          </div>
        </div>
        <div class="columns large-4">
          <div class="breakout-section-box">
            <h4 class="editorial-card-title blue"><a href="#">Audubon Near You</a></h4>
            <div class="editorial-card-list-item">
              <h5 class="editorial-card-title no-margin"><a href="#">Richardson Bay Audubon Center &amp; Sanctuary <small class="serif"><em>(Tiberon,&nbsp;CA)</em></small></a></h5>
            </div>
            <div class="editorial-card-list-item">
              <h5 class="editorial-card-title no-margin"><a href="#">Audubon Center at Debs Park <small class="serif"><em>(Los&nbsp;Angeles,&nbsp;CA)</em></small></a></h5>
            </div>
            <div class="editorial-card-list-item">
              <h5 class="editorial-card-title no-margin"><a href="#">Bobelaine Audubon Sanctuary <small class="serif"><em>(Sacramento,&nbsp;CA)</em></small></a></h5>
            </div>
            <h4 class="editorial-card-title blue"><a href="#">Upcoming Events</a></h4>
            <div class="editorial-card-list-item small">
              <h5 class="editorial-card-title"><a href="#">Summer Camp Open House</a><br>
              <small class="serif"><em>Saturday, April 26, 2014</em></small></h5>
              <p>Richardson Bay Audubon Center hosts an open house for their 2014 Summer Camp program.</p>
            </div>
            <div class="editorial-card-list-item small">
              <h5 class="editorial-card-title"><a href="#">Birds Along the Bay</a><br>
              <small class="serif"><em>Saturday, May 3, 2014</em></small></h5>
              <p>Join the Marin Audubon Society for a Saturday morning on birding along the Pacific Coast.</p>
            </div>
          </div>
        </div>
        <div class="columns large-4">
          <div class="breakout-section-box">
            <img src="../img/pacific-flyway-map.png" alt="">
            <br>
            <p class="serif"><em>The Pacific Flyway includes Alaska, Hawaii, Washington, Oregon, and California.</em></p>
          </div>
        </div>
      </div>
    </div>
  </div>

  <div class="row section-header space-top">
    <div class="column">
      <h2 class="thin">News from the Network</h2>
    </div>
    <div class="column">
      <ul class="inline-list section-nav">
        <li><a href="#">Find the Audubon Chapter Near You »</a></li>
      </ul>
    </div>
  </div>
  <div class="row space-bottom">
    <div class="columns large-3">
      <div class="editorial-card feature collapse-minimal">
        <div class="editorial-card-photo">
          <img src="../img/feature-5.jpg" alt="">
        </div>
        <div class="editorial-card-content">
          <a href="#" class="editorial-card-slug">Audubon North Carolina</a>
          <h4 class="editorial-card-title no-margin"><a href="#">Putting Working Lands to Work for Birds and People</a></h4>
        </div>
      </div>
    </div>
    <div class="columns large-3">
      <div class="editorial-card feature collapse-minimal">
        <div class="editorial-card-photo">
          <img src="../img/feature-6.jpg" alt="">
        </div>
        <div class="editorial-card-content">
          <a href="#" class="editorial-card-slug">Audubon Center at Debs Park</a>
          <h4 class="editorial-card-title no-margin"><a href="#">Conservation Ed Internships for College Students</a></h4>
        </div>
      </div>
    </div>
    <div class="columns large-3">
      <div class="editorial-card feature collapse-minimal">
        <div class="editorial-card-photo">
          <img src="../img/feature-7.jpg" alt="">
        </div>
        <div class="editorial-card-content">
          <a href="#" class="editorial-card-slug">Audubon Washington</a>
          <h4 class="editorial-card-title no-margin"><a href="#">Songbird Survey in Eastern Washington Underway</a></h4>
        </div>
      </div>
    </div>
    <div class="columns large-3">
      <div class="editorial-card feature collapse-minimal">
        <div class="editorial-card-photo">
          <img src="../img/feature-8.jpg" alt="">
        </div>
        <div class="editorial-card-content">
          <a href="#" class="editorial-card-slug">Audubon Florida</a>
          <h4 class="editorial-card-title no-margin"><a href="#">Everglades Birds are Talking. Are We Listening?</a></h4>
        </div>
      </div>
    </div>
  </div>

  <div class="breakout-section no-hero" style="background-image: url(../img/breakout-section-4.jpg); background-color: #444444">
    <div class="breakout-section-content light-text">
      <div class="row space-top space-bottom double">
        <div class="columns large-5 text-container">
          <h1 class="thin">Get Outside</h1>
          <br>
          <h2 class="thin close-heading">Birding</h2>
          <p>Birding can be as simple as watching the pigeons fly by your window or pausing to marvel at the chirping sparrows in the trees.
          <br><a href="#" class="sans">Start with Three Easy Steps to Birding »</a></p>
          <h2 class="thin close-heading">Photography</h2>
          <p>For wildlife and nature photographers, birds provide fascinating but challenging subjects to capture with even a long lens.
          <br><a href="#" class="sans">Photo Tips from the Pros »</a></p>
          <h2 class="thin close-heading">Healthy Yards</h2>
          <p>Roll up your sleeves and get started. Learn how to create a natural and healthy habitat in your backyard.
          <br><a href="#" class="sans">Selecting Bird-Friendly Plants for Your Yard »</a></p>
        </div>
      </div>
    </div>
  </div>

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
              <img src="../img/engagement-card-1.jpg" alt="">
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
              <img src="../img/engagement-card-2.jpg" alt="">
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
              <img src="../img/engagement-card-3.jpg" alt="">
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
