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

        $('.upcoming-events-block').hide();

        var state = getCookie('Drupal.visitor.state');
        if (state && state.length == 2){
          onSuccess(state);
	    }
        else {
          geoip.getState(onSuccess);
	    }
      });
    }
  };

  function getCookie(cname) {
    var name = cname + "=";
    var ca = document.cookie.split(';');
    for(var i = 0; i < ca.length; i++) {
      var c = ca[i];
      while (c.charAt(0) == ' ') c = c.substring(1);
      if (c.indexOf(name) === 0) return c.substring(name.length, c.length);
    }
    return "";
  }
})(jQuery);
