(function ($) {


  $(window).on('load', function () {


    // Init thumbnail preview.
    $('.thumbnail-container ul').owlCarousel({
      loop: false,
      responsiveClass:true,
      thumbs: true,
      navigation: true,
      items: 5
    });


    $('.video-page-section').each(function () {
      var el = $(this);
      var activeDotClass = 'active';

      var waypoint = new Waypoint({
        element: el,
        handler: function (direction) {

          // For modern browser need to check in ie10
          var hash = '#' + el.attr('id');
          history.pushState(null, null, hash);

          // Change class for dot navigation.
          $('.js-dot-navigation a').removeClass(activeDotClass);
          $('.js-dot-navigation a[href="' + hash + '"]').addClass(activeDotClass);

        },
        offset: 0
      })

    });

    // Sticky dot navigation.
    var stickyDotNavigation = new Waypoint.Sticky({
      element: $('.js-dot-navigation')[0],
      stuckClass: 'is-fixed',
      wrapper: false
    });


    // Thumbnail auto play.
    var thumbnailVideo = $('.thumbnail-video');
    thumbnailVideo.on('mouseenter', function () {
      if (this.paused) {
        this.play();
      }
    }).on('mouseleave', function () {
      if (!this.paused) {
        this.pause();
      }
    });


    // Animated anchor link scroll.
    $('a[href^="#"]').on('click', function (e) {
      e.preventDefault();

      var target = this.hash;
      var $target = $(target);

      $('html, body').stop().animate({
        'scrollTop': $target.offset().top - 50
      }, 900, 'swing', function () {
        window.location.hash = target;
      });
    });


    $('video').each(function(){
      if ($(this).is(":in-viewport")) {
        $(this)[0].play();
      } else {
        $(this)[0].pause();
      }
    })

  })


})(jQuery);

