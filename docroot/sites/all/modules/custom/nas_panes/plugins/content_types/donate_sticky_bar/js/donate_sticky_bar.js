(function ($) {

  Drupal.donate_sticky_bar = Drupal.donate_sticky_bar || {};
  Drupal.donate_sticky_bar.setPennies = function () {
    var input = $('input#inputValue').val();
    input = input.replace(/[\\$,]/g, '');
    $('input#setValue').val(input * 100);
    return true;
  };

})(jQuery);
