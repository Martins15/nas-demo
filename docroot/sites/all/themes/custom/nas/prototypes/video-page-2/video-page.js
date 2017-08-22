(function ($) {

  $(window).on('resize', function () {
    Waypoint.refreshAll();
  });

  $(window).on('scroll', function() {
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

    function autoslick() {
      var windowHash = window.location.hash;
      var sectionNum = windowHash.replace( /^\D+/g, '')
      return sectionNum;
    }

    function videoContainerLogic(){

      var loadClass = 'is-loaded';
      var activeDotClass = 'active';
      var videoContainer = $('.video-container');
      var videoPageSection = $('.video-page-section');


      function changeActiveDot(hash) {
        $('.js-dot-navigation a').removeClass(activeDotClass);
        $('.js-dot-navigation a[href="' + hash +
            '"]').addClass(activeDotClass);
      }

      // Detect down scroll.
      videoContainer.each(function(){
        var el = $(this);
        var waypoint = new Waypoint({
          element: el,
          handler: function(direction) {
            if (direction == 'down') {

              // For modern browser need to check in ie10
              var hash = '#' + el.attr('id');

              if (hash === '#undefined') {
                history.pushState(null, null, window.location.pathname);
              } else {
                history.pushState(null, null, hash);
              }


              var $video = $('.main-video-item', el);
              var videoSrc = $video.data('src');
              var $placeholder = $('img', el);
              var videoContent = $('.video-content', el);

              // Lazy load for video and autoplay.
              $('source', el).attr("src", videoSrc);
              $video.get(0).load();
              $placeholder.addClass(loadClass);
              videoContent.addClass(loadClass);
              $video.get(0).play();

              // Change class for dot navigation.
              changeActiveDot(hash);

              $('.dot-navigation ul').slick('slickGoTo',
                  autoslick()
              )

            }
          },
          offset: '50%'
        });
      });


      // Detect up scroll.
      videoPageSection.each(function() {
        var el = $(this);
        var waypointUp = new Waypoint({
          element: el, // класс секции с текстом
          handler: function(direction) {
            if (direction == 'up') {

              // For modern browser need to check in ie10
              var hash = '#' + el.data('section');

              if (hash === '#undefined') {

                history.pushState(null, null, window.location.pathname);
              } else {
                history.pushState(null, null, hash);
              }


              // Change class for dot navigation.
              changeActiveDot(hash);
              $('.dot-navigation ul').slick('slickGoTo',
                  autoslick()
              )
            }
          },
          offset: '-50%'
        });
      })

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
          , $link = $('.dot', $dotContainer)
          , $textLink = $('.text', $dotContainer);

      // Dot title.
      $link.each(function () {
        var $el = $(this);
        var linkText = $el.data('text');
        var linkHref = $el.attr('href');
        $el.next().text(linkText);
        $el.next().attr('href', linkHref);

        console.log(linkText);

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
              slidesToShow: 3,
              centerMode: true
            }
          },
          {
            breakpoint: 320,
            settings: {
              arrows: false,
              slidesToShow: 3,
              centerMode: true
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


    thumbnailCarousel();
    dotNavigation();
    stickyDotsNav();
    thumbnailAutoplay();
    anchorLinks();
    videoContainerLogic();

  })


})(jQuery);

