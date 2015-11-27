(function($) {

  Drupal.behaviors.iba_landing_map = {
    attach: function(context, settings) {
      $('.iba-state-switcher select').change(function() {
        window.location.pathname = $(this).find(':selected').val();
      });      
    }      
  };

})(jQuery);
