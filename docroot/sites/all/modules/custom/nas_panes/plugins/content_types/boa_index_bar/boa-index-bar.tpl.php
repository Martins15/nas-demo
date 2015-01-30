<?php
/**
 * @file
 * Template to custom pane flyway_in_the_news.
 *
 * Available variables:
 *  $contextual_links - contextual links.
 *  $title - pane's title.
 *  $teasers - array of rendered news.
 */
?>

<div class="guide-bar clearfix">
  <div class="row">
    <div class="column">
      <a href="<?php print url('birds-of-america'); ?>">
        <h2 class="guide-bar-title">
          <span class="hide-for-small hide-for-tiny"></span><?php print t("John J. Audubon’s Birds of America"); ?>
        </h2>
      </a>
      <div class="hide-for-small hide-for-tiny boa-guide-bar-attribution">
        <ul>
        <?php foreach ($links as $link): ?>
          <li><?php print $link; ?></li>
        <?php endforeach; ?>
        </ul>
      </div>
    </div>
  </div>
</div>
<div class="row">
  <div class="john-audubon-logo">
    <img src="<?php print base_path() . drupal_get_path('theme', 'nas'); ?>/img/john_audubon.png">
  </div>
</div>
