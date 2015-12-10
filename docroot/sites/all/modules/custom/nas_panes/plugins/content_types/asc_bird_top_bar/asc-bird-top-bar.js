/**
 * Defines behaviour for back-to-center pane.
 */

;(function($, Drupal) {
  Drupal.behaviors.ascBirdTopBar = {
    attach: function (context, settings) {
      $(".national-strip.back-to-center").once(function () {
        var $backBar = $(this);
        $backBar.css({
          width: "100%",
          position: 'fixed',
          zIndex: 500,
          top: 0
        });
        setTimeout(function() {
          $(".global-header").css({paddingTop: $backBar.outerHeight()});
        }, 0);
        // Close button.
        $backBar.find('.close').click(function () {
          $backBar.slideUp(200);
          $(".global-header").animate({paddingTop: 0}, 100);
          return false;
        });
        // Workaround for admin menu.
        if ($("body").hasClass('admin-menu')) {
          setTimeout(function() {
            $backBar.css({top: $("#admin-menu").outerHeight()});
          }, 100);
        }
      });
    }
  };
})(jQuery, Drupal);
