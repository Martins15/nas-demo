(function ($) {
  Drupal.behaviors.boa_subscribe_popup = {
    attach: function (context, settings) {
      $('#modalContent .close.reload').bind('click touchend', function(e) {
        window.location.reload();
      });
      if ($.cookie('show_download_link') !== null && settings.nas_panes.boa_plate_original_image_path !== 'undefined') {
      	$('#subscribe-link').attr('href', settings.nas_panes.boa_plate_original_image_path);
      	$('#subscribe-link').removeClass('ctools-use-modal');
      	$('#subscribe-link').removeClass('ctools-use-modal-processed');
      	$('#subscribe-link').clone().appendTo('.download-link');
      	$('#subscribe-link:first').remove();
      }
      $('#modalBackdrop').click(function() {
         Drupal.CTools.Modal.dismiss();
      });
      $('#nas-panes-boa-mail-subscription-form #edit-cancel').bind('click touchend', function(e) {
        e.preventDefault();
        $(this).parents('form').remove();
        $('#modal-content').append('<a target="_blank" href="' + settings.nas_panes.boa_plate_original_image_path + '">' + Drupal.t('Download your image here.') + '</a>');
        $.cookie('show_download_link', 1, { expires : 365 });
        $('#subscribe-link').attr('href', settings.nas_panes.boa_plate_original_image_path);
        $('#subscribe-link').removeClass('ctools-use-modal');
        $('#subscribe-link').removeClass('ctools-use-modal-processed');
        $('#subscribe-link').clone().appendTo('.download-link');
        $('#subscribe-link:first').remove();
      });
    }
  };
})(jQuery);
