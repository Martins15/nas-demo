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
  </section>
</section>
