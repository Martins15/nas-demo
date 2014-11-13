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
  <div<?php if ($classes_array[$id]): print ' class="' . $classes_array[$id] .'"'; endif; ?>>
    <?php print $row; ?>
  </div>
  <?php endforeach; ?>
  <div class="editorial-card-list-item">
    <h5 class="editorial-card-title no-margin"><?php print l(t('More News »'), 'news'); ?></h5>
  </div>
</div>
<div class="editorial-card-banner fixed blue">
  <div class="social-sharing">
    <span class="social-sharing-caption small">Follow us </span>
    <a class="social-sharing-icon white small" href="http://twitter.com"><i class="icon-twitter"></i></a>
    <a class="social-sharing-icon white small" href="http://facebook.com"><i class="icon-facebook"></i></a>
    <a class="social-sharing-icon white small" href="http://youtube.com"><i class="icon-youtube"></i></a>
    <a class="social-sharing-icon white small" href="http://pinterest.com"><i class="icon-pinterest"></i></a>
  </div>
</div>
