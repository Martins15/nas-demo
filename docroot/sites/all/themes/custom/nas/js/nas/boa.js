(function ($) {
  Drupal.behaviors.boa_equalizer = {
    attach: function (context, settings) {
      $(window).on('load', function() {
        var breakpoints = {2: 601, 3: 768, 4:99999},
            // Equilize the height of the birds based on the row height.
            boa_equalize = function() {
              var max_height = 0,
                  col_number = range(window.innerWidth),
                  count = 1,
                  index = 1;
              $('.view-boa-index').attr('boa-equalizer', col_number);
              $('.view-boa-index .boa-item').each(function() {
                var height = $(this).find('.photo').height() + $(this).find('.common-name').height();
                $(this).attr('data-row', count);
                if (height > max_height) max_height = height;
                if ((index === col_number) || $(this).is(':last-child')) {
                  $('[data-row=' + count + ']').css('height', max_height + 40);
                  max_height = 0;
                  count = count + 1;
                  index = 0;
                }
                index = index + 1;
              });
            },
            // Get the number of birds in a row based on the screen size.
            range = function(number) {
              if (number < breakpoints[2]) return 2;
              else if (number < breakpoints[3]) return 3;
              else return 4;
            };
        // Recalculate all when window resize.
        function resizedw(){
          boa_equalize();
        }

        var doit;
        window.onresize = function(){
          clearTimeout(doit);
          doit = setTimeout(resizedw, 100);
        };

        // Init
        $('.boa-item').removeAttr('data-equalizer-watch');
        boa_equalize();
      });
    }
  };
})(jQuery);
