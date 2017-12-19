/**
 * @file
 * NAS CT Custom JS.
 */

(function ($, Drupal) {

  Drupal.behaviors.nas_conservation_tracker = {
    attach: function (context, settings) {
      // Highlight states which have sites.
      var polygons = [],
        states = {};
      for (var i = 0 in settings.nas_conservation_tracker.json_data.actions.sites) {
        var stateID = settings.nas_conservation_tracker.json_data.actions.sites[i].state;
        if (Number.isInteger(states[stateID])) {
          states[stateID]++;
        }
        else {
          states[stateID] = 0;
        }
      }
      for (var j = 0 in settings.nas_conservation_tracker_states_data) {
        if (typeof settings.nas_conservation_tracker_states_data[j].properties.shortname == 'string' &&
          states[settings.nas_conservation_tracker_states_data[j].properties.shortname] > 0) {
          polygons.push(settings.nas_conservation_tracker_states_data[j]);
        }
      }
      L.geoJson({type: 'FeatureCollection', features: polygons}, {style: getStateStyle}).addTo(settings.leaflet['0'].lMap);

      // Display sites (dots).

      // Helper functions.
      function getStateStyle(feature) {
        var d = states[feature.properties.shortname],
        color = d > 10 ? '#FEB24C' :
          d > 5 ? '#FED976' : '#FFEDA0';
        return {
          fillColor: color,
          weight: 2,
          opacity: 1,
          color: 'black',
          fillOpacity: 1
        }
      }
    }
  };

})(jQuery, window.Drupal);