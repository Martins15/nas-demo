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
      $.get(
          '/conservation-tracker/ajax/landscapes',
          function (data) {
            Drupal.settings.nasConservationTracker = Drupal.settings.nasConservationTracker || {};
            Drupal.settings.nasConservationTracker.landscapes = data.data;
            Drupal.nasCtInitLandscapesMap([]);
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
      polygons[name] = new LPolygon(
          name,
          location.polygon,
          location.flyway,
          location
      );
    }

    var polygons = L.geoJson({
      type: 'FeatureCollection',
      features: Object.values(polygons)
    }, {style: getPolygonStyle, onEachFeature: getPolygonEvents});
    polygons.addTo(lMap);

    function getPolygonEvents(feature, layer) {
      // Placeholder.
    }

    function getPolygonStyle(feature) {
      var style = {};

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
        flyway: flyway,
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
      var $filterElement = $('#nas-conservation-tracker-landscapes-map-form input');
      $filterElement.on('change', function () {
        var filters = {'strategy': null, 'status': [], 'flyways': []};
        $filterElement.filter(':checked').each(function (index, el) {
          if ($(el).attr('type') == 'radio') {
            filters.strategy = $(el).val();
          }
          else if ($(el).attr('name').indexOf('status') === 0) {
            filters.status.push($(el).val());
          }
          else if ($(el).attr('name').indexOf('flyways') === 0) {
            filters.flyways.push($(el).val());
          }
        });
        Drupal.settings.nasConservationTracker.mapFilters = filters;

        var allLandscapes = Drupal.settings.nasConservationTracker.landscapes;
        var selectedLandscapes = [];
        for (var i = 0; i < allLandscapes.length; i++) {
          if (allLandscapes[i].strategy.name.toLowerCase() == filters.strategy
              && filters.status.indexOf(allLandscapes[i].status.toLowerCase()) >= 0) {

            var hasAllFlyways = true;
            for (var j = 0; j < allLandscapes[i].flyway.length; j++) {
              if (filters.flyways.indexOf(allLandscapes[i].flyway[j].name.toLowerCase()) == -1) {
                hasAllFlyways = false;
              }
            }
            if (hasAllFlyways) {
              selectedLandscapes.push(allLandscapes[i]);
            }

          }
        }

        Drupal.nasCtInitLandscapesMap(selectedLandscapes);
      });

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