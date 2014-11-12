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
      <ul class="section-nav inline-list mag-issue-nav">
        <li><?php print l(t('Subscriber Services'), ''); ?></li>
        <li><?php print l(t('Past Issues'), ''); ?></li>
      </ul>
    </div>
  </div>
  <div class="row">

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
      <div class="sidebar-section editorial-card-photo">
      <?php print $content['cover']; ?>
      </div>
      <?php print $content['right_sidebar']; ?>
      <div class="sidebar-section engagement-card">
        <div class="engagement-card-content no-min-height">
          <h3 class="engagement-card-headline">Donate Today & Get the Magazine</h3>
          <p>An annual donation of $40 gets Audubon Magazine delivered straight to your door.</p>
          <div class="engagement-card-cta">
            <a href="#" class="button tomato large">Support Audubon</a>
          </div>
        </div>
        <div class="engagement-card-photo">
          <a href="#"><img src="<?php print base_path() . path_to_theme() . '/img/'; ?>engagement-card-27.jpg" alt=""></a>
        </div>
      </div>
    </div>
    <!-- END SIDEBAR -->
  </div>
  <!-- BEGIN BOTTOM ROW -->
  <div class="row">
    <div class="large-8 columns index-list">
      <?php print $content['other_issues']; ?>
    </div>
  </div>
  <!-- END BOTTOM ROW -->
</section>
