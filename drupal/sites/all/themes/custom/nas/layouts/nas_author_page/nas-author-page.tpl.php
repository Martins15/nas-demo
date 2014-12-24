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
        <?php print $content['link']; ?>
        <h1 class="bio-name"><?php print $content['name']; ?> <?php print $content['twitter']; ?></h1>
        <small class="bio-title"><?php print $content['title']; ?></small>
      </header>
    </div>
  </div>

  <div class="row space-top">

    <!-- BEGIN MAIN COLUMN -->
    <div class="large-8 columns text-container">
      <?php print $content['bio']; ?>
      <?php print $content['articles']; ?>
    </div>
    <!-- END MAIN COLUMN -->

    <!-- BEGIN SIDEBAR -->

    <div class="sidebar large-4 columns">
      <?php print $content['right']; ?>
      <!--
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
      </div>-->
    </div>

    <!-- END SIDEBAR -->

  </div>

  <?php print $content['related_birds']; ?>

</section>
