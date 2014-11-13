(function($) {
  Drupal.behaviors.frontpage_flyway = {
    attach: function(context, settings) {
      var onSuccess = function(location) {
        var locationObject = $.parseJSON(JSON.stringify(location, undefined, 4));
        console.log("Lookup successful:");
        console.log(locationObject);
        var StateIsoCode = locationObject.subdivisions['0'].iso_code;
        if (typeof(StateIsoCode) === 'undefined') {
          StateIsoCode = 'default';
        }
        var ajax = new Drupal.ajax(false, false, {
          url: "ajax/get/fpp/" + StateIsoCode
        });
        ajax.eventResponse(ajax, {});
      };

      var onError = function(error) {
        console.log("Error:\n\n" + JSON.stringify(error, undefined, 4));
      };

      geoip2.city(onSuccess, onError);
    }
  }
})(jQuery);
