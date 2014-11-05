<?php
/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>

<?php print $content['header']; ?>

<section class="global-content with-padding">
  <div class="breakout-section fixed-height"
  <?php if (!empty($background_image)): ?>
       style="background-image: url(<?php print $background_image; ?>)"
  <?php endif; ?>>
    <div class="breakout-section-content <?php print !empty($color_mode_text) ? $color_mode_text : 'dark'; ?>-text">
      <div class="row text-container">
        <div class="column">
          <h1 class="thin"><?php print $content['secondary_title']; ?></h1>
          <div class="deck"><?php print $content['subtitle']; ?></div>
        </div>
        <?php print $content['body']; ?>
      </div>
    </div>
  </div>

  <div class="bird-card-set">
    <div class="row section-header space-top">
      <div class="columns">
        <h2 class="thin">Atlantic Flyway’s Priority Birds</h2>
      </div>
      <div class="columns">
        <ul class="section-nav inline-list">
          <li><a href="#">More Priority Birds</a></li>
          <li><a class="cta" href="#">Adopt a Bird</a></li>
        </ul>
      </div>
    </div>
    <div class="row bird-card-container">
      <div class="bird-card-scroller" style="transition: 0ms cubic-bezier(0.1, 0.57, 0.1, 1); -webkit-transition: 0ms cubic-bezier(0.1, 0.57, 0.1, 1); transform: translate(0px, 0px) translateZ(0px);">
        <div class="columns tiny-3">
          <figure class="bird-card">
            <div class="bird-card-illustration">
              <a href="#"><img src="../../img/bird-1.png" alt=""></a>
            </div>
            <figcaption class="bird-card-caption">
              <h4 class="common-name"><a href="#">Cactus Wren</a></h4>
              <p class="scientific-name">Campylorhynchus brunneicapillus</p>
            </figcaption>
            <a href="#" class="icon-sound-full bird-card-audio"></a>
          </figure>
        </div>
        <div class="columns tiny-3">
          <figure class="bird-card">
            <div class="bird-card-illustration">
              <a href="#"><img src="../../img/bird-2.png" alt=""></a>
            </div>
            <figcaption class="bird-card-caption">
              <h4 class="common-name"><a href="#">Bullock's Oriole</a></h4>
              <p class="scientific-name">Icterus Bullocki</p>
            </figcaption>
            <a href="#" class="icon-sound-full bird-card-audio"></a>
          </figure>
        </div>
        <div class="columns tiny-3">
          <figure class="bird-card">
            <div class="bird-card-illustration">
              <a href="#"><img src="../../img/bird-3.png" alt=""></a>
            </div>
            <figcaption class="bird-card-caption">
              <h4 class="common-name"><a href="#">Pileated Woodpecker</a></h4>
              <p class="scientific-name">Dryocopus pileatus</p>
            </figcaption>
            <a href="#" class="icon-sound-full bird-card-audio"></a>
          </figure>
        </div>
        <div class="columns tiny-3">
          <figure class="bird-card">
            <div class="bird-card-illustration">
              <a href="#"><img src="../../img/bird-4.png" alt=""></a>
            </div>
            <figcaption class="bird-card-caption">
              <h4 class="common-name"><a href="#">Western Scrub‑Jay</a></h4>
              <p class="scientific-name">Aphelocoma californica</p>
            </figcaption>
            <a href="#" class="icon-sound-full bird-card-audio"></a>
          </figure>
        </div>
      </div>
      <div class="row indicator space-bottom">
        <div class="column">
          <p><i class="indicator-left icon-arrow-left disabled"></i>&nbsp;&nbsp;&nbsp;<i class="indicator-right icon-arrow-right"></i></p>
        </div>
      </div>
    </div>
  </div>

  <div class="card-set bg-gray">
    <div class="row section-header space-top">
      <div class="column">
        <h2 class="thin">Important Bird Areas of the Atlantic Flyway</h2>
      </div>
      <div class="column">
        <ul class="inline-list section-nav">
          <li><a href="#">More IBAs »</a></li>
        </ul>
      </div>
    </div>
    <div class="row card-set-wrapper space-bottom double">
      <div class="clearfix card-set-scroller">
        <div class="columns tiny-4">
          <div class="editorial-card" style="min-height: 338px;">
            <div class="editorial-card-photo">
              <img src="../../img/editorial-card-14.jpg">
            </div>
            <div class="editorial-card-content short">
              <a href="#" class="editorial-card-slug">Florida</a>
              <h4 class="editorial-card-title">Greater Everglades Ecosystem</h4>
              <p>Along with the title, we should include a short description of the IBA.</p>
            </div>
          </div>
        </div>
        <div class="columns tiny-4">
          <div class="editorial-card" style="min-height: 338px;">
            <div class="editorial-card-photo">
              <img src="../../img/editorial-card-2.jpg">
            </div>
            <div class="editorial-card-content short">
              <a href="#" class="editorial-card-slug">New York</a>
              <h4 class="editorial-card-title">Long Island Sound</h4>
              <p>Along with the title, we should include a short description of the IBA.</p>
            </div>
          </div>
        </div>
        <div class="columns tiny-4">
          <div class="editorial-card" style="min-height: 338px;">
            <div class="editorial-card-photo">
              <img src="../../img/editorial-card-3.jpg">
            </div>
            <div class="editorial-card-content short">
              <a href="#" class="editorial-card-slug">North Carolina</a>
              <h4 class="editorial-card-title">Outer Banks</h4>
              <p>Along with the title, we should include a short description of the IBA.</p>
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
    </div>
  </div>

  <div class="row section-header space-top">
    <div class="column">
      <h2 class="thin">Atlantic Flyway in the News</h2>
    </div>
    <div class="column">
      <ul class="section-nav inline-list">
        <li><a href="#">More News »</a></li>
      </ul>
    </div>
  </div>
  <div class="row space-bottom">
    <div class="columns large-4">
      <div class="editorial-card collapse-minimal" style="min-height: 341px;">
        <div class="editorial-card-photo">
          <img src="../../img/editorial-card-1.jpg">
        </div>
        <div class="editorial-card-content short">
          <a href="#" class="editorial-card-slug">In The News</a>
          <h4 class="editorial-card-title">Atlantic Coast Oil Spill Imperils Thousands of Birds</h4>
          <p><em><a href="#" class="editorial-card-link">Map of impacted areas</a></em></p>
        </div>
      </div>
    </div>
    <div class="columns large-4">
      <div class="editorial-card collapse-minimal" style="min-height: 341px;">
        <div class="editorial-card-photo">
          <img src="../../img/editorial-card-2.jpg">
        </div>
        <div class="editorial-card-content short">
          <a href="#" class="editorial-card-slug">Citizen Science</a>
          <h4 class="editorial-card-title">Get Geared Up for the Great Backyard Bird Count</h4>
          <p><em><a href="#" class="editorial-card-link">How you can participate</a></em></p>
        </div>
      </div>
    </div>
    <div class="columns large-4">
      <div class="editorial-card collapse-minimal" style="min-height: 341px;">
        <div class="editorial-card-photo">
          <img src="../../img/editorial-card-3.jpg">
        </div>
        <div class="editorial-card-content short">
          <a href="#" class="editorial-card-slug">Conservation</a>
          <h4 class="editorial-card-title">Improving the Health of Rivers in the Mid-Atlantic</h4>
          <p><em><a href="#" class="editorial-card-link">Two dozen areas targeted</a></em></p>
        </div>
      </div>
    </div>
  </div>

  <div class="card-set">
    <div class="row section-header">
      <div class="column">
        <h2 class="thin">Conservation Projects in the Atlantic Flyway</h2>
      </div>
      <div class="column">
        <ul class="section-nav inline-list">
          <li><a href="#">More Projects »</a></li>
        </ul>
      </div>
    </div>
    <div class="row card-set-wrapper">
      <div class="clearfix card-set-scroller">
        <div class="tiny-4 columns">
          <div class="editorial-card" style="min-height: 368px;">
            <div class="editorial-card-photo">
              <a href="#"><img src="../../img/editorial-card-10.jpg" alt=""></a>
            </div>
            <div class="editorial-card-content">
              <a href="#" class="editorial-card-slug">Seas &amp; Shores</a>
              <h4 class="editorial-card-title"><a href="#">Here’s the Name of a Conservation Project</a></h4>
              <p>Along with the title, we should include a short description of the project. </p>
            </div>
          </div>
        </div>
        <div class="tiny-4 columns">
          <div class="editorial-card" style="min-height: 368px;">
            <div class="editorial-card-photo">
              <a href="#"><img src="../../img/editorial-card-11.jpg" alt=""></a>
            </div>
            <div class="editorial-card-content">
              <a href="#" class="editorial-card-slug">Working Lands</a>
              <h4 class="editorial-card-title"><a href="#">Another Example of a Conservation Project</a></h4>
              <p>Along with the title, we should include a short description of the project. </p>
            </div>
          </div>
        </div>
        <div class="tiny-4 columns">
          <div class="editorial-card" style="min-height: 368px;">
            <div class="editorial-card-photo">
              <a href="#"><img src="../../img/editorial-card-12.jpg" alt=""></a>
            </div>
            <div class="editorial-card-content">
              <a href="#" class="editorial-card-slug">Important Bird Areas</a>
              <h4 class="editorial-card-title"><a href="#">And a THird Conservation Project Linked Here</a></h4>
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
        <span class="social-sharing-caption white">Spread the word. It’s the least you can do.</span>
        <a class="social-sharing-icon white" href="#"><i class="icon-twitter"></i></a>
        <a class="social-sharing-icon white" href="#"><i class="icon-facebook"></i></a>
        <a class="social-sharing-icon white" href="#"><i class="icon-mail"></i></a>
      </div>
    </div>
  </section>
</section>