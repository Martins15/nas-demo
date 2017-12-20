/**
 * @file
 * NAS CT Custom JS.
 */

(function ($, Drupal) {

  Drupal.nas_conservation_tracker_init = function () {
    //console.log(Drupal.settings.nas_conservation_tracker.json_data);
      var lMap = Drupal.settings.leaflet['0'].lMap,
        markerClass = 'ct-leaflet-site',
        loc = getLocation(),
        polygons = [],
        states = {};

      // Delete existing sites from map.
      lMap.eachLayer(function(layer) {
        console.log(layer);
        if (layer._leaflet_id !== 'earth' && !layer._layers) {
          lMap.removeLayer(layer);

        }

      });
      // Highlight states which have sites.
      for (var i = 0 in Drupal.settings.nas_conservation_tracker.json_data[loc].sites) {
        var stateID = Drupal.settings.nas_conservation_tracker.json_data[loc].sites[i].state;
        if (Number.isInteger(states[stateID])) {
          states[stateID]++;
        }
        else {
          states[stateID] = 1;
        }
        // Display sites (dots).
        var dot = L.divIcon({className: markerClass}),
          latLon = [
            parseFloat(Drupal.settings.nas_conservation_tracker.json_data[loc].sites[i].latitude),
            parseFloat(Drupal.settings.nas_conservation_tracker.json_data[loc].sites[i].longitude),
          ];
        L.marker(latLon, {icon: dot}).bindTooltip(Drupal.settings.nas_conservation_tracker.json_data[loc].sites[i].name).addTo(lMap);
      }
      showMarkers();
      //console.log(states);
      for (var j = 0 in Drupal.settings.nas_conservation_tracker_states_data) {
        if (typeof Drupal.settings.nas_conservation_tracker_states_data[j].properties.shortname == 'string' &&
          states[Drupal.settings.nas_conservation_tracker_states_data[j].properties.shortname] > 0) {
          polygons.push(Drupal.settings.nas_conservation_tracker_states_data[j]);
        }
      }
      //console.log(polygons);
      L.geoJson({type: 'FeatureCollection', features: polygons}, {style: getStateStyle}).addTo(lMap);

      // Show/hide markers depending on zoom.
      lMap.on('zoomend', function() {
        showMarkers();
      });

      // Helper functions.
      function getStateStyle(feature) {
        var d = states[feature.properties.shortname],
        color = d > 4 ? '#FEB24C' :
          d > 1 ? '#FED976' : '#FFEDA0';
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
      function getLocation() {
        var loc = window.location.href;
        return loc.split("/").slice(-1)[0];
      }
  };

})(jQuery, window.Drupal);