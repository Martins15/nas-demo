(function ($) {
  Drupal.behaviors.boa_subscribe_popup = {
    attach: function (context, settings) {
      $('#modalContent .close.reload').bind('click touchend', function(e) {
        window.location.reload();
      });
      if ($.cookie('show_download_link') !== null && settings.nas_panes.boa_plate_original_image_path !== 'undefined') {
      	$('#subscribe-link').attr('href', settings.nas_panes.boa_plate_original_image_path);
      }
    }
  };
})(jQuery);
