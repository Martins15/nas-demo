<?php
/**
 * @file
 * Site template with big header.
 */
?>

<header class="global-header transparent light-bg dark-text">
  <?php print $content['header']; ?>
</header>
<section class="global-content">
  <?php print $content['main']; ?>
</section>
<?php print $content['footer']; ?>