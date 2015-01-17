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
<?php if ($width == 'default'): ?>
<figure class="article-image">
  <?php print render($content['field_wysiwyg_image']); ?>
    <?php if (!empty($figcaption)): ?>
    <figcaption>
      <?php print $figcaption; ?>
    </figcaption>
  <?php endif; ?>
</figure>
<?php elseif ($width == 'half-right'): ?>
<aside class="article-aside <?php print $width; ?>-width">
  <figure class="article-image">
    <div class="hide-for-tiny hide-for-small image-container">
      <?php print render($content['field_wysiwyg_image']); ?>
      <?php if (!empty($figcaption)): ?>
      <figcaption class="caption article-aside-caption">
        <?php print $figcaption; ?>
      </figcaption>
      <?php endif; ?>
    </div>
  </figure>
</aside>
<?php elseif ($width == 'one-third-left'): ?>
<div class="<?php print $width; ?>-width medium-4 columns">
  <figure class="article-image">
    <?php print render($content['field_wysiwyg_image']); ?>
    <?php if (!empty($figcaption)): ?>
      <figcaption class="caption article-aside-caption">
        <?php print $figcaption; ?>
      </figcaption>
    <?php endif; ?>
  </figure>
</div>
<?php else: ?>
<aside class="article-aside <?php print $width; ?>-width">
  <figure class="article-image">
    <?php print render($content['field_wysiwyg_image']); ?>
    <?php if (!empty($figcaption)): ?>
    <figcaption class="caption article-aside-caption">
      <?php print $figcaption; ?>
    </figcaption>
    <?php endif; ?>
  </figure>
</aside>
<?php endif; ?>
