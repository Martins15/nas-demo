(function($) {
  'use strict';

  /**
   * Native Plants Additional resource near you pane show more results.
   */
  Drupal.behaviors.nativePlantsAdditionalResourceNearYou  = {
    attach: function (settings) {
      var $hidden = $('.row .hidden');
      $(".show-more-resources").on('click', function (event) {
        event.preventDefault();
        if ($hidden.hasClass('hide')) {
          $hidden.addClass('invisible').removeClass('hide');
          $(this).text('Show less «');
        }
        else {
          $hidden.addClass('hide').removeClass('invisible');
          $(this).text('Show more »');
        }
      });
    }
  };

})(jQuery);
