(function($) {

  Drupal.behaviors.local_chapters_centers_block = {
    attach: function(context, settings) {

      var onSuccess = function(location) {
        var wrapper = '#chapters-centers-content-wrapper';
        var stateIsoCode = location.subdivisions['0'].iso_code;
        if (typeof(stateIsoCode) === 'undefined') {
          return;
        }

        // Replace default block with content filtered by state.
        $.ajax({
          type: 'GET',
          url: Drupal.settings.basePath + 'ajax/local-chapters-centers',
          data: { 'state': stateIsoCode },
          dataType: 'html',
          success: function (data) {
            $(wrapper).replaceWith(data);
            $(wrapper).addClass('state-code-' + stateIsoCode);
          }
        });
      };

      var onError = function(error) {
        console.log('Error:' + JSON.stringify(error));
      };

      geoip2.city(onSuccess, onError);
    }
  };
})(jQuery);
