/**
 * @file
 * NAS Climate Custom JS.
 */

(function ($, Drupal) {
  Drupal.behaviors.nasClimateTurnover = {
    attach: function (context, settings) {
      var chart = new TurnoverChart({
        element: '#' + settings.nasClimateFeature.elementId, // some container to render the chart inside of
        dataUrl: settings.nasClimateFeature.dataUrl, //path to the static data file
        park: settings.nasClimateFeature.parkTitle, // the name of the park to focus on
        onClick: parkOnClick, // callback on clicking dots in the chart, function will be passed the name of the park and then the client side can open up that page's detail page.
        season: 'summer' // the season to render
      });

      function parkOnClick(parkName) {
        location = settings.nasClimateFeature.parkUrl;
      }
    }
  }
})(jQuery, window.Drupal);