(function($) {
  Drupal.behaviors.native_plants_email_form = {};
  Drupal.behaviors.native_plants_email_form.attach = function (context, settings) {
    // Copy ZIP code value from the search form.
    $('.native-plants-search-form--zip-code', context).once('native-plants-email-form', function() {
      if ($(this).val()) {
        $('.native-plants-bottom-form-right--zipcode', context).val($(this).val());
      }
    }).change(function() {
      $('.native-plants-bottom-form-right--zipcode', context).val($(this).val());
    });
  };
})(jQuery);
