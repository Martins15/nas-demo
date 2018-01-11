/**
 * @file
 * NAS CT Custom JS.
 */

(function ($, Drupal) {

  Drupal.behaviors.nasCtInitLandscapes = {
    attach: function (context, settings) {
      $.ajax({
        url: url,
        data: data,
        success: success,
        dataType: dataType
      });
      Drupal.nasCtInitLandscapesMap();
    }
  };

  Drupal.nasCtInitLandscapesMap = function () {

    var lMap = Drupal.settings.leaflet['0'].lMap;
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