<?php
/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<?php print render($content['top']); ?>

<section class="category-nav strip-nav">
  <div class="row">
    <div class="columns">
      <ul class="inline-list">
        <li><a href="#">Important Bird Areas</a></li>
        <li><a href="#">Bird Friendly Communities</a></li>
        <li><a href="#">Climate &amp; Energy</a></li>
        <li><a href="#">Seas &amp; Shores</a></li>
        <li><a href="#">Working Lands</a></li>
        <li><a href="#">Science</a></li>
        <li><a href="#">Advocacy</a></li>
        <li><a href="#">Education</a></li>
      </ul>
    </div>
  </div>
</section>

<section class="global-content with-padding">
<div class="row">
  <div class="medium-3 medium-centered large-uncentered large-6 large-push-6 columns hide-for-tiny hide-for-small">
    <img src="<?php print base_path() . path_to_theme() . '/img/conservation-img-1.jpg'; ?>" alt="">
  </div>
  <div class="large-6 large-pull-6 columns text-container">
    <h2 class="thin">We maximize our conservation results by focusing on five key strategies critical for birds</h2>
    <p>For more than a century Audubon has protected birds and their habitat for the benefit of humanity as well as the earth’s biodiversity. Our legacy is built on science, education, advocacy, and on-the-ground conservation. We bring all of this together through our unparalleled network. This combination of expertise and on-the-ground engagement makes Audubon a truly unique and trusted force for conservation.</p>
    <div class="donate-bar">
      <div class="donate-bar-caption">Support our conservation work by contributing today.</div><div href="#" class="donate-bar-button"><a href="#" class="button tomato large">Donate</a></div>
    </div>
    <p>Audubon’s mission is more urgent today than ever before. Natural habitat and open spaces are disappearing at an alarming rate. Protections for wildlife, natural places, and clean air and water are in jeopardy. By protecting birds, we’re also safeguarding America’s great natural heritage for future gen- erations, preserving our shared quality of life and fostering a healthier environment for us all.</p>
    <blockquote class="pull-quote">Audubon’s national and state programs, Centers, Chapters, and Important Bird Areas come together with an unparalleled wingspan for conservation.</blockquote>
  </div>
</div>
<section class="conservation-slider">
  <div class="conservation-indicator row">
    <div class="column">
      <a class="conservation-indicator-icon active"><img src="<?php print base_path() . path_to_theme() . '/img/conservation-icon-small-1.png'; ?>" alt=""></a>
      <a class="conservation-indicator-icon"><img src="<?php print base_path() . path_to_theme() . '/img/conservation-icon-small-2.png'; ?>" alt=""></a>
      <a class="conservation-indicator-icon"><img src="<?php print base_path() . path_to_theme() . '/img/conservation-icon-small-3.png'; ?>" alt=""></a>
      <a class="conservation-indicator-icon"><img src="<?php print base_path() . path_to_theme() . '/img/conservation-icon-small-4.png'; ?>" alt=""></a>
      <a class="conservation-indicator-icon"><img src="<?php print base_path() . path_to_theme() . '/img/conservation-icon-small-5.png'; ?>" alt=""></a>
    </div>
  </div>
  <div class="conservation-wrapper">
    <div class="conservation-scroller">
      <div class="slide">
        <div class="conservation-slide-image" style="background-image: url(<?php print base_path() . path_to_theme() . '/img/conservation-slide-1.jpg'; ?>)"> </div>
        <div class="conservation-slide-text text-container">
          <div class="row">
            <div class="column text-container">
              <h2 class="conservation-slide-headline thin">Putting Working Lands to Work for Birds &amp; People</h2>
              <p><em>Best management practices on ranches, farms, and forests hold the key to survival for more than 150 species of threatened grassland and forest birds. </em></p>
              <p>By partnering with landowners, Audubon can help ensure a bright future for birds like the Cerulean War- bler and the Tricolored Blackbird, and a healthy landscape for future generations.</p>
              <p><em><a href="#">Learn more »</a></em></p>
              <div class="editorial-card index">
                <div class="small-4 large-2 columns hide-for-small hide-for-tiny">
                  <div class="editorial-card-photo">
                    <img src="<?php print base_path() . path_to_theme() . '/img/editorial-card-index-9.jpg'; ?>" alt="">
                  </div>
                </div>
                <div class="small-8 large-8 end columns">
                  <div class="editorial-card-content">
                    <img class="editorial-card-inline-photo" src="<?php print base_path() . path_to_theme() . '/img/editorial-card-index-9.jpg'; ?>" alt="">
                    <a class="editorial-card-slug">Featured Project</a>
                    <h4 class="editorial-card-title"><a href="#">Transforming the Central Valley</a></h4>
                    <p>California’s central valley, one of this country’s most important food-producing areas, offers a good example of the power of Audubon’s partnerships.</p>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
      <div class="slide">
        <div class="conservation-slide-image" style="background-image: url(<?php print base_path() . path_to_theme() . '/img/conservation-slide-2.jpg'; ?>)"> </div>
        <div class="conservation-slide-text">
          <div class="row">
            <div class="column text-container">
              <h2 class="conservation-slide-headline thin">Saving Important Bird Areas</h2>
              <p><em>Knowing which places are most important for birds is the first step toward conserv- ing them.</em></p>
              <p>Audubon has identified 2,544 Important Bird Areas in the United States, covering 378 million acres, and is supporting work in some of the 2,345 IBAs in Latin America, the Caribbean, and Canada. </p>
              <p><em><a href="#">Learn more »</a></em></p>
              <div class="editorial-card index">
                <div class="small-4 large-2 columns">
                  <div class="editorial-card-photo hide-for-small hide-for-tiny">
                    <img src="<?php print base_path() . path_to_theme() . '/img/editorial-card-index-10.jpg'; ?>" alt="">
                  </div>
                </div>
                <div class="small-8 large-8 end columns">
                  <div class="editorial-card-content">
                    <img class="editorial-card-inline-photo" src="<?php print base_path() . path_to_theme() . '/img/editorial-card-index-10.jpg'; ?>" alt="">
                    <a class="editorial-card-slug">Featured Project</a>
                    <h4 class="editorial-card-title"><a href="#">Arctic Slope</a></h4>
                    <p>The coastal plain of the Arctic National Wildlife Refuge (ANWR), which serves as the calving grounds of the Porcupine caribou herd, has long been a high-profile loca- tion in the debate over energy development versus wildlife conservation.</p>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
      <div class="slide">
        <div class="conservation-slide-image" style="background-image: url(<?php print base_path() . path_to_theme() . '/img/conservation-slide-3.jpg'; ?>)"> </div>
        <div class="conservation-slide-text text-container">
          <div class="row">
            <div class="column text-container">
              <h2 class="conservation-slide-headline thin">Sharing Our Seas &amp; Shores</h2>
              <p><em>Coastal areas are a magnet for birds and people alike. Unfortunately, overfishing, development, and sea level rise put sixty percent of coastal birds at risk. </em></p>
              <p>By expanding our successful coastal stewardship program, and incorporating marine sites into our Important Bird Areas, Audubon can reduce threats to vital coastal bird habitats. </p>
              <p><em><a href="#">Learn more »</a></em></p>
              <div class="editorial-card index">
                <div class="small-4 large-2 columns">
                  <div class="editorial-card-photo hide-for-small hide-for-tiny">
                    <img src="<?php print base_path() . path_to_theme() . '/img/editorial-card-index-8.jpg'; ?>" alt="">
                  </div>
                </div>
                <div class="small-8 large-8 end columns">
                  <div class="editorial-card-content">
                    <img class="editorial-card-inline-photo" src="<?php print base_path() . path_to_theme() . '/img/editorial-card-index-8.jpg'; ?>" alt="">
                    <a class="editorial-card-slug">Featured Project</a>
                    <h4 class="editorial-card-title"><a href="#">Saving Seabirds Along the Pacific Coast</a></h4>
                    <p>The stretch of land and sea from Barrow, Alaska, to Baja California is home to more than 100 million seabirds.</p>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
      <div class="slide">
        <div class="conservation-slide-image" style="background-image: url(<?php print base_path() . path_to_theme() . '/img/conservation-slide-4.jpg'; ?>)"> </div>
        <div class="conservation-slide-text text-container">
          <div class="row">
            <div class="column text-container">
              <h2 class="conservation-slide-headline thin">Shaping a Healthy Climate &amp; Clean Energy Future</h2>
              <p><em>Climate change poses an unprecedented threat not just to birds but to biodiversity and our shared quality of life.</em></p>
              <p>Audubon is responding to this challenge with an equally unprecedented combination of strategies, from advancing transformational policies that reduce carbon emissions and support well-sited green energy to leading adaptive land management practices that will mitigate the impact of sea level rise and climate change.</p>
              <p><em><a href="#">Learn more »</a></em></p>
              <div class="editorial-card index">
                <div class="small-4 large-2 columns">
                  <div class="editorial-card-photo hide-for-small hide-for-tiny">
                    <img src="<?php print base_path() . path_to_theme() . '/img/editorial-card-index-11.jpg'; ?>" alt="">
                  </div>
                </div>
                <div class="small-8 large-8 end columns">
                  <div class="editorial-card-content">
                    <img class="editorial-card-inline-photo" src="<?php print base_path() . path_to_theme() . '/img/editorial-card-index-11.jpg'; ?>" alt="">
                    <a class="editorial-card-slug">Featured Project</a>
                    <h4 class="editorial-card-title"><a href="#">Site It Right</a></h4>
                    <p>The science is clear: Climate change poses the greatest threat to wildlife and habitat in our lifetime.</p>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
      <div class="slide">
        <div class="conservation-slide-image" style="background-image: url(<?php print base_path() . path_to_theme() . '/img/conservation-slide-5.jpg'; ?>)"> </div>
        <div class="conservation-slide-text">
          <div class="row">
            <div class="column text-container">
              <h2 class="conservation-slide-headline thin">Creating Bird-Friendly Communities</h2>
              <p><em>Most Americans live in cities or suburbs, and people can play a critical role in fostering healthy wildlife populations and communities.</em></p>
              <p>Rural regions have an outsized opportuni- ty to contribute. As the leading voice for birds, Audubon can inspire the one in five adults who watch birds to make daily lifestyle choices that add up to real conservation impact.</p>
              <p><em><a href="#">Learn more »</a></em></p>
              <div class="editorial-card index">
                <div class="small-4 large-2 columns">
                  <div class="editorial-card-photo hide-for-small hide-for-tiny">
                    <img src="<?php print base_path() . path_to_theme() . '/img/editorial-card-index-12.jpg'; ?>" alt="">
                  </div>
                </div>
                <div class="small-8 large-8 end columns">
                  <div class="editorial-card-content">
                    <img class="editorial-card-inline-photo" src="<?php print base_path() . path_to_theme() . '/img/editorial-card-index-12.jpg'; ?>" alt="">
                    <a class="editorial-card-slug">Featured Project</a>
                    <h4 class="editorial-card-title"><a href="#">Lights Out Chicago and Minneapolis</a></h4>
                    <p>Migrating birds face a wide range of manmade threats. One of the most deadly is collisions with tall buildings, which cause millions of fatalities each spring and fall.</p>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
    <a class="conservation-slider-button prev"></a>
    <a class="conservation-slider-button next"></a>
  </div>
</section>
<section class="breakout-section black-bg">
  <div class="breakout-section-hero margin-bottom" style="background-image: url(<?php print base_path() . path_to_theme() . '/img/breakout-section-1.jpg'; ?>)">
    <div class="row">
      <div class="column">
        <h1 class="breakout-section-headline centered">Our on-the-ground conservation work is fueled by science, advocacy, and education.</h1>
      </div>
    </div>
  </div>
  <div class="breakout-section-content">
    <div class="row">
      <div class="columns medium-4">
        <div class="editorial-card dark no-border">
          <div class="editorial-card-content">
            <a href="#" class="editorial-card-slug">Science</a>
            <a href="#">
              <h4 class="editorial-card-title">Understanding the Science of Conservation and Climate</h4>
            </a>
            <p>Audubon pioneered the idea of Citizen Science with the first Christmas Bird Count. Today the longest-running wildlife census in the world continues to shape and inform our approach to conservation.</p>
            <p><a href="#" class="editorial-card-link sans">Explore Our Science Initiatives</a></p>
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
