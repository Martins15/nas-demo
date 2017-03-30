(function($) {
  'use strict';

  /**
   * Native Plants Nurseries near you pane show more results.
   */
  Drupal.behaviors.nativePlantsArNearYou  = {
    attach: function (context, settings) {
      var $hidden = $('.row .hidden');
      $(".how-more-resources").on('click', function (event) {
        event.preventDefault();
        if($hidden.hasClass("hide")) {
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
