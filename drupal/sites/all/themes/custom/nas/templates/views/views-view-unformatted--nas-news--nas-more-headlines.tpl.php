<?php

/**
 * @file
 * Custom view template to display News from the Network.
 *
 * @ingroup views_templates
 */
?>
<div class="editorial-card-content has-fixed-banner">
  <h3 class="close-heading"><?php print $view->display[$view->current_display]->display_title; ?></h3>
  <hr>
  <?php foreach ($rows as $id => $row): ?>
  <div<?php print !empty($classes_array[$id]) ? ' class="' . $classes_array[$id] . '"' : ''; ?>>
    <?php print $row; ?>
  </div>
  <?php endforeach; ?>
  <div class="editorial-card-list-item">
    <h5 class="editorial-card-title no-margin"><?php print l(t('More News »'), 'news'); ?></h5>
  </div>
  <div class="editorial-card-banner fixed blue">
    <div class="social-sharing">
      <span class="social-sharing-caption small">Follow us </span>
      <a class="social-sharing-icon white small" href="https://twitter.com/audubonsociety"><i class="icon-twitter"></i></a>
      <a class="social-sharing-icon white small" href="https://www.facebook.com/NationalAudubonSociety"><i class="icon-facebook"></i></a>
      <a class="social-sharing-icon white small" href="http://www.youtube.com/user/NationalAudubon"><i class="icon-youtube"></i></a>
      <a class="social-sharing-icon white small" href="http://pinterest.com"><i class="icon-pinterest"></i></a>
    </div>
  </div>
</div>
