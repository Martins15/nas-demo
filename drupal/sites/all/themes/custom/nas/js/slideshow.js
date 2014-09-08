(function($) {

$(function() {
  if($(".slideshow").length) {
    var Slideshow = {},
        scroll;

    // @todo Relieve some magic numbers

    Slideshow.resize = function() {
      $(".slideshow").each(function() {
        var $this = $(this),
            $slides = $this.find(".slide"),
            $wrapper = $this.find(".slideshow-wrapper"),
            $scroller = $this.find(".slideshow-scroller"),
            $title = $this.find(".slideshow-title"),
            $indicator = $this.find(".slideshow-indicator");
            $buttons = $this.find(".slideshow-button");

        $slides.css("width", $("body").width() + "px");
        $scroller.css("width", $("body").width() * $slides.length + "px");

        Slideshow._resizeImg($slides);
        Slideshow._setupIndicatorPosition($slides, $indicator);
        Slideshow._setupButtonPosition($slides, $buttons);
      });
    }

    Slideshow._resizeImg = function($slides) {
      var $imgWrappers = $slides.find(".slide-img"),
          $imgs = $imgWrappers.find("img");

      $imgs.removeAttr("style");

      // Then give the images the body width
      $imgs.css({
        "width": $("body").width() + "px",
        "height": "auto"
      });


      // Get the max height of all landscape 
      var slideHeights = $slides.not(".portrait").map(function() {
        return $(this).find("img").height();
      }).get();


      var defaultHeight = $("body").width() * 0.625;
          maxHeight = Math.max.apply(null, slideHeights);

      if (defaultHeight > maxHeight) {
        maxHeight = defaultHeight;
      }

      if (maxHeight > ($(window).height() * .95)) {
        maxHeight = ($(window).height() * .95);
        $imgs.css({
          "height": maxHeight + "px",
          "width": "auto"
        })
      }
      else {
        $imgs.css({
          "height": maxHeight + "px"
        })
      }

      $slides.filter(".portrait").find("img").css({
        "width": "auto"
      });

      if($(window).width() < 768) {
        $slides.filter(".portrait").find("img").css({
          "min-width": "50%",
          "height": "auto",
          "max-height": maxHeight * 1.5 + "px"
        });
      }
    }

    Slideshow.setup = function() {
      var $body = $(".slideshow"),
          $indicator = $body.find(".slideshow-indicator"),
          $controls = $body.find(".slideshow-control");

      Slideshow._setSizes($body);

      scroll = new IScroll(".slideshow-wrapper", {
        scrollX: true,
        scrollY: false,
        momentum: false,
        snap: ".slide",
        bounce: false,
        touch: true,
        eventPassthrough: true,
        snapSpeed: 600,
        resizePolling: 200,
        bindToWrapper: true
      });

      Slideshow._setupIndicator($indicator, $body);
      Slideshow._setupControls($controls);
      Slideshow.resize();
    }

    Slideshow._setSizes = function($body) {
      var $scroller = $body.find(".slideshow-scroller"),
          $wrapper = $body.find(".slideshow-wrapper"),
          $slides = $body.find(".slide"),
          $title = $body.find(".slideshow-title"),
          $indicator = $body.find(".slideshow-indicator"),
          $buttons = $body.find(".slideshow-button");

      $slides.css("width", $("body").width() + "px");
      $scroller.css("width", $slides.width() * $slides.length + "px");

      Slideshow._setupIndicatorPosition($slides, $indicator);
      Slideshow._setupButtonPosition($slides, $buttons);
    }

    Slideshow._setupIndicator = function($indicator, $body) {
      scroll.on("scrollEnd", function() {
        var currentPage = scroll.currentPage.pageX + 1,
            totalPages = $body.find(".slide").length;

        $(".indicator-current").html(scroll.currentPage.pageX + 1);
        $(".ss-icon").removeClass("inactive");

        if(currentPage == 1) {
          $(".ss-icon.prev").addClass("inactive");
        }
        if(currentPage == totalPages) {
          $(".ss-icon.next").addClass("inactive");
        }
      }); 
    }

    Slideshow._setupIndicatorPosition = function($slides, $indicator) {
      var slideHeight = $slides.find(".slide-img").height(),
          indicatorHeight = $indicator.outerHeight(),
          indicatorMargin = 20;

      if($("body").width() > 767) {
        $indicator.css({
          "position": "relative",
          "top": slideHeight + indicatorHeight + indicatorMargin + "px",
          "z-index": "2"
        });
      }
      else {
        $indicator.removeAttr("style");
      }
    }

    Slideshow._setupButtonPosition = function($slides, $buttons) {
      var slideHeight = $slides.find(".slide-img").height(),
          buttonHeight = $buttons.height();

      $buttons.css({
        "top": (slideHeight / 2) - (buttonHeight / 2) + 20 + "px"
      });
    }

    Slideshow._setupControls = function($controls) {
      $controls.bind("click", function() {
        var $this = $(this);
        
        if ($this.hasClass("next")) {
          scroll.next(400)
        }
        else if ($this.hasClass("prev")) {
          scroll.prev(400)
        }
        else if ($this.hasClass("restart")) {
          scroll.goToPage(0, 0, 400);
        }
      });
    }

    $(window).bind("resize", function() {
      Slideshow.resize();
    });

    Slideshow.setup();
  }
});

})(jQuery);
