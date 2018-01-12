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
    }
  };
})(jQuery, window.Drupal);