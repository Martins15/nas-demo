(function($) {

$(function() {

  $(".curtain").each(function() {
    var $curtain = $(this),
        $body = $("body");

    // Stuff we need for touch
    var delta = 0,
        dragThreshold = 0.15,
        dragStart = null,
        percentage = 0,
        target,
        previousTarget;

    // Get the initial touch position
    function touchStart(e) {
      if (dragStart !== null) { return; }
      if (e.originalEvent.touches) { 
        e = e.originalEvent.touches[0];
      }

      dragStart = e.clientY;
    }

    // Get the new position and animate
    function touchMove(e) {
      if (dragStart === null) { return; }
      if (e.originalEvent.touches) { 
        e = e.originalEvent.touches[0];
      }

      delta = dragStart - e.clientY;
      percentage = delta / $(window).height();

      if (percentage > 0) {
        $curtain.css({
          "-webkit-transform": "translateY(-" + percentage * 150 + "%)",
          "-moz-transform": "translateY(-" + percentage * 150 + "%)",
          "transform": "translateY(-" + percentage * 150 + "%)"
        });
      }

      return false;
    }

    // If we've moved sufficiently, raise the curtain entirely
    function touchEnd(e) {
      dragStart = null;

      $curtain.css({
        "-webkit-transform": "",
        "-moz-transform": "",
        "transform": ""
      });

      if (percentage >= dragThreshold) {
        $curtain.addClass("off");

        $body.bind({
          "touchstart": bodyStart,
          "touchmove": bodyMove
        });
      }

      percentage = 0;
    }

    function bodyStart(e) {
      if (dragStart !== null) { return; }
      if (e.originalEvent.touches) { 
        e = e.originalEvent.touches[0];
      }

      dragStart = e.clientY;
    }

    function bodyMove(e) {
      if (e.originalEvent.touches) { 
        touch = e.originalEvent.touches[0];
      }

      delta = dragStart - touch.clientY;

      if (window.scrollY == 0 && delta < -10) {
        e.preventDefault();
        $curtain.removeClass("off");
        $body.unbind("touchstart touchmove");
      }
    }

    // Bind curtain movement on swipe
    $curtain.bind({
      "touchstart": touchStart,
      "touchmove": touchMove,
      "touchend": touchEnd
    });

    var position = 0;

    // Bind curtain movement on wheel
    $curtain.bind("wheel mousewheel DOMMouseScroll", function(e) {
      e.preventDefault();

      if (e.deltaY < -10) {
        $curtain.addClass("off");
        $body.bind("wheel mousewheel DOMMouseScroll", function(e) {
          if (e.deltaY > 10 && window.scrollY <= 0) {
            e.preventDefault();
            $curtain.removeClass("off");
          }
        });
      }
    });

    // Fallback: click the button to raise the curtain
    $curtain.find(".curtain-arrow").bind("click", function(e) {
      e.preventDefault();
      $curtain.addClass("off");
    });
  });
});

})(jQuery);
