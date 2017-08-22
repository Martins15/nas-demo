(function ($) {

  $(window).on('resize', function () {
    Waypoint.refreshAll();
  });

  $(window).on('scroll', function() {
    Waypoint.refreshAll();
  });

  /**
   * Thumbnail carousel with anchor links
   */
  Drupal.behaviors.thumbnailCarousel = {
    attach: function (context, settings) {
      var thumbClass = 'js-thumbnail-main'; // Main Thumbnail class.
      var copyThumbClass = 'js-thumbnail-secondary'; // Name for second thumb slider.
      var articleBodyClass = 'article-body'; // Main article class.
      var $originThumb = $('.' + thumbClass);
      var $thumbContainerOrigin = $('ul', $originThumb);

      // Clone origin thumb HTML and append to bottom article part.
      $originThumb
          .clone()
          .appendTo('.' + articleBodyClass)
          .removeClass(thumbClass)
          .addClass(copyThumbClass);

      // Main Top carousel.
      $thumbContainerOrigin.owlCarousel({
        loop: false,
        responsiveClass: true,
        thumbs: true,
        navigation: true,
        items: 5
      });

      // Bottom carousel.
      $('.js-thumbnail-secondary ul').owlCarousel({
        loop: false,
        responsiveClass: true,
        thumbs: true,
        navigation: true,
        items: 5
      });
    }

  };

  /**
   * Return digit from window.hash.
   * @returns {string}
   */
  function autoslick() {
    var windowHash = window.location.hash;
    var sectionNum = windowHash.replace( /^\D+/g, '')
    return sectionNum;
  }


  /**
   * Main page part logic.
   * @type {{attach: Drupal.behaviors.videoContainerLogic.attach}}
   */
  Drupal.behaviors.videoContainerLogic = {
    attach: function (context, settings) {
      var loadClass = 'is-loaded'; // Load class name.
      var activeDotClass = 'active'; // Active dot class.
      var videoContainer = $('.video-container', context); // Block with video.
      var videoPageSection = $('.video-page-section'); // Block with text.

      // Trigger active class on dot carousel.
      function changeActiveDot(hash) {
        $('.js-dot-navigation a').removeClass(activeDotClass);
        $('.js-dot-navigation a[href="' + hash +
            '"]').addClass(activeDotClass);
      }

      // Detect down scroll on each video container.
      videoContainer.each(function(){
        var el = $(this);
        var waypoint = new Waypoint({
          element: el,
          handler: function(direction) {
            if (direction == 'down') {

              // Get hash tag from current section in viewport.
              var hash = '#' + el.attr('id');

              // Remove window.hash from main video block.
              if (hash === '#undefined') {
                history.pushState(null, null, window.location.pathname);
              } else {
                history.pushState(null, null, hash);
              }

              var $video = $('.main-video-item', el); // Block with video tag.
              var videoSrc = $video.data('src'); // Current video src from data.
              var $placeholder = $('img', el); // Video placeholder.
              var videoContent = $('.video-content', el); // Video copy.
              var fadeTimer = 2000; // Fade time.

              // Lazy load for video.
              // Get src from data attr and hide placeholder image.
              $('source', el).attr("src", videoSrc);
              $video.get(0).load(); // Load current video.
              $placeholder.fadeOut(fadeTimer); // Hide placeholder.
              videoContent.addClass(loadClass); // Add load class.
              $video.get(0).play(); // Play current video.

              // Change active class in dot navigation.
              changeActiveDot(hash);

              // Auto slide dot navigation to current anchor link.
              $('.dot-navigation ul').slick('slickGoTo',
                  autoslick()
              );

            }
          },
          // Implement logic when section in 50% of the viewport.
          offset: '50%'
        });
      });


      // Detect UP scroll.
      videoPageSection.each(function() {
        var el = $(this);
        var waypointUp = new Waypoint({
          element: el,
          handler: function(direction) {
            if (direction == 'up') {

              // Change window.hash from visible section.
              var hash = '#' + el.data('section');
              if (hash === '#undefined') {
                history.pushState(null, null, window.location.pathname);
              } else {
                history.pushState(null, null, hash);
              }

              // Change active class in dot navigation.
              changeActiveDot(hash);

              // Auto slide dot navigation to current anchor link.
              $('.dot-navigation ul').slick('slickGoTo',
                  autoslick()
              )

            }
          },
          // Implement logic when section in 50% of the viewport.
          offset: '-50%'
        });
      })
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


      $thumbLink.each(function() {
        var el = $(this);

        // Start video play on hover;
        el.on('mouseenter', function () {
          var $thumbnailVideo = $('.thumbnail-video', el);
          if ($thumbnailVideo.get(0).paused) {
            $thumbnailVideo.get(0).play();
          }
        });

      });

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
   * Implement dot navigation with slider.
   * @type {{attach: Drupal.behaviors.dotNavigation.attach}}
   */
  Drupal.behaviors.dotNavigation = {
    attach: function (context, settings) {
      var $dotContainer = $('.dot-navigation', context) // Dot nav section;
          , $dotList = $('ul', $dotContainer) // Slider selector.
          , $link = $('.dot', $dotContainer); // Get dot link

      // Get data for link tooltip from data attr.
      $link.each(function () {
        var $el = $(this);
        var linkText = $el.data('text');
        var linkHref = $el.attr('href');
        $el.next().text(linkText);
        $el.next().attr('href', linkHref);
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

