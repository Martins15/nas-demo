(function($) {

  Drupal.behaviors.local_chapters_centers_block = {
    attach: function(context, settings) {
      if ($('.top-offset').length) {
        var height = $('#audubon-near-you--local-chapter--wrapper').height();
        $('.top-offset > div').css('margin-top', height+30);
	  }
    }
  };
})(jQuery);
