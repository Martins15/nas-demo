(function ($) {

  Drupal.behaviors.animateBlock = {
    attach: function (context, settings) {
      var wrapBlock = $('.show-hide-text', context);

      if (wrapBlock.length) {
        wrapBlock.each(function () {
          var $bannerBlock = $('.banner-text', this),
            $bannerHeight = $('.banner-text', this).outerHeight(true),
            $titleHeight = $('.banner-title', this).outerHeight(true),
            heightAnimate = '-' + ($bannerHeight - $titleHeight - 25) + 'px';
          $bannerBlock.css('bottom', heightAnimate);

          var isTouchDevice = is_touch_device(),
            showEvent = isTouchDevice ? 'touchstart' : 'mouseenter',
            hideEvent = isTouchDevice ? 'touchstart' : 'mouseleave';

          $(this).on(showEvent, function () {
            $bannerBlock.css('bottom', 0);
          });
          $(this).on(hideEvent, function () {
            $bannerBlock.css('bottom', heightAnimate);
          });

          function is_touch_device() {
            return 'ontouchstart' in window || navigator.maxTouchPoints;
          };

        })
      }
    }
  };

})(jQuery);