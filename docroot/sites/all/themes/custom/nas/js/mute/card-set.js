(function($) {

$(function() {
  $(".card-set").has(".card-set-scroller").each(function() {
    var CardSet = {},
        $this = $(this);
        scroll;

    CardSet.on = false;

    CardSet.setup = function() {
      var $scroller = $this.find(".card-set-scroller"),
          $wrapper = $this.find(".card-set-wrapper"),
          $dots = $this.find(".card-set-dots .dot");

      var scroll = new IScroll($wrapper[0], {
        scrollX: true,
        scrollY: false,
        momentum: false,
        snap: true,
        bounce: true,
        touch: true,
        eventPassthrough: true
      });

      scroll.on("scrollEnd", function() {
        var curPage = scroll.currentPage.pageX;

        $dots.removeClass("active");
        $dots.eq(curPage).addClass("active");    
      });

      scroll.goToPage(1, 0, 1);

      CardSet.on = true;
    }

    CardSet.reset = function() {
      console.log("destroy card set");
      if (typeof scroll.destroy == "function") {
        scroll.destroy();
      }
      $(".card-set-scroller").removeAttr("style");

      CardSet.on = false;
    }

    $(document).bind("respond", function(e) {
      if(e.size == "tiny" || e.size == "small" || e.size == "medium") {
        if (!CardSet.on) {
          CardSet.setup();
        }
      }
      if(e.size == "large") {
        if (CardSet.on) {
          CardSet.reset();
        }
      }
    });
  });
});

})(jQuery);
