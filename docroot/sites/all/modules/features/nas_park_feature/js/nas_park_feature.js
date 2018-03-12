/**
 * @file
 * NAS Climate Custom JS.
 */

(function ($, Drupal) {
  Drupal.behaviors.nasClimateTurnover = {
    attach: function (context, settings) {
      if (settings.nasClimateFeature.turnoverChart) {
        var chart = new StamenAudubonParks.TurnoverChart({
          element: '#' + settings.nasClimateFeature.elementId,
          dataUrl: settings.nasClimateFeature.dataUrl,
          park: settings.nasClimateFeature.parkTitle,
          onClick: parkOnClick,
          season: 'summer'
        });
      }
    }
  }

  Drupal.behaviors.nasClimateParkMap = {
    attach: function (context, settings) {
      if (settings.nasClimateFeature.parkMap) {
        var parkMap = new StamenAudubonParks.ParkMap({
          element: '#' + settings.nasClimateFeature.elementId,
          dataUrl: settings.nasClimateFeature.dataUrl,
          season: 'summer',
          metric: 'colonization',
          shapeUrl: settings.nasClimateFeature.shapeUrl,
          onClick: parkOnClick
        });
      }
    }
  }

  function parkOnClick(parkName) {
    location = location.origin + '/' + Drupal.settings.nasClimateFeature.parkLinks[parkName];
  }
})(jQuery, window.Drupal);