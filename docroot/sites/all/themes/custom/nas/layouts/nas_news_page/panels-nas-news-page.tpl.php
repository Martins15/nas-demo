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
    </div>

    <!-- END SIDEBAR -->

  </div>
</section>
