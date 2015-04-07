(function($) {
  Drupal.behaviors.scrolljack = {
    attach: function(context, settings) {
      if($(".bird-guide-container").length !== 0) {
        var USERAGENT = navigator.userAgent.toLowerCase(),
            ISWINDOWS = USERAGENT.match("windows"),
            ISWEBKIT  = $.browser.webkit,
            ISFIREFOX = USERAGENT.match("firefox"),
            MINSCROLL = 50,
            MAXSCROLL = parseInt($(".bird-guide-container").css("padding-top")) + 1;

        var scroll = function(e, $container, cardPadding, delta) {
          if(ISWINDOWS && ISWEBKIT || ISWINDOWS && ISFIREFOX) {
            delta = delta * 15;
          } else if(ISWEBKIT || ISFIREFOX) {
            delta = delta * 15;
          } else {
            delta = delta * 15;
          }


          var newPos = cardPadding + delta ;

          if(window.scrollY === 0) {
            if(newPos < MINSCROLL) {
              $container.css("padding-top", MINSCROLL + "px");
            }
            else if(newPos > MAXSCROLL) {
              $container.css("padding-top", MAXSCROLL + "px");
            }
            else {
              e.preventDefault();
              $container.css("padding-top", newPos + "px");
            }
          }
        };

        var stickyContainer = function() {
          var $hero_credit = $('.bird-hero-attribution'),
              $bird_guide_card = $('.bird-guide-card');

          if (typeof $bird_guide_card.visible != "undefined") {
            // Add sticky class when container is not visible.
            if ($bird_guide_card.visible(true) === true) {
              $hero_credit.removeClass('sticky');
              $hero_credit.css({
                width: 'auto'
              });
            }
            else {
              // 2 - container border.
              $hero_credit.width($bird_guide_card.innerWidth() + 2);
              $hero_credit.addClass('sticky');
            }
          }
        };


        $(window).on('resize', function(){
          stickyContainer();
        });

        $(document).bind("respond", function(e) {
          $(window).unmousewheel();
          stickyContainer();

          if(e.size == "tiny" || e.size == "small") {
            $(".bird-guide-container").css("padding-top", "");
          }
          if(e.size == "medium" || e.size == "large") {
            MAXSCROLL = parseInt($(".bird-guide-container").css("padding-top"));

            $(window).scroll(function(e) {
              stickyContainer();
            });

            $(window).mousewheel(function(e) {
              var $container = $(".bird-guide-container"),
                  cardPadding = parseInt($container.css("padding-top")),
                  delta = e.deltaY;

              stickyContainer();
              if(cardPadding <= MAXSCROLL && delta < 0) {
                scroll(e, $container, cardPadding, delta);
              }

              if(cardPadding >= MINSCROLL && delta > 0) {
                scroll(e, $container, cardPadding, delta);
              }

            });
          }
        });

        // ---
        // Totally jerky touch scrolling
        // ---

        // var touchStartY = 0,
        //     touchEndY = 0;

        // $(".bird-guide-container").bind("touchstart", function(e) {
        //   touchStartY = e.originalEvent.changedTouches[0].clientY;
        // });

        // $(".bird-guide-container").bind("touchmove", function(e) {
        //   var $container = $(".bird-guide-container"),
        //       cardPadding = parseInt($container.css("padding-top")),
        //       touchPos = e.originalEvent.touches[0].clientY,
        //       delta = touchStartY - touchPos;

        //   console.log(delta);

        //   if(cardPadding >= MINSCROLL && delta > 0) {
        //     scroll(e, $container, cardPadding, delta);
        //   }
        //   if(cardPadding <= MAXSCROLL && delta < 0) {
        //     scroll(e, $container, cardPadding, delta);
        //   }

        //   touchStartY = touchPos;
        // });
      }
    }
  };
})(jQuery);
