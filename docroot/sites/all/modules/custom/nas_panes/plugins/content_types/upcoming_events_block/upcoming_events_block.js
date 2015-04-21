(function($) {

  Drupal.behaviors.upcoming_events_block = {
    attach: function(context, settings) {
      // Replace location only once.
      $('.upcoming-events-content-layout').once('location-replace', function() {
        var wrapper = '#upcoming-events-content-wrapper';

        var onSuccess = function(stateIsoCode) {
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
              if (data !== '') {
                $(wrapper).once().replaceWith(data);
                $('.upcoming-events-block').show();
              }
              else {
			    $('.upcoming-events-block').hide();	  
			  }
              $(wrapper).once().addClass('state-code-' + stateIsoCode);
            }
          });
        };
        
        // If locations were loaded by default state, no Ajax is required.
        if ($('#upcoming-events-content-wrapper li').lenght == 0){
          $('.upcoming-events-block').hide();
          // Internal request.
          geoip.getState(onSuccess);
	    }
      });
    }
  };
})(jQuery);
