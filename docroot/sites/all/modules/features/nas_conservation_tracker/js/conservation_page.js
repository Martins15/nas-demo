(function ($) {


  var colors = {
        'water': '#54b5af',
        'coasts': '#007db6',
        'working lands': '#8a6540'
      },
      flywayColors = {
        'pacific': '#cfccc4',
        'central': '#f5da9d',
        'mississippi': '#ccda9b',
        'atlantic': '#b9dde8'
      };

  Drupal.behaviors.animateBlock = {
    attach: function (context, settings) {
      $('body').once('curtainFix', function () {
        setTimeout(function () {
          if (Drupal.curtain) {
            Drupal.curtain.reset();
            Drupal.curtain.setup();
          }
        }, 500);
      });

      var wrapBlock = $('.show-hide-text', context);

      if (wrapBlock.length) {
        wrapBlock.each(function () {
          var $bannerBlock = $('.banner-text', this),
              $bannerHeight = $('.banner-text', this).outerHeight(true),
              $titleHeight = $('.banner-title', this).outerHeight(true),
              heightAnimate = '-' + ($bannerHeight - $titleHeight - 25) + 'px';
          $bannerBlock.css('bottom', heightAnimate);

          var isTouchDevice = is_touch_device(),
              showEvent = isTouchDevice ? 'touchstart' : 'mouseenter',
              hideEvent = isTouchDevice ? 'touchstart' : 'mouseleave';

          $(this).on(showEvent, function () {
            $bannerBlock.css('bottom', 0);
          });
          $(this).on(hideEvent, function () {
            $bannerBlock.css('bottom', heightAnimate);
          });

          function is_touch_device() {
            return 'ontouchstart' in window || navigator.maxTouchPoints;
          };

        })
      }
    }
  };


  Drupal.behaviors.nasCtForm = {
    attach: function (context) {

      var $linkFilter = $('.nas-ct-refine-listing', context);
      var $formFilter = $('#nas-conservation-tracker-landscapes-map-form', context);
      var $blockFilter = $('.filter-block form', context);
      var wrapForm = '';
      var textLink = $linkFilter.text();
      $linkFilter.appendTo('body', context);

      if ($formFilter.length) {
        wrapForm = $formFilter;
      }
      if ($blockFilter.length) {
        $blockFilter.append($('.filter-block > div', context));
        wrapForm = $blockFilter;
      }

      $('<div class="title-form hide-for-large hide-for-xlarge"><p>' + textLink + '</p><span class="js-exit"></span></div>').prependTo(wrapForm);
      $linkFilter.click(function (e) {
        e.preventDefault();
        wrapForm.toggleClass('js-open-mobile');
        $('body').toggleClass('js-overflow');
      });
      $('.js-exit').click(function () {
        wrapForm.removeClass('js-open-mobile');
        $('body').removeClass('js-overflow');
      })
    }
  };

  Drupal.nasCtInitLandscapesMap = function (data) {

    var lMap = Drupal.settings.leaflet['0'].lMap;

    lMap.scrollWheelZoom.disable();

    if (!lMap.initiated) {
      lMap.initiated = true;

      $(window).resize(function() {
        Drupal.settings.desktopZoom = Drupal.settings.desktopZoom || lMap.getZoom();
        if ($( window ).width() < 768) {
          lMap.setZoom(2);
        }
        else {
          lMap.setZoom(Drupal.settings.desktopZoom);
        }
      });

      var flywayPolygons = [];
      for (var flyway in Drupal.settings.nasCtUnitData) {

        var unit = {'type': 'flyway'};
        // name, coordinates, flyway, unit, type
        var flywayItem = new LPolygon(
          flyway,
          Drupal.settings.nasCtUnitData[flyway].coordinates,
          flyway,
          unit,
          ''
        );

        flywayPolygons.push(flywayItem);
      }

      var polygons = L.geoJson({
        type: 'FeatureCollection',
        features: flywayPolygons
      }, {style: getPolygonStyle, onEachFeature: getPolygonEvents});
      polygons.addTo(lMap);



    }

    // Delete existing sites from map.
    lMap.eachLayer(function (layer) {
      if (layer._leaflet_id !== 'earth' && !layer._layers && !isFlyway(layer)) {
        lMap.removeLayer(layer);
      }
    });

    function isFlyway(layer) {
      if (layer.feature && layer.feature.properties && layer.feature.properties.unit.type == 'flyway') {
        return true;
      }
      return false;
    }

    //var polygons = [];
    for (var i = 0; i < data.length; i++) {

      // Display locations (dots).
      var location = data[i],
          name = location.name.toLowerCase();
      if (!Drupal.settings.nasCtLandscapesData) {
        console.log('No landscapes data loaded');
        return;
      }

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


      if (!location.latitude || location.latitude == '' || !location.longitude || location.longitude == '') {
        continue;
      }

      location.latLon = [
        parseFloat(location.latitude),
        parseFloat(location.longitude),
      ];

      var dot = L.divIcon({iconSize: [12, 12], className: 'ct-leaflet-site'});

      var marker = L.marker(location.latLon, {icon: dot, zIndexOffset: 200});
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
          features: Object.keys(polygons).map(function (e) {
            return polygons[e];
          })
        }, {style: getPolygonStyle, onEachFeature: getPolygonEvents});

        polygons.addTo(lMap);

      });
      marker.on('mouseout', function (e) {
        lMap.eachLayer(function (layer) {

          if (layer.feature && layer.feature.properties && layer.feature.properties.machineName == getMachineName(e.target.options.location.name)) {
            lMap.removeLayer(layer);
            return;
          }
        });
      });


      marker.bindPopup(text, {
        minWidth: minWidth
      }).addTo(lMap);
    }


    function getPolygonEvents(feature, layer) {
      // Placeholder.
    }

    function getPolygonStyle(feature) {

      if (feature.properties.unit.type && feature.properties.unit.type == 'flyway') {
        var style = {fillOpacity: 0.2, opacity: 0.1};

        var color = flywayColors[feature.properties.name.toLowerCase()];
        style.fillColor = color;
        style.color = color;

      }
      else {
        var style = {fillOpacity: 1};

        var color = colors[feature.properties.unit.strategy.name.toLowerCase()];
        style.fillColor = color;
        style.color = color;
      }

      return style;
    }

    // Constructors.
    function LPolygon(name, coordinates, flyway, unit, type) {
      if (!type) {
        type = 'Polygon';
      }
      this.type = 'Feature';
      this.properties = {
        machineName: getMachineName(name),
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



  }

  Drupal.nasConservationTracker = Drupal.nasConservationTracker || {};
  Drupal.nasConservationTracker.updateLandscapesFilters = function (filters) {
    if (!Drupal.settings.nasConservationTracker.landscapes) {
      return;
    }

    Drupal.settings.nasConservationTracker.mapFilters = filters;

    var allLandscapes = Drupal.settings.nasConservationTracker.landscapes;
    var selectedLandscapes = [];
    for (var i = 0; i < allLandscapes.length; i++) {
      if (allLandscapes[i].strategy.name.toLowerCase() == filters.strategy || filters.strategy == 'all') {
        if (filters.status.indexOf(allLandscapes[i].status.toLowerCase()) >= 0 || filters.status == 'all' ) {
          var hasAllFlyways = true;
          for (var j = 0; j < allLandscapes[i].flyway.length; j++) {
            if (filters.flyways.indexOf(allLandscapes[i].flyway[j].name.toLowerCase()) == -1) {
              hasAllFlyways = false;
            }
          }
          if (hasAllFlyways || filters.flyways == 'all' ) {
            selectedLandscapes.push(allLandscapes[i]);
          }
        }


      }
    }

    Drupal.nasCtInitLandscapesMap(selectedLandscapes);
  }

})(jQuery);