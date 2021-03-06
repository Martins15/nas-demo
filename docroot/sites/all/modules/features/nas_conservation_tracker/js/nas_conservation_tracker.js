/**
 * @file
 * NAS CT Custom JS.
 */

(function ($, Drupal) {

  var colors = {
    response: ['#74c476', '#41ab5d', '#238b45', '#006d2c', '#00441b'],
    actions: ['#6baed6', '#4292c6', '#2171b5', '#08519c', '#08306b'],
    threats: ['#f768a1', '#dd3497', '#ae017e', '#7a0177', '#49006a']
  };

  Drupal.nasCtInitMap = function () {

    var lMap = Drupal.settings.leaflet['0'].lMap,
      styleActive = {
        weight: 2,
        opacity: 0.3,
        fillOpacity: 0.3,
      },
      styleSelected = {
        weight: 2,
        opacity: 0.9,
        fillOpacity: 0.3,
      },
      classes = {
        site: 'ct-leaflet-site',
        visibleArea: 'ct-visible-area',
        charts: 'help-wrap-items-map-items',
      },
      loc = getLocation(),
      json = Drupal.settings.nasConservationTracker.jsonData[loc],
      $radios = $('input[name="map_type"]'),
      $reset = $('#edit-map-reset'),
      $container = $('#charts');

    $container.removeAttr('class').addClass('wrap-map-diagram').addClass(loc + '-charts');

    // Delete existing sites from map.
    lMap.eachLayer(function (layer) {
      if (layer._leaflet_id !== 'earth' && !layer._layers) {
        lMap.removeLayer(layer);
      }
    });

    if (!angular.isDefined(json) || !angular.isDefined(json.sites) || json.sites.length == 0) {
      $('.leaflet-container').after('<div class="no-data-overlay">' + Drupal.t('Data collection pending') + '</div>');
    }

    if (angular.isDefined(json) && angular.isDefined(json.sites)) {
      Drupal.settings.nasConservationTracker.currentMap = {};
      Drupal.settings.nasConservationTracker.currentMap.flyway = {};
      Drupal.settings.nasConservationTracker.currentMap.state = {};
      Drupal.settings.nasConservationTracker.currentMap.county = {};

      if (json.sites.length > 0) {
        $('.no-data-overlay').remove();

        for (var i = 0 in json.sites) {
          // Display sites (dots).
          var site = json.sites[i];
          if (site.latitude == '' || site.longitude == '') {
            continue;
          }
          site.latLon = [
            parseFloat(site.latitude),
            parseFloat(site.longitude),
          ];
          var dot = L.icon({
            iconUrl: Drupal.settings.nasConservationTracker.iconUrl,
            iconSize: new L.Point(6, 6),
            className: classes.site
          });
          var marker = L.marker(site.latLon, {icon: dot});
          var text = site.name;
          var categories = [];
          for (var j = 0 in site[loc]) {
            for (var l = 0 in site[loc][j].categories) {
              if (categories.indexOf(site[loc][j].categories[l].name) < 0) {
                text += ("<br/><small>" + site[loc][j].categories[l].name + "</small>");
                categories.push(site[loc][j].categories[l].name);
              }
            }
          }
          marker.properties = {
            marker: true,
            flyway: site.flyway.toLowerCase(),
            state: site.state.toLowerCase(),
            site: site,
          };
          marker.properties.county = site.county ? site.county.toLowerCase() : detectCounty(site, marker);
          marker.bindTooltip(text).addTo(lMap);

          Drupal.settings.nasConservationTracker.currentMap.flyway[marker.properties.flyway] = Drupal.settings.nasConservationTracker.currentMap.flyway[marker.properties.flyway] || [];
          Drupal.settings.nasConservationTracker.currentMap.state[marker.properties.state] = Drupal.settings.nasConservationTracker.currentMap.state[marker.properties.state] || [];
          Drupal.settings.nasConservationTracker.currentMap.county[marker.properties.county] = Drupal.settings.nasConservationTracker.currentMap.county[marker.properties.county] || [];

          Drupal.settings.nasConservationTracker.currentMap.flyway[marker.properties.flyway].push(site);
          Drupal.settings.nasConservationTracker.currentMap.state[marker.properties.state].push(site);
          Drupal.settings.nasConservationTracker.currentMap.county[marker.properties.county].push(site);

        }
      }
    }

    // Set correct scaling options.
    $radios.each(function () {
      // Get scaling optons from json. Fallback to global settings if not
      // defined.
      var scale = Drupal.settings.nasConservationTracker.jsonData.settings[loc].scale ?
        Drupal.settings.nasConservationTracker.jsonData.settings[loc].scale : Drupal.settings.nasConservationTracker.scale[loc];
      if (scale) {
        if (scale.indexOf($(this).val()) < 0) {
          $(this).parent().hide();
        }
        else {
          if ($(this).val() == scale[0]) {
            $(this).prop('checked', true).change();
          }
          $(this).parent().show();
        }
      }
    });

    // Show/hide markers depending on zoom.
    showMarkers();

    resetMap();

    // Create visible area.
    $('#' + Drupal.settings.leaflet[0].mapId).parent().prepend('<div class="' + classes.visibleArea + '"></div>');
    var $visibleArea = $('.' + classes.visibleArea);
    rebuildVisibleArea($visibleArea, classes);
    lMap.scrollWheelZoom.disable();
    if (!lMap.initiated) {
      // Event linsteners.
      lMap.on('moveend', function () {
        //console.log('CENTER', lMap.getCenter());
        rebuildChartsByZoom($visibleArea);
      });

      lMap.on('zoomend', function () {
        showMarkers();
        rebuildChartsByZoom($visibleArea);
      });

      lMap.on('click', function () {
        if (lMap.scrollWheelZoom.enabled()) {
          lMap.scrollWheelZoom.disable();
        }
        else {
          lMap.scrollWheelZoom.enable();
        }
      });


      $radios.change(function () {
        resetMap();
        scaleMapTo($(this).val());
      });

      $(window).resize(function () {
        rebuildVisibleArea($visibleArea, classes);
      });

      $reset.click(function (e) {
        e.preventDefault();
        resetMap();
      });

      lMap.initiated = true;
    }

    lMap.invalidateSize();
    
    // Helper functions.

    function detectCounty(site, marker) {
      for (var county in Drupal.settings.nasCtUnitData[marker.properties.flyway]['states'][marker.properties.state]['counties']) {
        if (isInsidePolygon(site.latLon[0], site.latLon[1], Drupal.settings.nasCtUnitData[marker.properties.flyway]['states'][marker.properties.state]['counties'][county].coordinates)) {
          return county;
        }
      }
    }

    function rebuildChartsBySelection() {
      resetSelection();
      lMap.eachLayer(function (unitLayer) {
        if (isUnit(unitLayer) && unitLayer.feature.properties.selected) {
          Drupal.settings.nasConservationTracker.selectedUnits++;
          lMap.eachLayer(function (siteLayer) {
            var machineName = unitLayer.feature.properties.machineName;
            if (unitLayer.feature.properties.unit == 'state') {
              machineName = unitLayer.feature.properties.state;
            }
            if (isSite(siteLayer) && (siteLayer.properties[unitLayer.feature.properties.unit] == machineName)) {
              Drupal.settings.nasConservationTracker.visibleSites.push(siteLayer.properties.site);
            }
          });
        }
      });
      Drupal.nasCtInitCharts();
    }

    function rebuildChartsByZoom(area) {
      // This should work only if no manually selected units present.
      if (!Drupal.settings.nasConservationTracker.selectedUnits) {
        Drupal.settings.nasConservationTracker.visibleSites = [];
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
              Drupal.settings.nasConservationTracker.visibleSites.push(layer.properties.site);
            }
          }
        });
        Drupal.nasCtInitCharts();
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
      var style = {};
      //Object.assign(style, styleActive);
      style = $.extend({}, styleActive);

      var k = 0;
      for (var i in Drupal.settings.nasConservationTracker.currentMap.range) {
        if (Drupal.settings.nasConservationTracker.currentMap.rows[feature.properties.machineName] >= Drupal.settings.nasConservationTracker.currentMap.range[i]) {
          k = i;
        }
      }

      var color = colors[getLocation()][k];
      style.fillColor = color;
      style.color = color;
      return style;
    }

    function resetMap() {
      var loc = getLocation();
      if (Drupal.settings.nasConservationTracker.scale[loc]) {
        var latlng = L.latLng(
          Drupal.settings.nasConservationTracker.jsonData.settings[loc].map.latitude,
          Drupal.settings.nasConservationTracker.jsonData.settings[loc].map.longitude
        );
        lMap.setView(latlng, Drupal.settings.nasConservationTracker.jsonData.settings[loc].map.zoom);
        resetSelection();

        var scale = Drupal.settings.nasConservationTracker.jsonData.settings[loc].scale ?
          Drupal.settings.nasConservationTracker.jsonData.settings[loc].scale : Drupal.settings.nasConservationTracker.scale[loc];

        scaleMapTo(scale[0]);
        Drupal.nasCtInitCharts();
      }
    }

    function resetSelection() {
      Drupal.settings.nasConservationTracker.visibleSites = [];
      Drupal.settings.nasConservationTracker.selectedUnits = 0;
    }

    function isUnit(layer) {
      return (layer.feature);
      //return (layer.feature && layer.feature.constructor == LPolygon);
    }

    function isSite(layer) {
      return (layer.properties && layer.properties.marker);
    }

    function showMarkers() {
      var markersZoom = 7;
      if (Drupal.settings.nasConservationTracker.jsonData.settings[loc] && Drupal.settings.nasConservationTracker.jsonData.settings[loc].map.markersZoom) {
        markersZoom = Drupal.settings.nasConservationTracker.jsonData.settings[loc].map.markersZoom;
      }

      var visibility = lMap.getZoom() >= markersZoom ? 'visible' : 'hidden';
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
      $radios.each(function () {
        if ($(this).val() == unit) {
          $(this).prop('checked', true);
        }
      });
      var polygons = {};

      lMap.eachLayer(function (layer) {
        if (isUnit(layer)) {
          // Remove present polygons.
          lMap.removeLayer(layer);
        }
        if (isSite(layer)) {
          switch (unit) {
            case 'county':
              var county = Drupal.settings.nasCtUnitData
                [layer.properties.flyway]['states'][layer.properties.state]['counties'][layer.properties.county];
              if (typeof county == 'undefined') {
                console.log('COUNTY NOT DEFINED', layer);
              }
              if (county) {
                polygons[layer.properties.county] = new LPolygon(
                  county.CNTY_NAME,
                  county.coordinates,
                  layer.properties.state,
                  layer.properties.flyway,
                  unit
                );
              }
              break;
            case 'state':
              var state = Drupal.settings.nasCtUnitData[layer.properties.flyway]['states'][layer.properties.state];
              var stateData = Object.keys(state['counties']).map(function (e) {
                return state['counties'][e];
              });

              polygons[layer.properties.state] = new LPolygon(
                state.name,
                state.geometry.coordinates,
                layer.properties.state,
                stateData[0].FLY_NAME,
                unit,
                state.geometry.type
              );
              break;
            case 'flyway':
              var flyway = Drupal.settings.nasCtUnitData[layer.properties.flyway];
              // var flyData = Object.keys(flyway.states).map(function(e) {
              //   return flyway.states[e];
              // });

              polygons[layer.properties.flyway] = new LPolygon(
                layer.properties.flyway,
                flyway.coordinates,
                '',
                flyway.name,
                unit
              );
              break;
          }
        }
      });

      var polygonsVals = Object.keys(polygons).map(function (e) {
        return polygons[e];
      });

      if (polygonsVals.length > 0) {
        Drupal.settings.nasConservationTracker.currentMap.rows = {};
        var min, max;

        for (var i in polygons) {
          if (unit == 'state') {
            var rows = getChartData(Drupal.settings.nasConservationTracker.currentMap[unit][polygons[i].properties.state]);
          }
          else {
            var rows = getChartData(Drupal.settings.nasConservationTracker.currentMap[unit][polygons[i].properties.machineName]);
          }

          var z = 0;
          for (var j in rows) {
            rows[j].shift();
            for (var m in rows[j]) {
              var w = parseFloat(rows[j][m]);
              if (!isNaN(w)) {
                z += w;
              }
            }
          }
          if (min == null) {
            min = z;
          }
          if (max == null) {
            max = z;
          }
          if (z < min) {
            min = z;
          }
          if (z > max) {
            max = z;
          }

          Drupal.settings.nasConservationTracker.currentMap.rows[polygons[i].properties.machineName] = z;
          Drupal.settings.nasConservationTracker.currentMap.min = min;
          Drupal.settings.nasConservationTracker.currentMap.max = max;
        }

        var step = (max - min) / 5;
        var range = [];
        range[0] = min;
        for (var i = 1; i < 5; i++) {
          range[i] = range[i - 1] + step;
        }
        range[4] = max;
        Drupal.settings.nasConservationTracker.currentMap.range = range;

        L.Control.Legend = L.Control.extend({
          options: {
            position: 'bottomleft',
            legend: '1'
          },
          update: function () {
            var div = L.DomUtil.get('map-legend');
            div.innerHTML = this.getContent();
          },
          onAdd: function (map) {
            // Add reference to map
            map.legendControl = this;
            var div = L.DomUtil.create('div', 'info legend');
            div.id = 'map-legend';
            div.innerHTML = this.getContent();
            return div;
          },
          onRemove: function (map) {
            // Remove reference from map
            delete map.legendControl;
          },
          getContent: function () {
            var content = '',
              min = Drupal.settings.nasConservationTracker.currentMap.min,
              max = Drupal.settings.nasConservationTracker.currentMap.max;
            var loc = getLocation();
            // If only one element is displayed
            if (min == max) {
              content = '';
            }
            else {
              if (!Number.isInteger(min)) {
                min = Number(min).toFixed(2);
              }
              if (!Number.isInteger(max)) {
                max = Number(max).toFixed(2);
              }
              content = '<div class="legend-color" style="background: linear-gradient(to bottom, '
                + colors[loc][4] + ' 0%,' + colors[loc][0] + ' 100%);"><div class="legend-max">'
                + max + '</div><div class="legend-min">' + min + '</div></div>';
            }

            return content;
          }
        });
        if (lMap.legendControl) {
          lMap.legendControl.update();
        }
        else {
          var legend = new L.Control.Legend();
          legend.addTo(lMap);
        }


        var polygons = L.geoJson({
          type: 'FeatureCollection',
          features: polygonsVals
        }, {style: getPolygonStyle, onEachFeature: getPolygonEvents});
        polygons.addTo(lMap);
      }
    }

    // Constructors.
    function LPolygon(name, coordinates, state, flyway, unit, type) {
      if (!type) {
        type = 'Polygon';
      }
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
        type: type,
        coordinates: coordinates,
      };
    }
  }

  Drupal.nasCtInitCharts = function () {
    // Charts. TODO make it look good
    var loc = getLocation();
    var json = Drupal.settings.nasConservationTracker.jsonData[loc] ? Drupal.settings.nasConservationTracker.jsonData[loc] : {sites: []};
    var objectivesRows = [];
    var objectivesTips = [];
    var overall = 0, overallCount = 0;
    var sites = (Drupal.settings.nasConservationTracker.visibleSites.length > 0) ?
      Drupal.settings.nasConservationTracker.visibleSites :
      json.sites;
    var tabSettings = Drupal.settings.nasConservationTracker.jsonData.settings[loc];

    if (!sites) {
      sites = [];
    }

    var objectives = tabSettings.objectives;
    for (var j = 0 in objectives) {
      if ($.isNumeric(objectives[j].value)) {
        objectivesRows.push([objectives[j].description, objectives[j].value]);
        overall += parseFloat(objectives[j].value);
        overallCount++;
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

    // Update tooltips.
    var tooltipMain = tabSettings.tooltip ?
      tabSettings.tooltip : Drupal.settings.nasConservationTracker.tooltipsDefault[loc];
    var tooltipObjectives = tabSettings.objectives.tooltip ?
      tabSettings.objectives.tooltip : Drupal.settings.nasConservationTracker.tooltipsDefault[loc + '_objectives'];
    $('#tooltip-text').html(tooltipMain);
    $('#tooltip-objectives-text').html(tooltipObjectives);

    // Charts.
    var objectives = Drupal.d3.ct_circular('d3-objectives', {rows: []});
    objectives.update({rows: objectivesRows, tooltips: objectivesTips});
    if (objectivesRows.length > 0) {
      var objectWrap = $('.objectives-wrap');

      // Check if array and if empty hide block.
      if ($.isArray(objectivesRows) && objectivesRows[0][0].length === 0) {
        objectWrap.hide();
      }
      else {
        objectWrap.show();
      }


    }
    else {
      $('.objectives-wrap').hide();
    }

    if (overall > 0 && overallCount > 0) {
      overall = Math.round(overall / overallCount);
      updateOverall(overall);

      function updateOverall(overall) {
        $overallWrapper = $('.progress-item');
        if (0 && overall > 40) {
          $overallWrapper.find('p').css('width', overall + '%').attr('data-value', overall).data('value', overall);
        }
        else {
          $overallWrapper.find('p').css('width', '40%').attr('data-value', overall).data('value', overall);
        }

        $overallWrapper.find('progress').val(overall);
      }

      $('.progress-wrap').show();
    }
    else {
      $('.progress-wrap').hide();
    }

    var mainRows = getChartData(sites);

    if (mainRows.length > 0 || Object.keys(mainRows).length) {
      var $diagram = $('.diagram-wrap');
      var chartTitle = tabSettings.chart.title ? tabSettings.chart.title : tabSettings.chart.value_type;
      $diagram.find('.map-title .map-span-title').text(chartTitle);
      $diagram.show();

      if (tabSettings.chart.chart_type == 'linegraph') {
        var mainChart = Drupal.d3.ct_linegraph('d3-actions', {rows: []});
      }
      else {
        var mainChart = Drupal.d3.ct_bar('d3-actions', {rows: []});
      }

      var legend = false;
      if (tabSettings.chart.legend && Array.isArray(tabSettings.chart.legend)) {
        legend = tabSettings.chart.legend;
      }
      else if (tabSettings.chart.legend === true) {
        legend = Drupal.settings.nasConservationTracker.legend
      }

      Drupal.settings.nasConservationTracker.legend = Drupal.settings.nasConservationTracker.legend || [];
      mainChart.update({
        rows: mainRows,
        width: 512,
        height: 306,
        padding: [20, 0, 70, 20],
        barWidth: 9,
        barRx: 4,
        //graphColor: [colors[loc][1]],
        graphColor: tabSettings.chart.colors || colors[loc],
        tooltip: tabSettings.chart.tooltip || false,
        lineY: tabSettings.chart.line_y || false,
        legend: legend
      });
      $('#site-count').text(sites.length);
      if (tabSettings.chart.count_copy) {
        $('#site-count-copy').text(tabSettings.chart.count_copy);
      }
      else {
        $('#site-count-copy').text(Drupal.t('Sites in selected/visible area(s): '));
      }


    }
    else {
      $('.diagram-wrap').hide();
    }
  };

  function getChartData(sites, tabSettings) {

    if (typeof tabSettings == 'undefined') {
      var loc = getLocation();
      tabSettings = Drupal.settings.nasConservationTracker.jsonData.settings[loc];
    }
    Drupal.settings.nasConservationTracker.legend = [];

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
                if (tabSettings.chart.per_site != true) {
                  var site = 'common';
                }
                else {
                  var site = sites[i]['name'];
                }

                mainObjRows[site] = mainObjRows[site] || {};
                if (Array.isArray(data.key)) {
                  for (var z = 0 in data.key) {
                    mainObjRows[site][data.key[z]] = mainObjRows[site][data.key[z]] || 0;
                    if (Drupal.settings.nasConservationTracker.legend.indexOf(data.key[z]) < 0) {
                      Drupal.settings.nasConservationTracker.legend.push(data.key[z]);
                    }
                    switch (agOp) {
                      case 'sum':
                        mainObjRows[site][data.key[z]] += parseFloat(data.value[z]);
                        break;
                      case 'avg':
                        mainObjRows[site][data.key[z]] += parseFloat(data.value[z]);

                        additionalData[site][data.key[z]] = additionalData[site][data.key[z]] || {};
                        additionalData[site][data.key[z]]['count'] = additionalData[site][data.key[z]]['count'] || 0;
                        additionalData[site][data.key[z]]['count']++;
                        break;
                    }
                  }
                }
                else {
                  mainObjRows[site][data.key] = mainObjRows[site][data.key] || 0;
                  if (Drupal.settings.nasConservationTracker.legend.indexOf(data.key) < 0) {
                    Drupal.settings.nasConservationTracker.legend.push(data.key);
                  }
                  switch (agOp) {
                    case 'sum':
                      mainObjRows[site][data.key] += parseFloat(data.value);
                      break;
                    case 'avg':
                      mainObjRows[site][data.key] += parseFloat(data.value);
                      additionalData[site] = additionalData[site] || {};
                      additionalData[site][data.key] = additionalData[site][data.key] || {};
                      additionalData[site][data.key]['count'] = additionalData[site][data.key]['count'] || 0;
                      additionalData[site][data.key]['count']++;
                      break;
                  }

                }
              }
            }
          }
        }
        else if (tabSettings.chart.type == 'actions' || tabSettings.chart.type == 'threats') {

          for (var j = 0 in sites[i][tabSettings.chart.type]) {
            var data = sites[i][tabSettings.chart.type][j];
            var key = data.categories[0].name;
            if (tabSettings.chart.per_site != true) {
              var site = 'common';
            }
            else {
              var site = sites[i]['name'];
            }
            mainObjRows[site] = mainObjRows[site] || {};
            mainObjRows[site][key] = mainObjRows[site][key] || 0;
            switch (agOp) {
              case 'sum':
                mainObjRows[site][key] += 1;
                break;
            }
          }
        }
      }
    }

    if (mainObjRows.common) {
      mainObjRows = mainObjRows.common;
      additionalData = additionalData.common;
      var mainRows = Object.keys(mainObjRows).map(function (key) {

        var value = mainObjRows[key];
        if (agOp == 'avg') {
          value = (mainObjRows[key] / additionalData[key]['count']).toFixed(2);
        }
        return [key, value];
      });
    }
    else {
      mainRows = Object.keys(mainObjRows).map(function(site){
        var values = Object.keys(mainObjRows[site]).map(function(key){
          var value = mainObjRows[site][key];
          if (agOp == 'avg') {
            value = (mainObjRows[site][key] / additionalData[site][key]['count']).toFixed(2);
          }
          return value;

        });
        values.unshift(site);
        return values;
      });
    }

    return mainRows;
  }

  // Common helper functions.
  function getLocation() {
    var currentTab = '';
    if (Drupal.settings.nasConservationTracker.currentTab) {
      currentTab = Drupal.settings.nasConservationTracker.currentTab;
    }
    else {
      var loc = window.location.href;
      currentTab = loc.split("/").slice(-1)[0];
    }
    return currentTab;
  }

  Drupal.behaviors.nasFixedHeader = {
    attach: function (context, settings) {
      var cloneHeader = $('.global-header', context).clone(true),
        $bodyWrap = $('body'),
        ctHeader = $('.ct-scorecard-header', context).clone(),
        bgImage = $('.ct-scorecard-header .hero-image img').attr('src');

      // Clone header and image on top.
      cloneHeader.addClass('clone-header');
      ctHeader.addClass('clone-header');

      $(document).ready(function () {
        // Prepend to body clone html.
        $bodyWrap.prepend(ctHeader);
        $bodyWrap.prepend(cloneHeader);
        // Wrap clone element.
        cloneHeader.add(ctHeader).wrapAll('<div class="curtain" style="background-color: #fff; background-image: url(' + bgImage + ');"></div>');
        // Wrap element for work scroll image.
        $('body > .global-header, .panel-display.panel-1col, .mailing-list, .global-footer', context).wrapAll('<div class="curtain-wrapper"></div>');
      });
    }
  };

  Drupal.behaviors.nasCtMapControlsToggle = {
    attach: function (context, settings) {
      $(".form-item-map-type.form-type-radios").once(function () {
        $(".form-item-map-type.form-type-radios label", context).click(function (e) {
          $(this).next('#edit-map-type').slideToggle('fast');
        });
      });
    }
  };

  Drupal.behaviors.nasCtOwl = {
    attach: function (context, settings) {
      $("#ct-scorecard-owl").owlCarousel({
        'items': 4,
        'paginationSpeed': 100,
        'navigation': true,
        'rewindNav': false,
        'pagination': false,
        'navigationText': ["<i class=\"indicator-left icon-arrow-left\"></i>", "<i class=\"indicator-right icon-arrow-right\"></i>"]
      });
    }
  };

  // Custom breadcrumbs for bird page.
  Drupal.behaviors.birdGroubBreadcrumbs = {
    attach: function (context, settings) {
      var $breadcrumbBlock = $('.ct-scorecard-tabs', context);
      if ($breadcrumbBlock.length) {
        var $ul = $breadcrumbBlock.find('ul.custom-dropdown');
        $breadcrumbBlock.find('.menu-has-children').hover(function () {
          $ul.show();
          $('.active-trail').addClass('hover');
        }, function () {
          $ul.hide();
          $('.active-trail').removeClass('hover');
        });
      }
    }
  };

  Drupal.behaviors.nasCtRatingForm = {
    attach: function (context, settings) {
      var loc = getLocation();
      var $rating = $('.map-items .rating-wrap');
      var $form = $('#nas-conservation-tracker-rating-form', $rating);
      $form.find('input[type="radio"]').change(function(){
        $form.find('textarea, input').fadeIn();
        Drupal.settings.leaflet['0'].lMap.invalidateSize();
      });
      if (settings.nasConservationTracker.jsonData && settings.nasConservationTracker.jsonData[loc]) {
        if (loc !== 'partners' && settings.nasConservationTracker.jsonData[loc].sites.length > 0) {
          $rating.show();
        }
        else {
          $rating.hide();
        }
      }
    }
  };

})(jQuery, window.Drupal);

Number.isInteger = Number.isInteger || function (value) {
  return typeof value === "number" &&
    isFinite(value) &&
    Math.floor(value) === value;
};