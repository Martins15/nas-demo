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
