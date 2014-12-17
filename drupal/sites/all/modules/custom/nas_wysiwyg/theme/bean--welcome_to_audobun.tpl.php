<?php
/**
 * @file
 * Default theme implementation for beans.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) entity label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-{ENTITY_TYPE}
 *   - {ENTITY_TYPE}-{BUNDLE}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>
<aside class="article-aside reflow reflow-into-body">
  <div class="welcome-card teal" data-equalizer-watch>
    <div class="welcome-card-illustration">
      <?php print ($image);?>
    </div>
    <div class="welcome-card-content">
      <div class="welcome-card-headline">
        Welcome to<br>
        <img class="logo" src="<?php print ($path_to_logo);?>" alt="">
      </div>
      <div class="welcome-card-blurb">
        <?php print ($summary);?>
        <?php print ($link_more);?>
        <hr>
      </div>
      <a href="<?php print ($path_news);?>" class="editorial-card-slug">In the News</a>
      <h5 class="editorial-card-title"><?php print ($link_news);?></h5>
      <a href="<?php print ($path_most_popular);?>" class="editorial-card-slug">Most Popular</a>
      <h5 class="editorial-card-title"><?php print ($link_most_popular);?></h5>
    </div>
    <div class="welcome-card-banner" style="background-color:<?php print ($color);?>">
      <div class="social-sharing">
        <span class="social-sharing-caption small">Follow us </span>
        <a class="social-sharing-icon small" href="<?php print ($social_link_fb);?>"><i class="icon-twitter"></i></a>
        <a class="social-sharing-icon small" href="<?php print ($social_link_tw);?>"><i class="icon-facebook"></i></a>
        <a class="social-sharing-icon small" href="<?php print ($social_link_yotube);?>"><i class="icon-youtube"></i></a>
        <a class="social-sharing-icon small" href="<?php print ($social_link_pi);?>"><i class="icon-pinterest"></i></a>
      </div>
    </div>
  </div>
</aside>