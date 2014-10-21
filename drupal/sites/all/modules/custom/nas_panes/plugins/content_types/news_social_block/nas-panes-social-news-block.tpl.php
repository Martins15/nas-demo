<?php
/**
 * @file
 * News social block template file.
 *
 * Available variables:
 * - $page_link: url node.
 * - $caption: static text.
 * - $title: title node.
 */
?>
<div class="social-sharing">
  <span class="social-sharing-caption small"><?php print $caption; ?></span>
  <a class="social-sharing-icon blue" target="_blank" href="http://twitter.com/share?url=/&amp;text=<?php print $page_link; ?>"><i class="icon-twitter"></i></a>
  <a class="social-sharing-icon blue" target="_blank" href="http://www.facebook.com/sharer/sharer.php?u=<?php print $page_link; ?>"><i class="icon-facebook"></i></a>
  <a class="social-sharing-icon blue" href="mailto:?subject=<?php print $title; ?>&body=<?php print $page_link; ?>"><i class="icon-mail"></i></a>
</div>
