<?php
/**
 * @file
 * Featured Frontpage template file.
 *
 * Available variables:
 * - $conversation_link: Rendered conversation link from article.
 * - $article_title: the (sanitized) article title.
 * - $article_raw_link: raw article link.
 * - $image_path: path to the hero image of the bird.
 * - $contextual_links: rendered contextual links.
 */
?>
  <div class="columns large-8 medium-6">
    <div class="editorial-card contextual-links-region skip-nas-equalization" data-equalizer-watch>
      <?php print $contextual_links; ?>
      <div class="editorial-card-photo">
        <a href="<?php print $article_raw_link ?>"><img src="<?php print $image_path; ?>" alt=""></a>
      </div>
      <div class="editorial-card-content minimal">
        <h3 class="editorial-card-title"><a href="<?php print $article_raw_link ?>"><?php print $article_title ?></a></h3>
        <?php if ($subtitle): ?>
          <p><?php print $subtitle; ?></p>
        <?php endif; ?>
      </div>
    </div>
  </div>
