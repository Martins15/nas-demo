(function ($) {
  Drupal.behaviors.curtain = {
    attach: function (context, settings) {
      function Curtain($curtain) {
        var self = this,
            $body = $("body"),
            $wrapper = $(".curtain-wrapper");

        // Tracking curtain movement and status
        self.height = 0;
        self.buffer = 20;
        self.bodyHeight = 0;
        self.bufferScreen = 0;

        self.init = function () {
          window.scrollTo(0, 1);

          $(document).on('respond', function (e) {
            if (e.size == "tiny" || e.size == "small" || e.size == "medium") {
              console.log('ON RESPOND', e.size);
              self.reset();
            }
            else if (e.size == "large") {
              if ($body.is('.force-curtain-fallback')) {
                self.reset();
              }
              else {
                self.setup();
              }
            }
          });

          $('.curtain-arrow').click(function(e){
            e.preventDefault();
          });
          $('.curtain-arrow').on('click', function () {
            self.arrowClick = true;
            self.unfurl();
          });
        };

        self.setup = function () {
          self.bodyHeight = $body.height();

          $body.css({"min-height": self.bodyHeight});

          self.setCurtainFocus(true);
          self.bind();
        };

        self.reset = function () {
          $body.removeAttr("style");
          $wrapper.removeClass("on").removeAttr("style");

          self.unbind();
        };

        self.bind = function () {
          $(window).on('scroll', self.handleScroll);
        };

        self.unbind = function () {
          $(window).off('scroll');
        };

        self.handleScroll = function (e) {
          var scrollFactor = document.documentElement.scrollTop || $(document).scrollTop();
          self.bufferScreen = self.getTotalHeight() * 2 - self.bodyHeight;
          if (self.bufferScreen < 0) {
            self.bufferScreen = 0;
          }

          // If we're scrolled down past the curtain, let the page scroll
          if ((scrollFactor + self.bufferScreen) > self.getTotalHeight()) {
            self.setCurtainFocus(true);
          }
          // And if we're not, make sure the curtain is all that scrolls
          else {
            self.setCurtainFocus(false);
          }
        };

        self.setCurtainFocus = function (state) {
          self.updateHeight();

          if (state) {
            $wrapper.attr("style", "margin-top: " + (self.getTotalHeight() - self.buffer) + "px;");
            $wrapper.removeClass("on");
          }
          else {
            $wrapper.attr("style", "margin-bottom: " + self.getTotalHeight() + "px; margin-top: " + self.bufferScreen + "px;");
            $wrapper.addClass("on");
          }
        };

        // Update the height of the curtain, in case it's changed
        self.updateHeight = function () {
          self.height = $curtain.height();
          return self.height;
        };

        // Curtain height plus an arbitrary buffer
        self.getTotalHeight = function () {
          return self.height + self.buffer;
        };

        self.unfurl = function () {
          var scrollFactor = self.height ;

          // Unbind for a second
          self.unbind();

          $('html, body').animate({
            scrollTop: scrollFactor
          }, {
            duration: 400,
            complete: function () {
              self.bind();
              self.handleScroll();
              if (self.bufferScreen > 0 && self.arrowClick) {
                self.arrowClick = false;
                self.unfurl();
              }
            }
          });
        };

        self.init();
      }


      var $curtain = $('.curtain'),
          $ipe_editing = $('.panels-ipe-editing');

      if ($curtain.length) {
        if ($ipe_editing.length === 0) {
          if (typeof Drupal.curtain === 'undefined') {
            Drupal.curtain = new Curtain($curtain);
          }
          else {
            // Drupal.curtain.init();
          }
        }
        else {
          Drupal.curtain.reset();
        }
      }


    }
  };
})(jQuery);
