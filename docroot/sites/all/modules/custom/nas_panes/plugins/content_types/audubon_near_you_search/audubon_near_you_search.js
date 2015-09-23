(function($) {

  Drupal.near_you = Drupal.near_you || {};

  Drupal.behaviors.near_you = {
    attach: function(context, settings) {
      // Replace blocks only once.
      $('.audubon-near-you--global-content-wrapper').once('location-replace', function() {
        var onSuccess = function(stateIsoCode) {
          if (typeof(stateIsoCode) === 'undefined') {
            return;
          }

          // Update content according state code.
          Drupal.near_you.update_content(stateIsoCode);
        };

        // Internal request.
        geoip.getState(onSuccess);
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
      url: Drupal.settings.basePath + Drupal.settings.pathPrefix  + 'ajax/audubon-near-you',
      data: { 'state': stateIsoCode },
      dataType: 'json',
      success: function (data) {
        for (var i = 0; i < data.length; i++) {
          var wrapper = '#' + data[i].wrapper;
          // Replace content.
          $(wrapper).once().replaceWith(data[i].content);
          $(wrapper).once().addClass('state-code-' + stateIsoCode);
        }
      }
    });
  };

})(jQuery);
