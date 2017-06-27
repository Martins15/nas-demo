;(function ($) {
  Drupal.behaviors.grid_gallery = {
    attach: function (context, settings) {
      $('.grid-gallery .grid-gallery__lightbox', context).each(function() {
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
      var lastSlide = false;

      $('#grid-gallery', context)
        .on('open', function (event) {
          // Gallery open event handler
        })
        .on('opened', function (event) {
          // Gallery opened event handler
          var gallery = $("#grid-gallery").data('gallery');
          $('#grid-gallery .slide', context).each(function() {
            resize_slide(this, $(this).data('index') == gallery.index);
          });
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
            $description.find('.title').parents('.title-wrapper').removeClass('overlay');
            if (!$(slide).hasClass('slide-loading')) {
              waitingSlide = false;
              if (index == lastSlide) return;
              lastSlide = index;
              resize_slide(slide, true);
            }
            else {
              waitingSlide = index;
            }
          });
        })
        .on('slideend', function (event, index, slide) {
          // Gallery slideend event handler
          window.history.replaceState(null, null, '#photo' + (index + 1));
        })
        .on('slidecomplete', function (event, index, slide) {
          // Gallery slidecomplete event handler
          if (waitingSlide === index) {
            waitingSlide = false;
            resize_slide(slide, true);
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
        var gallery = $("#grid-gallery").data('gallery');
        $('#grid-gallery .slide', context).each(function() {
          resize_slide(this, $(this).data('index') == gallery.index);
        });
      });

      var resize_description = function (event, index, slide) {
        var gallery = $(event.target).data('gallery');
        var $description = gallery.container.find('.description');
        var $title = $description.find('.title');
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
        gallery.container.find('.title').animate({opacity:1}, 400);
      };

      // Handle landscape pictures.
      var resize_slide = function (slide, current_slide) {
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

        var is_alternative = false;
        if (current_slide) {
          var maximum_allowed = {
            height: window.innerHeight,
            width: window.innerWidth > 1000 ? Math.max(1000, window.innerWidth * 0.8) : window.innerWidth
          };
          var minimum_description_width = 320;

          var eff_height = maximum_allowed.height - 50 - parseInt($('.slides').css('padding-top'));
          var eff_width = eff_height * image_aspect_ratio;

          if (eff_width > maximum_allowed.width - minimum_description_width) {
            $('.nas-blueimp-gallery').removeClass('nas-blueimp-gallery-alternative');
          }
          else {
            is_alternative = true;
            $('.nas-blueimp-gallery').addClass('nas-blueimp-gallery-alternative');
            image_dimensions = {
              width: $img.width(),
              height: $img.height()
            };
            $('.title-wrapper-alternative').css({
              marginLeft: image_dimensions.width / 2 - 160,
              maxHeight: image_dimensions.height,
              overflow: 'auto'
            });
          }
        }

        $(slide).find('img').removeClass('slide-content-landscape');
        if (!is_alternative && image_aspect_ratio > slide_aspect_ratio) {
          $(slide).find('img').addClass('slide-content-landscape');
        }

        if (current_slide) {
          resize_description({target: '#grid-gallery'}, 0, slide);

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
