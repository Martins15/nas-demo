<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>

<div class="guide-bar">
    <div class="row">
      <div class="column">
        <h2 class="guide-bar-title"><span class="hide-for-small hide-for-tiny">Guide to </span>North American Birds</h2>
        <div class="guide-bar-attribution"><span class="preamble">Brought to you by</span><img class="canon-logo" src="<?php print base_path() . path_to_theme() . '/img/canon-logo.png'; ?>"></div>
      </div>
    </div>
  </div>

  <section class="global-content">
    <div class="row">
      <?php print $content['top']; ?>
    </div>
    <div class="bird-card-grid">
      <a href="" class="bg-egg icon-binoculars white"></a>
      <?php print $content['main']; ?>
      <div class="row space-bottom"></div>
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
          <img src="../../../img/engagement-card-1.jpg" alt="">
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
          <img src="../../../img/engagement-card-2.jpg" alt="">
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
          <img src="../../../img/engagement-card-3.jpg" alt="">
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
