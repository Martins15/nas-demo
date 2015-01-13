$(function() {

  $(".curtain").each(function() {
    var $curtain = $(this),
        $body = $("body"),
        curtainPosition = 0;

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
    if(isIELessThan10()) {
      $curtain.bind("mousewheel DOMMouseScroll", function(e) {
        e.preventDefault();

        if (e.deltaY <= -1) {
          $curtain.animate({top: "-" + $(window).height()}, 600, function() {
            $curtain.addClass("off");
          });
        }
      });

      $(document).bind("mousewheel DOMMouseScroll", function(e) {
        if (e.deltaY >= 1 && document.documentElement.scrollTop == 0) {
          e.preventDefault();
          $curtain.animate({top: "0"}, 600, function() {
            $curtain.removeClass("off");
          });
        }
      });
    }
    else {      
      $curtain.bind("mousewheel DOMMouseScroll", function(e) {
        e.preventDefault();

        if(e.deltaY < 0) {
          $curtain.css({"top": e.deltaY});
        }

        // if (e.deltaY <= -1) {
        //   $curtain.addClass("off");
        //   $body.bind("mousewheel DOMMouseScroll", function(e) {

        //     if (e.deltaY >= 1 && window.scrollY <= 0) {
        //       e.preventDefault();
        //       $curtain.removeClass("off");
        //     }
        //   });
        // }
      });
    }

    // Fallback: click the button to raise the curtain
    $curtain.find(".curtain-arrow").bind("click", function(e) {
      e.preventDefault();
      $curtain.addClass("off");
    });
  });

  function isIELessThan10() {
    var ua = window.navigator.userAgent,
        msie = ua.indexOf("MSIE ");

    // It's IE
    if(msie > 0) {
      var version = parseInt(ua.substring(msie + 5, ua.indexOf(".", msie)));

      // It's IE < 10
      if(version < 10) {
        return true;
      }
      // It's IE >= 10
      else {
        return false;
      }
    }
    // It's something else
    else {
      return false;
    }
  }
});