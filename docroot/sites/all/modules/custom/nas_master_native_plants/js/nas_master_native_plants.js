(function ($) {
  /**
   * Birds Carousel on Native plants search results page.
   */
  Drupal.behaviors.npOwl = {
    attached: function(context, settings) {
      $('.bird-card-carousel .owl-carousel').once('np-owl', function () {
        var self = $(this);
        if (self.find('.node').length === 0) {
          return;
        }
        self.owlCarousel({
          items: 2,
          nav:true,
          pagination: false,
          autoWidth: true,
          margin: 10,
          navText: ["<i class=\"indicator-left icon-arrow-left\"></i>", "<i class=\"indicator-right icon-arrow-right\"></i>"],
          responsive : {
            0 : {
              items: 1,
              autoWidth: false
            },

            320 : {
              items: 2,
              autoWidth: false
            },

            580: {
              items: 3,
              autoWidth: false
            },

            602 : {
              items: 2,
              autoWidth: true
            }
          }
        });

        // Shift card title down if it gets split on several lines.
        $(window).bind('resize', function (e) {
          $('.bird-card-caption', self).each(function () {
            var $caption = $(this);
            var $header = $(this).find('h4');
            if ($header.height() > parseInt($header.css('line-height')) + 2) {
              $caption.addClass('bird-card-caption-long');
            }
            else {
              $caption.removeClass('bird-card-caption-long');
            }
          });
        });
      });
    }
  };

  /**
   * Bind camera icon to clearing thumbs.
   */
  Drupal.behaviors.npClearingFix = {
    attached: function(context, settings) {
      if (typeof Foundation === 'undefined') {
        return;
      }
      $(document).foundation({
        clearing: {
          close_selectors: '.clearing-close, div.clearing-blackout, div.visible-img, img'
        }
      });
      $('a.clearing-attach').once('np-clearing-fix', function () {
        var $self = $(this);
        $self.bind('click', function() {
          $self.parent().find('[data-clearing] a').trigger('click');
          return false;
        });
      });
    }
  };

  /**
   * Content search on native plants page.
   */
  Drupal.behaviors.nas_master_native_plants_contentSearch = {
    attach: function(context, settings) {
      var form_prefix = '<div class="row columns js-native-plants-search-button hide-for-medium hide-for-large hide-for-xlarge collapsed">' +
        '<div class="native-plants-search-icon icon-magnifier open js-open"></div>' +
        '<div class="native-plants-search-icon icon-delete close js-close"></div>' +
        '</div>';

      $('.js-search-collapsible').once('search-collapsible', function () {
        var prev = $(this).prev();
        if (prev.hasClass('js-native-plants-search-button')) {
          prev.remove();
        }
        var $buttonWrapper = $(form_prefix).insertBefore($(this)),
          $open = $buttonWrapper.find('.js-open'),
          $close = $buttonWrapper.find('.js-close'),
          $form = $buttonWrapper.next('.js-search-collapsible');

        $open.on('click', function () {
          $form.removeClass('collapsed');
          $buttonWrapper.removeClass('collapsed');
        });

        $close.on('click', function () {
          $form.addClass('collapsed');
          $buttonWrapper.delay(500).queue(function() {
            $(this).addClass('collapsed').dequeue();
          });
        });
      });
    }
  };

  /**
   * Update results after completing editing content via IPE.
   */
  Drupal.behaviors.nativePlantsEndIPE = {
    attach: function (context, settings) {
      $('body').once('np-endIPE', function () {
        $('body.panels-ipe').bind('endIPE', function () {
          if ($('.view-native-plants-search').length == 0) {
            return;
          }
          $('.view-filters .form-select:first', $('.view-native-plants-search')).trigger('change');
        });
      });
    }
  };

})(jQuery);
