<?php
/**
 * @file
 * Site template with big header.
 */
?>
<?php print $content['top']; ?>
<header class="global-header <?php
  $color = &drupal_static('nas_header_class');
  print $color;
?>">
  <?php print $content['header']; ?>
</header>
<?php print $content['main']; ?>
<?php print $content['footer']; ?>
