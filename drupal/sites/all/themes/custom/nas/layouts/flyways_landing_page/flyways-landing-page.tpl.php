<?php
/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>

</header>
<?php print $content['content']; ?>

<section class="global-content with-padding">
  <div class="row">
    <div class="medium-6 medium-push-6 columns">
      <div id="flyway-map" class="flyway-paths">
        <div id="flyway-map-1" class="flyway-path-map current">
          <img src="../../img/flyway-path-1.jpg" alt="Pacific Flyway">
          <a href="#" id="flyway-point-1" class="flyway-megamap-point"">
            <div class="portrait">
              <img src="../../img/flyway-bird-1.png" alt="Whimbel">
            </div>
            <div class="name">
              <div class="bird">Whimbel</div>
              <div class="flyway">Pacific Flyway</div>
            </div>
          </a>
          <div class="flyway-path-dots">
            <a href="#flyway-map-1" class="dot active"></a>
            <a href="#flyway-map-2" class="dot"></a>
            <a href="#flyway-map-3" class="dot"></a>
            <a href="#flyway-map-4" class="dot"></a>
          </div>
        </div>
        <div id="flyway-map-2" class="flyway-path-map">
          <img src="../../img/flyway-path-2.jpg" alt="Central Flyway">
          <a href="#" id="flyway-point-2" class="flyway-megamap-point">
            <div class="portrait">
              <img src="../../img/flyway-bird-2.png" alt="Whimbel">
            </div>
            <div class="name">
              <div class="bird">Sandhill Crane</div>
              <div class="flyway">Central Flyway</div>
            </div>
          </a>
          <div class="flyway-path-dots">
            <a href="#flyway-map-1" class="dot"></a>
            <a href="#flyway-map-2" class="dot active"></a>
            <a href="#flyway-map-3" class="dot"></a>
            <a href="#flyway-map-4" class="dot"></a>
          </div>
        </div>
        <div id="flyway-map-3" class="flyway-path-map">
          <img src="../../img/flyway-path-3.jpg" alt="Mississippi Flyway">
          <a href="#" id="flyway-point-3" class="flyway-megamap-point">
            <div class="portrait">
              <img src="../../img/flyway-bird-3.png" alt="Whimbel">
            </div>
            <div class="name">
              <div class="bird">Prothonotary</div>
              <div class="flyway">Mississippi Flyway</div>
            </div>
          </a>
          <div class="flyway-path-dots">
            <a href="#flyway-map-1" class="dot"></a>
            <a href="#flyway-map-2" class="dot"></a>
            <a href="#flyway-map-3" class="dot active"></a>
            <a href="#flyway-map-4" class="dot"></a>
          </div>
        </div>
        <div id="flyway-map-4" class="flyway-path-map">
          <img src="../../img/flyway-path-4.jpg" alt="Atlantic Flyway">
          <a href="#" id="flyway-point-4" class="flyway-megamap-point">
            <div class="portrait">
              <img src="../../img/flyway-bird-4.png" alt="Whimbel">
            </div>
            <div class="name">
              <div class="bird">Black Throated Blue Warbler</div>
              <div class="flyway">Atlantic Flyway</div>
            </div>
          </a>
          <div class="flyway-path-dots">
            <a href="#flyway-map-1" class="dot"></a>
            <a href="#flyway-map-2" class="dot"></a>
            <a href="#flyway-map-3" class="dot"></a>
            <a href="#flyway-map-4" class="dot active"></a>
          </div>
        </div>
      </div>
    </div>
    <div class="medium-6 medium-pull-6 columns text-container">
      <h1>We follow the flyways and work as one.</h1>
      <div class="deck">Audubon&rsquo;s national and state programs, Centers, Chapters, and Important Bird Areas come together with an unparalleled wingspan for conservation.</div>
      <p>The flyways traveled by migratory birds each spring and fall inspire our model for organizational alignment. By connecting the work of the Audubon network—Chapters, Centers, national and state staff, volunteers, U.S. and international partners, and other supporters—along each of the flyways of the Americas, Audubon can weave a seamless web of conservation for both migratory and non-migratory species. By working toward common flyway conservation goals, we can have greater impact. And by coordinating resources and expertise, we can increase our efficiency across the network. </p>
    </div>
  </div>

  <div class="row space-top text-container">
    <div class="medium-4 columns">
      <h3 class="">State Programs</h3>
      <p>Audubon&rsquo;s 22 state programs give us a presence at statehouses and are a powerful force for programmatic alignment throughout the flyways.</p>
    </div>
    <div class="medium-4 columns">
      <h3>Centers</h3>
      <p>Forty-seven Audubon Centers introduce more than a million visitors each years to the natural world—and inspire them to help protect it. </p>
    </div>
    <div class="medium-4 columns">
      <h3>Chapters</h3>
      <p>Audubon’s 465 Chapters are more than our face in communities from coast to coast; they are the drivers of our on-the-ground conservation work. </p>
    </div>
  </div>

  <section class="category-nav strip-nav">
    <div class="row">
      <div class="columns">
        <ul class="inline-list">
          <li><a class="flyway-slide-button" href="#pacific-flyway-slide">Pacific Flyway</a></li>
          <li><a class="flyway-slide-button current" href="#central-flyway-slide">Central Flyway</a></li>
          <li><a class="flyway-slide-button" href="#mississippi-flyway-slide">Mississippi Flyway</a></li>
          <li><a class="flyway-slide-button" href="#atlantic-flyway-slide">Atlantic Flyway</a></li>
        </ul>
      </div>
    </div>
  </section>

  <div class="flyway-slides">
    <div class="flyway-slides-container">
      <div id="pacific-flyway-slide" class="flyway-slide">
        <div class="row section-header">
          <div class="column">
            <h1>Pacific Flyway</h1>
          </div>
          <div class="column">
            <ul class="inline-list section-nav">
              <li>
                <a href="#">Conservation Goals</a><br>
                58 million acres | 17 priority bird species
              </li>
            </ul>
          </div>
        </div>
        <div class="row">
          <div class="column">
            <p>The Central Flyway extends from the grasslands of the Great Plains to the western Gulf Coast. Many of its migratory bird species winter in Central and South America; some migrate across the Western Hemisphere as far north at the Arctic Circle and others south to Patagonia in southern South America.
              <a href="#">Learn More »</a></p>
          </div>
        </div>
        <div class="row space-top space-bottom">
          <div class="columns large-4">
            <div class="editorial-card collapse-minimal">
              <div class="editorial-card-photo">
                <img src="../../img/editorial-card-1.jpg">
              </div>
              <div class="editorial-card-content short">
                <a href="#" class="editorial-card-slug">Priority Birds</a>
                <h4 class="editorial-card-title"><a href="#">Greater Sage Grouse</a></h4>
                <p>The flyway is home to 17 Priority Bird species, depend on a wide range of habitats.</p>
              </div>
            </div>
          </div>
          <div class="columns large-4">
            <div class="editorial-card collapse-minimal">
              <div class="editorial-card-photo">
                <img src="../../img/editorial-card-2.jpg">
              </div>
              <div class="editorial-card-content short">
                <a href="#" class="editorial-card-slug">Important Bird Areas</a>
                <h4 class="editorial-card-title"><a href="#">Aiken Canyon Preserve</a></h4>
                <p>The United States region of the Central Flyway is home to 65 global Important Bird Areas.</p>
              </div>
            </div>
          </div>
          <div class="columns large-4">
            <div class="editorial-card collapse-minimal">
              <div class="editorial-card-photo">
                <img src="../../img/editorial-card-3.jpg">
              </div>
              <div class="editorial-card-content short">
                <a href="#" class="editorial-card-slug">In The News</a>
                <h4 class="editorial-card-title"><a href="#">Improving the Health of Rivers in the Mid-Atlantic</a></h4>
                <p>April 23, 2014</p>
              </div>
            </div>
          </div>
        </div>
      </div>
      <div id="central-flyway-slide" class="flyway-slide current">
        <div class="row section-header">
          <div class="column">
            <h1>Central Flyway</h1>
          </div>
          <div class="column">
            <ul class="inline-list section-nav">
              <li>
                <a href="#">Conservation Goals</a><br>
                58 million acres | 17 priority bird species
              </li>
            </ul>
          </div>
        </div>
        <div class="row">
          <div class="column">
            <p>The Central Flyway extends from the grasslands of the Great Plains to the western Gulf Coast. Many of its migratory bird species winter in Central and South America; some migrate across the Western Hemisphere as far north at the Arctic Circle and others south to Patagonia in southern South America.
              <a href="#">Learn More »</a></p>
          </div>
        </div>
        <div class="row space-top space-bottom">
          <div class="columns large-4">
            <div class="editorial-card collapse-minimal">
              <div class="editorial-card-photo">
                <img src="../../img/editorial-card-1.jpg">
              </div>
              <div class="editorial-card-content short">
                <a href="#" class="editorial-card-slug">Priority Birds</a>
                <h4 class="editorial-card-title"><a href="#">Greater Sage Grouse</a></h4>
                <p>The flyway is home to 17 Priority Bird species, depend on a wide range of habitats.</p>
              </div>
            </div>
          </div>
          <div class="columns large-4">
            <div class="editorial-card collapse-minimal">
              <div class="editorial-card-photo">
                <img src="../../img/editorial-card-2.jpg">
              </div>
              <div class="editorial-card-content short">
                <a href="#" class="editorial-card-slug">Important Bird Areas</a>
                <h4 class="editorial-card-title"><a href="#">Aiken Canyon Preserve</a></h4>
                <p>The United States region of the Central Flyway is home to 65 global Important Bird Areas.</p>
              </div>
            </div>
          </div>
          <div class="columns large-4">
            <div class="editorial-card collapse-minimal">
              <div class="editorial-card-photo">
                <img src="../../img/editorial-card-3.jpg">
              </div>
              <div class="editorial-card-content short">
                <a href="#" class="editorial-card-slug">In The News</a>
                <h4 class="editorial-card-title"><a href="#">Improving the Health of Rivers in the Mid-Atlantic</a></h4>
                <p>April 23, 2014</p>
              </div>
            </div>
          </div>
        </div>
      </div>
      <div id="mississippi-flyway-slide" class="flyway-slide">
        <div class="row section-header">
          <div class="column">
            <h1>Mississippi Flyway</h1>
          </div>
          <div class="column">
            <ul class="inline-list section-nav">
              <li>
                <a href="#">Conservation Goals</a><br>
                58 million acres | 17 priority bird species
              </li>
            </ul>
          </div>
        </div>
        <div class="row">
          <div class="column">
            <p>The Central Flyway extends from the grasslands of the Great Plains to the western Gulf Coast. Many of its migratory bird species winter in Central and South America; some migrate across the Western Hemisphere as far north at the Arctic Circle and others south to Patagonia in southern South America.
              <a href="#">Learn More »</a></p>
          </div>
        </div>
        <div class="row space-top space-bottom">
          <div class="columns large-4">
            <div class="editorial-card collapse-minimal">
              <div class="editorial-card-photo">
                <img src="../../img/editorial-card-1.jpg">
              </div>
              <div class="editorial-card-content short">
                <a href="#" class="editorial-card-slug">Priority Birds</a>
                <h4 class="editorial-card-title"><a href="#">Greater Sage Grouse</a></h4>
                <p>The flyway is home to 17 Priority Bird species, depend on a wide range of habitats.</p>
              </div>
            </div>
          </div>
          <div class="columns large-4">
            <div class="editorial-card collapse-minimal">
              <div class="editorial-card-photo">
                <img src="../../img/editorial-card-2.jpg">
              </div>
              <div class="editorial-card-content short">
                <a href="#" class="editorial-card-slug">Important Bird Areas</a>
                <h4 class="editorial-card-title"><a href="#">Aiken Canyon Preserve</a></h4>
                <p>The United States region of the Central Flyway is home to 65 global Important Bird Areas.</p>
              </div>
            </div>
          </div>
          <div class="columns large-4">
            <div class="editorial-card collapse-minimal">
              <div class="editorial-card-photo">
                <img src="../../img/editorial-card-3.jpg">
              </div>
              <div class="editorial-card-content short">
                <a href="#" class="editorial-card-slug">In The News</a>
                <h4 class="editorial-card-title"><a href="#">Improving the Health of Rivers in the Mid-Atlantic</a></h4>
                <p>April 23, 2014</p>
              </div>
            </div>
          </div>
        </div>
      </div>
      <div id="atlantic-flyway-slide" class="flyway-slide">
        <div class="row section-header">
          <div class="column">
            <h1>Atlantic Flyway</h1>
          </div>
          <div class="column">
            <ul class="inline-list section-nav">
              <li>
                <a href="#">Conservation Goals</a><br>
                58 million acres | 17 priority bird species
              </li>
            </ul>
          </div>
        </div>
        <div class="row">
          <div class="column">
            <p>The Central Flyway extends from the grasslands of the Great Plains to the western Gulf Coast. Many of its migratory bird species winter in Central and South America; some migrate across the Western Hemisphere as far north at the Arctic Circle and others south to Patagonia in southern South America.
              <a href="#">Learn More »</a></p>
          </div>
        </div>
        <div class="row space-top space-bottom">
          <div class="columns large-4">
            <div class="editorial-card collapse-minimal">
              <div class="editorial-card-photo">
                <img src="../../img/editorial-card-1.jpg">
              </div>
              <div class="editorial-card-content short">
                <a href="#" class="editorial-card-slug">Priority Birds</a>
                <h4 class="editorial-card-title"><a href="#">Greater Sage Grouse</a></h4>
                <p>The flyway is home to 17 Priority Bird species, depend on a wide range of habitats.</p>
              </div>
            </div>
          </div>
          <div class="columns large-4">
            <div class="editorial-card collapse-minimal">
              <div class="editorial-card-photo">
                <img src="../../img/editorial-card-2.jpg">
              </div>
              <div class="editorial-card-content short">
                <a href="#" class="editorial-card-slug">Important Bird Areas</a>
                <h4 class="editorial-card-title"><a href="#">Aiken Canyon Preserve</a></h4>
                <p>The United States region of the Central Flyway is home to 65 global Important Bird Areas.</p>
              </div>
            </div>
          </div>
          <div class="columns large-4">
            <div class="editorial-card collapse-minimal">
              <div class="editorial-card-photo">
                <img src="../../img/editorial-card-3.jpg">
              </div>
              <div class="editorial-card-content short">
                <a href="#" class="editorial-card-slug">In The News</a>
                <h4 class="editorial-card-title"><a href="#">Improving the Health of Rivers in the Mid-Atlantic</a></h4>
                <p>April 23, 2014</p>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
    <a href="#" class="flyway-slides-paddle prev"></a>
    <a href="#" class="flyway-slides-paddle next"></a>
  </div>

  <section class="breakout-section black-bg">
    <div class="breakout-section-hero margin-bottom" style="background-image: url(../../img/breakout-section-6.jpg)">
      <div class="row">
        <div class="column">
          <h1 class="breakout-section-headline">Hemispheric Partners</h1>
        </div>
      </div>
    </div>
    <div class="breakout-section-content">
      <div class="row space-bottom">
        <div class="column">
          <div class="deck">Audubon works with 19 BirdLife International partners and others across the Americas to protect birds throughout their annual life cycles of breeding, migration, and wintering. <a href="#">Learn more »</a></div>

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
              <img src="../../img/engagement-card-1.jpg" alt="">
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
              <img src="../../img/engagement-card-2.jpg" alt="">
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
              <img src="../../img/engagement-card-3.jpg" alt="">
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