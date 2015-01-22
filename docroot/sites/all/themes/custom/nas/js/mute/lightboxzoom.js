// This script adds features like: zoomIn, zoomOut and drag to a picture.
// This script works with Colorbox script.
// But it can be easily changed for over cases.

(function($) {
  Drupal.behaviors.boa_expand_hero = {
    attach: function(context, settings) {
      var colorboxMaxWidth = "95%",
          colorboxMaxHeight = "90%",
          maxZoomLevel = 5000;
      $('.lightboxzoom').colorbox({
        maxWidth: colorboxMaxWidth,
        maxHeight: colorboxMaxHeight,
        innerWidth: colorboxMaxWidth,
        innerHeight: colorboxMaxHeight,
        reposition: true,
        onComplete: function() {

          // Define DOM elements
          var $content = $('#cboxLoadedContent'),
              $colorbox = $('#colorbox'),
              $img = $content.find('img'),
              $draggble = $('<div class="draggble"></div>'),
              $controls = $('<div class="controls"></div>'),
              $zoomin = $('<i class="lzoom_zoomin"></i>'),
              $zoomout = $('<i class="lzoom_zoomout"></i>'),
              $fullScreen = $('<i class="lzoom_fullscreen"></i>'),
              isMouseWheel = false,
              originalWidth = $content.width(),
              mouseWheelOb = {state: 'inactive'},
              fullScreen_state = 'FullscreenOff';

              $(window).on("resize", function(){
                if (fullScreen_state === 'FullscreenOff') {
                  $.colorbox.resize({
                    width: colorboxMaxWidth,
                    height: colorboxMaxHeight
                  });
                }
              });
          $colorbox.addClass('lzoom'); // from lightboxzoom

          $controls.append($zoomin, $zoomout, $fullScreen);

          // Add DOM elements and modify css
          $content.append($draggble, $controls);
          $content.css({
            'overflow': 'hidden'
          });

          $img.css({
            'height': 'auto',
            'position': 'relative',
            'left': 0,
            'top': 0,
            'max-width': 'none',
            'width': $colorbox.width()
          });


          // Zoomin event
          $zoomin.click(function() {
            if ($img.width() < maxZoomLevel) {
              zoom('in');
            }
          });

          // Zoomout event
          $zoomout.click(function() {
            if ($img.width() > originalWidth) {
              zoom('out');
            }
          });

          // Zoomin or out by scrolling. Draggble event on MouseWheel
          $draggble.mousewheel(function(e) {
            e.preventDefault();
            e.stopImmediatePropagation();

            if (mouseWheelOb.state === 'inactive') {
              if (e.deltaY === 1) {
                if ($img.width() < maxZoomLevel) {
                  mouseWheelOb.state = 'active' ;
                  zoom("in", function() {mouseWheelOb.state = 'inactive'});
                }
              } else if (e.deltaY === -1) {
                if ($img.width() > originalWidth) {
                  mouseWheelOb.state = 'active' ;
                  zoom("out", function() {mouseWheelOb.state = 'inactive'});
                }
              }
            }
          });

          $fullScreen.click(function() {
            var req;
            if (fullScreen_state === 'FullscreenOff') {
              req = $content.get( 0 ).requestFullScreen ||
                  $content.get( 0 ).webkitRequestFullScreen ||
                  $content.get( 0 ).msRequestFullscreen ||
                  $content.get( 0 ).mozRequestFullScreen;
              req.call($content.get( 0 ));
            } else {
              req = document.exitFullscreen ||
                  document.webkitExitFullscreen ||
                  document.msExitFullscreen ||
                  document.mozCancelFullScreen;
              req.call(document);
            }

          });

          $(document).bind('webkitfullscreenchange mozfullscreenchange fullscreenchange MSFullscreenChange', function(e) {
              var state = document.fullScreen || document.mozFullScreen || document.webkitIsFullScreen || document.MSFullscreenChange;
              fullScreen_state = state ? 'FullscreenOn' : 'FullscreenOff';

              if (fullScreen_state === 'FullscreenOn') {
                $content.addClass('fullscreen');
                $colorbox.width($(window).width());
                $content.width('100%');
                $content.height('100%');
              } else {
                $content.removeClass('fullscreen');
              }
          });

          //------- Draggble feature -------

          // Draggble variables
          var drag = false,
              xPos0 = 0,
              xPos1 = 0,
              yPos0 = 0,
              yPos1 = 0;

          // Draggble event on MouseDown
          $draggble.mousedown(function(e){
            drag = true;
            xPos0 = e.pageX;
            yPos0 = e.pageY;
          });

          // Draggble event on MouseUp
          $(document).mouseup(function(e){
            drag = false;
          });

          // Draggble event on MouseMove
          $draggble.mousemove(function(e){
            if (!drag) return false;
            e.preventDefault();
            xPos1 = xPos0;
            yPos1 = yPos0;
            xPos0 = e.pageX;
            yPos0 = e.pageY;

            var left = xPos0 - xPos1,
              top = yPos0 - yPos1;

            $img.css('left', parseInt($img.css('left')) + left + 'px');
            $img.css('top', parseInt($img.css('top')) +  top + 'px');

          });

          // Draggble event for mobile TouchMove
          $draggble.on("touchstart", function(e){
            xPos0 = e.pageX;
            yPos0 = e.pageY;
          });

          // Draggble event for mobile TouchMove
          $draggble.on("touchmove", function(e){
            e.preventDefault();
            xPos1 = xPos0;
            yPos1 = yPos0;
            xPos0 = e.originalEvent.touches[0].pageX;
            yPos0 = e.originalEvent.touches[0].pageY;

            var left = xPos0 - xPos1,
              top = yPos0 - yPos1;

            $img.css('left', parseInt($img.css('left')) + left + 'px');
            $img.css('top', parseInt($img.css('top')) +  top + 'px');
          });



          // Functions
          function zoom(type, callb) {
            var w = 0,
                wb = false, // width boolean
                hb = false, // height boolean
                cssOb = {};

            if ($img.width() >= $content.width()) {
              w = $content.width();
              wb = true;
            }

            if ($img.height() > $content.height()) {
              hb = true;
            }

            if (type === 'in') {
              cssOb = {
                'width': $img.width() * 2,
                'left': wb ? (parseInt($img.css('left')) * (-2) + w / 2) * (-1) : 0,
                'top': hb ? (parseInt($img.css('top')) * (-2) + w / 2) * (-1) : 0
              };
            } else if (type === 'out') {
              cssOb = {
                'width': $img.width() / 2,
                'left': wb ?  (parseInt($img.css('left')) / (-2) - w / 4) * (-1) : 0,
                'top': hb ? (parseInt($img.css('top')) / (-2) - w / 4 ) * (-1) : 0
              };

              // Set default place.
              if (cssOb.width < originalWidth) {
                cssOb = {
                  'width': originalWidth,
                  'left': 0,
                  'top': 0
                };
              }
            }

            if (typeof callb === 'function') {
              $img.animate(cssOb, callb);
            } else {
              $img.animate(cssOb);
            }

          }

        },
        onClosed: function() {
          var $colorbox = $('#colorbox');
          $colorbox.removeClass('lzoom');
        }
      });
    }
  };
})(jQuery);