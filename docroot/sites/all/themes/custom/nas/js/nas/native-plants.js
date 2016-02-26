(function($) {
  /**
   * Birds Carousel on Native plants search results page.
   */
  Drupal.behaviors.npOwl = {
    attach: function(context, settings) {
      $(".bird-card-carousel .owl-carousel").once('np-owl', function () {
        var self = $(this);
        self.owlCarousel({
          items: 2,
          itemsDesktop: false,
          itemsDesktopSmall: false,
          itemsTablet: false,
          itemsMobile: false,
          paginationSpeed: 100,
          navigation: true,
          rewindNav: false,
          pagination: false,
          navigationText: ["<i class=\"indicator-left icon-arrow-left\"></i>", "<i class=\"indicator-right icon-arrow-right\"></i>"]
        });

        // Shift card title down if it gets split on several lines.
        $(window).bind('resize', function (e) {
          $(".bird-card-caption", self).each(function () {
            var $caption = $(this);
            var $header = $(this).find('h4');
            if ($header.height() > parseInt($header.css('line-height')) + 2) {
              $caption.addClass('bird-card-caption-long');
            }
            else {
              $caption.removeClass('bird-card-caption-long');
            }
          });
        });
      });
    }
  };

  /**
   * Sticky footer on Native plants search results page.
   */
  Drupal.behaviors.npStickyFooter = {
    attach: function(context, settings) {
      $(".native-plants-bottom").once('np-sticky-footer', function () {
        var $self = $(this),
          $list = $(".native-plants-bottom-plant-list"),
          $w = $(window),
          $button = $('.native-plants-botton--get-list'),
          $formTitle = $('.native-plants-bottom-form-title'),
          $form = $('.native-plants-bottom-form');

        $(window).bind('scroll resize', function (e) {
//          $self.removeAttr('style');
          $self.removeClass('native-plants-bottom-fixed');
          var s = $w.scrollTop() + $w.height();
          var offset = $formTitle.offset().top;
          if (s < offset) {
            $self.addClass('native-plants-bottom-fixed');
//            $self.css({
//              bottom: 0,
//              position: 'fixed',
//              width: '100%'
//            });
          }
          else {
//            $self.removeAttr('style');
            $self.removeClass('native-plants-bottom-fixed');
          }

          // Form isn't fully visible.
          if (s < offset + $formTitle.outerHeight() + $form.outerHeight() - 10) {
            $button.removeClass('js-form-is-visible');
            // If form just became hidden, show button.
            if (!$button.hasClass('js-form-isnt-visible')) {
              $button.stop().css({display: 'block'}).animate({opacity: 1});
            }
            // Mark button as it knows that form isn't visible.
            $button.addClass('js-form-isnt-visible');
          }
          // Form is fully visible.
          else {
            $button.removeClass('js-form-isnt-visible');
            // Form just became visible, hide button.
            if (!$button.hasClass('js-form-is-visible')) {
              $button.stop().animate({opacity: 0}, function () {
                $(this).css({display: 'none'});
              });
            }
            // Mark button as it knows that form is visible.
            $button.addClass('js-form-is-visible');
          }

        }).trigger('scroll');

        // Button click handler.
        $button.click(function () {
          // Remove styles to properly calculate offsets.
          var style = $self.attr('style');
          $self.removeAttr('style');
          var offset = $formTitle.offset().top;
          var h = $formTitle.outerHeight() + $form.outerHeight();
          var s =  h + offset - $w.height();
          // Apply styles back in order to prevent blinking.
          $self.attr({ style: style });
          $('html, body').animate({ scrollTop: s });
        });
      });
    }
  };

  /**
   * Bind camera icon to clearing thumbs.
   */
  Drupal.behaviors.npClearingFix = {
    attach: function(context, settings) {
      $(document).foundation();
      $('a.clearing-attach').once('np-clearing-fix', function () {
        var $self = $(this);
        $self.bind('click', function() {
          $self.parent().find('[data-clearing] a').trigger('click');
          return false;
        });
      });
    }
  };
})(jQuery);