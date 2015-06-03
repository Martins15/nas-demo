(function($) {
  Drupal.behaviors.flywaySlides = {
    attach: function(context, settings) {
      var $slides = $(".flyway-slide"),
          $links = $(".flyway-slide-button");

      // Navigation links above
      $(".flyway-slide-button").once('flywaySlides').bind("click", function(e) {
        e.preventDefault();

        var $this = $(this),
            href = $this.attr("href"),
            $newSlide = $(href);

        $links.removeClass("current");
        $this.addClass("current");

        $slides.removeClass("current");
        $newSlide.addClass("current");
        
        $('.flyways-slides-dots .active').removeClass('active');
        $('.flyways-slides-dots a[href='+href+'] span').addClass('active');
      });

      // Next and previous paddles on the side
      $(".flyway-slides-paddle").once('flywaySlides').bind("click", function(e) {
        e.preventDefault();

        var $this = $(this),
                $currentSlide = $slides.filter(".current"),
                $link = "",
                $newSlide = "";

        if ($this.hasClass("next")) {
          $newSlide = $currentSlide.next(".flyway-slide");
          if ($newSlide.length == 0) {
            $newSlide = $slides.first();
          }
        }
        else if ($this.hasClass("prev")) {
          $newSlide = $currentSlide.prev(".flyway-slide");
          if ($newSlide.length == 0) {
            $newSlide = $slides.last();
          }
        }

        $link = $links.filter("[href='#" + $newSlide.attr("id") + "']");
        $links.removeClass("current");
        $link.addClass("current");

        $slides.removeClass("current");
        $newSlide.addClass("current");
      });
      
      // Dots to change slider
      $('.flyways-slides-dots a').once('flywaySlides').bind('click', function(e) {
        var selector = $(this).attr('href');
        e.preventDefault();
        $('.flyway-slide.current').removeClass('current');
        $('.flyways-slides-dots .active').removeClass('active');
        $('.flyway-slide-button.current').removeClass('current');
        $(selector).addClass('current');
        $(this).find('.dot').addClass('active');
        $('.flyway-slide-button[href='+selector+']').addClass('current');
      });
      
      // Equalize slider height
      if ($('.page-birds-flyways').length) {
        var max_height = 0;
        $('.flyway-slide').each(function() {
          var height = $(this).height();
          if (height > max_height) {
            max_height = height;
          }
        });
        // +100 relative to container padding.
        $('.flyway-slide').height(max_height + 100);
        $('.flyway-slide').parent().height(max_height + 100);
      }
    },
  };

})(jQuery);
