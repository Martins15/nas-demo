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
              resize_slide(slide, true);
              resize_description(event, index, slide);
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
            resize_slide(slide, true);
            resize_description(event, index, slide);
          }
        })
        .on('close', function (event) {
          // Gallery close event handler
          window.history.replaceState(null, null, '#');
        })
        .on('closed', function (event) {
          // Gallery closed event handler
        });

      $(window).on('resize', function () {
        $("#grid-gallery .slide", context).each(function() {
          resize_slide(this);
        });
      });

      var resize_description = function (event, index, slide) {
        var gallery = $(event.target).data('gallery');
        waitingSlide = false;
        var $title = gallery.container.find('.title');
        var $description = gallery.container.find('.description');
        var image_width = Math.max($(slide).find('img').width(), 320);
        var margin = ($(window).width() >= 480 && $(window).width() <= 1020) ? 25 : 12.5;
        var padding = Math.max(($(window).width() - image_width) / 2 - margin, 0);
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
      };

      // Handle landscape pictures.
      var resize_slide = function (slide, prev_next) {
        var $img = $(slide).find('img');
        if ($img.size() == 0) {
          return;
        }
        var image_dimensions = {
          width: $img.width(),
          height: $img.height()
        };
        var slide_dimensions = {
          width: $(slide).width(),
          height: $(slide).height()
        };
        var image_aspect_ratio = image_dimensions.width / image_dimensions.height;
        var slide_aspect_ratio = slide_dimensions.width / slide_dimensions.height;
        $(slide).find('img').removeClass('slide-content-landscape');
        if (image_aspect_ratio > slide_aspect_ratio) {
          $(slide).find('img').addClass('slide-content-landscape');
        }

        if (prev_next) {
          if ($(slide).next('.slide')) {
            resize_slide($(slide).next('.slide'), false);
          }
          if ($(slide).next('.slide').next('.slide')) {
            resize_slide($(slide).next('.slide').next('.slide'), false);
          }
          if ($(slide).prev('.slide')) {
            resize_slide($(slide).prev('.slide'), false);
          }
        }
      };
    }
  };
})(jQuery);
