<?php

/**
 * @file
 * Template for Full-width Hero block.
 *
 * Available variables:
 * - $node: Node object with all information about node.
 * - $node_url: Node url.
 * - $author_name: Author name.
 * - $author_link: Url of the author's page.
 * - $author_image: Author image path.
 * - $published: Article's publish date.
 */
?>

<!-- Byline block -->
<header class="article-header article-full-width article-full-width-byline row">
  <div class="large-header large-centered columns">
    <div class="article-meta clearfix">
      <?php if ($author_image): ?>
      <a href="<?php print $author_link; ?>">
        <img class="article-author-image" src="<?php print $author_image; ?>" alt="<?php print $author_name; ?>">
      </a>
      <?php endif; ?>
      <a href="<?php print $author_link; ?>"><h5 class="article-author-name">By <?php print $author_name; ?></h5></a>
      <small class="article-date"><?php print $published; ?></small>
      <section class="social-sharing no-caption">
        <a class="social-sharing-icon" target="_blank" href="http://twitter.com/share?text=<?php print $node->title; ?>&via=audubonsociety&url=<?php print $node_url; ?>"><i class="icon-twitter"></i></a>&nbsp;
        <a class="social-sharing-icon" target="_blank" href="http://www.facebook.com/sharer/sharer.php?u=<?php print $node_url; ?>"><i class="icon-facebook"></i></a>&nbsp;
        <a class="social-sharing-icon" href="mailto:?subject=<?php print $node->title; ?>&body=<?php print $node_url; ?>"><i class="icon-mail"></i></a>
      </section>
    </div>
  </div>
</header>
<!-- Byline block -->
