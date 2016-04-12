(function($) {
  Drupal.behaviors.native_plants_email_form = {};
  Drupal.behaviors.native_plants_email_form.attach = function (context, settings) {
    // Copy ZIP code value from the search form.
    // We don't use context here cause it doesn't allow us to attach to the refreshed exposed form.
    $('.native-plants-search-form--zip-code').once('native-plants-email-form', function() {
      if ($(this).val()) {
        $('.native-plants-bottom-form-right--zipcode').val($(this).val());
      }
    }).change(function() {
      $('.native-plants-bottom-form-right--zipcode').val($(this).val());
    });
  };
})(jQuery);
