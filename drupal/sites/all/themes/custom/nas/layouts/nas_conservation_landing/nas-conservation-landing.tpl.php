<?php
/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<?php print render($content['top']); ?>
<?php print render($content['menu_bar']); ?>

<section class="global-content with-padding">
  <div class="row">
    <?php print $content['body']; ?>
  </div>
  <?php print $content['slideshow']; ?>
  <?php print $content['full_bg_area']; ?>
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
