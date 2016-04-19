(function ($) {
  $(document).ajaxSend(function (event, jqxhr, settings) {
    if (!Drupal.ajaxScreenLock.unblock) {
      var target = Drupal.ajaxScreenLock.getUrlPath(settings.url);
      var pages = Drupal.settings.ajaxScreenLock.pages;
      var visibility = Drupal.settings.ajaxScreenLock.visibility;

      // Handle for certain pages.
      if (!$.isEmptyObject(pages)) {
        $.each(pages, function (num, page) {
          page = Drupal.ajaxScreenLock.getUrlPath(page);
          if (target.length >= page.trim().length) {
            if (target.substr(0, page.trim().length) == page.trim() && visibility == 1) {
              Drupal.ajaxScreenLock.blockUI();
            }
            else if (visibility == 0 && target.substr(0, page.trim().length) != page.trim()) {
              Drupal.ajaxScreenLock.blockUI();
            }
          }
        });
      }
      // Lock for all.
      else {
        Drupal.ajaxScreenLock.blockUI();
      }
    }
  });

  $(document).ajaxStop(function (r, s) {
    if (Drupal.ajaxScreenLock.unblock) {
      $.unblockUI();
      Drupal.ajaxScreenLock.unblock = false;
    }
  });

  Drupal.ajaxScreenLock = {
    // Grab path from AJAX url.
    getUrlPath: function (ajaxUrl) {
      var url = document.createElement("a");
      url.href = ajaxUrl;
      return url.pathname;
    },

    blockUI: function () {
      Drupal.ajaxScreenLock.unblock = true;
      if (Drupal.settings.ajaxScreenLock.throbber_hide) {
        $('.ajax-progress-throbber').hide();
      }

      $.blockUI({
        message: Drupal.settings.ajaxScreenLock.message,
        css: {
          top: ($(window).height() - 400) / 2 + 'px',
          left: ($(window).width() - 400) / 2 + 'px',
          width: '400px'
        },
        timeout: Drupal.settings.ajaxScreenLock.timeout
      });
    },

    unblock: false
  }
}(jQuery));
