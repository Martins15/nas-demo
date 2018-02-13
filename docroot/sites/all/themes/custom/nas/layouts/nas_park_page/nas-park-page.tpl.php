<?php

/**
 * @file
 * Park page template.
 */
//dpm(get_defined_vars());
?>

<!-- Park page layout begin -->
<!-- Region: top -->
<div class="park_top">
  <div class="hero dark-gradient">
    <div class="hero-image">
      <?php print $content['top']; ?>
    </div>
  </div>
  <?php if (!empty($content['header_hero_attr_text'])): ?>
    <div class="hero-caption">
      <div class="hero-attribution-fullscreen row">
        <p><?php print $content['header_hero_attr_text']; ?></p>
      </div>
    </div>
  <?php endif; ?>
</div>
<!-- /Region: top -->

<div class="row">
  <!-- Region: park info -->
  <div class="park_info columns">
    <?php print $content['park_info']; ?>
  </div>
  <!-- /Region: park info -->

  <section class="global-content">
    <article class="park park-page-layout">
      <div class="park-body columns">
        <!-- Region: Main body content-->
        <?php print $content['primary_content']; ?>
        <!-- /Region: Main body content-->
      </div>
    </article>
  </section>
</div>

<!-- Region: Secondary content-->
<?php print $content['secondary_content']; ?>
<!-- /Region: Secondary content-->

<div class="clearfix"></div>
<!-- Park page layout end -->
