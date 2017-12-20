/**
 * @file
 * NAS CT Custom JS.
 */

(function ($, Drupal) {

  Drupal.behaviors.nas_conservation_tracker = {
    attach: function (context, settings) {
      // Charts.
      var objectives = Drupal.d3.ct_circular('d3-objectives', {rows: []});
      objectives.update({rows: [['test1', 10], ['test2', 30]]});


      // Highlight states which have sites.
      var lMap = settings.leaflet['0'].lMap,
        markerClass = 'ct-leaflet-site',
        polygons = [],
        states = {};1
      for (var i = 0 in settings.nas_conservation_tracker.json_data.actions.sites) {
        var stateID = settings.nas_conservation_tracker.json_data.actions.sites[i].state;
        if (Number.isInteger(states[stateID])) {
          states[stateID]++;
        }
        else {
          states[stateID] = 0;
        }
        // Display sites (dots).
        var dot = L.divIcon({className: markerClass}),
          latLon = [
            parseFloat(settings.nas_conservation_tracker.json_data.actions.sites[i].latitude),
            parseFloat(settings.nas_conservation_tracker.json_data.actions.sites[i].longitude),
          ];
        L.marker(latLon, {icon: dot}).addTo(lMap);
        showMarkers();
      }
      for (var j = 0 in settings.nas_conservation_tracker_states_data) {
        if (typeof settings.nas_conservation_tracker_states_data[j].properties.shortname == 'string' &&
          states[settings.nas_conservation_tracker_states_data[j].properties.shortname] > 0) {
          polygons.push(settings.nas_conservation_tracker_states_data[j]);
        }
      }
      L.geoJson({type: 'FeatureCollection', features: polygons}, {style: getStateStyle}).addTo(lMap);

      // Show/hide markers depending on zoom.
      lMap.on('zoomend', function() {
        showMarkers();
      });

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
      function showMarkers() {
        var visibility = lMap.getZoom() > 5 ? 'visible' : 'hidden';
        $('.' + markerClass).css('visibility', visibility);
      }




    }
  };

})(jQuery, window.Drupal);