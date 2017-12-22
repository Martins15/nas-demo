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
      counties = {},
      $radios = $('input[name="map_type"]');
    if (!Drupal.settings.nas_conservation_tracker_unit_data_sorted) {
      Drupal.settings.nas_conservation_tracker_unit_data_sorted = new LUnitSorted(Drupal.settings.nas_conservation_tracker_unit_data.features);
    }
    // Delete existing sites from map.
    lMap.eachLayer(function (layer) {
      if (layer._leaflet_id !== 'earth' && !layer._layers) {
        lMap.removeLayer(layer);
      }
    });
    for (var i = 0 in Drupal.settings.nas_conservation_tracker.json_data[loc].sites) {
      // Display sites (dots).
      var site = Drupal.settings.nas_conservation_tracker.json_data[loc].sites[i];
      var dot = L.divIcon({className: markerClass}),
        latLon = [
          parseFloat(site.latitude),
          parseFloat(site.longitude),
        ];
      var marker = L.marker(latLon, {icon: dot});
      marker.properties = {
        marker: true,
        flyway: site.flyway.toLowerCase(),
        state: site.state.toLowerCase(),
      };
      for (var county in Drupal.settings.nas_conservation_tracker_unit_data_sorted[marker.properties.flyway][marker.properties.state]) {
        if (isInsidePolygon(latLon[0], latLon[1], Drupal.settings.nas_conservation_tracker_unit_data_sorted[marker.properties.flyway][marker.properties.state][county].coordinates)) {
          marker.properties.county = county;
        }
      }
      marker.bindTooltip(site.name).addTo(lMap);
    }
    L.geoJson({type: 'FeatureCollection', features: polygons}, {style: getPolygonStyle}).addTo(lMap);
    // Scale map to selected unit.
    $radios.each(function() {
      if ($(this).prop('checked')) {
        scaleMapTo($(this).val());
      }
    });
    // Show/hide markers depending on zoom.
    showMarkers();

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

    function scaleMapTo(unit) {
      var polygons = {};
      lMap.eachLayer(function (layer) {
        if (layer.feature && layer.feature.constructor == LPolygon) {
          // Remove present polygons.
          lMap.removeLayer(layer);
        }
        if (layer.properties && layer.properties.marker) {
          switch (unit) {
            case 'county':
              var county = Drupal.settings.nas_conservation_tracker_unit_data_sorted
                [layer.properties.flyway][layer.properties.state][layer.properties.county];
              polygons[layer.properties.county] = new LPolygon(
                county.NAMELSAD,
                [county.coordinates],
                layer.properties.state,
                layer.properties.flyway,
                unit,
              );
              break;
            case 'state':
              var state = Drupal.settings.nas_conservation_tracker_unit_data_sorted[layer.properties.flyway][layer.properties.state];
              var stateData = Object.values(state);
              var coordinates = [];
              for (var county in state) {
                // Create a multipolygon from county coordinates.
                coordinates.push(state[county].coordinates);
              }
              polygons[layer.properties.state] = new LPolygon(
                stateData[0].STATE_NAME,
                coordinates,
                layer.properties.state,
                stateData[0].FLY_NAME,
                unit,
              );
              break;
            case 'flyway':
              var flyway = Drupal.settings.nas_conservation_tracker_unit_data_sorted[layer.properties.flyway];
              var flyData = Object.values(flyway);
              var coordinates = [];
              for (var state in flyway) {
                for (var county in flyway[state]) {
                  // Create a multipolygon from county coordinates.
                  coordinates.push(flyway[state][county].coordinates);
                }
              }
              polygons[layer.properties.flyway] = new LPolygon(
                layer.properties.flyway,
                coordinates,
                '',
                layer.properties.flyway,
                unit,
              );
              break;
          }
        }
      });
      if (Object.values(polygons).length > 0) {
        L.geoJson({type: 'FeatureCollection', features: Object.values(polygons)}, {style: getPolygonStyle}).addTo(lMap);
      }
    }

    // Constructors.

    function LUnitSorted(data) {
      this.pacific = {};
      this.central = {};
      this.mississippi = {};
      this.atlantic = {};
      for (var i = 0 in data) {
        var flyway = data[i].attributes.FLY_NAME.toLowerCase();
        var state = data[i].attributes.STATE_ABV.toLowerCase();
        var county = data[i].attributes.CNTY_NAME.toLowerCase().replace(/\s/g,'');
        if (this[flyway]) {
          if (!this[flyway][state]) {
            this[flyway][state] = {};
          }
          this[flyway][state][county] = data[i].attributes;
          this[flyway][state][county].coordinates = data[i].geometry.rings[0];
        }
      }
    }

    function LPolygon(name, coordinates, state, flyway, unit) {
      this.type = 'Feature';
      this.properties = {
        name: name,
        state: state.toLowerCase(),
        flyway: flyway.toLowerCase(),
        unit: unit,
      };
      this.geometry = {
        type: (coordinates[0][0].length > 2 && typeof(coordinates[0][0][0]) === 'object') ? 'MultiPolygon' : 'Polygon',
        coordinates: coordinates,
      };
    }

    // Event linsteners.

    lMap.on('zoomend', function () {
      showMarkers();
    });

    $radios.change(function() {
      scaleMapTo($(this).val());
    });
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