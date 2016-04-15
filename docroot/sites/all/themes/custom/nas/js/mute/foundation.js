/**
 * Init foundation javascripts.
 */

(function($) {
  Drupal.behaviors.equalizer = {
    attach: function(context, settings) {
      $('body').once('foundation').foundation();
    }
  };
})(jQuery);
