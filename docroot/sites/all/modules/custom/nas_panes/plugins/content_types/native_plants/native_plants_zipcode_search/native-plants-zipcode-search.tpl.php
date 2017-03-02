<?php

/**
 * @file
 * Template for Native Plants zipcode search form.
 */
?>
<div class="row columns js-native-plants-search-button hide-for-medium hide-for-large hide-for-xlarge collapsed">
  <div class="native-plants-search-icon icon-magnifier open js-open"></div>
  <div class="native-plants-search-icon icon-delete close js-close"></div>
</div>
<form class="native-plants-search-form native-plants-search-form-inline js-search-collapsible collapsed"
      data-ng-controller="NativePlantsZipcodeSearchController as zipcodeC">
  <div class="row<?php print !empty($context_links) ? ' contextual-links-region' : ''; ?>">
    <?php print $context_links; ?>
    <div class="columns">
      <h2 class="thin hide-for-tiny hide-for-small"><?php print $title; ?></h2>
      <input type="text" value="" class="form-text native-plants-search-form--zip-code" placeholder="<?php print $zipcode_placeholder; ?>"
             data-native-plants-fields-sync="zipcode"
             data-native-plants-fields-sync-override="0"
             data-ng-model="zipcodeC.storage.stateParams.zipcode"/>
      <button type="submit" class="native-plants-search-form--submit form-submit button tomato large"
              data-ng-click="zipcodeC.storage.setZipcode()">
        <span><?php print $button_text; ?></span>
      </button>
    </div>
  </div>
  <div class="row ng-hide" data-ng-show="zipcodeC.storage.data.status=='error'">
    <div class="messages error">
      <h2 class="element-invisible"><?php print t('Error message'); ?></h2>
      {{zipcodeC.storage.data.error}}</div>
  </div>
</form>
