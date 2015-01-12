(function($) {

  Drupal.near_you = Drupal.near_you || {};

  Drupal.behaviors.near_you = {
    attach: function(context, settings) {
      // Replace blocks only once.
      $('.audubon-near-you--global-content-wrapper').once('location-replace', function() {
        var onSuccess = function(location) {
          var stateIsoCode = location.subdivisions['0'].iso_code;
          if (typeof(stateIsoCode) === 'undefined') {
            return;
          }

          // Replace default block with content filtered by state.
          Drupal.near_you.update_content(stateIsoCode);
        };

        var onError = function(error) {
          console.log('Error:' + JSON.stringify(error));
          Drupal.near_you.update_content('CA');
        };

        geoip2.city(onSuccess, onError);
      });
    }
  };

  /**
   * Update content on the Audubon Near You page.
   *
   * @param stateIsoCode
   *   Iso code.
   */
  Drupal.near_you.update_content = function(stateIsoCode) {
    $.ajax({
      type: 'GET',
      url: Drupal.settings.basePath + 'ajax/audubon-near-you',
      data: { 'state': stateIsoCode },
      dataType: 'json',
      success: function (data) {
        for (var i = 0; i < data.length; i++) {
          var wrapper = '#' + data[i].wrapper;
          $(wrapper).once().replaceWith(data[i].content);
          $(wrapper).once().addClass('state-code-' + stateIsoCode);
        }
      }
    });
  };

})(jQuery);
