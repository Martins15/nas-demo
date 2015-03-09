// Load each thumbnail strip
(function ($) {
  Drupal.behaviors.thumb_strip = {
    attach: function (context, settings) {
      $(".thumb-strip").each(function() {
        var wrapper = $(this).find(".thumb-strip-wrapper"),
            scroller = $(this).find("ul"),
            thumbs = $(this).find("li"),
            thumbHeight = thumbs.last().height(),
            scrollerWidth = 0;

        thumbs.each(function() {
          scrollerWidth += $(this).outerWidth();
        });

        scroller.css({
          "width": scrollerWidth + "px",
          "height": thumbHeight + "px"
        });

        var scroll = new IScroll(wrapper[0], {
          scrollX: true,
          scrollY: false,
          momentum: false,
          snap: 'li',
          bounce: false,
          touch: true,
          eventPassthrough: true
        });

        $(this).find(".thumb-strip-prev").bind("click", function() {
          scroll.prev();
        });

        $(this).find(".thumb-strip-next").bind("click", function() {
          scroll.next();
        });

        $(this).addClass("loaded");
      });
    });
  }
}
})(jQuery);
