(function($) {

$(function() {
  if($(".conservation-slider").length) {
    var Slider = {},
        scroll;

    Slider.setup = function() {
      $(".conservation-slider").each(function() {
        var $wrapper = $(this).find(".conservation-wrapper"),
            $indicator = $(this).find(".conservation-indicator"),
            $controls = $(this).find(".conservation-slider-button");

        scroll = new IScroll($wrapper[0], {
          scrollX: true,
          scrollY: false,
          momentum: false,
          snap: ".slide",
          bounce: false,
          touch: true,
          eventPassthrough: true,
          snapSpeed: 600
        });

        Slider._setupControls($controls);
        Slider._setupIndicator($indicator);
      });
    }

    Slider._setupControls = function($controls) {
      $controls.bind("click", function() {
        var $this = $(this),
            direction = $this.hasClass("next") ? "next" : "prev";

        direction == "next" ? scroll.next(500) : scroll.prev(500);
      });
    }

    Slider._setupIndicator = function($indicator) {
      var $icons = $indicator.find(".conservation-indicator-icon");

      scroll.on("scrollEnd", function() {
        var currentPage = scroll.currentPage.pageX;

        $icons.removeClass("active");
        $icons.eq(currentPage).addClass("active");
      }); 

      $icons.bind("click", function() {
        var page = $icons.index($(this));
        console.log(page);

        $icons.removeClass("active");
        $icons.eq(page).addClass("active");
        scroll.goToPage(page, 0, 500);
      });
    }

    Slider.setup();
  }
});

})(jQuery);
