;(function ($) {
  Drupal.behaviors.grid_gallery = {
    attach: function (context, settings) {
      $(".grid-gallery .grid-gallery__lightbox", context).each(function() {
        $(this).attr('data-gallery', '#grid-gallery');
      });

      if (context == document) {
        var links = $('[data-gallery="#grid-gallery"]');
        var slide_index = window.location.hash.substring(6);
        if (!isNaN(slide_index) && slide_index !== '' && $(window).width() >= 600) {
          setTimeout(function() {
            $(links.get(slide_index - 1)).trigger('click');
          }, 100);
        }
      }

      var waitingSlide = false;

      $("#grid-gallery", context)
        .on('open', function (event) {
          // Gallery open event handler
        })
        .on('opened', function (event) {
          // Gallery opened event handler
        })
        .on('slide', function (event, index, slide) {
          // Gallery slide event handler
          var gallery = $(event.target).data('gallery');
          var total = (index + 1) + ' of ' + gallery.list.length;
          gallery.container.find('.total').text(total);
          gallery.container.find('.credit').text($(gallery.list[index]).find('img').data('credit') || '');

          var $title = gallery.container.find('.title');
          var $description = gallery.container.find('.description');
          $title.stop().animate({opacity:0}, 200, function() {
            $title.html($(gallery.list[index]).find('img').data('title'));
            $title.parents('.title-wrapper').removeClass('overlay');
            if (!$(slide).hasClass('slide-loading')) {
              var image_width = Math.max($(slide).find('img').width(), 320);
              var padding = Math.max(($(window).width() - image_width) / 2 - 12.5, 0);
              $description
                .css({
                  paddingLeft: padding,
                  paddingRight: padding
                });
                setTimeout(function () {
                  if ($title.outerHeight() > $title.parent().outerHeight()) {
                    $title.parents('.title-wrapper').addClass('overlay');
                  }
                }, 100);
              $title.animate({opacity:1}, 400);
              waitingSlide = false;
            }
            else {
              waitingSlide = index;
            }
          });
        })
        .on('slideend', function (event, index, slide) {
          // Gallery slideend event handler
          window.history.replaceState(null, null, '#' + 'photo' + (index + 1));
        })
        .on('slidecomplete', function (event, index, slide) {
          // Gallery slidecomplete event handler
          if (waitingSlide === index) {
            var gallery = $(event.target).data('gallery');
            waitingSlide = false;
            var $title = gallery.container.find('.title');
            var $description = gallery.container.find('.description');
            var image_width = Math.max($(slide).find('img').width(), 320);
            var padding = Math.max(($(window).width() - image_width) / 2 - 12.5, 0);
            $description
              .css({
                paddingLeft: padding,
                paddingRight: padding
              });

            setTimeout(function () {
              if ($title.outerHeight() > $title.parent().outerHeight()) {
                $title.parents('.title-wrapper').addClass('overlay');
              }
            }, 100);
            $title.animate({opacity:1}, 400);
          }
        })
        .on('close', function (event) {
          // Gallery close event handler
          window.history.replaceState(null, null, '#');
        })
        .on('closed', function (event) {
          // Gallery closed event handler
        });

    }
  };
})(jQuery);
