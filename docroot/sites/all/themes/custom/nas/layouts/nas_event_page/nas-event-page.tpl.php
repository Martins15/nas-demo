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
    
    <!-- BEGIN HEADER -->
    <div class="column">
      <header class="title">
        <?php //print $content['header']; ?>
      </header>
    </div>
    <!-- END HEADER -->
  
  </div>

  <div class="row space-top">

    <!-- BEGIN MAIN COLUMN -->
    <div class="large-8 columns text-container">
      <?php print $content['location']; ?>
      <?php print $content['description']; ?>
    </div>
    <!-- END MAIN COLUMN -->

    <!-- BEGIN SIDEBAR -->
    <div class="sidebar large-4 columns">
      <?php print $content['registration']; ?>
      <?php print $content['sidebar']; ?>
    </div>
    <!-- END SIDEBAR -->

  </div>

</section>
