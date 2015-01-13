<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<?php print $content['header']; ?>
</header>
<section <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?> class="global-content">
  <div class="row section-header mag-issue-header">
    <div class="columns">
      <h1 class="mag-issue-title"><?php print t('Audubon Magazine'); ?> <span><?php print $content['title']; ?></span></h1>
    </div>
    <div class="columns">
      <?php print $content['mag_issue_nav']; ?>
    </div>
  </div>
  <div class="row">

    <div class="hide-for-large hide-for-xlarge">
      <?php print $content['cover']; ?>
    </div>
  <!-- BEGIN MAIN COLUMN -->
    <div class="large-8 columns index-list">
      <?php print $content['featured']; ?>
      <?php print $content['articles_top']; ?>
      <?php print $content['donate']; ?>
      <?php print $content['articles_bottom']; ?>
    </div>
  <!-- END MAIN COLUMN -->

  <!-- BEGIN SIDEBAR -->
    <div class="sidebar large-4 columns">
      <div class="hide-for-tiny hide-for-small hide-for-medium sidebar-section editorial-card-photo">
      <?php print $content['cover']; ?>
      </div>
      <?php print $content['right_sidebar']; ?>
    </div>
    <!-- END SIDEBAR -->
  </div>
  <!-- BEGIN BOTTOM ROW -->
  <div class="row">
    <div class="columns">
      <?php print $content['other_issues']; ?>
    </div>
  </div>
  <!-- END BOTTOM ROW -->
</section>
