(function ($) {

  Drupal.behaviors.VideoLogic = {
    attach: function (context, settings) {
      var $videoContainer = $('.video-container', context);

      // Video lazy load.
      $videoContainer.once('video-lazy-load').each(function () {
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
            $('source', el).attr('src', videoSrc);
            if (!$video.hasClass(loadedVideoClass)) {
              $video.addClass(loadedVideoClass);
              $video.get(0).load();
            }
            else if (direction == 'up') {
              $video.get(0).play();
            }
            videoContent.addClass(loadClass); // Add load class.
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
   * Builds thumbnail out of video section blocks data.
   */
  Drupal.behaviors.buildThumbnail = {
    attach: function (context, settings) {
      $('.thumbnail-container', context).once('thumbnail-container', function () {
        $(this).hide();
        var $list = $('<ul></ul>');
        $('.video-container').not('.main-video').each(function() {
          var hash = $(this).attr('id'),
            $video = $(this).find('video:eq(0)'),
            thumbPoster = ($video.data('thumb-poster') || $video.attr('poster')),
            thumbSource = ($video.data('thumb-src') || $video.data('src')),
            shortTitle = ($video.data('short-title') || $(this).find('h1').text()),
            shortTitlColor = $('.dot-navigation').css("background-color");
          var $listitem = '<li>' +
            '<div class="thumbnail-item">' +
            '  <a href="#' + hash + '">' +
            '    <video muted playsinline class="thumbnail-video" poster="' + thumbPoster + '"  preload="none">' +
            '      <source src="' + thumbSource + '" type="video/mp4">' +
            '    </video>' +
            '    <div class="thumb-tooltip"';
          if (shortTitlColor.length) {
            $listitem += 'style="background-color:' + shortTitlColor + ';"';
          }
          $listitem += '>' +
            '      <span>' + shortTitle + '</span>' +
            '    </div>' +
            '  </a>' +
            '</div>' +
            '</li>';
          $listitem = $($listitem);
          $listitem.appendTo($list);
        });
        $list.appendTo($(this));
        $(this).fadeIn(2000);

        // Attach slick.
        $list.slick({
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
      });
    }
  };

  /**
   * Return digit from window.hash.
   * @returns {string}
   */
  function autoslick() {
    var windowHash = window.location.hash;
    if (windowHash !== '') {
      return $(windowHash).index('.video-container') - 1;
    }
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

      // Trigger active class on dot carousel.
      function changeActiveDot(hash) {
        $('.js-dot-navigation a').removeClass(activeDotClass);
        $('.js-dot-navigation a[href="' + hash +'"]').addClass(activeDotClass);
      }

      // Workaround for scrolling up.
      var prev_hash = '#undefined';
      $('.video-container').not('.main-video').each(function () {
        $(this).data('prev-hash', prev_hash);
        prev_hash = '#' + $(this).attr('id');
      });

      // Detect scrolls on each video container.
      videoContainer.once('video-container-logic').each(function () {
        var el = $(this);
        var waypoint = new Waypoint({
          element: el,
          handler: function (direction) {
            var hash;
            if (direction == 'up') {
              // Get hash tag from previous section in viewport.
              hash = $(el).data('prev-hash');
            }

            if (direction == 'down') {
              // Get hash tag from current section in viewport.
              hash = '#' + el.attr('id');
            }
            if (hash === '#undefined') {
              hash = '';
            }

            var video = $('.main-video-item', el).get(0); // Block with video tag.
            if (video.currentTime == video.duration) {
              video.currentTime = 0;
            }
            video.play();

            // Remove window.hash from main video block.
            if (window.location.hash !== hash) {
              // Change active class in dot navigation.
              changeActiveDot(hash);
              try {
                if (hash === '') {
                  history.replaceState(null, null, window.location.pathname);
                }
                else {
                  history.replaceState(null, null, hash);
                }
              }
              catch (e) {
              }
            }


            // Auto slide dot navigation to current anchor link.
            $('.dot-navigation ul').slick('slickGoTo', autoslick());
          },
          offset: function() {
            var top = $('.dot-navigation').css('top');
            if (top == 'auto') {
              top = 0;
            }
            return ($(window).width() > 767 ? 50 : 48) + parseInt(top);
          }
        });
      });
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
      var $videoContainer = $('.video-container', context);
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
            var top = $('.dot-navigation').css('top');
            if (top == 'auto') {
              top = 0;
            }
            return ($(window).width() > 767 ? 50 : 48) + parseInt(top);
          }
        });
      });

      $('a.dot').on('mouseenter', function() {
        $('a.dot').removeClass(videoAtTopClass);
      });

    }
  };


  /**
   * Smooth scroll for anchor link.
   * @type {{attach: Drupal.behaviors.anchorLinks.attach}}
   */
  Drupal.behaviors.zAnchorLinks = {
    attach: function (context, settings) {
      // Get all links with section href.
      $('.thumbnail-container a[href^="#"], .dot-navigation a[href^="#"]').on('click', function (e) {
        e.preventDefault();

        var target = this.hash;
        var $target = $(target);
        var $dotnavigation = $('.dot-navigation');
        var dotNavHeight = $dotnavigation.height() - 3;
        var fixedClass = 'is-fixed';
        
          // Smooth scroll.
          $('html, body').stop().animate({
            'scrollTop': $target.offset().top - dotNavHeight
          }, 900, 'swing', function () {
          });

      });
    }
  };



  /**
   * Implements video content position.
   */
  Drupal.behaviors.videoContentPosition = function () {
    var $videoContent = $('.video-content');
    $videoContent.each(function (key, value) {
      var $el = $(this)
        , elPositionTop = $el.data('top')
        , elPositionBottom = $el.data('bottom')
        , elPositionTopJsOffset = Drupal.behaviors.calculateVideoTitleOffset($el, key);

      if (typeof elPositionTopJsOffset !== "undefined") {
        elPositionTop = elPositionTopJsOffset;
        elPositionBottom = '';
      }
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
  };


  /**
   * React on window resize to adjust video title position.
   */
  Drupal.behaviors.resizeVideoTitlePosition = {
    attach: function (context, settings) {
      Drupal.behaviors.videoContentPosition();
      $(window).on('resize', function(){
        Drupal.behaviors.videoContentPosition();
      });
    }
  };


  /**
   * Calculate if we need top offset based on screen ratio.
   * @returns {string}
   */
  Drupal.behaviors.calculateVideoTitleOffset = function ($el, key) {
    if($el.height() !== 0){
      var h = window.innerHeight
        , w = window.innerWidth
        , ratio = h/w
        // height of the dot bar
        , dotBarHeight = 48;
      if(ratio<0.6){
        h -= (key == 0) ? $('body>header').height() : dotBarHeight;
        h -= $el.height();
        return h;
      }
    }
  };


  /**
   * Implement dot navigation with slider.
   * @type {{attach: Drupal.behaviors.dotNavigation.attach}}
   */
  Drupal.behaviors.dotNavigation = {
    attach: function (context, settings) {
      var $dotContainer = $('.dot-navigation', context),
        $scrollToTop = $('.dot-title', $dotContainer),
        backgroundColor = $dotContainer.css('background-color'),
        scrollTime = 1500;

      $dotContainer.once('dot-navigation', function () {
        $(this).hide();
        var $list = $('<ul></ul>');
        $('.video-container').not('.main-video').each(function () {
          var hash = $(this).attr('id'),
            $video = $(this).find('video:eq(0)'),
            shortTitle = ($video.data('short-title') || $(this).find('h1').text());
          var $listitem = $('<li>' +
            '  <a href="#' + hash + '" data-text="' + shortTitle + '" class="dot">' +
            '    <span class="circle"></span>' +
            '    <span class="text-wrapper">' +
            '      <span href="#' + hash + '" class="text">' + shortTitle + '</span>' +
            '    </span>' +
            '  </a>' +
            '</li>');
          $listitem.find('.text').css({backgroundColor: backgroundColor});
          $listitem.appendTo($list);
        });
        $list.appendTo($(this).find('.mobile-slide-wrapper'));
        $(this).fadeIn();

        // Dot carousel
        $list.slick({
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
      });

      $scrollToTop.on('click', function(e) {
        e.preventDefault();
        var body = $("html, body");
        body.stop().animate({scrollTop:0}, scrollTime, 'swing', function() {
          // Finish animating.
        });
      });

      Drupal.behaviors.zAnchorLinks.attach(context, settings);
    },
    detach: function (context) {
      $('.dot-navigation-processed', context).each(function () {
        $(this)
          ///.removeClass('dot-navigation-processed')
          .find('ul')
            .remove();
      });
      // Todo: detach slick.
    }
  };


  /**
   * Implement sticky dot nav.
   * @type {{attach: Drupal.behaviors.stickyDotsNav.attach}}
   */
  Drupal.behaviors.stickyDotsNav = {
    obj: null,
    attach: function (context, settings) {
      if ($('.panels-ipe-editing').size() > 0) {
        return;
      }
      if (!$('.js-dot-navigation', context).size()) {
        return;
      }
      Drupal.behaviors.stickyDotsNav.obj = new Waypoint.Sticky({
        element: $('.js-dot-navigation', context)[0],
        stuckClass: 'is-fixed'
      });
    },
    detach: function (context) {
      $('.js-dot-navigation.is-fixed').removeClass('is-fixed');
      if (Drupal.behaviors.stickyDotsNav.obj) {
        Drupal.behaviors.stickyDotsNav.obj.destroy();
        Drupal.behaviors.stickyDotsNav.obj = null;
      }
    }
  };

})(jQuery);
