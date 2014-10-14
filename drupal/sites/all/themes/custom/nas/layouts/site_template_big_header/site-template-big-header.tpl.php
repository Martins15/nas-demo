<?php
/**
 * @file
 * Site template with big header.
 */
?>

<header class="global-header transparent  <?php
  $color = &drupal_static('nas_header_class', 'light-bg dark-text');
  print $color;
?>">
  <?php print $content['header']; ?>
</header>
<?php print $content['main']; ?>
<?php print $content['footer']; ?>