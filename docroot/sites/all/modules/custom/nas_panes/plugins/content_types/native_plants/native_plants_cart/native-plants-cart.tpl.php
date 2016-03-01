<?php
/**
 * @file
 * Template for the Native Plants cart.
 */
?>
<div class="column medium-3 large-3 tiny-6 native-plants-bottom-plant-list-info">
  <h2 class="thin native-plants-bottom--label"><?php print $title; ?></h2>
  <span class="native-plants-bottom--selected-count">
    <span class="plants-counter"><?php print t('No plants selected'); ?></span>
    <span class="clear-plants-list"> | <a href="#" class="native-plants-bottom--clear-plants-list">Clear list</a></span>
  </span>
</div>
<div class="column medium-6 large-5 hide-for-tiny hide-for-small native-plants-bottom-plant-list-items">
  <?php print t('No plants yet'); ?>
</div>
<div class="column medium-3 large-4 tiny-6 native-plants-bottom--button-container">
  <button type="submit" class="tomato large native-plants-botton--get-list">
    <span class="hide-for-tiny hide-for-small hide-for-medium"><?php print $button_desktop; ?></span>
    <span class="hide-for-large hide-for-xlarge"><?php print $button_mobile; ?></span>
  </button>
</div>