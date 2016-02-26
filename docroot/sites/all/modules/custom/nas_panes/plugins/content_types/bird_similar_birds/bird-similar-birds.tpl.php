<?php
/**
 * @file
 * Template for the similar birds pane.
 */
?>
<div class="bird-card-set bg-bone-white">
  <div class="row section-header space-top">
    <div class="columns">
      <h2 class="thin"><?php print $title; ?></h2>
    </div>
    <div class="columns">
      <ul class="section-nav inline-list">
        <li class="first"><?php print $bird_guide_link; ?></li>
        <li class="last"><?php print $adopt_bird_link; ?></li>
      </ul>
    </div>
  </div>
  <div class="row bird-card-container">
    <div class="owl-carousel">
      <?php foreach ($birds as $bird):
        print $bird;
      endforeach; ?>
    </div>
  </div>
</div>