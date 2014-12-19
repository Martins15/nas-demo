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
      <?php print $content['title']; ?>
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
    </div>
  <!-- END MAIN COLUMN -->

    <!-- BEGIN SIDEBAR -->

    <div class="sidebar large-4 columns">
      <?php print $content['right_sidebar']; ?>
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
</section>
