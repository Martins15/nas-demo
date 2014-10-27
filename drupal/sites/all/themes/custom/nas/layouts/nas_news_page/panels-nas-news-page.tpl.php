<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<?php print $content['header']; ?>
</header>
<section <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?> class="global-content">
  <div class="row section-header">
    <div class="columns">
      <h1><?php print t('News'); ?></h1>
    </div>
    <div class="columns">
      <div class="section-nav hide-for-tiny hide-for-small hide-for-medium">
        <?php print $content['social']; ?>
      </div>
    </div>
  </div>
  <div class="row">
    <div class="large-12 columns contextual-links-region">
      <?php print $content['featured']; ?>
    </div>
  </div>
  <div class="row">

  <!-- BEGIN MAIN COLUMN -->
    <div class="large-8 columns index-list">
      <?php print $content['articles_top']; ?>
      <?php print $content['donate']; ?>
      <?php print $content['articles_bottom']; ?>      
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
      <?php print $content['right_sidebar']; ?>
    </div>

    <!-- END SIDEBAR -->

  </div>
</section>