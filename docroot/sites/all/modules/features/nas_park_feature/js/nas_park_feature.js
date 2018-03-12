/**
 * @file
 * NAS Climate Custom JS.
 */

//(function ($, Drupal) {
  var chart = new TurnoverChart({
    element: '#' + Drupal.settings.nasClimateFeature.elementId, // some container to render the chart inside of
    dataUrl: Drupal.settings.nasClimateFeature.dataUrl, //path to the static data file
    park: Drupal.settings.nasClimateFeature.parkTitle, // the name of the park to focus on
    onClick: parkOnClick, // callback on clicking dots in the chart, function will be passed the name of the park and then the client side can open up that page's detail page.
    season: 'summer' // the season to render
  });

  function parlOnClick(parkName) {
    location = Drupal.settings.nasClimateFeature.parkUrl;
  }
//})(jQuery, window.Drupal);