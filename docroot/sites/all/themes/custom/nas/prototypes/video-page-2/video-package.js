(function ($) {

  $(window).on('resize', function () {
    Waypoint.refreshAll();
  });

  $(window).on('scroll', function () {
    Waypoint.refreshAll();
  });

  $(window).on('load', function() {
    Waypoint.refreshAll();
  });

  Drupal.behaviors.VideoLogic = {
    attach: function (context, settings) {

      var $videoContainer = $('.video-container', context);

      // Start playing when video will scroll at the top of the window.
      $videoContainer.each(function () {
        var el = $(this); // Video container.
        var waypoint = new Waypoint({
          element: el,
          handler: function() {
            var $video = $('.main-video-item', el); // Block with video tag.
            $video.get(0).currentTime = 0;
            $video.get(0).play();
            $video.get(0).addEventListener('ended',function(){
                this.currentTime = this.duration;
            });
          },
          offset: function() {
            return $('.dot-navigation').height();
          }
        })
      });


      // Video lazy load.
      $videoContainer.each(function () {
        var el = $(this); // Video container.
        var $video = $('.main-video-item', el); // Block with video tag.
        var videoSrc = $video.data('src'); // Current video src from data.
        var videoContent = $('.video-content', el); // Video copy.
        var loadClass = 'is-loaded'; // Load class name.
        var $dotContainer = $('.dot-navigation');
        var loadedVideoClass = 'video-loaded';
        // Lazy load for video.
        var inview = new Waypoint.Inview({
          element: el,

          // Video container in viewport.
          enter: function (direction) {
            // Get src from data attr and hide placeholder image.
            var $videoSrc = el.data('src');
            if (typeof $videoSrc == typeof undefined || $videoSrc == false) {// Element has this attribute
             $('source', el).attr('src', videoSrc);
             if( !$video.hasClass(loadedVideoClass) ) {
               $video.addClass(loadedVideoClass);
               $video.get(0).load(); // Load current video.
             }
              videoContent.addClass(loadClass); // Add load class.
            }
            else {
            }

          },

          // Video container out of viewport.
          exited: function (direction) {
            // Stop current video.
            $video.get(0).pause();

            // Hide title from active dot navigation.
            $('a.dot', $dotContainer).removeClass('video-at-top');

          }
        });
      });
    }
  };


  /**
   * Thumbnail carousel with anchor links.
   */
  Drupal.behaviors.thumbnailCarousel = {
    attach: function (context, settings) {
      var thumbClass = 'js-thumbnail-main'; // Main Thumbnail class.
      var copyThumbClass = 'js-thumbnail-secondary'; // Name for second thumb
                                                     // slider.
      var articleBodyClass = 'article-body'; // Main article class.
      var $originThumb = $('.' + thumbClass);
      var $thumbContainerOrigin = $('ul', $originThumb);

      // Clone origin thumb HTML and append to bottom article part.
      $originThumb
          .clone()
          .appendTo('.' + articleBodyClass)
          .removeClass(thumbClass)
          .addClass(copyThumbClass);

      $thumbContainerOrigin.slick({
        infinite: true,
        slidesToShow: 5,
        slidesToScroll: 1,
        responsive: [
          {
            breakpoint: 1024,
            settings: {
              slidesToShow: 5,
              slidesToScroll: 1
            }
          },
          {
            breakpoint: 600,
            settings: {
              slidesToShow: 3,
              slidesToScroll: 1
            }
          },
          {
            breakpoint: 480,
            settings: {
              slidesToShow: 2,
              slidesToScroll: 1
            }
          }
        ]
      });

      $('.js-thumbnail-secondary ul').slick({
        infinite: true,
        slidesToShow: 5,
        slidesToScroll: 1,
        responsive: [
          {
            breakpoint: 1024,
            settings: {
              slidesToShow: 5,
              slidesToScroll: 1,
            }
          },
          {
            breakpoint: 600,
            settings: {
              slidesToShow: 3,
              slidesToScroll: 1
            }
          },
          {
            breakpoint: 480,
            settings: {
              slidesToShow: 2,
              slidesToScroll: 1
            }
          }
        ]
      });

    }

  };


  /**
   * Return digit from window.hash.
   * @returns {string}
   */
  function autoslick() {
    var windowHash = window.location.hash;
    var sectionNum = windowHash.replace(/^\D+/g, '');
    sectionNum = sectionNum - 1;
    return sectionNum;
  }


  /**
   * Main page part logic.
   * @type {{attach: Drupal.behaviors.videoContainerLogic.attach}}
   */
  Drupal.behaviors.videoContainerLogic = {
    attach: function (context, settings) {

      var activeDotClass = 'active'; // Active dot class.
      var videoContainer = $('.video-container', context); // Block with video.
      var videoPageSection = $('.video-page-section'); // Block with text.

      // Trigger active class on dot carousel.
      function changeActiveDot(hash) {
        $('.js-dot-navigation a').removeClass(activeDotClass);
        $('.js-dot-navigation a[href="' + hash +'"]').addClass(activeDotClass);
      }

      // Detect down scroll on each video container.
      videoContainer.each(function () {
        var el = $(this);
        var waypoint = new Waypoint({
          element: el,
          handler: function (direction) {
            var hash;
            if (direction == 'up') {
              // Get hash tag from previous section in viewport.
              hash = '#' + $(el).prevUntil('.video-container').prev('.video-container').attr('id');
            }

            if (direction == 'down') {
              // Get hash tag from current section in viewport.
              hash = '#' + el.attr('id');
            }

            // Remove window.hash from main video block.
            if (hash === '#undefined') {
              history.pushState(null, null, window.location.pathname);
            }
            else {
              history.pushState(null, null, hash);
            }

            // Change active class in dot navigation.
            changeActiveDot(hash);

            // Auto slide dot navigation to current anchor link.
            $('.dot-navigation ul').slick('slickGoTo', autoslick());
          },
          // Implement logic when section in 50% of the viewport.
          offset: function() {
            return $('.dot-navigation').height();
          }
        });
      });


      //// Detect UP scroll.
      //videoPageSection.each(function () {
      //  var el = $(this);
      //  var waypointUp = new Waypoint({
      //    element: el,
      //    handler: function (direction) {
      //      if (direction == 'up') {
      //
      //        // Change window.hash from visible section.
      //        var hash = '#' + el.data('section');
      //        if (hash === '#undefined') {
      //          history.pushState(null, null, window.location.pathname);
      //        }
      //        else {
      //          history.pushState(null, null, hash);
      //        }
      //
      //        // Change active class in dot navigation.
      //        changeActiveDot(hash);
      //
      //        // Auto slide dot navigation to current anchor link.
      //        $('.dot-navigation ul').slick('slickGoTo',
      //            autoslick()
      //        );
      //
      //      }
      //    },
      //    // Implement logic when section in 50% of the viewport.
      //    offset: '-50%'
      //  });
      //})
    }
  };


  /**
   * Implement auto play on thumbnail hover.
   * @type {{attach: Drupal.behaviors.thumbnailAutoplay.attach}}
   */
  Drupal.behaviors.thumbnailAutoplay = {
    attach: function (context, settings) {
      var $thumbItem = $('.thumbnail-item', context); // Thumb item.
      var $thumbLink = $('a', $thumbItem); // Thumb link.
      var startDelay = 500;

      $("video").bind("ended", function () {
        this.currentTime = 0;
      });

      $thumbLink.each(function () {
        var el = $(this);
        var myTimeout;
        el.mouseenter(function () {
          myTimeout = setTimeout(function () {
            var thumbnailVideo = $('.thumbnail-video', el).get(0);
            if (thumbnailVideo.readyState !== 4) {
              thumbnailVideo.load();
            }
            if (thumbnailVideo.paused) {
              thumbnailVideo.play();
            }
          }, startDelay);
        }).mouseleave(function () {
          clearTimeout(myTimeout);
        });

      });

    }
  };


  /**
   * Implements show dot title when video at the top of the screen.
   * @type {{attach: Drupal.behaviors.showNavTitleOnTop.attach}}
   */
  Drupal.behaviors.showNavTitleOnTop = {
    attach: function (context, settings) {
      var $videoContainer = $('.video-container');
      var $video = $('.main-video-item', $videoContainer);
      var $dotContainer = $('.dot-navigation');
      var videoAtTopClass = 'video-at-top';

      $video.each(function () {
        var el = $(this);
        var waypointUp = new Waypoint({
          element: el,
          handler: function (direction) {


            $('a.dot', $dotContainer).removeClass(videoAtTopClass);
            $('a.dot.active').addClass(videoAtTopClass);

            setTimeout(function () {
              $('a.dot', $dotContainer).removeClass(videoAtTopClass);
            }, 3000)

          },
          offset: function () {
            return $('.dot-navigation').height();
          }

        });
      });

      $('a.dot').on('mouseenter', function() {
        $('a.dot').removeClass(videoAtTopClass);
      })

    }
  };


  /**
   * Smooth scroll for anchor link.
   * @type {{attach: Drupal.behaviors.anchorLinks.attach}}
   */
  Drupal.behaviors.anchorLinks = {
    attach: function (context, settings) {

      // Get all link with section href.
      $('a[href^="#"]').on('click', function (e) {
        e.preventDefault();

        var target = this.hash;
        var $target = $(target);

        // Smooth scroll.
        $('html, body').stop().animate({
          'scrollTop': $target.offset().top
        }, 900, 'swing', function () {
          window.location.hash = target;
        });
      });

    }
  };


  /**
   * Implements video content position.
   * @type {{attach: Drupal.behaviors.videoContentPosition.attach}}
   */
  Drupal.behaviors.videoContentPosition = {
    attach: function (context, settings) {
      var $videoContent = $('.video-content');

      $videoContent.each(function () {
        var $el = $(this);
        var elPositionTop = $el.data('top');
        var elPositionBottom = $el.data('bottom');

        // Set top position fot video content.
        if (elPositionTop !== '') {
          $el.css({
            'top': elPositionTop,
            'bottom': 'auto'
          })
        }

        // Set bottom position fot video content.
        if (elPositionBottom !== '') {
          $el.css({
            'bottom': elPositionBottom,
            'top': 'auto'
          })
        }

      });

    }
  };


  /**
   * Implement dot navigation with slider.
   * @type {{attach: Drupal.behaviors.dotNavigation.attach}}
   */
  Drupal.behaviors.dotNavigation = {
    attach: function (context, settings) {
      var $dotContainer = $('.dot-navigation', context) // Dot nav section;
          , $dotList = $('ul', $dotContainer) // Slider selector.
          , $link = $('.dot', $dotContainer) // Get dot link
          , $scrollToTop = $('.dot-title') // Scroll to top link.
          , scrollTime = 1500;

      // Get data for link tooltip from data attr.
      $link.each(function () {
        var $el = $(this);
        var $tooltip = $('.text', $el);
        var linkText = $el.data('text');
        var linkHref = $el.attr('href');
        $tooltip.text(linkText);
        $tooltip.attr('href', linkHref);

      });

      $scrollToTop.on('click', function(e) {
        e.preventDefault();
        var body = $("html, body");
        body.stop().animate({scrollTop:0}, scrollTime, 'swing', function() {
          // Finish animating.
        });
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
              centerMode: true,
              loop: true
            }
          },
          {
            breakpoint: 320,
            settings: {
              arrows: false,
              slidesToShow: 3,
              centerMode: true,
              loop: true
            }
          }
        ]
      });
    }
  };


  /**
   * Implement sticky dot nav.
   * @type {{attach: Drupal.behaviors.stickyDotsNav.attach}}
   */
  Drupal.behaviors.stickyDotsNav = {
    attach: function (context, settings) {
      var stickyDotNavigation = new Waypoint.Sticky({
        element: $('.js-dot-navigation')[0],
        stuckClass: 'is-fixed'
      });
    }
  };


})(jQuery);

