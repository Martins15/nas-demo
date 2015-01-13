(function($) {

$(function() {
  if($.browser.msie && $.browser.version == 8) {
    $(".slideshow, .conservation-slider").each(function() {
      var $this = $(this),
          $slides = $this.find(".slide"),
          $current = $slides.first();
          $buttons = $this.find(".slideshow-control, .conservation-slider-button"),
          $scroller = $this.find(".slideshow-scroller, .conservation-scroller"),
          $indicator = $this.find(".slideshow-indicator"),
          scrollerPosition = 0;

      $current.addClass("current");
      $scroller.css("position", "relative");

      $buttons.bind("click", function(e) {
        e.preventDefault();

        var $this = $(this);

        if($this.hasClass("next")) {
          nextSlide();
        }
        else if($this.hasClass("prev")) {
          prevSlide();
        }
        else if($this.hasClass("restart")) {
          firstSlide();
        }
      });

      function nextSlide() {
        if (!$current.is($slides.last())) {
          var movement = $slides.width() * -1,
              newPosition = scrollerPosition + movement;
              scrollerPosition = newPosition;

          $scroller.animate({
            left: newPosition + "px"
          }, 600, function() {
            $slides.removeClass("current");
            $current = $current.next();
            $current.addClass("current");

            updateIndicator();
          });
        }
      }

      function prevSlide() {
        if (!$current.is($slides.first())) {
          var movement = $slides.width(),
              newPosition = scrollerPosition + movement;
              scrollerPosition = newPosition;

          $scroller.animate({
            left: newPosition + "px"
          }, 600, function() {
            $slides.removeClass("current");
            $current = $current.prev();
            $current.addClass("current");

            updateIndicator();
          });
        }
      }

      function updateIndicator() {
        $indicator.find(".indicator-current").text($current.index() + 1);
      }

      function firstSlide() {
        scrollerPosition = 0;

        $scroller.animate({
          left: "0px"
        }, 600, function() {
          $slides.removeClass("current");
          $current = $slides.first();
          $current.addClass("current");

          updateIndicator();
        });
      }
    });
  }
});

})(jQuery);
