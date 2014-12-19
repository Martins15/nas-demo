// This script adds features like: zoomIn, zoomOut and drag to a picture.
// This script works with Colorbox script.
// But it can be easily changed for over cases.

(function($) {
  Drupal.behaviors.expand_hero = {
    attach: function(context, settings) {
      $('.lightboxzoom').colorbox({
        maxWidth:'80%',
        maxHeight:'80%',
        onComplete: function() {

          // Define DOM elements
          var $content = $('#cboxLoadedContent'),
              $img = $content.find('img'),
              $draggble = $('<div class="draggble"></div>'),
              $zoomin = $('<i class="lzoom_zoomin"></i>'),
              $zoomout = $('<i class="lzoom_zoomout"></i>'),
              $fullScreen = $('<i class="lzoom_fullscreen"></i>'),
              isMouseWheel = false,
              originalWidth = $content.width();


          // Add DOM elements and modify css
          $content.append($draggble, $zoomin, $zoomout, $fullScreen);
          $content.css({
            'overflow': 'hidden'
          });
          $img.css({
            'height': 'auto',
            'position': 'relative',
            'left': 0,
            'top': 0,
            'max-width': 'none'
          });


          // Zoomin event
          $zoomin.click(function() {
            if ($img.width() < 4000) {
              var w = 0,
                  wb = false, // width boolean
                  hb = false; // height boolean

              if ($img.width() < $content.width()) {
                w = $content.width() - $img.width();
              } else {
                w = $content.width();
                wb = true;
              }

              if ($img.height() > $content.height()) {
                hb = true;
              }

              $img.animate({
                'width': $img.width() * 2,
                'left': wb ? (parseInt($img.css('left')) * (-2) + w / 2) * (-1) : 0,
                'top': hb ? (parseInt($img.css('top')) * (-2) + w / 2) * (-1) : 0
              });
            }
          });

          // Zoomout event
          $zoomout.click(function() {
            if ($img.width() > originalWidth) {
              var w = 0,
                  wb = false, // width boolean
                  hb = false; // height boolean

              if ($img.width() < $content.width()) {
                w = $content.width() - $img.width();
              } else {
                w = $content.width();
                wb = true;
              }

              if ($img.height() > $content.height()) {
                hb = true;
              }

              $img.animate({
                'width': $img.width() / 2,
                'left': wb ?  (parseInt($img.css('left')) / (-2) - w / 4) * (-1) : 0,
                'top': hb ? (parseInt($img.css('top')) / (-2) - w / 4 ) * (-1) : 0
              });

            }
          });

          // Zoomin or out by scrolling. Draggble event on MouseWheel
          $draggble.mousewheel(function(e) {
            e.preventDefault();
            e.stopImmediatePropagation();


            if (!isMouseWheel) {
              var w = 0,
                  wb = false, // width boolean
                  hb = false; // height boolean

              if ($img.width() < $content.width()) {
                w = $content.width() - $img.width();
              } else {
                w = $content.width();
                wb = true;
              }

              if ($img.height() > $content.height()) {
                hb = true;
              }

              if (e.deltaY === 1) {
                if ($img.width() < 4000) {
                  isMouseWheel = true;
                  $img.animate({
                    'width': $img.width() * 2,
                    'left': wb ? (parseInt($img.css('left')) * (-2) + $content.width() / 2) * (-1) : 0,
                    'top': hb ? (parseInt($img.css('top')) * (-2) + $content.height() / 2) * (-1) : 0
                  },function() {isMouseWheel = false});
                }
              } else if (e.deltaY === -1) {
                if ($img.width() > originalWidth) {
                  isMouseWheel = true;
                  $img.animate({
                    'width': $img.width() / 2,
                    'left': wb ? (parseInt($img.css('left')) / (-2) - $content.width() / 4) * (-1) : 0,
                    'top': hb ? (parseInt($img.css('top')) / (-2) - $content.height() / 4) * (-1) : 0
                  },function() {isMouseWheel = false});
                }
              }
              console.log(e.deltaX, e.deltaY, e.deltaFactor);


            }

          });

          $fullScreen.click(function() {
            var req = $content.get( 0 ).requestFullScreen ||
                $content.get( 0 ).webkitRequestFullScreen ||
                $content.get( 0 ).msRequestFullscreen ||
                $content.get( 0 ).mozRequestFullScreen;
            req.call($content.get( 0 ));

          })

          $content.bind('webkitfullscreenchange mozfullscreenchange fullscreenchange msfullscreenchange', function(e) {
              var state = document.fullScreen || document.mozFullScreen || document.webkitIsFullScreen || document.MSFullscreenChange;
              var event = state ? 'FullscreenOn' : 'FullscreenOff';

              if (event === 'FullscreenOn') {
                $content.addClass('fullscreen');
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

        }
      });
    }
  };
})(jQuery);