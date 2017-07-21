<?php

/**
 * @file
 * Article Full width template of Article layout.
 */
?>

<!-- Full width layout begin -->
<!-- Region: top -->
<?php print $content['top']; ?>
<!-- /Region: top -->

<section class="global-content">
  <article class="article article-full-width-layout">
    <div class="article-body">
      <!-- Region: Main body content-->
      <?php print $content['primary_content']; ?>
      <!-- /Region: Main body content-->
    </div>
  </article>
</section>

<!-- Region: Secondary content-->
<?php print $content['secondary_content']; ?>
<!-- /Region: Secondary content-->

<div class="clearfix"></div>
<!-- Full width layout end -->
