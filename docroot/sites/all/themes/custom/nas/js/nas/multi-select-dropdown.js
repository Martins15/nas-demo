(function($) {
  Drupal.behaviors.nas = {
    attach: function(context, settings) {
      $(".search-select").multiselect({
          columns: 1,
          placeholder: ''
      });
    }
  };
})(jQuery);
