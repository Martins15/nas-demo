(function ($) {

  /**
   * Modified ajax_screen_lock function.
   */
  Drupal.ajaxScreenLock = Drupal.ajaxScreenLock || {};
  Drupal.ajaxScreenLock.blockUI = function () {
    Drupal.ajaxScreenLock.unblock = true;
    if (Drupal.settings.ajaxScreenLock.throbber_hide) {
      $('.ajax-progress-throbber').hide();
    }

    $.blockUI({
      message: Drupal.settings.ajaxScreenLock.message,
      css: {
        top: ($(window).height() - 90) / 2 + 'px',
        left: ($(window).width() - 90) / 2 + 'px',
        width: '90px'
      },
      timeout: Drupal.settings.ajaxScreenLock.timeout
    });
  };

})(jQuery);
