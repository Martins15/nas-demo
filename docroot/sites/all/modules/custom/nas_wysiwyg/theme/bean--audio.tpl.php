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
 * - $alignment: is one of: left, center, right.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>
<?php

/**
 * Don't use div inside bean block markup. For some reason WYSIWYG may remove last div.
 */
?>

<figure class="article-audio-container">
  <?php print render($content['field_wysiwyg_image']); ?>
  <?php if (!empty($figcaption)): ?>
      <figcaption class="caption">
        <?php print $figcaption; ?>
      </figcaption>
  <?php endif; ?>
</figure>
