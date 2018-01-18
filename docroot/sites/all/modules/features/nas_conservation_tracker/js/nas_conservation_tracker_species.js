/**
 * @file
 * NAS CT Custom JS.
 */

(function ($, Drupal) {
  // Custom breadcrumbs for bird page.
  Drupal.behaviors.nasCtSpecies = {
    attach: function (context, settings) {
      var $a = $('#reset-filters a');
      if (location.search.length || location.pathname !== settings.nasConservationTracker.speciesPath) {
        $a.show();
      }
      else {
        $a.hide();
      }
      $('#species-aplphabet li a').click(function (e) {
        e.preventDefault();
        //alert($(this).data('letter'));
        //$(this).parent().addClass('active').siblings().removeClass('active');
        $('input[name="letter"]').val($(this).data('letter'));
        $('input#edit-submit-ct-species').click();
      })
    }
  };
})(jQuery, window.Drupal);