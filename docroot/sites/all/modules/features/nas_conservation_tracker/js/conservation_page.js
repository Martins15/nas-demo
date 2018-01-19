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


  Drupal.behaviors.nasCtForm = {
    attach: function (context) {

      var $linkFilter = $('.nas-ct-refine-listing', context);
      var $formFilter = $('#nas-conservation-tracker-landscapes-map-form', context);
      var $blockFilter = $('.filter-block form', context);
      var wrapForm = '';
      var textLink = $linkFilter.text();
      $linkFilter.appendTo('body', context);

      if ($formFilter.length) {
        wrapForm = $formFilter;
      }
      if ($blockFilter.length) {
        $blockFilter.append($('.filter-block > div', context));
        wrapForm = $blockFilter;
      }

      $('<div class="title-form hide-for-large hide-for-xlarge"><p>' + textLink + '</p><span class="js-exit"></span></div>').prependTo(wrapForm);
      $linkFilter.click(function (e) {
        e.preventDefault();
        wrapForm.toggleClass('js-open-mobile');
        $('body').toggleClass('js-overflow');
      });
      $('.js-exit').click(function () {
        wrapForm.removeClass('js-open-mobile');
        $('body').removeClass('js-overflow');
      })
    }
  };

})(jQuery);