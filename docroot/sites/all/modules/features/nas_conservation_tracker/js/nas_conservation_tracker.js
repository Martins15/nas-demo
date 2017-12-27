/**
 * @file
 * NAS CT Custom JS.
 */

(function ($, Drupal) {

  Drupal.nas_conservation_tracker_init_map = function () {
    var lMap = Drupal.settings.leaflet['0'].lMap,
      classes = {
        site: 'ct-leaflet-site',
        visible_area: 'ct-visible-area',
        charts: 'help-wrap-items-map-items',
      },
      loc = getLocation(),
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
      var dot = L.divIcon({iconSize: [6, 6], className: classes.site}),
        latLon = [
          parseFloat(site.latitude),
          parseFloat(site.longitude),
        ];
      var marker = L.marker(latLon, {icon: dot});
      marker.properties = {
        marker: true,
        flyway: site.flyway.toLowerCase(),
        state: site.state.toLowerCase(),
        site: site,
      };
      for (var county in Drupal.settings.nas_conservation_tracker_unit_data_sorted[marker.properties.flyway][marker.properties.state]) {
        if (isInsidePolygon(latLon[0], latLon[1], Drupal.settings.nas_conservation_tracker_unit_data_sorted[marker.properties.flyway][marker.properties.state][county].coordinates)) {
          marker.properties.county = county;
        }
      }
      marker.bindTooltip(site.name).addTo(lMap);
    }
    // Scale map to selected unit.
    $radios.each(function() {
      if ($(this).prop('checked')) {
        scaleMapTo($(this).val());
      }
    });
    // Show/hide markers depending on zoom.
    showMarkers();

    // Create visible area.
    $('#' + Drupal.settings.leaflet[0].mapId).parent().prepend('<div class="' + classes.visible_area + '"></div>');
    var $visibleArea = $('.' + classes.visible_area);
    rebuildVisibleArea($visibleArea, classes);

    // Event linsteners.

    lMap.on('moveend', function () {
      rebuildCharts($visibleArea);
    });

    lMap.on('zoomend', function () {
      showMarkers();
      rebuildCharts($visibleArea);
    });

    $radios.change(function() {
      scaleMapTo($(this).val());
    });

    $(window).resize(function() {
      rebuildVisibleArea($visibleArea, classes);
    });

    // Helper functions.

    function rebuildCharts(area) {
      Drupal.settings.nas_conservation_tracker.visible_sites = [];
      var w = parseInt(area.width().toFixed());
      var h = parseInt(area.height().toFixed());
      lMap.eachLayer(function (layer) {
        if (layer.properties && layer.properties.marker) {
          var iconOffset = $(layer._icon).offset();
          var x = parseInt(iconOffset.left.toFixed());
          var y = parseInt(iconOffset.top.toFixed()) - parseInt(area.offset().top.toFixed());
          if (
            y >= 0 &&
            x >= 0 &&
            x <= w &&
            y <= h) {
            Drupal.settings.nas_conservation_tracker.visible_sites.push(layer.properties.site);
          }
        }
      });
      console.log(Drupal.settings.nas_conservation_tracker.visible_sites);
      Drupal.nas_conservation_tracker_init_charts();
    }

    function rebuildVisibleArea(area, classes) {
      area.css({
        'width': $('.' + classes.charts).offset().left.toFixed(0) + 'px',
        'height': $('#' + Drupal.settings.leaflet[0].mapId).height() + 'px',
      });
    }
    
    function getPolygonStyle(feature) {
      var i = 0;
      lMap.eachLayer(function (layer) {
        if (layer.properties && layer.properties.marker) {
          latLon = layer.getLatLng();
          for (var j = 0 in feature.geometry.coordinates) {
            if (isInsidePolygon(latLon.lat, latLon.lng, feature.geometry.coordinates[j])) {
              i++;
            }
          }
        }
      });
      var color = i > 6 ? '#ff0000' :
        i > 1 ? '#feb24c' : '#FFEDA0';
      return {
        fillColor: color,
        weight: 2,
        opacity: 0.3,
        color: color,
        fillOpacity: 0.3,
      }
    }

    function showMarkers() {
      var visibility = lMap.getZoom() > 5 ? 'visible' : 'hidden';
      $('.' + classes.site).css('visibility', visibility);
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
        type: 'Polygon',
        coordinates: coordinates,
      };
    }
  }

  Drupal.nas_conservation_tracker_init_charts = function () {
      // Charts. TODO make it look good
      var loc = getLocation();
      var objectivesRows = [];
      var overall = 0;
      var sites = (Drupal.settings.nas_conservation_tracker.visible_sites) ?
        Drupal.settings.nas_conservation_tracker.visible_sites :
        Drupal.settings.nas_conservation_tracker.json_data[loc].sites;
      for (var i = 0 in sites) {
        for (var j = 0 in sites[i].data) {
          if (angular.isDefined(sites[i].data[j].value_type) && sites[i].data[j].value_type.name == 'Objective') {
            var data = sites[i].data[j];
            objectivesRows.push([data.value_type.description, data.value]);
            overall += parseFloat(data.value);
          }
        }
      }

      // Charts.
      var objectives = Drupal.d3.ct_circular('d3-objectives', {rows: []});
      objectives.update({rows: objectivesRows});

      overall = Math.round(overall/objectivesRows.length);
      updateOverall(overall);
      function updateOverall(overall) {
        $overallWrapper = $('.progress-item');
        if (overall > 40) {
          $overallWrapper.find('p').css('width', overall + '%').attr('data-value', overall);
        }
        else {
          $overallWrapper.find('p').css('width', '40%').attr('data-value', overall);
        }

        $overallWrapper.find('progress').val(overall);
      }



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
    mainChart.update({rows: mainRows,width: 512, height: 306, barWidth: 9, barRx: 4, barColor: ['#ef5a3e']});
    $('#site-count').text(sites.length);
  };

  // Common helper functions.
  function getLocation() {
    var loc = window.location.href;
    return loc.split("/").slice(-1)[0];
  }

})(jQuery, window.Drupal);