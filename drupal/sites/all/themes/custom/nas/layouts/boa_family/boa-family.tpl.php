<?php
/**
 * @file
 * Template implementation to display BOA layout.
 */
?>
<section class="global-content with-padding">
  <div class="row">
    <div class="boa-family-text-block text-container">
      <div class="large-12 columns">
        <h1 class="thin family-name"><?php print $content['title']; ?></h1>
        <p class="scientific-name"><?php print $content['scientific_name']; ?></p>
      </div>
      <div class="large-6 columns">
        <?php print $content['body_column_1']; ?>
      </div>
      <div class="large-6 columns">
        <?php print $content['body_column_2']; ?>
      </div>
    </div>
  </div>
  <?php print $content['bottom']; ?>
  <section class="card-set bg-1">
    <div class="row">
      <div class="column">
        <h1 class="card-set-heading pea-green">Here’s how you can make a difference.</h1>
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
              <img src="<?php print base_path() . drupal_get_path('theme', 'nas') . '/img/'; ?>engagement-card-1.jpg" alt="">
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
              <img src="<?php print base_path() . drupal_get_path('theme', 'nas') . '/img/'; ?>engagement-card-2.jpg" alt="">
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
              <img src="<?php print base_path() . drupal_get_path('theme', 'nas') . '/img/'; ?>engagement-card-3.jpg" alt="">
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
        <span class="social-sharing-caption white">Spread the word about Audubon and the work that we do.</span>
        <a class="social-sharing-icon white" href="#"><i class="icon-twitter"></i></a>
        <a class="social-sharing-icon white" href="#"><i class="icon-facebook"></i></a>
        <a class="social-sharing-icon white" href="#"><i class="icon-mail"></i></a>
      </div>
    </div>
  </section>
</section>