<?php
/**
 * @file
 * Featured Frontpage template file.
 *
 * Available variables:
 * - $conversation_link: Rendered conversation link from article.
 * - $article_title: the (sanitized) article title.
 * - $article_raw_link: raw article link.
 * - $tagline_text: the (sanitized) tagline text.
 * - $image_path: path to the hero image of the bird.
 * - $contextual_links: rendered contextual links.
 */
?>
  <div class="columns large-8 medium-6">
    <div class="editorial-card contextual-links-region" data-equalizer-watch>
      <?php print $contextual_links; ?>
      <div class="editorial-card-photo">
        <img src="<?php print $image_path; ?>" alt="">
      </div>
      <div class="editorial-card-content short">
        <h3 class="editorial-card-title"><a href="<?php print $article_raw_link ?>"><?php print $article_title ?></a></h3>
        <?php if ($subtitle): ?>
          <p><?php print $subtitle; ?></p>
        <?php endif; ?>
        <p><a href="<?php print $article_raw_link ?>" class="editorial-card-link"><?php print $tagline_text ?></a></p>
      </div>
    </div>
  </div>
