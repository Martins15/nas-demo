(function ($) {
  Drupal.behaviors.boa_equalizer = {
    attach: function (context, settings) {
      $(window).on('load', function() {
        var breakpoints = {2: 601, 3: 768, 4:99999},
            // Equilize the height of the birds based on the row height.
            boa_equalize = function() {
              var max_height = 0,
                  col_number = range(window.innerWidth),
                  row_number = 1,
                  index = 1;
              $('.view-boa-index').attr('boa-equalizer', col_number);
              $('.view-boa-index .boa-item').each(function() {
                var height = 0,
                    fontsize = 0;
				$(this).removeAttr('style');
				$(this).removeAttr('data-row');
                height = $(this).height();
                $(this).attr('data-row', row_number);
                if (height > max_height) max_height = height;
                if ((index === col_number) || $(this).is(':last-child')) {
                  $('[data-row=' + row_number + ']').css('height', max_height);
                  max_height = 0;
                  row_number = row_number + 1;
                  index = 0;
                }
                index = index + 1;
                // State name div height fix
                while ($(this).find('h2.boa-family-set-title').height() > 40) {
				  fontsize = parseInt($(this).find('h2.boa-family-set-title').css('font-size'));
                  $(this).find('h2.boa-family-set-title').css('font-size', fontsize - 2);
                }
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
        
        $(document).ajaxSuccess(function() {
          boa_equalize();
        });
      });
    }
  };
  
  Drupal.behaviors.boa_pager = {
    attach: function (context, settings) {
      $('.view-display-id-boa_index_state').find('.pager').parent().hide();
    }
  };
})(jQuery);
