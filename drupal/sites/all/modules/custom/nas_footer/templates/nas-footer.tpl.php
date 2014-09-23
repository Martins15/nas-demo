<?php
/**
 * @file
 * Template for footer section.
 */
?>
<footer class="global-footer">
  <section class="footer-site-map">
    <div class="row">
      <div class="medium-12 large-3 columns">
        <?php if ($logo) : ?>
          <?php print $logo; ?>
        <?php endif; ?>
        <h5><?php print $mission_title; ?></h5>
        <p><?php print $mission; ?></p>
      </div>
      <?php print $footer_menu; ?>
    </div>
  </section>
  <section class="footer-copyright">
    <div class="row">
      <div class="column">
        <p>
          <?php print $copyright; ?>
          <span class="footer-copyright-links"><?php print $footer_copyright_menu; ?></span>
        </p>
      </div>
    </div>
  </section>
</footer>
