(function($) {
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

        self.init = function() {
          window.scrollTo(0, 1);

          $(document).on('respond', function(e) {
            if(e.size == "tiny" || e.size == "small" || e.size == "medium") {
              self.reset();
            }
            else if(e.size == "large") {
              if ($body.is('.force-curtain-fallback')) {
                self.reset();
              }
              else {
                self.setup();
              }
            }
          });

          $('.curtain-arrow').on('click', self.unfurl);
        };

        self.setup = function() {
          self.bodyHeight = $body.height();
          self.bufferScreen = self.getTotalHeight() * 2 - $body.height();
          if (self.bufferScreen < 0) {
            self.bufferScreen = 0;
          }
          
          $body.css({"min-height": self.bodyHeight});

          self.setCurtainFocus(true);
          self.bind();
        };

        self.reset = function() {
          $body.removeAttr("style");
          $wrapper.removeClass("on").removeAttr("style");

          self.unbind();
        };

        self.bind = function() {
          $(window).on('scroll', self.handleScroll);
        };

        self.unbind = function() {
          $(window).off('scroll');
        };

        self.handleScroll = function(e) {
          var scrollFactor = document.documentElement.scrollTop || $(document).scrollTop();

          // If we're scrolled down past the curtain, let the page scroll
          if((scrollFactor + self.bufferScreen) > self.getTotalHeight()) {
            self.setCurtainFocus(true);
          }
          // And if we're not, make sure the curtain is all that scrolls
          else {
            self.setCurtainFocus(false);
          }
        };

        self.setCurtainFocus = function(state) {
          self.updateHeight();

          if (state) {
            $wrapper.attr("style", "margin-top: " + self.getTotalHeight() + "px;");
            $wrapper.removeClass("on");
          } 
          else {
            $wrapper.attr("style", "margin-bottom: " + self.getTotalHeight() + "px; margin-top: " + (self.bufferScreen - self.buffer) + "px;");
            $wrapper.addClass("on");
          }
        };

        // Update the height of the curtain, in case it's changed
        self.updateHeight = function() {
          self.height = $curtain.height();
          return self.height;
        };

        // Curtain height plus an arbitrary buffer
        self.getTotalHeight = function() {
          return self.height + self.buffer;
        };

        self.unfurl = function() {
          var scrollFactor = self.height + self.buffer;

          // Unbind for a second
          self.unbind();

          $('html, body').animate({
            scrollTop: scrollFactor
          }, {
            duration: 400,
            complete: function() {
              self.bind();
              self.handleScroll();
            }
          });
        };

        self.init();
      }

      $(window).load(function(){
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
      });


    }
  };
})(jQuery);
