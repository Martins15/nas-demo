<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<?php print $content['hero']; ?>
<section <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?> class="global-content no-padding">
  <div class="row banner-set">
    <div class="large-6 columns"><?php print $content['left_card']; ?></div>
    <div class="large-6 columns"><?php print $content['right_card']; ?></div>
  </div>
  <div class="row">
    <?php print $content['cards']; ?>
  </div>
  <section class="card-set bg-1">
    <?php print $content['engagement_cards']; ?>
    <div class="row">
      <div class="card-set-social social-sharing">
        <span class="social-sharing-caption white">Spread the word. It’s the least you can do.</span>
        <a class="social-sharing-icon white" href="#"><i class="icon-twitter"></i></a>
        <a class="social-sharing-icon white" href="#"><i class="icon-facebook"></i></a>
        <a class="social-sharing-icon white" href="#"><i class="icon-mail"></i></a>
      </div>
    </div>
  </section>
</section>
