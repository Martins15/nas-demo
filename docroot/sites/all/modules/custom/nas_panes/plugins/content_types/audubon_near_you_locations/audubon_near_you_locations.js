(function($) {

  Drupal.behaviors.local_chapters_centers_block = {
    attach: function(context, settings) {
      if ($('.top-offset').length) {
        // Set 'Your Local Chapters' position when displayed.
        var height = $('#audubon-near-you--local-chapter--wrapper').height();
        $('.top-offset > div').css('margin-top', height+30);
        // Remove Local chapter from Offices & Chapters
        $('#audubon-near-you--local-chapter--wrapper article').each(function() {
          var selector = $(this).attr('class');
          $('#audubon-near-you--office-chapter--wrapper .'+selector).addClass('hide');
		});
	  }
	  if ($('.near-you-form.bird-guide-country select').hasClass('hide')) {
        $('.near-you-form.bird-guide-country').addClass('hide');
	  }
    }
  };
})(jQuery);
