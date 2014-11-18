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

  <?php print $content['bottom']; ?>

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