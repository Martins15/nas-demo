<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<?php print $content['header']; ?>
</header>
<section <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?> class="global-content">
<div class="top-search-form">
  <div class="row">
    <div class="columns">
      <?php print $content['search_form']; ?>
    </div>
  </div>
</div>

<?php print $content['birds_search_results']; ?>

<section class="global-content global-content-search no-padding">
  <div class="row">
    <div class="section-header columns large-8 border-bottom">
      <?php print $content['search_results_count']; ?>
    </div>
  </div>
  <div class="row">
    <div class="sidebar columns large-push-8 large-4">
      <?php print $content['sidebar']; ?>
    </div>
    <?php print $content['search_results']; ?>
  </div>
</section>
