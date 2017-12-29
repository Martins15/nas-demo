/**
 * @file
 * NAS CT Custom JS.
 */

(function ($, Drupal) {

  Drupal.nas_conservation_tracker_init_map = function () {

    var lMap = Drupal.settings.leaflet['0'].lMap,
        styleActive = {
          weight: 2,
          opacity: 0.2,
          fillOpacity: 0.2,
        },
        styleSelected = {
          weight: 2,
          opacity: 0.5,
          fillOpacity: 0.5,
        },
        classes = {
          site: 'ct-leaflet-site',
          visible_area: 'ct-visible-area',
          charts: 'help-wrap-items-map-items',
        },
        loc = getLocation(),
        json = Drupal.settings.nas_conservation_tracker.json_data[loc],
        $radios = $('input[name="map_type"]'),
        $reset = $('#edit-map-reset');
    if (!Drupal.settings.nas_conservation_tracker_unit_data_sorted) {
      Drupal.settings.nas_conservation_tracker_unit_data_sorted = new LUnitSorted(Drupal.settings.nas_conservation_tracker_unit_data.features);
    }
    // Delete existing sites from map.
    lMap.eachLayer(function (layer) {
      if (layer._leaflet_id !== 'earth' && !layer._layers) {
        lMap.removeLayer(layer);
      }
    });
    if (angular.isDefined(json)) {

      if (json.sites.length == 0) {
        $('.leaflet-container').after('<div class="no-data-overlay">No data to display</div>');
      }
      else {
        $('.no-data-overlay').remove();
        for (var i = 0 in json.sites) {
          // Display sites (dots).
          var site = json.sites[i];
          var dot = L.divIcon({iconSize: [6, 6], className: classes.site}),
              latLon = [
                parseFloat(site.latitude),
                parseFloat(site.longitude),
              ];
          var marker = L.marker(latLon, {icon: dot});
          var text = site.name;
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
        }
      }


      for (var i = 0 in json.sites) {
        // Display sites (dots).
        var site = json.sites[i];
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
      if (angular.isDefined(site)) {
        for (var j = 0 in site.actions) {
          for (var l = 0 in site.actions[j].categories) {
            text += ("<br/><small>" + site.actions[j].categories[l].name + "</small>");
          }
        }
        marker.bindTooltip(text).addTo(lMap);
      }
    }

    // Scale map to selected unit.
    scaleMapTo(getScaling());

    // Show/hide markers depending on zoom.
    showMarkers();

    // Create visible area.
    $('#' + Drupal.settings.leaflet[0].mapId).parent().prepend('<div class="' + classes.visible_area + '"></div>');
    var $visibleArea = $('.' + classes.visible_area);
    rebuildVisibleArea($visibleArea, classes);

    // Event linsteners.

    lMap.on('moveend', function () {
      rebuildChartsByZoom($visibleArea);
    });

    lMap.on('zoomend', function () {
      showMarkers();
      rebuildChartsByZoom($visibleArea);
    });

    lMap.scrollWheelZoom.disable();
    lMap.on('click', function () {
      if (lMap.scrollWheelZoom.enabled()) {
        lMap.scrollWheelZoom.disable();
      }
      else {
        lMap.scrollWheelZoom.enable();
      }
    });

    $radios.change(function () {
      scaleMapTo($(this).val());
    });

    $(window).resize(function () {
      rebuildVisibleArea($visibleArea, classes);
    });

    $reset.click(function (e) {
      e.preventDefault();
      var latlng = L.latLng(
        Drupal.settings.nas_conservation_tracker.json_data.settings.map.latitude,
        Drupal.settings.nas_conservation_tracker.json_data.settings.map.longitude
      );
      lMap.setView(latlng, Drupal.settings.nas_conservation_tracker.json_data.settings.map.zoom);
      resetSelection();
      scaleMapTo(Drupal.settings.nas_conservation_tracker.scale);
      Drupal.nas_conservation_tracker_init_charts();
    });

    // Helper functions.

    function rebuildChartsBySelection() {
      resetSelection();
      lMap.eachLayer(function (unitLayer) {
        if (isUnit(unitLayer) && unitLayer.feature.properties.selected) {
          Drupal.settings.nas_conservation_tracker.selected_units++;
          lMap.eachLayer(function (siteLayer) {
            if (isSite(siteLayer) && siteLayer.properties[unitLayer.feature.properties.unit] == unitLayer.feature.properties.machineName) {
              Drupal.settings.nas_conservation_tracker.visible_sites.push(siteLayer.properties.site);
            }
          });
        }
      });
      Drupal.nas_conservation_tracker_init_charts();
    }

    function rebuildChartsByZoom(area) {
      // This should work only if no manually selected units present.
      if (!Drupal.settings.nas_conservation_tracker.selected_units) {
        Drupal.settings.nas_conservation_tracker.visible_sites = [];
        var w = parseInt(area.width().toFixed());
        var h = parseInt(area.height().toFixed());
        lMap.eachLayer(function (layer) {
          if (isSite(layer)) {
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
        Drupal.nas_conservation_tracker_init_charts();
      }
    }

    function rebuildVisibleArea(area, classes) {
      area.css({
        'width': $('.' + classes.charts).offset().left.toFixed(0) + 'px',
        'height': $('#' + Drupal.settings.leaflet[0].mapId).height() + 'px',
      });
    }

    function getPolygonEvents(feature, layer) {
      layer.on('click', function (event) {
        layer.feature.properties.selected = !layer.feature.properties.selected;
        if (layer.feature.properties.selected) {
          layer.setStyle(styleSelected);
        }
        else {
          layer.setStyle(styleActive);
        }
        rebuildChartsBySelection();
      });
    }

    function getPolygonStyle(feature) {
      var i = 0;
      var style = styleActive;
      lMap.eachLayer(function (layer) {
        if (isSite(layer)) {
          latLon = layer.getLatLng();
          if (isInsidePolygon(latLon.lat, latLon.lng, feature.geometry.coordinates)) {
            i++;
          }
        }
      });
      var color = i > 6 ? '#ff0000' :
          i > 1 ? '#feb24c' : '#FFEDA0';
      style.fillColor = color;
      style.color = color;
      return style;
    }

    function getScaling() {
      var scaling = 'county';
      $radios.each(function () {
        if ($(this).prop('checked')) {
          scaling = $(this).val();
        }
      });
      return scaling;
    }

    function resetSelection() {
      Drupal.settings.nas_conservation_tracker.visible_sites = [];
      Drupal.settings.nas_conservation_tracker.selected_units = 0;
    }

    function isUnit(layer) {
      return (layer.feature && layer.feature.constructor == LPolygon);
    }

    function isSite(layer) {
      return (layer.properties && layer.properties.marker);
    }

    function showMarkers() {
      var visibility = lMap.getZoom() > 6 ? 'visible' : 'hidden';
      $('.' + classes.site).css('visibility', visibility);
    }

    function isInsidePolygon(x, y, polyPoints) {
      var inside = false;
      for (var subPoints in polyPoints) {
        for (var i = 0, j = polyPoints[subPoints].length - 1; i < polyPoints[subPoints].length; j = i++) {
          // Y is before X in data coming from unit-data.js
          var xi = polyPoints[subPoints][i][1],
              yi = polyPoints[subPoints][i][0];
          var xj = polyPoints[subPoints][j][1],
              yj = polyPoints[subPoints][j][0];
          var intersect = ((yi > y) != (yj > y)) && (x < (xj - xi) * (y - yi) / (yj - yi) + xi);
          if (intersect) {
            inside = !inside;
          }
        }
      }
      return inside;
    }

    function scaleMapTo(unit) {
      var polygons = {};
      lMap.eachLayer(function (layer) {
        if (isUnit(layer)) {
          // Remove present polygons.
          lMap.removeLayer(layer);
        }
        if (isSite(layer)) {
          switch (unit) {
            case 'county':
              var county = Drupal.settings.nas_conservation_tracker_unit_data_sorted
                  [layer.properties.flyway][layer.properties.state][layer.properties.county];
              polygons[layer.properties.county] = new LPolygon(
                  county.CNTY_NAME,
                  county.coordinates,
                  layer.properties.state,
                  layer.properties.flyway,
                  unit
              );
              break;
            case 'state':
              var state = Drupal.settings.nas_conservation_tracker_unit_data_sorted[layer.properties.flyway][layer.properties.state];
              var stateData = Object.values(state);
              var coordinates = [];
              for (var county in state) {
                // Create a multipolygon from county coordinates.
                for (var i = 0 in state[county].coordinates) {
                  coordinates.push(state[county].coordinates[i]);
                }
              }
              polygons[layer.properties.state] = new LPolygon(
                  stateData[0].STATE_ABV,
                  coordinates,
                  layer.properties.state,
                  stateData[0].FLY_NAME,
                  unit
              );
              break;
            case 'flyway':
              var flyway = Drupal.settings.nas_conservation_tracker_unit_data_sorted[layer.properties.flyway];
              var flyData = Object.values(flyway);
              var coordinates = [];
              for (var state in flyway) {
                for (var county in flyway[state]) {
                  // Create a multipolygon from county coordinates.
                  for (var i = 0 in flyway[state][county].coordinates) {
                    coordinates.push(flyway[state][county].coordinates[i]);
                  }
                }
              }
              polygons[layer.properties.flyway] = new LPolygon(
                  layer.properties.flyway,
                  coordinates,
                  '',
                  layer.properties.flyway,
                  unit
              );
              break;
          }
        }
      });
      if (Object.values(polygons).length > 0) {
        var polygons = L.geoJson({
          type: 'FeatureCollection',
          features: Object.values(polygons)
        }, {style: getPolygonStyle, onEachFeature: getPolygonEvents});
        polygons.addTo(lMap);
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
        var county = data[i].attributes.CNTY_NAME.toLowerCase().replace(/\s/g, '');
        if (this[flyway]) {
          if (!this[flyway][state]) {
            this[flyway][state] = {};
          }
          this[flyway][state][county] = data[i].attributes;
          this[flyway][state][county].coordinates = data[i].geometry.rings;
        }
      }
    }

    function LPolygon(name, coordinates, state, flyway, unit) {
      this.type = 'Feature';
      this.properties = {
        machineName: name.toLowerCase().replace(/\s/g, ''),
        name: name,
        state: state.toLowerCase(),
        flyway: flyway.toLowerCase(),
        unit: unit,
        selected: false,
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
    var json = Drupal.settings.nas_conservation_tracker.json_data[loc];
    var objectivesRows = [];
    var objectivesTips = [];
    var overall = 0;
    var sites = (Drupal.settings.nas_conservation_tracker.visible_sites.length > 0) ?
        Drupal.settings.nas_conservation_tracker.visible_sites :
        json.sites;
    var tabSettings = Drupal.settings.nas_conservation_tracker.json_data.settings[loc];

    var objectives = tabSettings.objectives;
    for (var j = 0 in objectives) {
      if ($.isNumeric(objectives[j].value)) {
        objectivesRows.push([objectives[j].description, objectives[j].value]);
        overall += parseFloat(objectives[j].value);
      }
      else {
        objectivesRows.push([objectives[j].description, -1]);
      }
      var tooltip = '';
      if (angular.isDefined(objectives[j].tooltip)) {
        tooltip = objectives[j].tooltip;
      }
      objectivesTips.push(tooltip);
    }


    // Charts.
    var objectives = Drupal.d3.ct_circular('d3-objectives', {rows: []});
    objectives.update({rows: objectivesRows, tooltips: objectivesTips});
    if (objectivesRows.length > 0) {
      $('.objectives-wrap').show();
      overall = Math.round(overall / objectivesRows.length);
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
    }
    else {
      $('.objectives-wrap').hide();
    }

    if (overall > 0) {
      $('.progress-wrap').show();
    }
    else {
      $('.progress-wrap').hide();
    }


    // Charts. TODO make it look good
    var mainObjRows = {};
    var additionalData = {};
    if (typeof tabSettings.chart != 'undefined') {
      var agOp = tabSettings.chart.operation;

      for (var i = 0 in sites) {
        if (tabSettings.chart.type == 'data') {
          for (var j = 0 in sites[i].data) {
            if (angular.isDefined(sites[i].data[j].value_type) && sites[i].data[j].value_type.name == tabSettings.chart.value_type) {
              if (angular.isDefined(sites[i].data[j].key_type) && sites[i].data[j].key_type.name == tabSettings.chart.key_type) {
                var data = sites[i].data[j];
                mainObjRows[data.key] = mainObjRows[data.key] || 0;
                switch (agOp) {
                  case 'sum':
                    mainObjRows[data.key] += parseFloat(data.value);
                    break;
                  case 'avg':
                    mainObjRows[data.key] += parseFloat(data.value);

                    additionalData[data.key] = additionalData[data.key] || {};
                    additionalData[data.key]['count'] = additionalData[data.key]['count'] || 0;
                    additionalData[data.key]['count']++;
                    break;
                }

              }
            }
          }
        }
        else if (tabSettings.chart.type == 'actions') {
          for (var j = 0 in sites[i].actions) {
            var data = sites[i].actions[j];
            var key = data.categories[0].name;
            mainObjRows[key] = mainObjRows[key] || 0;
            switch (agOp) {
              case 'sum':
                mainObjRows[key] += 1;
                break;
            }
          }
        }


      }
    }

    var mainRows = Object.keys(mainObjRows).map(function (key) {
      var value = mainObjRows[key];
      if (agOp == 'avg') {
        value = (mainObjRows[key] / additionalData[key]['count']).toFixed(2);
      }
      return [key, value];
    });

    if (mainRows.length > 0) {
      var $diagram = $('.diagram-wrap');
      $diagram.find('.map-title').text(tabSettings.chart.value_type);
      $diagram.show();

      if (tabSettings.chart.chart_type == 'linegraph') {
        var mainChart = Drupal.d3.ct_linegraph('d3-actions', {rows: []});
      }
      else {
        var mainChart = Drupal.d3.ct_bar('d3-actions', {rows: []});
      }

      mainChart.update({
        rows: mainRows,
        width: 512,
        height: 306,
        barWidth: 9,
        barRx: 4,
        barColor: ['#ef5a3e'],
      });
      $('#site-count').text(sites.length);

    }
    else {
      $('.diagram-wrap').hide();
    }
  };

  // Common helper functions.
  function getLocation() {
    var loc = window.location.href;
    return loc.split("/").slice(-1)[0];
  }

  Drupal.behaviors.scrollToNext = {
    attach: function (context, settings) {
      $(".curtain-arrow.storecard").once(function () {
        $(".curtain-arrow.storecard").click(function (e) {
          e.preventDefault();
          $('html, body').animate({
            scrollTop: $(".ct-scorecard-tabs").offset().top
          }, 1000);
        });
      });
    }
  };

  Drupal.behaviors.mapControlsToggle = {
    attach: function (context, settings) {
      $(".form-item-map-type.form-type-radios").once(function () {
        $(".form-item-map-type.form-type-radios label", context).click(function (e) {
          $(this).next('#edit-map-type').slideToggle('fast');
        });
      });
    }
  };

})(jQuery, window.Drupal);