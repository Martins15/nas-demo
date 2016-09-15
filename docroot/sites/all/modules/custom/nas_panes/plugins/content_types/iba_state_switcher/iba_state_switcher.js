(function($) {

  Drupal.behaviors.iba_state_switcher = {
    attach: function(context, settings) {
      // Preload image by appending to body and removing.
      var preload = $('<div class="svg-throbber"></div>').appendTo('body');
      setTimeout(function () { preload.remove(); }, 0);

      $('.iba-state-switcher select').change(function() {
        var height = $(this).height();
        var outerHeight = $(this).outerHeight();
        // Put throbber after the select element.
        $('<div class="svg-throbber"></div>')
          .css({
            height: height,
            marginLeft: (outerHeight - height) / 2,
            marginTop: (outerHeight - height) / 2,
            width: height
          })
          .insertAfter(this);

        // Navigate page.
        window.location.pathname = $(this).find(':selected').val();
      });      
    }      
  };

})(jQuery);
