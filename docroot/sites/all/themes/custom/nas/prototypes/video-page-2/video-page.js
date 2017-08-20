(function ($) {

  $(window).on('resize', function () {
    Waypoint.refreshAll();
  });


  $(window).on('load', function () {

    function thumbnailCarousel(){

      var thumbClass = 'js-thumbnail-main';
      var copyThumbClass = 'js-thumbnail-secondary';
      var articleBodyClass = 'article-body';
      var $originThumb = $('.' + thumbClass);
      var $secondaryThumb = $('.' + copyThumbClass);
      var $thumbContainerOrigin = $('ul', $originThumb);
      var $thumbContainerCopy = $('ul', $secondaryThumb);

      $originThumb
          .clone()
          .appendTo('.' + articleBodyClass)
          .removeClass(thumbClass)
          .addClass(copyThumbClass);

      $thumbContainerOrigin.owlCarousel({
        loop: false,
        responsiveClass: true,
        thumbs: true,
        navigation: true,
        items: 5
      });


      $('.js-thumbnail-secondary ul').owlCarousel({
        loop: false,
        responsiveClass: true,
        thumbs: true,
        navigation: true,
        items: 5
      });

    }

    function videoContainerLogic(){
      $('.video-container').each(function () {
        var el = $(this);
        var activeDotClass = 'active';
        var $video = $('.main-video-item', el);
        var videoSrc = $video.data('src');
        var $placeholder = $('img', el);
        var loadClass = 'is-loaded';

        var waypoint = new Waypoint({
          element: el,
          handler: function (direction) {

            // For modern browser need to check in ie10
            var hash = '#' + el.attr('id');
            history.pushState(null, null, hash);

            // Lazy load for video and autoplay.
            $('source', el).attr("src", videoSrc);
            $video.get(0).load();
            $placeholder.addClass(loadClass);
            $video.get(0).play();

            // Change class for dot navigation.
            $('.js-dot-navigation a').removeClass(activeDotClass);
            $('.js-dot-navigation a[href="' + hash +
                '"]').addClass(activeDotClass);
          }, offset: '50%'
        })
      });
    }

    function thumbnailAutoplay() {
      var $thumbItem = $('.thumbnail-item');
      var $thumbLink = $('a', $thumbItem);

      $thumbLink.each(function() {
        var el = $(this);

        el.on('mouseenter', function () {
          var $thumbnailVideo = $('.thumbnail-video', el);
          if ($thumbnailVideo.get(0).paused) {
            $thumbnailVideo.get(0).play();
          }
        });

      })


      $thumbLink.on('mouseenter', function () {
        var el = $(this);
        var $thumbnailVideo = $('.thumbnail-video', el);
        if ($thumbnailVideo.paused) {
          $thumbnailVideo.get(0).play();
        }
      });

    }

    function anchorLinks(){
      $('a[href^="#"]').on('click', function (e) {
        e.preventDefault();

        var target = this.hash;
        var $target = $(target);

        $('html, body').stop().animate({
          'scrollTop': $target.offset().top
        }, 900, 'swing', function () {
          window.location.hash = target;
        });
      });
    }

    function dotNavigation() {
      var $dotContainer = $('.dot-navigation')
          , $dotList = $('ul', $dotContainer)
          , $link = $('a', $dotContainer);

      // Dot title.
      $link.each(function () {
        var $el = $(this);
        var linkText = $el.data('text');
        $el.next().text(linkText);
      });

      // Dot carousel
      $dotList.slick({
        centerMode: false,
        slidesToShow: 9,
        infinite: false,
        arrows: false,
        responsive: [
          {
            breakpoint: 768,
            settings: {
              arrows: false,
              slidesToShow: 3
            }
          },
          {
            breakpoint: 320,
            settings: {
              arrows: false,
              slidesToShow: 3
            }
          }
        ]

      });


    }

    function stickyDotsNav() {
      var stickyDotNavigation = new Waypoint.Sticky({
        element: $('.js-dot-navigation')[0],
        stuckClass: 'is-fixed'
      });
    }


    videoContainerLogic();
    thumbnailCarousel();
    dotNavigation();
    stickyDotsNav();
    thumbnailAutoplay();
    anchorLinks();

  })


})(jQuery);

