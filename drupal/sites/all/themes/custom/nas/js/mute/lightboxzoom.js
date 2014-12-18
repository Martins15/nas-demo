// This script adds features like: zoomIn, zoomOut and drag to a picture.
// This script works with Colorbox script.
// But it can be easily changed for over cases.

(function($) {
  Drupal.behaviors.expand_hero = {
    attach: function(context, settings) {
      $('.lightboxzoom').colorbox({
        maxWidth:'90%',
        maxHeight:'90%',
        onComplete: function(){

          // Define DOM elements
          var $content = $('#cboxLoadedContent'),
              $img = $content.find('img'),
              $draggble = $('<div class="draggble"></div>')
              $zoomin = $('<i class="lzoom_zoomin"></i>'),
              $zoomout = $('<i class="lzoom_zoomout"></i>');

          // Add DOM elements and modify css
          $content.append($draggble, $zoomin, $zoomout);
          $content.css({'overflow': 'hidden'});
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
              $img.animate({
                'width': $img.width() * 2,
                'left': (parseInt($img.css('left')) * (-2) + $content.width() / 2) * (-1),
                'top': (parseInt($img.css('top')) * (-2) + $content.height() / 2) * (-1)
              });
            }
          });

          // Zoomout event
          $zoomout.click(function() {
            if ($img.width() > $content.width()) {
              $img.animate({
                'width': $img.width() / 2,
                'left': (parseInt($img.css('left')) / (-2) - $content.width() / 4) * (-1),
                'top': (parseInt($img.css('top')) / (-2) - $content.height() / 4) * (-1)
              });
            }
          });


        //------- Draggble feaure -------
          // Draggble variables
          var drag = false,
              xPos0 = 0,
              xPos1 = 0,
              yPos0 = 0;
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
          })

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