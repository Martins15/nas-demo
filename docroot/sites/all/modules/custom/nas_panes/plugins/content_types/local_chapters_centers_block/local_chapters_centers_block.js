(function($) {

  Drupal.behaviors.local_chapters_centers_block = {
    attach: function(context, settings) {
      // Replace location only once.
      $('.chapters-centers-content-layout').once('location-replace', function() {
        var wrapper = '#chapters-centers-content-wrapper';

        var onSuccess = function(stateIsoCode) {
          if (typeof(stateIsoCode) === 'undefined' || stateIsoCode === null || stateIsoCode === '') {
            return;
          }

          // Replace default block with content filtered by state.
          $.ajax({
            type: 'GET',
            url: Drupal.settings.basePath + 'ajax/local-chapters-centers',
            data: { 'state': stateIsoCode },
            dataType: 'html',
            success: function (data) {
              if (data !== '') {
                $(wrapper).once().replaceWith(data);
              }
              $(wrapper).once().addClass('state-code-' + stateIsoCode);
            }
          });
        };

        // Internal request.
        geoip.getState(onSuccess);
      });
    }
  };
})(jQuery);
