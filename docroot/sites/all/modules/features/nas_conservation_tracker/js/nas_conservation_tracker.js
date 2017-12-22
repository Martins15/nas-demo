/**
 * @file
 * NAS CT Custom JS.
 */

(function ($, Drupal) {

  Drupal.nas_conservation_tracker_init_map = function () {
    var lMap = Drupal.settings.leaflet['0'].lMap,
      markerClass = 'ct-leaflet-site',
      loc = getLocation(),
      polygons = [],
      counties = {};

    // Delete existing sites from map.
    lMap.eachLayer(function (layer) {
      //console.log(layer);
      if (layer._leaflet_id !== 'earth' && !layer._layers) {
        lMap.removeLayer(layer);
      }

    });
    // Highlight county which have sites.
    for (var i = 0 in Drupal.settings.nas_conservation_tracker.json_data[loc].sites) {
      // Display sites (dots).
      var dot = L.divIcon({className: markerClass}),
        latLon = [
          parseFloat(Drupal.settings.nas_conservation_tracker.json_data[loc].sites[i].latitude),
          parseFloat(Drupal.settings.nas_conservation_tracker.json_data[loc].sites[i].longitude),
        ];
      L.marker(latLon, {icon: dot}).bindTooltip(Drupal.settings.nas_conservation_tracker.json_data[loc].sites[i].name).addTo(lMap);
      for (var j = 0 in Drupal.settings.nas_conservation_tracker_unit_data.features) {
        if (isInsidePolygon(latLon[0], latLon[1], Drupal.settings.nas_conservation_tracker_unit_data.features[j].geometry.rings[0])) {
          var ctyID = Drupal.settings.nas_conservation_tracker_unit_data.features[j].attributes.FID;
          if (Number.isInteger(counties[ctyID])) {
            counties[ctyID]++;
          }
          else {
            counties[ctyID] = 1;
            var polygon = new LPolygon(
              Drupal.settings.nas_conservation_tracker_unit_data.features[j].attributes.FID,
              Drupal.settings.nas_conservation_tracker_unit_data.features[j].attributes.CNTY_NAME,
              Drupal.settings.nas_conservation_tracker_unit_data.features[j].geometry.rings
            );
            polygons.push(polygon);
          }
          break;
        }
      }
    }
    L.geoJson({type: 'FeatureCollection', features: polygons}, {style: getPolygonStyle}).addTo(lMap);
    showMarkers();

    // Show/hide markers depending on zoom.
    lMap.on('zoomend', function () {
      showMarkers();
    });

    // Helper functions.
    function getPolygonStyle(feature) {
      var d = counties[feature.id],
        color = d > 4 ? '#ff0000' :
          d > 1 ? '#feb24c' : '#FFEDA0';
      return {
        fillColor: color,
        weight: 2,
        opacity: 1,
        color: color,
        fillOpacity: 1
      }
    }

    function showMarkers() {
      var visibility = lMap.getZoom() > 5 ? 'visible' : 'hidden';
      $('.' + markerClass).css('visibility', visibility);
    }

    function isInsidePolygon(x, y, polyPoints) {
      var inside = false;
      for (var i = 0, j = polyPoints.length - 1; i < polyPoints.length; j = i++) {
        // Y is before X in data coming from unit-data.js
        var xi = polyPoints[i][1], yi = polyPoints[i][0];
        var xj = polyPoints[j][1], yj = polyPoints[j][0];
        var intersect = ((yi > y) != (yj > y)) && (x < (xj - xi) * (y - yi) / (yj - yi) + xi);
        if (intersect) inside = !inside;
      }
      return inside;
    }

    function LPolygon(id, name, coordinates) {
      this.type = 'Feature';
      this.id = id;
      this.properties = {
        name: name,
      };
      this.geometry = {
        type: 'Polygon',
        coordinates: coordinates,
      };
    }
    //$('input[type=radio][name=]').change(function() {

    //};
  }

  Drupal.nas_conservation_tracker_init_charts = function () {
      // Charts. TODO make it look good
      var loc = getLocation();
      var objectivesRows = [];
      var sites = Drupal.settings.nas_conservation_tracker.json_data[loc].sites;
      for (var i = 0 in sites) {
        for (var j = 0 in sites[i].data) {
          if (angular.isDefined(sites[i].data[j].value_type) && sites[i].data[j].value_type.name == 'Objective') {
            var data = sites[i].data[j];
            objectivesRows.push([data.value_type.description, data.value]);
          }
        }
      }

      // Charts.
      var objectives = Drupal.d3.ct_circular('d3-objectives', {rows: []});
      objectives.update({rows: objectivesRows});

       // Charts. TODO make it look good
      var mainObjRows = {};
      var agOp = 'sum';
      for (var i = 0 in sites) {
        for (var j = 0 in sites[i].data) {
          if (angular.isDefined(sites[i].data[j].value_type) && sites[i].data[j].value_type.name != 'Objective') {
            var data = sites[i].data[j];
            switch(agOp) {
              case 'sum':
                mainObjRows[data.key] = mainObjRows[data.key] || 0;
                mainObjRows[data.key] += parseFloat(data.value);
                break;
            }
          }
        }
      }
      var mainRows = Object.keys(mainObjRows).map(function (key) { return [key, mainObjRows[key]]; });

      // Charts.
      //var mainChart = Drupal.d3.ct_linegraph('d3-actions', {rows: []});
    var mainChart = Drupal.d3.ct_bar('d3-actions', {rows: []});
      mainChart.update({rows: mainRows,legend: ['Actions']});
  };

  // Common helper functions.
  function getLocation() {
    var loc = window.location.href;
    return loc.split("/").slice(-1)[0];
  }

})(jQuery, window.Drupal);