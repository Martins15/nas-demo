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

  <!-- BEGIN TOP FULLWIDTH -->
  <div class="row">
    <div class="large-12 columns">
      <?php print $content['top']; ?>
    </div>
  </div>
  <!-- END TOP FULLWIDTH -->

  <div class="row">
    <!-- BEGIN MAIN COLUMN -->
    <div class="large-8 columns index-list">
      <?php print $content['top_left']; ?>
    </div>
    <!-- END MAIN COLUMN -->

    <!-- BEGIN SIDEBAR -->
    <div class="sidebar large-4 columns">
      <?php print $content['top_right']; ?>
    </div>
    <!-- END SIDEBAR -->
  </div>

  <!-- BEGIN MIDDLE FULLWIDTH -->
  <div class="row">
    <div class="large-12 columns">
      <?php print $content['middle']; ?>
    </div>
  </div>
  <!-- END MIDDLE FULLWIDTH -->

  <div class="row">
    <!-- BEGIN MAIN COLUMN -->
    <div class="large-8 columns index-list">
      <?php print $content['bottom_left']; ?>
    </div>
    <!-- END MAIN COLUMN -->

    <!-- BEGIN SIDEBAR -->
    <div class="sidebar large-4 columns">
      <?php print $content['bottom_right']; ?>
    </div>
    <!-- END SIDEBAR -->
  </div>

  <!-- BEGIN BOTTOM FULLWIDTH -->
  <div class="row">
    <div class="large-12 columns">
      <?php print $content['bottom']; ?>
    </div>
  </div>
  <!-- END BOTTOM FULLWIDTH -->
</section>
