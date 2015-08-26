<?php
/**
 * @file
 * Template to custom pane engagement_cards_sidebar.
 *
 * Available variables:
 *  $contextual_links - contextual links.
 *  $teaser - rendered node.
 */
?>
<div class="sidebar-section engagement-card-sidebar-section contextual-links-region" <?php print $equalize_height; ?>>
  <?php print $contextual_links; ?>
  <?php if ($show_social_icons): ?>
  <div class="engagement-card-and-social-icons">
  <?php endif; ?>
  <?php foreach ($teasers as $teaser): ?>
    <?php print $teaser; ?>
  <?php endforeach; ?>
  <?php if (empty($teasers)): ?>
    <p>&nbsp;</p>
  <?php endif; ?>
  <?php if ($show_social_icons): ?>
    <div class="editorial-card-banner editorial-card-banner-frontpage blue">
      <div class="social-sharing">
        <span class="social-sharing-caption small">Follow us </span>
        <a class="social-sharing-icon white small" href="<?php print $social_icons['twitter']; ?>"><i class="icon-twitter"></i></a>
        <a class="social-sharing-icon white small" href="<?php print $social_icons['facebook']; ?>"><i class="icon-facebook"></i></a>
        <a class="social-sharing-icon white small" href="<?php print $social_icons['instagram']; ?>"><i class="icon-instagram"></i></a>
      </div>
    </div>
  </div>
  <?php endif; ?>
</div>
