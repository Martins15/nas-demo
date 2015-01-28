<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<?php print $content['header']; ?>
</header>
<?php print $content['hero']; ?>
<section <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?> class="global-content no-padding">
  <div class="bird-card-set">
    <?php print $content['bird_card_set']; ?>
  </div>

  <div class="row banner-set">
    <?php print $content['banner_set']; ?>
  </div>
  <div class="row">
    <?php print $content['cards']; ?>
  </div>
  <section class="card-set bg-1">
    <?php print $content['engagement_cards']; ?>
  </section>
</section>