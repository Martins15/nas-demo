/**
 * @file
 * NAS CT Custom JS.
 */

(function ($, Drupal) {

  var colors = {
    'water': '#54b5af',
    'coasts': '#007db6',
    'working lands': '#8a6540'
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

    //var polygons = [];
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
      var text = '<div class="text-wrap bg-white">' + location.name + '</div>',
          minWidth = 50;
      if (location.imagePreview) {
        text = '<img class="landscape-popup-preview" src="' + location.imagePreview + '" alt="" />' + text;
        minWidth = 300;
      }

      if (location.scorecardUrl) {
        text += '<div class="link-wrap bg-white"><a href="' + location.scorecardUrl + '">' + Drupal.t('See Interactive Report') + '</a></div>';
      }

      marker.options.location = location;
      marker.on('mouseover', function (e) {
        var location = e.target.options.location;
        var name = location.name.toLowerCase();
        var polygons = {};
        polygons[name] = new LPolygon(
            name,
            location.polygon,
            location.flyway,
            location
        );

        var polygons = L.geoJson({
          type: 'FeatureCollection',
          features: Object.values(polygons)
        }, {style: getPolygonStyle, onEachFeature: getPolygonEvents});

        polygons.addTo(lMap);

      });
      marker.on('mouseout', function (e) {
        lMap.eachLayer(function (layer) {

          if (layer.feature && layer.feature.properties && layer.feature.properties.machineName==getMachineName(e.target.options.location.name)) {
            lMap.removeLayer(layer);
            return;
          }
        });
      });


      marker.bindPopup(text, {
        minWidth: minWidth
      }).addTo(lMap);
      // polygons[name] = new LPolygon(
      //     name,
      //     location.polygon,
      //     location.flyway,
      //     location
      // );
    }

    // var polygons = L.geoJson({
    //   type: 'FeatureCollection',
    //   features: Object.values(polygons)
    // }, {style: getPolygonStyle, onEachFeature: getPolygonEvents});

    //polygons.addTo(lMap);

    function getPolygonEvents(feature, layer) {
      // Placeholder.
    }

    function getPolygonStyle(feature) {
      var style = {fillOpacity: 1};

      var color = colors[feature.properties.unit.strategy.name.toLowerCase()];
      style.fillColor = color;
      style.color = color;
      return style;
    }

    // Constructors.
    function LPolygon(name, coordinates, flyway, unit, type) {
      if (!type) {
        type = 'Polygon';
      }
      this.type = 'Feature';
      this.properties = {
        machineName:  getMachineName(name),
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

    function getMachineName(name) {
      return name.toLowerCase().replace(/\s/g, '');
    }


    lMap.scrollWheelZoom.disable();

    if (!lMap.initiated) {
      lMap.initiated = true;
      var $filterElement = $('#nas-conservation-tracker-landscapes-map-form input');
      $filterElement.on('change', updateFilters);
      updateFilters();

      function updateFilters() {
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
      }

      // lMap.on('click', function () {
      //   if (lMap.scrollWheelZoom.enabled()) {
      //     lMap.scrollWheelZoom.disable();
      //   }
      //   else {
      //     lMap.scrollWheelZoom.enable();
      //   }
      // });

    }
  }

  Drupal.behaviors.nasCtAccordion = {
    attach: function (context) {
      // Create accordion for form items.
      $('#nas-conservation-tracker-landscapes-map-form > div > .form-item', context).each(function () {
        var labelBlock = $('> label', this);
        labelBlock.append('<i class="plus"></i>');
        labelBlock.click(function (e) {
          e.preventDefault();
          $(this).toggleClass('js-open');
          $('i', this).toggleClass('js-open');
        })
      });
      $('.form-item-strategies label', context).click().parent().find('input[value="coasts"]').click();
    }
  };

})(jQuery, window.Drupal);