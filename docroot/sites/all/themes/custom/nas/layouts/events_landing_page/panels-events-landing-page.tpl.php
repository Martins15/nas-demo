<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<?php print $content['header']; ?>
</header>

<div class="events-search show">
  <div class="row">
    <div class="columns large-12">
      <?php print $content['exposed_form']; ?>
    </div>
  </div>
</div>
<section <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?> class="global-content">
  <div class="row">
    <!-- BEGIN MAIN COLUMN -->
    <div class="large-8 columns index-list">
      <?php print $content['main']; ?>
    </div>
    <!-- END MAIN COLUMN -->

    <!-- BEGIN SIDEBAR -->
    <div class="sidebar large-4 columns">
      <?php print $content['sidebar']; ?>
    </div>
    <!-- END SIDEBAR -->
  </div>

  <!-- BEGIN MIDDLE FULLWIDTH -->
  <div class="row">
    <div class="large-12 columns">
      <?php print $content['bottom']; ?>
    </div>
  </div>
  <!-- END MIDDLE FULLWIDTH -->
</section>

