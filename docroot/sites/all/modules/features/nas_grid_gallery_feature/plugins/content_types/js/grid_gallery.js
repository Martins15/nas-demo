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
          $title.stop().animate({opacity:0}, 100, function() {
            $title.html($(gallery.list[index]).find('img').data('title'));
            $title.parent().removeClass('overlay');
            if ($title.outerHeight() > $title.parent().outerHeight()) {
              $title.parent().addClass('overlay');
            }
            $title.animate({opacity:1}, 400);
          });
        })
        .on('slideend', function (event, index, slide) {
          // Gallery slideend event handler
          window.location.hash = index + 1;
        })
        .on('slidecomplete', function (event, index, slide) {
          // Gallery slidecomplete event handler
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
