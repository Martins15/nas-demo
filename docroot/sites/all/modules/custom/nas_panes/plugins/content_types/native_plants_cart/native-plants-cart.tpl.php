<?php
/**
 * @file
 * Template for the Native Plants cart.
 */
?>
<div class="native-plants-bottom-plant-list">
  <div class="row">
    <div class="column medium-3 large-3 tiny-6 native-plants-bottom-plant-list-info">
      <h2 class="thin native-plants-bottom--label"><?php print $title; ?></h2>
      <span class="native-plants-bottom--selected-count">12 plants selected</span>
    </div>
    <div class="column medium-6 large-5 hide-for-tiny hide-for-small native-plants-bottom-plant-list-items">
      No plants yet.
    </div>
    <div class="column medium-3 large-4 tiny-6 native-plants-bottom--button-container">
      <button type="submit" class="tomato large native-plants-botton--get-list">
        <span class="hide-for-tiny hide-for-small hide-for-medium"><?php print $button_desktop; ?></span>
        <span class="hide-for-large hide-for-xlarge"><?php print $button_mobile; ?></span>
      </button>
    </div>
  </div>
</div>