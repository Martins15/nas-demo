(function($) {

$(function() {
  if(!$(".bird-guide-container").length == 0) {
    var MINSCROLL = 50,
        MAXSCROLL = parseInt($(".bird-guide-container").css("padding-top")) + 1;

    function scroll(e, $container, cardPadding, delta) {
      if(navigator.userAgent.toLowerCase().match("windows") && $.browser.webkit) {
        delta = delta * 15;
      }

      var newPos = cardPadding + delta;

      if(window.scrollY == 0) {
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
    }

    $(document).bind("respond", function(e) {
      $(window).unmousewheel();

      if(e.size == "tiny" || e.size == "small") {
        $(".bird-guide-container").css("padding-top", "");
      }
      if(e.size == "medium" || e.size == "large") {
        MAXSCROLL = parseInt($(".bird-guide-container").css("padding-top"));

        $(window).mousewheel(function(e) {
          var $container = $(".bird-guide-container"),
              cardPadding = parseInt($container.css("padding-top")),
              delta = e.deltaY;

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
});

})(jQuery);