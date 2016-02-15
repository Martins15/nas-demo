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
  <div class="native-plants-bottom-plant-list-placeholder"> </div>
  <div class="native-plants-bottom-plant-list">
    <div class="row">
      <?php print $content['bottom_cart']; ?>
    </div>
  </div>

  <div class="native-plants-bottom-form-title">
    <div class="row">
      <div class="column tiny-12">
        <?php print $content['bottom_form_title']; ?>
      </div>
    </div>
  </div>

  <div class="native-plants-bottom-form">
    <div class="row">
      <div class="column medium-7">
        <?php print $content['bottom_form_description']; ?>
      </div>
      <div class="column medium-5">
        <?php print $content['bottom_form']; ?>
      </div>
    </div>
  </div>

</div>