(function($) {
  Drupal.behaviors.slideshow = {
    attach: function(context, settings) {
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

          Slideshow._resizeSlides($slides);
          Slideshow._setupIndicatorPosition($slides, $indicator);
          Slideshow._setupButtonPosition($slides, $buttons);
        });
      }

      Slideshow._resizeSlides = function($slides) {
        var $imgWrappers = $slides.find(".slide-img"),
            $imgs = $imgWrappers.find("img"),
            aspectRatio = $(window).width() / $(window).height();

        $imgs.removeAttr("style");
        $imgWrappers.removeAttr("style");

        // Then give the images the body width
        $imgs.css({
          "width": $("body").width() + "px"
        });

        // Get the max height of all landscape
        var slideHeights = $slides.not(".portrait").map(function() {
          return $(this).find(".slide-img img").height();
        }).get();

        var defaultHeight = $("body").width() * 0.625;
            maxHeight = Math.max.apply(null, slideHeights);

        if (defaultHeight > maxHeight) {
          maxHeight = defaultHeight;
        }

        if (maxHeight > ($(window).height())) {
          maxHeight = ($(window).height());
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

        $slides.filter(".portrait").find(".slide-img img").css({
          "width": "auto"
        });

        // Mobile resizing rules
        if($(window).width() < 768 && aspectRatio < 1) {
          var $portraitSlides = $slides.filter(".portrait").not(".title-slide, .end-slide"),
              $landscapeSlides = $slides.not(".portrait, .title-slide, .end-slide"),
              $capSlides = $slides.filter(".title-slide, .end-slide"),
              slideshowHeight;

          // If there are portrait images, set the wrapper heights accordingly
          if($portraitSlides.length) {
            $imgWrappers.css({
              "height": maxHeight * 1.5 + "px"
            });
          }

          // Horizontally center portrait images
          $portraitSlides.find(".slide-img img").css({
            "height": "100%"
          });

          // Vertically center landscape images
          $landscapeSlides.each(function() {
            var $this = $(this),
                $img = $this.find(".slide-img img"),
                $imgWrapper = $img.parent(),
                heightDifference = $imgWrapper.height() - $img.height();

            $img.css({
              "position": "relative",
              // "width": "100%",
              "top": heightDifference/2 + "px"
            });
          });

          // Now we can calculate the total slideshow height...
          slideshowHeight = $slides.parents(".slideshow-wrapper").height();

          $capSlides.find(".slide-img").css({
            "height": slideshowHeight + "px"
          });
          $capSlides.find(".slide-img img").css({
            "height": slideshowHeight + "px",
            "width": "auto"
          });
        }
        // Landscape-orientation resizing rules
        else if($(window).width() < 768 && aspectRatio > 1.45) {
          var $capSlides = $slides.filter(".title-slide, .end-slide"),
              maxHeight = $(window).height() * 0.75 + "px";

          $slides.not(".title-slide, .end-slide").find("img").css({
            "height": maxHeight,
            "width": "auto"
          });
          $capSlides.find(".slide-img").css({
            "height": $slides.parents(".slideshow-wrapper").height()
          });
          $capSlides.find(".slide-img img").css({
            "width": "100%",
            "height": "auto"
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
        $controls.bind("click", function(e) {
          e.preventDefault();

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
      setTimeout(function() {
        Slideshow.resize();
      }, 1000);
    }
  }
};
})(jQuery);
