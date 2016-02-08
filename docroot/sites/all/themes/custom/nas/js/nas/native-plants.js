(function($) {
  /**
   * Birds Carousel on Native plants search results page.
   */
  Drupal.behaviors.npOwl = {
    attach: function(context, settings) {
      $(".bird-card-carousel .owl-carousel").once('np-owl', function () {
        $(this).owlCarousel({
          items: 2,
          itemsDesktop: false,
          itemsDesktopSmall: false,
          itemsTablet: false,
          itemsMobile: false,
          paginationSpeed: 100,
          navigation: true,
          rewindNav: false,
          pagination: false,
          navigationText: ["<i class=\"indicator-left icon-arrow-left\"></i>", "<i class=\"indicator-right icon-arrow-right\"></i>"]
        });
      });
    }
  };

  /**
   * Sticky footer on Native plants search results page.
   */
  Drupal.behaviors.npStickyFooter = {
    attach: function(context, settings) {
      $(".native-plants-bottom-plant-list").once('np-sticky-footer', function () {
        var $self = $(this), $w = $(window);
        $(window).bind('scroll', function (e) {
          $self.removeAttr('style');
          var s = $w.scrollTop() + $w.height();
          var offset = $('.native-plants-bottom-form-title').offset().top;
          if (s < offset) {
            $self.css({
              bottom: 0,
              position: 'fixed',
              width: '100%',
              zIndex: 1
            });
          }
          else {
            $self.removeAttr('style');
          }
        });

        $('.native-plants-botton--get-list').click(function () {
          $self.removeAttr('style');
          var offset = $('.native-plants-bottom-form-title').offset().top;
          var h = $('.native-plants-bottom-form-title').outerHeight();
          h += $('.native-plants-bottom-form').outerHeight();
          var s =  h + offset - $w.height();
          $w.scrollTop(s);
        });
      });
    }
  };
})(jQuery);