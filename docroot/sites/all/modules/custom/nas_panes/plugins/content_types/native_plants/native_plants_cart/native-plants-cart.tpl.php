<?php

/**
 * @file
 * Template for the Native Plants cart.
 */
?>
<div class="native-plants-bottom-plant-list-placeholder"> </div>
<div class="native-plants-bottom-plant-list<?php print !empty($context_links) ? ' contextual-links-region' : ''; ?>"
     data-ng-controller="NativePlantsCartController as cartC"
     data-ng-show="cartC.cartShow()">
  <?php print $context_links; ?>
  <div class="row">
    <div class="column tiny-5 medium-3 large-3 native-plants-bottom-plant-list-info">
      <h2 class="thin native-plants-bottom--label"><?php print $title; ?></h2>
      <span class="native-plants-bottom--selected-count">
        <span class="plants-counter"
              data-ng-bind-html="cartC.plantsCounter()"></span>
        <span class="clear-plants-list"> |
          <a href="javascript:void(0)" class="native-plants-bottom--clear-plants-list"
             data-ng-click="cartC.storage.clearCart()"><?php print t('Clear list'); ?></a>
        </span>
      </span>
    </div>
    <div class="column medium-5 large-5 hide-for-tiny hide-for-small native-plants-bottom-plant-list-items"
         data-ng-bind-html="cartC.plantsList()"></div>
    <div class="column medium-4 large-4 native-plants-get-list-form">
      <?php print $form; ?>
    </div>
    <div class="column tiny-7 medium-4 large-4 native-plants-bottom--button-container">
      <button type="submit" class="tomato large native-plants-botton--get-list">
        <span class="hide-for-tiny hide-for-small hide-for-medium"><?php print $button_desktop; ?></span>
        <span class="hide-for-large hide-for-xlarge"><?php print $button_mobile; ?></span>
      </button>
    </div>
  </div>
</div>
