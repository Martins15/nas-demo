<?php

/**
 * @file
 * Template for Native Plants search.
 */
?>
<?php print $content['top']; ?>
<section class="global-content with-padding static-page-content">
  <div class="row">
    <div class="text-container columns">
      <?php print $content['main_top']; ?>
    </div>
  </div>
  <div class="row">
    <div class="columns">
      <?php print $content['search_form']; ?>
    </div>
  </div>
  <div class="row try-these-first"">
    <div class="columns">
      <?php print $content['main_middle']; ?>
    </div>
  </div>
  <?php print $content['main']; ?>
</section>
<div class="native-plants-bottom">
  <?php print $content['bottom']; ?>
</div>
