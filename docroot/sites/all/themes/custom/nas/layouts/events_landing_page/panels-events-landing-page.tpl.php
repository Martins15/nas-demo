<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<?php print $content['header']; ?>
</header>

<?php if (!empty($content['exposed_form'])): ?>
<div class="events-search show">
  <div class="row">
    <div class="columns large-12">
      <?php print $content['exposed_form']; ?>
    </div>
  </div>
</div>
<?php endif; ?>
<section <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?> class="global-content ffw-hack-margin-top">
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

  <!-- Engagement cards -->
  <section class="card-set bg-1">
    <?php print $content['bottom']; ?>
  </section>
  <!-- END Engagement cards -->
</section>

