<?php
/**
 * @file
 * BOA social block template file.
 *
 * Available variables:
 * - $page_link: url node.
 * - $caption: static text.
 */
?>
<section class="social-sharing bird-guide-section right-col boa-social-sharing small">
  <span class="social-sharing-caption small"><?php print $caption; ?></span>
  <a class="social-sharing-icon blue small" href="http://twitter.com/share?url=/&amp;text=<?php print $page_link; ?>"><i class="icon-twitter"></i></a>
  <a class="social-sharing-icon blue small" href="http://www.facebook.com/sharer/sharer.php?u=<?php print $page_link; ?>"><i class="icon-facebook"></i></a>
  <a class="social-sharing-icon blue small" href="http://pinterest.com/pin/create/button/?url=<?php print $page_link; ?>"><i class="icon-pinterest"></i></a>
  <a class="social-sharing-icon blue small" href="mailto:?subject=<?php print $page_link; ?>"><i class="icon-mail"></i></a>
</section>
