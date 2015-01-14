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
 * Custom variables:
 * - $figcaption: concatenation of file's caption & credit.
 * - $width: is one of: half, default, full.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>
  </div>
</div>
<div class="slideshow clearfix">
  <div class="row slideshow-title">
    <div class="column">
      <h3><?php print $title; ?></h3>
    </div>
  </div>
  <div class="slideshow-indicator row">
    <div class="column large-offset-9 large-3">
      <p><i class="ss-icon icon-chevron-left inactive slideshow-control prev"></i> <span class="indicator-current">1</span> of <span class="indicator-total"><?php print $count; ?></span> <i class="ss-icon icon-chevron-right slideshow-control next"></i></p>
    </div>
  </div>
  <a href="#" class="slideshow-button slideshow-control prev hide-for-tiny hide-for-small"></a>
  <a href="#" class="slideshow-button slideshow-control next hide-for-tiny hide-for-small"></a>
  <div class="slideshow-wrapper">
    <div class="slideshow-scroller">
    <?php foreach ($slides as $slide): ?>
      <div class="slide">
        <div class="slide-img">
          <?php print $slide['image']; ?>
        </div>
        <div class="row">
          <div class="large-9 columns">
            <div class="slide-caption"><?php print $slide['caption']; ?></div>
          </div>
        </div>
      </div>
    <?php endforeach; ?>
    </div>
  </div>
</div>
<div class="article-body row">
  <div class="article-text large-10 columns reflow-body">
