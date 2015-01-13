(function($) {
  function in_array(needle, haystack) {
    var found = false,
      key;
    for (key in haystack) {
      if (haystack[key] == needle) {
        found = true;
        break;
      }
    }
    return found;
  }

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
        var fpp_class_to_show = '',
          all_fpp_classes = [],
          class_to_show = '';
        for (var key in Drupal.settings.frontpage_flyway) {
          if (in_array(StateIsoCode, Drupal.settings.frontpage_flyway[key])) {
            fpp_class_to_show = key;
          }
          all_fpp_classes.push(key);
        }
        if (fpp_class_to_show !== '') {
          class_to_show = '.' + fpp_class_to_show;
        } else {
          var randKey = Math.floor((Math.random() * all_fpp_classes.length));
          class_to_show = '.' + all_fpp_classes[randKey];
        }
        $(class_to_show).show();
      };

      var onError = function(error) {
        console.log("Error:\n\n" + JSON.stringify(error, undefined, 4));
      };

      geoip2.city(onSuccess, onError);
    }
  };
})(jQuery);
