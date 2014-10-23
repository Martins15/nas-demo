<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<?php print $content['header']; ?>
</header>
<section <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?> class="global-content">
  <div class="row space-top">
    <div class="column">
      <header class="bio-header">
        <?php print $content['image']; ?>
        <h1 class="bio-name"><?php print $content['name']; ?> <?php print $content['twitter']; ?></h1>
        <small class="bio-title"><?php print $content['title']; ?>Vice President, Content</small>
      </header>
    </div>
  </div>

  <div class="row space-top">

    <!-- BEGIN MAIN COLUMN -->
    <div class="large-8 columns index-list">
      <?php print $content['bio']; ?>
      <?php print $content['articles']; ?>
    </div>
    <!-- END MAIN COLUMN -->

    <!-- BEGIN SIDEBAR -->

    <div class="sidebar large-4 columns">
      <div class="sidebar-section engagement-card">
        <div class="engagement-card-content no-min-height">
          <h3 class="engagement-card-headline">Save the Brown Pelican</h3>
          <p>Numerous oil spills along the Gulf Coast have threatened thousands of native birds.</p>
          <div class="engagement-card-cta">
            <a href="#" class="button tomato large">Endorse New Legislation</a>
          </div>
        </div>
        <div class="engagement-card-photo">
          <a href="#"><img src="<?php print base_path() . path_to_theme() . '/img/'; ?>engagement-card-1.jpg" alt=""></a>
        </div>
      </div>
      <div class="sidebar-section editorial-card">
        <div class="editorial-card-photo">
          <a href="#"><img src="<?php print base_path() . path_to_theme() . '/img/'; ?>editorial-card-4.jpg" alt=""></a>
        </div>
        <div class="editorial-card-banner green"><i class="icon-marker"></i> Audubon Near You</div>
        <div class="editorial-card-content">
          <h4 class="editorial-card-title"><a href="#">Birders Arrive in Droves to See Marsh Sandpiper in Solano County</a></h4>
          <hr />
          <a href="#" class="editorial-card-slug">In the News</a>
          <h5 class="editorial-card-title"><a href="#">An Update on the Tricolored Blackbird Colony</a></h5>
          <a href="#" class="editorial-card-slug">Upcoming Event</a>
          <h5 class="editorial-card-title"><a href="#">2014 Black Oystercatcher Workshop Announced for April 27</a></h5>
          <a href="#" class="editorial-card-slug">Action Alert</a>
          <h5 class="editorial-card-title"><a href="#">Protect a Western Snowy Plover Nest</a></h5>
        </div>
      </div>
    </div>

    <!-- END SIDEBAR -->

  </div>

  <div class="bird-card-set">
    <div class="row section-header">
      <div class="columns">
        <h2 class="thin">Mark’s Favorite Birds</h2>
      </div>
      <div class="columns">
        <ul class="section-nav inline-list">
          <li><a href="#">The Bird Guide</a></li>
          <li><a class="orange" href="#">Adopt a Bird</a></li>
        </ul>
      </div>
    </div>
    <div class="row bird-card-container space-bottom">
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
    </div>
    <div class="row indicator space-bottom double">
      <div class="column">
        <p><i class="indicator-left icon-arrow-left disabled"></i>&nbsp;&nbsp;&nbsp;<i class="indicator-right icon-arrow-right"></i></p>
      </div>
    </div>
  </div>
</section>
