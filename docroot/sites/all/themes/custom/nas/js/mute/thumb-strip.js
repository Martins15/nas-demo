// Load each thumbnail strip
(function ($) {
  Drupal.behaviors.thumb_strip = {
    attach: function (context, settings) {
      $(".thumb-strip").once().each(function() {
        var self = this;
        var totalImages = $('img', this).size();
        var loadedImages = 0;

        $('img', this).each(function () {
          if (!this.complete) {
            $(this).bind('load', function() {
              if (++loadedImages == totalImages) {
                Drupal.behaviors.thumb_strip.applyIScroll(self);
              }
            });
          }
          else {
            loadedImages++;
          }
        });

        if (loadedImages == totalImages) {
          Drupal.behaviors.thumb_strip.applyIScroll(self);
        }
      });
    },

    applyIScroll: function (elem) {
      var wrapper = $(elem).find(".thumb-strip-wrapper"),
        scroller = $(elem).find("ul"),
        thumbs = $(elem).find("li"),
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

      $(elem).find(".thumb-strip-prev").bind("click", function() {
        scroll.prev();
      });

      $(elem).find(".thumb-strip-next").bind("click", function() {
        scroll.next();
      });

      $(elem).addClass("loaded");
    }
  }
})(jQuery);
