(function($) {
  Drupal.behaviors.expand_hero = {
    attach: function(context, settings) {
      /*window.scrollTo(0, 0);*/

      var oldWidth = $(".hero.expand").width(),
          oldHeight = $(".hero.expand").height(),
          oldAspectRatio = oldWidth / oldHeight;

      // Assume 2:3 aspect ratio if we can't calculate it
      if(oldHeight == 0) {
        oldHeight = oldWidth * 0.666667;
      }

      if($(".hero.expand").length > 0) {
        expandHero();

        $(".hero.expand img").load(expandHero);

        $(window).on("resize load", expandHero);
      }

      // Expands the hero to window height for a dramatic effect
      function expandHero() {
        var windowHeight = $(window).height(),
            windowWidth = $(window).width(),
            aspectRatio = windowWidth / windowHeight,
            $hero = $(".hero.expand"),
            $img = $hero.find("img");

        // Only expand for large screens
        if(windowWidth > 767) {
          var newHeight = windowHeight - $hero.offset().top,
              newWidth = (newHeight / oldHeight) * oldWidth,
              bleed = (newWidth - windowWidth) / -2;
          console.log('newHeight ' + newHeight);
          console.log('newWidth ' + newWidth);
          console.log('bleed ' + bleed);
          console.log('oldHeight ' + oldHeight);
          console.log('oldWidth ' + oldWidth);
          $hero.css({"height": newHeight + "px"});
          $img.css({
            "left": "0px",
            "max-width": "none",
            "height": "auto",
            "width": newWidth + "px"
          });

          if(newWidth > windowWidth) {
            $img.css({
              "left": bleed + "px"
            });
          }
        }
        // Everybody else gets a default-sized hero
        else {
          $hero.removeAttr("style");
          $img.removeAttr("style");
        }
      }
    }
  };
})(jQuery);