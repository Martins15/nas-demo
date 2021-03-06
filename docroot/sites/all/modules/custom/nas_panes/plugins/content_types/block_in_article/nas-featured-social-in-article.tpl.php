<?php

/**
 * @file
 * Featured Article social block template file.
 *
 * Available variables:
 * - $page_link: url node.
 * - $title: title node.
 */
?>
<section class="clearfix article-sidebar-section social-sharing no-caption hide-for-tiny hide-for-small hide-for-medium">
  <a class="social-sharing-icon" target="_blank" href="<?php print $twitter_url; ?>"><i class="icon-twitter"></i></a>&nbsp;
  <a class="social-sharing-icon" target="_blank" href="http://www.facebook.com/sharer/sharer.php?u=<?php print $page_link; ?>"><i class="icon-facebook"></i></a>&nbsp;
  <a class="social-sharing-icon" href="mailto:?subject=<?php print $title; ?>&body=<?php print $page_link; ?>"><i class="icon-mail"></i></a>
</section>
