;(function ($) {
  Drupal.behaviors.grid_gallery = {
    attach: function (context, settings) {
      $(".grid-gallery .grid-gallery__lightbox", context).each(function() {
        $(this).attr('data-gallery', '#grid-gallery');
      });

      if (context == document) {
        var links = $('[data-gallery="#grid-gallery"]');
        var slide_index = parseInt(window.location.hash.substring(1));
        if (slide_index) {
          slide = links.get(slide_index - 1);
          setTimeout(function() {
            $(slide).trigger('click');
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
          $(event.target).find('.total').text(total);
          $(event.target).find('.credit').text($(gallery.list[index]).find('img').data('credit') || '');

          var $title = $(event.target).find('.title');
          var $description = $(event.target).find('.description');
          $title.stop().animate({opacity:0}, 200, function() {
            $title.html($(gallery.list[index]).find('img').data('title'));
            $title.parents('.title-wrapper').removeClass('overlay');
            if (!$(slide).hasClass('slide-loading')) {
              var padding = Math.max(($(window).width() - $(slide).find('img').width()) / 2 - 12.5, 0);
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
          window.location.hash = index + 1;
        })
        .on('slidecomplete', function (event, index, slide) {
          // Gallery slidecomplete event handler
          if (waitingSlide === index) {
            waitingSlide = false;
            var $title = $(event.target).find('.title');
            var $description = $(event.target).find('.description');
            var padding = Math.max(($(window).width() - $(slide).find('img').width()) / 2 - 12.5, 0);
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
          window.location.hash = '';
        })
        .on('closed', function (event) {
          // Gallery closed event handler
        });

    }
  };
})(jQuery);
