/**
 * @file
 * NAS CT Custom JS.
 */

(function ($, Drupal) {

  var colors = {
    'water': '#0073c4',
    'coasts': '#d6a53e',
    'working lands': '#006e0f'
  };

  Drupal.behaviors.nasCtInitLandscapes = {
    attach: function (context, settings) {
      console.log('START!');
      $.get(
          '/conservation-tracker/ajax/landscapes',
          function (data) {
            console.log('DATA', data);
            Drupal.nasCtInitLandscapesMap(data.data);
          }
      );
    }
  };

  Drupal.nasCtInitLandscapesMap = function (data) {

    var lMap = Drupal.settings.leaflet['0'].lMap;

    // Delete existing sites from map.
    lMap.eachLayer(function (layer) {
      if (layer._leaflet_id !== 'earth' && !layer._layers) {
        lMap.removeLayer(layer);
      }
    });

    var polygons = [];
    for (var i = 0; i < data.length; i++) {

      // Display locations (dots).
      var location = data[i],
          name = location.name.toLowerCase();

      if (!Drupal.settings.nasCtLandscapesData[name]) {

        continue;
      }
      var geoData = Drupal.settings.nasCtLandscapesData[name].geoData;

      for (var j = 0; j < geoData.length; j++) {
        if (geoData[j].type == 'point') {
          location.latitude = geoData[j].data[1];
          location.longitude = geoData[j].data[0];
        }
        else if (geoData[j].type == 'polygon') {
          location.polygon = geoData[j].data;
        }
      }


      if (location.latitude == '' || location.longitude == '') {
        continue;
      }
      location.latLon = [
        parseFloat(location.latitude),
        parseFloat(location.longitude),
      ];

      var dot = L.divIcon({iconSize: [12, 12], className: 'ct-leaflet-site'});
      var marker = L.marker(location.latLon, {icon: dot});
      var text = location.name;

      marker.bindTooltip(text).addTo(lMap);
      console.log('COORDINATES', location.polygon);
      polygons[name] = new LPolygon(
          name,
          location.polygon,
          location.flyway,
          location
      );


    }
    console.log('POLYGONS', polygons);

    var polygons = L.geoJson({
      type: 'FeatureCollection',
      features: Object.values(polygons)
    }, {style: getPolygonStyle, onEachFeature: getPolygonEvents});
    polygons.addTo(lMap);

    function getPolygonEvents(feature, layer) {
      // layer.on('click', function (event) {
      //   layer.feature.properties.selected = !layer.feature.properties.selected;
      //   if (layer.feature.properties.selected) {
      //     layer.setStyle(styleSelected);
      //   }
      //   else {
      //     layer.setStyle(styleActive);
      //   }
      //   rebuildChartsBySelection();
      // });
    }

    function getPolygonStyle(feature) {
      var style = {};
      // Object.assign(style, styleActive);
      //
      // var k = 0;
      // for (var i in Drupal.settings.nasConservationTracker.currentMap.range) {
      //   if (Drupal.settings.nasConservationTracker.currentMap.rows[feature.properties.machineName] >= Drupal.settings.nasConservationTracker.currentMap.range[i]) {
      //     k = i;
      //   }
      // }

      var color = colors[feature.properties.unit.strategy.name.toLowerCase()];
      style.fillColor = color;
      style.color = color;
      return style;
    }

    // Constructors.
    function LPolygon(name, coordinates, flyway, unit, type = 'Polygon') {
      this.type = 'Feature';
      this.properties = {
        machineName: name.toLowerCase().replace(/\s/g, ''),
        name: name,
        flyway: flyway.toLowerCase(),
        unit: unit,
        selected: false,
      };
      this.geometry = {
        type: type,
        coordinates: coordinates,
      };
    }


    lMap.scrollWheelZoom.disable();
    if (!lMap.initiated) {
      // Event linsteners.
      // lMap.on('moveend', function () {
      //
      // });
      //
      // lMap.on('zoomend', function () {
      //
      // });

      lMap.on('click', function () {
        if (lMap.scrollWheelZoom.enabled()) {
          lMap.scrollWheelZoom.disable();
        }
        else {
          lMap.scrollWheelZoom.enable();
        }
      });
      lMap.initiated = true;
    }
  }

})(jQuery, window.Drupal);