(function($) {

  Drupal.behaviors.upcoming_events_block = {
    attach: function(context, settings) {
      // Replace location only once.
      $('.upcoming-events-content-layout').once('location-replace', function() {
        var wrapper = '#upcoming-events-content-wrapper';

        var onSuccess = function(stateIsoCode) {
          console.log(stateIsoCode);
          stateIsoCode = 'NC';
          if (typeof(stateIsoCode) === 'undefined' || stateIsoCode === null || stateIsoCode === '') {
            return;
          }

          // Replace default block with content filtered by state.
          $.ajax({
            type: 'GET',
            url: Drupal.settings.basePath + 'ajax/upcoming-events',
            data: { 'state': stateIsoCode },
            dataType: 'html',
            success: function (data) {
              var debugFragment = document.createElement('div');
              debugFragment.innerHTML = data;
              console.log('AJAX success');
              console.log(debugFragment);
              console.log(data);
              if (data !== '') {
                $(wrapper).once().replaceWith(data);
              }
              $(wrapper).once().addClass('state-code-' + stateIsoCode);
            }
          });
        };
        console.log('geoIP');
        // Internal request.
        geoip.getState(onSuccess);
      });
    }
  };
})(jQuery);
