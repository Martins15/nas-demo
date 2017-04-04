(function($) {
  'use strict';

  /**
   * Native Plants Additional resource near you pane show more results.
   */
  Drupal.behaviors.nativePlantsAdditionalResourceNearYou  = {
    attach: function (context, settings) {
      var $hidden = $('.row .hidden', context);
      $('.show-more-resources', context).on('click', function (event) {
        event.preventDefault();
        if ($hidden.hasClass('hide')) {
          $hidden.addClass('invisible').removeClass('hide');
          $(this).text(Drupal.t('Show less «'));
        }
        else {
          $hidden.addClass('hide').removeClass('invisible');
          $(this).text(Drupal.t('Show more »'));
        }
      });
    }
  };

})(jQuery);
