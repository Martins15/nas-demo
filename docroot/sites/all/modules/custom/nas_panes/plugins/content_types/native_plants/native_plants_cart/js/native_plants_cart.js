(function($) {
  /**
   * Sticky footer on Native plants search results page.
   */
  Drupal.behaviors.npStickyFooter = {};
  Drupal.behaviors.npStickyFooter.attach = function(context, settings) {
    $('.native-plants-bottom', context).once('np-sticky-footer', function () {
      var $self = $(this),
        $list = $('.native-plants-bottom-plant-list'),
        $list_info = $('.native-plants-bottom-plant-list-info'),
        $w = $(window),
        $anchor = '',
        $button = $('.native-plants-botton--get-list');

      // Find which is the next element to determine from where the scroll starts.
      var $test_elem = $list;
      while ($test_elem.next().length != 1) {
        $test_elem = $test_elem.parent();
      }
      $anchor = $test_elem.next();

      $w.bind('scroll resize', function (e) {
        $self.removeClass('native-plants-bottom-fixed');
        var s = $w.scrollTop() + $w.height();
        var offset = $anchor.offset().top;
        if (s < offset) {
          $self.addClass('native-plants-bottom-fixed');
        }
        else {
          $self.removeClass('native-plants-bottom-fixed');
        }
      }).trigger('scroll');

      // Button click handler.
      $button.click(function () {
        $button.stop().animate({opacity: 0}, function () {
          $list.addClass('native-plants-bottom-plant-list-form-show');
          if (Foundation.utils.is_small_only()) {
            $list_info.hide();
          }
        });
      });

      $w.on('click', function (event) {
        if ($list.hasClass('native-plants-bottom-plant-list-form-show')) {
          // If the click event came not from the form, throw a lost-focus event.
          if (!$(event.target).parents('.native-plants-get-list-form').size()) {
            $list.trigger('focus-lost');
          }
        }
      });

      // Throw a lost-focus event on tab switches.
      $('.js-tabs').on('toggled', function (event, tab) {
        if ($list.hasClass('native-plants-bottom-plant-list-form-show')) {
          $list.trigger('focus-lost');
        }
      });

      // Hide the form and show button on a lost-focus event.
      $list.on('focus-lost', function (e) {
        $list.removeClass('native-plants-bottom-plant-list-form-show');
        $w.trigger('resize');
        $button.stop().animate({opacity: 1});
      });

      $w.bind('resize', function () {
        if ($list.hasClass('native-plants-bottom-plant-list-form-show') && Foundation.utils.is_small_only()) {
          $list_info.hide();
        }
        else {
          $list_info.show();
        }
      });
    });
  };
})(jQuery);
