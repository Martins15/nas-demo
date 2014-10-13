<?php
/**
 * @file
 * Template for footer section.
 * 
 * Available variables:
 * - $contextual_links: array of rendered links for all menus
 * - $mission_title: string title
 * - $mission:  string mission
 * - $logo: <img> rendered image 
 * - $footer_menu: themed footer menu
 * - $copyright: string copyright message
 * - $footer_copyright_menu: themed copyright menu
 */
?>
<?php $cl_class = ($contextual_links['menu']) ? ' contextual-links-region' : '';?>
<footer class="global-footer">
  <section class="footer-site-map">
    <div class="row<?php print $cl_class; ?>">
      <?php print $contextual_links['menu']; ?>
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
      <div class="column footer-copyright-links<?php print $cl_class; ?>">
        <?php print $contextual_links['cr_menu']; ?>
        <p>
          <?php print $copyright; ?>
          <span class="footer-copyright-links"><?php print $footer_copyright_menu; ?></span>
        </p>
      </div>
    </div>
  </section>
</footer>