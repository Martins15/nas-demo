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
          nav:true,
          pagination: false,
          autoWidth: true,
          margin: 10,
          navText: ["<i class=\"indicator-left icon-arrow-left\"></i>", "<i class=\"indicator-right icon-arrow-right\"></i>"],
          responsive : {
            0 : {
              items: 1,
              autoWidth: false
            },

            320 : {
              items: 2,
              autoWidth: false
            },

            580: {
              items: 3,
              autoWidth: false
            },

            602 : {
              autoWidth: true,
              items: 2
            }
          }
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
          $formTitle = '',
          $button = $('.native-plants-botton--get-list'),
          $form = $('.native-plants-bottom-form');

        // Find which is the next element to determine from where the scroll starts.
        if ($list.next().length == 1) {
          $formTitle = $list.next();
        } else {
          $formTitle = $list.parent().next();
        }

        $(window).bind('scroll resize', function (e) {
          $self.removeClass('native-plants-bottom-fixed');
          var s = $w.scrollTop() + $w.height();
          var offset = $formTitle.offset().top;
          if (s < offset) {
            $self.addClass('native-plants-bottom-fixed');
          }
          else {
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
      if (typeof Foundation === 'undefined') {
        return;
      }
      $(document).foundation({
        clearing: {
          close_selectors: '.clearing-close, div.clearing-blackout, div.visible-img, img'
        }
      });
      $('a.clearing-attach').once('np-clearing-fix', function () {
        var $self = $(this);
        $self.bind('click', function() {
          $self.parent().find('[data-clearing] a').trigger('click');
          return false;
        });
      });
    }
  };

  /**
   * Content search on native plants page.
   */
  Drupal.behaviors.contentSearch = {
    attach: function(context, settings) {
      var $buttonWrapper = $('.js-native-plants-search-button'),
        $open = $buttonWrapper.find('.js-open'),
        $close = $buttonWrapper.find('.js-close'),
        $form = $buttonWrapper.next('.js-search-collapsible');

      $open.on('click', function (){
        $form.removeClass('collapsed');
        $buttonWrapper.removeClass('collapsed');
      });

      $close.on('click', function (){
        $form.addClass('collapsed');
        $buttonWrapper.delay(500).queue(function(){
          $(this).addClass('collapsed').dequeue();
        });
      });
    }
  };

  /**
   * Tabs.
   */
  Drupal.behaviors.tabs = {
    attach: function(context, settings) {
      var $jsTabs = $('.js-tabs');
        $('.js-native-plants-tabs').responsiveTabs({
            startCollapsed: 'accordion',
            active: 0,
            animation: 'slide',
            duration: 200,
            startCollapsed: false,
            scrollToAccordion: true
        });
    }
  };

})(jQuery);
